#ifndef HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_SOLUTION_H
#define HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_SOLUTION_H

#include <FlightEncoder.h>

#include <memory>

// we will call the method of the object by default
template <typename EncoderType>
void encode_override(const EncoderType& encoder)
{ encoder.encode(); }

class FlightEncoderWrapper
{
public:
    template <typename EncoderType>
    FlightEncoderWrapper(const EncoderType& encoder) : m_internal(std::make_unique<EncoderImpl<EncoderType>>(encoder)) {}

    void encode() const
    { m_internal->internal_encode(); }

private:
    struct EncoderBase
    {
        virtual ~EncoderBase() = default;
        virtual void internal_encode() const = 0;
    };

    template <typename EncoderType>
    struct EncoderImpl : EncoderBase
    {
        EncoderImpl(EncoderType encoder) : encoder(std::move(encoder)) {}
        void internal_encode() const override
        { encode_override(encoder); }
    private:
        EncoderType encoder;
    };

    std::unique_ptr<EncoderBase> m_internal;
};

void encode_override(FlightEncoder flightEncoder)
{
    flightEncoder.encoderFlight();
    flightEncoder.encodePassenger();
    // do not call encoderOtherStuff method
    //flightEncoder.encoderOtherStuff();
}

#endif //HANDLING_LEGACY_CODE_IN_CPP_WITH_RUNTIME_POLYMORPHISM_KATA_SOLUTION_H
