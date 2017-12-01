#include "MSP.hpp"

namespace msp {

MSP::MSP() : port(io){ }

MSP::MSP(const std::string &device, const size_t baudrate) : port(io) {
    connect(device, baudrate);
}

bool MSP::connect(const std::string &device, const size_t baudrate) {
    port.open(device);

    port.set_option(asio::serial_port::baud_rate(baudrate));
    port.set_option(asio::serial_port::parity(asio::serial_port::parity::none));
    port.set_option(asio::serial_port::character_size(asio::serial_port::character_size(8)));
    port.set_option(asio::serial_port::stop_bits(asio::serial_port::stop_bits::one));

    return true;
}

} // namespace msp
