cmake_minimum_required(VERSION 3.10) 
project(CarAgencyProgram) 

set(CMAKE_CXX_STANDARD 17) 

# Add jsoncpp library 
find_package(jsoncpp REQUIRED) 
include_directories(${JSONCPP_INCLUDE_DIR}) 

# Add server source files 
set(UDP_SERVER_SOURCES 
    src/server/udp_server.cpp 
    src/Car.cpp 
    src/User.cpp 
    src/CarAgency.cpp 
) 

set(TCP_SERVER_SOURCES 
    src/server/tcp_server.cpp
    src/Car.cpp 
    src/User.cpp 
    src/CarAgency.cpp 
) 

# Add client source files 
set(UDP_CLIENT_SOURCES 
    src/client/udp_client.cpp 
    src/Car.cpp 
    src/User.cpp 
    src/CarAgency.cpp 
) 

set(TCP_CLIENT_SOURCES 
    src/client/tcp_client.cpp
    src/Car.cpp 
    src/User.cpp 
    src/CarAgency.cpp 
) 

# Add all header files 
set(HEADERS 
    include/Car.hpp 
    include/User.hpp 
    include/CarAgency.hpp 
) 

# Add all JSON files 
set(JSON_FILES 
    car.json 
    user.json 
) 

# Create server executables 
add_executable(udp_server ${UDP_SERVER_SOURCES} ${HEADERS} ${JSON_FILES}) 
add_executable(tcp_server ${TCP_SERVER_SOURCES} ${HEADERS} ${JSON_FILES}) 

# Create client executables
add_executable(udp_client ${UDP_CLIENT_SOURCES} ${HEADERS} ${JSON_FILES}) 
add_executable(tcp_client ${TCP_CLIENT_SOURCES} ${HEADERS} ${JSON_FILES}) 

# Link jsoncpp library to executables 
target_link_libraries(udp_server jsoncpp)
target_link_libraries(tcp_server jsoncpp)
target_link_libraries(udp_client jsoncpp)
target_link_libraries(tcp_client jsoncpp)

# Set the output directory for the executables
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
