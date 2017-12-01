#include <rclcpp/rclcpp.hpp>

#include <serial_driver/MSP.hpp>

class SerialNode : public rclcpp::Node {
public:
    SerialNode() : Node("serial_device") {
        std::cout << "constructing..." << std::endl;
        msp::MSP device;
        std::cout << "done..." << std::endl;
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    std::cout << "creating node..." << std::endl;
    rclcpp::spin(std::make_shared<SerialNode>());

    std::cout << "exit" << std::endl;
    rclcpp::shutdown();
    return 0;
}
