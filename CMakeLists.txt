cmake_minimum_required(VERSION 3.16)

# Define our project
project("gpio-cpp")
set(CMAKE_CXX_STANDARD 17)

# Create all the dependecy targets
add_subdirectory("deps")

add_library( ${PROJECT_NAME} 
                src/gpio.cpp )

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC sigslot)

# Link pthreads under GCC
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
endif()