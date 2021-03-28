cmake_minimum_required(VERSION 3.0)
project(AbletonLinkMIDIClock)

include(modules/link/AbletonLinkConfig.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES main.cpp)

add_executable(AbletonLinkMIDIClock ${SOURCE_FILES})
target_link_libraries(AbletonLinkMIDIClock Ableton::Link)