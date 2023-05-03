cmake_minimum_required(VERSION 3.24)

set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_task1 main_task1.cpp)
add_executable(${BINARY}_task2 main_task2.cpp)

set_target_properties(${BINARY}_task1 PROPERTIES UNITY_BUILD ON)
set_target_properties(${BINARY}_task2 PROPERTIES UNITY_BUILD ON)

target_link_libraries(${BINARY}_task1 PUBLIC ${BINARY}_lib)
target_link_libraries(${BINARY}_task2 PUBLIC ${BINARY}_lib)