#ifndef MSP_HPP
#define MSP_HPP

#include <asio.hpp>

namespace msp {

/**
 * @brief The MSP class
 */
class MSP {
public:

    /**
     * @brief MSP construct MSP communication without establishing a connection
     */
    MSP();

    /**
     * @brief MSP constructor for MSP communication
     * @param device device path
     * @param baudrate serial baudrate
     */
    MSP(const std::string &device, const size_t baudrate=115200);

    /**
     * @brief connect establish connection to serial device
     * @param device path or name of serial device
     * @param baudrate serial baudrate (default: 115200)
     * @return true on success
     */
    bool connect(const std::string &device, const size_t baudrate=115200);

private:
    asio::io_service io;     ///<! io service
    asio::serial_port port;  ///<! port for serial device
};

} // namespace msp

#endif // MSP_HPP
