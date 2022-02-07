cmake_minimum_required (VERSION 3.8)

add_library(SocketDll SHARED "Socket.cpp" "Socket.h")
target_compile_definitions(SocketDll PRIVATE -DSOCKETDLL_EXPORTS)
target_link_libraries(SocketDll PRIVATE ws2_32)
