cmake_minimum_required (VERSION 3.8)

project ("TCPEchoServer")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(GLOBAL_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory ("SocketDll")
add_subdirectory ("Client")
add_subdirectory ("Server")
