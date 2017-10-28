#ifndef HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_FLIGHTENCODER_H
#define HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_FLIGHTENCODER_H

#include "InternalDataStructure.h"

class FlightEncoder
{
public:
    FlightEncoder(const InternalDataStructure& internalDataStructure)
            : m_internalDataStructure(internalDataStructure)
    {}

private:
    const InternalDataStructure& m_internalDataStructure;
};


#endif //HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_FLIGHTENCODER_H
