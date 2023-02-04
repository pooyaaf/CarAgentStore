cmake_minimum_required(VERSION 3.10) 
project(CarAgencyProgram) 
 
set(CMAKE_CXX_STANDARD 17) 
 
# Add jsoncpp library 
find_package(jsoncpp REQUIRED) 
include_directories(${JSONCPP_INCLUDE_DIR}) 
 
# Add all source files 
set(SOURCES 
    main.cpp 
############Car.cpp 
############User.cpp 
############CarAgency.cpp 
) 
 
# Add all header files 
#set(HEADERS 
#    Car.hpp 
#    User.hpp 
#    CarAgency.hpp 
#) 
 
# Add all JSON files 
set(JSON_FILES 
    car.json 
    user.json 
) 
 
# Create executable from source files ${HEADERS} 
add_executable(CarAgencyProgram ${SOURCES} ${JSON_FILES}) 
 
# Link jsoncpp library to executable 
target_link_libraries(CarAgencyProgram jsoncpp)

