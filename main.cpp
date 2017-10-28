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