#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"
#include <stdexcept>  // Для обработки исключений
#include <iostream>   // Для отладки
#include <initializer_list>  // Для работы с инициализаторами

class Array {
public:
    // Конструкторы и деструктор
    Array();
    Array(size_t initialSize);
    Array(const std::initializer_list<number>& initList);
    Array(const Array& other);  // Конструктор копирования
    Array& operator=(const Array& other);  // Оператор присваивания
    ~Array();

    // Методы
    size_t getSize() const;  // Возвращает текущий размер массива
    void resize(size_t newSize);  // Изменяет размер массива
    void add(number value); 
    void fill(const std::string& input);// Добавляет элемент в конец массива
    void clear();  // Очищает массив

    // Операторы доступа
    number& operator[](size_t index);
    const number& operator[](size_t index) const;

private:
    size_t size;     // Текущий размер массива (количество элементов)
    size_t capacity; // Текущая емкость (максимум элементов, которые могут быть сохранены без перевыделения памяти)
    number* array;   // Указатель на массив значений

    void reallocate(size_t newCapacity);  // Вспомогательная функция для перевыделения памяти
};

#endif // ARRAY_H
