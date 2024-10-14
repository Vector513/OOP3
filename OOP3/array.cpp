#include "array.h"
#include <sstream>
#include <algorithm>

Array::Array() : size(0), capacity(0), array(nullptr) {}

Array::Array(size_t initialSize) : size(0), capacity(0), array(nullptr) {
    resize(initialSize);
}

Array::Array(const std::initializer_list<number>& initList) : size(0), capacity(0), array(nullptr) {
    resize(initList.size());
    size_t i = 0;
    for (number value : initList) {
        array[i++] = value;
    }
    size = initList.size();
}

Array::Array(const Array& other) : size(other.size), capacity(other.capacity), array(nullptr) {
    if (capacity > 0) {
        array = new number[capacity];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;  // Защита от самоприсваивания

    delete[] array;  // Освобождаем текущую память

    size = other.size;
    capacity = other.capacity;

    if (capacity > 0) {
        array = new number[capacity];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    else {
        array = nullptr;
    }

    return *this;
}

Array::~Array() {
    delete[] array;  // Освобождаем память при разрушении объекта
}

size_t Array::getSize() const {
    return size;
}

void Array::resize(size_t newSize) {
    if (newSize > capacity) {
        reallocate(newSize);  // Увеличиваем емкость, если новый размер больше текущей емкости
    }
    size = newSize;
}

void Array::add(number value) {
    if (size >= capacity) {
        reallocate(capacity == 0 ? 1 : capacity * 2);  // Удваиваем емкость при необходимости
    }
    array[size++] = value;  // Добавляем элемент в массив
}

void Array::fill(const std::string& input) {
    std::istringstream stream(input);  // Поток для считывания данных из строки
    number value;

    clear();  // Очищаем массив перед заполнением

    // Пока можем считать число из строки, добавляем его в массив
    while (stream >> value) {
        add(value);

        // Пропускаем разделители (например, пробелы, запятые и т.п.)
        if (stream.peek() == ',' || stream.peek() == ' ' || stream.peek() == ';') {
            stream.ignore();
        }
    }

    // Обработка возможных ошибок
    if (stream.fail() && !stream.eof()) {
        throw std::invalid_argument("Invalid input string for filling Array");
    }
}


void Array::clear() {
    size = 0;  // Просто устанавливаем размер в 0, емкость не изменяется
}

number& Array::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

const number& Array::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

void Array::reallocate(size_t newCapacity) {
    number* newArray = new number[newCapacity];  // Выделяем новую память
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = array[i];  // Копируем существующие элементы
    }
    delete[] array;  // Освобождаем старую память
    array = newArray;  // Переключаем указатель на новый массив
    capacity = newCapacity;  // Обновляем емкость
}