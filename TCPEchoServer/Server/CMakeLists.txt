cmake_minimum_required (VERSION 3.8)

add_executable(Server "Server.cpp")
target_include_directories(Server PRIVATE ${GLOBAL_DIR}/SocketDll)
target_link_libraries(Server PRIVATE ws2_32 SocketDll)
