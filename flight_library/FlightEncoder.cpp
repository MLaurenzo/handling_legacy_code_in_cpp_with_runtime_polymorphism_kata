#include "FlightEncoder.h"

#include <>
#include <stdexcept>

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
    // encoder passenger information
}

void FlightEncoder::encoderFlight() const
{
    // encode fligt information
}

void FlightEncoder::encoderOtherStuff() const
{
    // simulate the database connexion failing
    throw std::runtime_error("Failed to connect to the database");
}