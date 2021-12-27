cmake_minimum_required (VERSION 3.8)
add_definitions(-DSOCKETDLL_EXPORTS)
add_compile_options(-std=c++11)

add_library (SocketDll SHARED "Socket.cpp" "Socket.h")
