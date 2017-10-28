# Handling legacy code in C++ with runtime polymorphism kata

In the context of working with legacy code, we sometimes would like to test our methods and
classes, but it happens that the type of the parameters we are using belongs to some legacy
code and cannot be used in unit tests because of depending on database connection
for instance.

A good first approach is to extract an interface from the type of the parameter,
create a mock and override the methods which we cannot use easily in our unit tests.
However it could also happen that we cannot change this legacy code
and then not being able to make the legacy class inherit
from the interface we just created
if the code belongs to another team for instance.

The goal of this kata is to explore different ways of implementing
the "override method" technique in C++.

## Project explanation
```
#include <FlightEncoder.h>
#include <InternalDataStructure.h>

void sendMessage(const FlightEncoder& flightEncoder)
{
    flightEncoder.encode();
}

int main()
{
    InternalDataStructure internalDataStructure;
    FlightEncoder flightEncoder(internalDataStructure);

    sendMessage(flightEncoder);
}
```
Your main.cpp file is responsible of instanciating a InternalDataStructure,
instanciating a FlightEncoder and calling the method encode on the FlightEncoder.

If you try to run this code, this is going to crash because
the encode method in the FlightEncoder is calling another method which is using
the database connection, which is not possible if you are not in the production environment
with all the magic initializations.

## Kata
First, practise the classical "override method":
- add a virtual destructor for the FlightEncoder
- make the method you want to override virtual
- create a mock class inheriting from the FlightEncoder class
- override the method which makes the class difficult to use

Secondly, try to come with a solution where you do not change the flight_library folder.

You can look at my personal solution. You just need to include the Solution.h file in the
main.cpp file, and change the sendMessage signature from
```
void sendMessage(const FlightEncoder& flightEncoder)
```
to
```
void sendMessage(const FlightEncoderWrapper& flightEncoder)
```