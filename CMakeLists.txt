cmake_minimum_required(VERSION 3.10)

project(Lab3)

add_library(${PROJECT_NAME}_lib
  src/Figure.cpp
  src/Octagon.cpp
  src/Square.cpp
  src/Triangle.cpp
  src/Array.cpp
)

add_executable(${PROJECT_NAME}_exe main.cpp)

target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)

# Добавление тестов
enable_testing()

add_executable(${PROJECT_NAME}_tests test/test.cpp)
target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME ProjectTests COMMAND ${PROJECT_NAME}_tests)