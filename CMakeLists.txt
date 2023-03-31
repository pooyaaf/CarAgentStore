cmake_minimum_required(VERSION 3.10) 
project(CarAgencyProgram) 
 
set(CMAKE_CXX_STANDARD 17) 
 
# Add jsoncpp library 
find_package(jsoncpp REQUIRED) 
include_directories(${JSONCPP_INCLUDE_DIR}) 

# Add server source files 
set(SERVER_SOURCES 
    main_server.cpp 
    Car.cpp 
    User.cpp 
    CarAgency.cpp 
) 
# Add client source files 
set(CLIENT_SOURCES 
    main_client.cpp 
    Car.cpp 
    User.cpp 
    CarAgency.cpp 
) 
 
# Add all header files 
set(HEADERS 
    Car.hpp 
    User.hpp 
    CarAgency.hpp 
) 
 
# Add all JSON files 
set(JSON_FILES 
    car.json 
    user.json 
) 
 
# Create server executable 
add_executable(server ${SERVER_SOURCES} ${HEADERS} ${JSON_FILES}) 
# Create client executable
add_executable(client ${CLIENT_SOURCES} ${HEADERS} ${JSON_FILES}) 
 
# Link jsoncpp library to executables 
target_link_libraries(server jsoncpp)
target_link_libraries(client jsoncpp)

# Set the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)