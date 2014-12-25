cmake_minimum_required (VERSION 2.6)
project (Reludp)

include_directories(include)

add_library(packet src/ru_packet)
add_library(socket src/ru_socket)
add_library(reludp src/reludp)
target_link_libraries(reludp packet socket)

add_executable(client src/client.c)
add_executable(server src/server.c)

target_link_libraries(client packet socket reludp)
target_link_libraries(server packet socket reludp)
