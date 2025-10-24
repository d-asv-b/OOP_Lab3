cmake_minimum_required(VERSION 3.10)

project(Lab3)

add_library(${PROJECT_NAME}_lib
  src/Figure.cpp
  src/Octagon.cpp
  src/Square.cpp
  src/Triangle.cpp
)

add_executable(${PROJECT_NAME}_exe main.cpp)

target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)

# Добавление тестов
enable_testing()

# Тестирование собственного класса Array
add_executable(Array_tests test/array_test.cpp)
target_link_libraries(Array_tests ${PROJECT_NAME}_lib gtest_main)

# Тестирование фигур
add_executable(Figures_tests test/figure_test.cpp)
target_link_libraries(Figures_tests ${PROJECT_NAME}_lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME Array_tests COMMAND Array_tests)
add_test(NAME Figures_tests COMMAND Figures_tests)