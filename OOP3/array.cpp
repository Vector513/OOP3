#include "array.h"
#include <sstream>
#include <algorithm>

// Конструкторы и деструктор
Array::Array() : size(0), capacity(0) {
	array = new number[capacity];
}

Array::Array(size_t initSize) : size(initSize), capacity(initSize) {
	array = new number[initSize];
}

Array::Array(const Array& other) : array(nullptr), capacity(0), size(0) {
	if (other.size > 0) {
		resize(other.capacity);
		for (size_t i = 0; i < other.size; ++i) {
			array[i] = other.array[i];
		}
		size = other.size;
	}
}

Array& Array::operator=(const Array& other) {
	if (this != &other) {
		delete[] array;

		if (other.size > 0) {
			resize(other.capacity);
			for (size_t i = 0; i < other.size; ++i) {
				array[i] = other.array[i];
			}
			size = other.size;
		}
		else {
			array = nullptr;
			capacity = 0;
			size = 0;
		}
	}

	return *this;
}

Array::~Array() {
	delete[] array;
}

// Очищает массив и сбрасывает его размер
void Array::clear() {
	size = 0;
	resize(0); // Сбрасываем емкость до начальной
}

// Изменяет емкость массива
void Array::resize(size_t newCapacity) {
	// Ограничиваем размер до новой емкости (в newCapacity >= 1)
	number* temp = new number[newCapacity];  // Новый массив

	// Копируем старые элементы в новый массив
	for (size_t i = 0; i < size && i < newCapacity; i++) {
		temp[i] = array[i];
	}

	// Если новая емкость больше текущего размера, инициализируем оставшиеся элементы нулями
	for (size_t i = size; i < newCapacity; i++) {
		temp[i] = 0; // Инициализация нулями
	}

	delete[] array; // Освобождаем старую память
	array = temp;
	capacity = newCapacity;

	// Если размер превышает новую емкость, корректируем размер
	if (size > newCapacity) {
		size = newCapacity;
	}
}

// Исправленная функция добавления элемента
void Array::add(number value) {
	if (size >= capacity) {
		resize(capacity == 0 ? 1 : capacity * 2);  // Расширение емкости массива
	}
	array[size++] = value;  // Увеличиваем size после добавления
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

/*
// Заполняет массив значениями из строки
void Array::fill(const std::string& input) {
	/*
	std::stringstream ss(input);
	number value;
	while (ss >> value) {
		add(value);
	}

	if (ss.fail() && !ss.eof()) { // Проверка на ошибки во вводе
		std::cerr << "Warning: some parts of the input were not numbers." << std::endl;
	}
	
	number value;
	while (input >> value) { // Читаем по одному комплексному числу
		add(value); // Добавляем его в вектор
	}
	//return input;
}
*/

void Array::fill(const std::string& input) {
	std::stringstream ss(input);
	number value;
	clear();  // Очищаем массив перед заполнением
	while (ss >> value) {
		add(value);
	}
	if (ss.fail() && !ss.eof()) {
		std::cerr << "Ошибка: некорректный ввод комплексного числа." << std::endl;
	}
}



// Печатает массив
void Array::show(std::ostream& output) {
	output << "Массив: ";
	for (size_t i = 0; i < size; i++) {
		output << array[i] << ' ';
	}
	output << '\n';
}

// Оператор доступа по индексу
number& Array::operator[](size_t index) {
	if (index >= capacity) {
		throw std::out_of_range("Index out of range");
	}
	if (index > size) {
		size = index;
	}
	return array[index];
}

const number& Array::operator[](size_t index) const {
	if (index >= capacity) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

size_t Array::getSize() const
{
	return size;
}

// Вычисляет среднее значение массива
number Array::average() {
	if (size == 0) return 0; // Защита от деления на 0
	number sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum / size;
}

// Вычисляет среднеквадратическое отклонение
number Array::MSD() {
	if (size < 2) return 0; // Защита от деления на 0
	number avg = average();
	number sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += pow((array[i] - avg), 2);
	}
	return sqrt(sum / (size - 1));
}

// Разворачивает массив
void Array::reverse() {
	for (size_t i = 0; i < size / 2; i++) {
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
