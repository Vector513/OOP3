#include "array.h"
#include <sstream>
#include <algorithm>

// Конструкторы и деструктор
Array::Array() : size(0), capacity(2) {
	array = new number[capacity];
}

Array::Array(int initCapacity) : size(0), capacity(initCapacity) {
	array = new number[capacity];
}

Array::~Array() {
	delete[] array;
}

// Очищает массив и сбрасывает его размер
void Array::clear() {
	size = 0;
	resize(2); // Сбрасываем емкость до начальной
}

// Изменяет емкость массива
void Array::resize(int newCapacity) {
	if (newCapacity <= 0) return; // Запретить отрицательные емкости

	// Ограничение размера до новой емкости
	number* temp = new number[newCapacity];
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	capacity = newCapacity;
}

// Добавляет элемент в массив
void Array::add(number value) {
	if (size >= capacity) {
		resize(capacity * 2);
	}
	array[size++] = value; // Увеличиваем size после добавления
}

// Удаляет последний элемент массива
void Array::remove() {
	if (size > 0) {
		--size;
		if (size <= capacity / 4 && capacity > 2) {
			resize(capacity / 2);
		}
	}
}

// Заполняет массив значениями из строки
void Array::fill(const std::string& input) {
	std::stringstream ss(input);
	number value;
	while (ss >> value) {
		add(value);
	}

	if (ss.fail() && !ss.eof()) { // Проверка на ошибки во вводе
		std::cerr << "Warning: some parts of the input were not numbers." << std::endl;
	}
}

// Печатает массив
void Array::show(std::ostream& output) {
	output << "Массив: ";
	for (int i = 0; i < size; i++) {
		output << array[i] << ' ';
	}
	output << '\n';
}

// Оператор доступа по индексу
number& Array::operator[](int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

// Вычисляет среднее значение массива
number Array::average() {
	if (size == 0) return 0; // Защита от деления на 0
	number sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum / size;
}

// Вычисляет среднеквадратическое отклонение
number Array::MSD() {
	if (size < 2) return 0; // Защита от деления на 0
	number avg = average();
	number sum = 0;
	for (int i = 0; i < size; i++) {
		sum += pow((array[i] - avg), 2);
	}
	return sqrt(sum / (size - 1));
}

// Разворачивает массив
void Array::reverse() {
	for (int i = 0; i < size / 2; i++) {
		std::swap(array[i], array[size - i - 1]);
	}
}

// Сортирует массив с использованием std::sort
void Array::sort(bool isReversed) {
	std::sort(array, array + size); // Сортировка по возрастанию
	if (isReversed) {
		reverse(); // Разворачиваем, если требуется
	}
}
