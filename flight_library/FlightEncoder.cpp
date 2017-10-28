#include "FlightEncoder.h"

#include <iostream>
#include <stdexcept>

using namespace std;

FlightEncoder::FlightEncoder(const InternalDataStructure &internalDataStructure)
        : m_internalDataStructure(internalDataStructure)
{

}

void FlightEncoder::encode() const
{
    encodePassenger();
    encoderFlight();
    encoderOtherStuff();
}

void FlightEncoder::encodePassenger() const
{
    cout << "encode passenger information" << endl;
}

void FlightEncoder::encoderFlight() const
{
    cout << "encode flight information" << endl;
}

void FlightEncoder::encoderOtherStuff() const
{
    // simulate the database connexion failing inside a unit test
    throw std::runtime_error("Failed to connect to the database");
}