cmake_minimum_required (VERSION 3.8)

add_executable(Client "Client.cpp")
target_include_directories(Client PRIVATE ${GLOBAL_DIR}/SocketDll)
target_link_libraries(Client PRIVATE ws2_32 SocketDll)
