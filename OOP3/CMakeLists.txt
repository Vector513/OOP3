# CMakeList.txt: проект CMake для OOP3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OOP3 "main.cpp"  "number.h" "complex.h" "complex.cpp" "array.h" "array.cpp" "polynom.h" "polynom.cpp" "application.h" "application.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OOP3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
