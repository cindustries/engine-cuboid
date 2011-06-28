cmake_minimum_required(VERSION 2.8)
project(cuboidengine)

include_directories(/usr/local/include/agar)
include_directories(/usr/local/include/bullet)
include_directories(/usr/include/SDL)
include_directories(${cuboidengine_SOURCE_DIR})

#add_subdirectory(shared)
add_subdirectory(server)
add_subdirectory(client)

add_executable(cuboidenginetest
main.cpp
)

target_link_libraries(cuboidenginetest cuboid_server_lib cuboid_client_lib)