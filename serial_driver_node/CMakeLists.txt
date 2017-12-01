cmake_minimum_required(VERSION 3.5)

project(serial_driver_node)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(PkgConfig)
pkg_check_modules(serial_driver_library REQUIRED serial_driver_library)
include_directories(${serial_driver_library_INCLUDE_DIRS})
link_directories(${serial_driver_library_LIBRARY_DIRS})

add_executable(serial_driver_node src/serial_driver_node.cpp)
ament_target_dependencies(serial_driver_node rclcpp)
target_link_libraries(serial_driver_node ${serial_driver_library_LIBRARIES})

install(TARGETS serial_driver_node
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib/${PROJECT_NAME})

ament_package()
