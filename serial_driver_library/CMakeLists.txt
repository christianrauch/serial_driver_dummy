cmake_minimum_required(VERSION 2.8)
project(serial_driver_library)

add_definitions(-std=c++11)
add_definitions(-Wall)

if(UNIX)
    set(BUILD_SHARED_LIBS "ON")
endif()

add_definitions(-DASIO_STANDALONE)

if(WIN32)
    include_directories(${ASIO_HEADER_PATH})
endif()

find_package(Threads)

set(MSP_INCLUDE_DIR inc/serial_driver)
include_directories(${MSP_INCLUDE_DIR})


################################################################################
### libraries

# low-level API
add_library(serial_driver src/MSP.cpp)
target_link_libraries(serial_driver ${CMAKE_THREAD_LIBS_INIT})

################################################################################
### installation

install(TARGETS serial_driver
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(DIRECTORY ${MSP_INCLUDE_DIR}/ DESTINATION include/serial_driver FILES_MATCHING PATTERN "*.hpp")

SET(PKG_CONFIG_LIBDIR       "\${prefix}/lib" )
SET(PKG_CONFIG_INCLUDEDIR   "\${prefix}/include/" )
SET(PKG_CONFIG_LIBS         "-L\${libdir} -lserial_driver" )
SET(PKG_CONFIG_CFLAGS       "-I\${includedir}" )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/pkg-config.pc.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
)

INSTALL(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc"
        DESTINATION lib/pkgconfig)
