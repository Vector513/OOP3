#include "array.h"
#include <sstream>
#include <algorithm>

// ������������ � ����������
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

// ������� ������ � ���������� ��� ������
void Array::clear() {
	size = 0;
	resize(0); // ���������� ������� �� ���������
}

// �������� ������� �������
void Array::resize(size_t newCapacity) {
	// ������������ ������ �� ����� ������� (� newCapacity >= 1)
	number* temp = new number[newCapacity];  // ����� ������

	// �������� ������ �������� � ����� ������
	for (size_t i = 0; i < size && i < newCapacity; i++) {
		temp[i] = array[i];
	}

	// ���� ����� ������� ������ �������� �������, �������������� ���������� �������� ������
	for (size_t i = size; i < newCapacity; i++) {
		temp[i] = 0; // ������������� ������
	}

	delete[] array; // ����������� ������ ������
	array = temp;
	capacity = newCapacity;

	// ���� ������ ��������� ����� �������, ������������ ������
	if (size > newCapacity) {
		size = newCapacity;
	}
}

// ������������ ������� ���������� ��������
void Array::add(number value) {
	if (size >= capacity) {
		resize(capacity == 0 ? 1 : capacity * 2);  // ���������� ������� �������
	}
	array[size++] = value;  // ����������� size ����� ����������
}


// ������� ��������� ������� �������
void Array::remove() {
	if (size > 0) {
		--size;
		if (size <= capacity / 4 && capacity > 2) {
			resize(capacity / 2);
		}
	}
}

/*
// ��������� ������ ���������� �� ������
void Array::fill(const std::string& input) {
	/*
	std::stringstream ss(input);
	number value;
	while (ss >> value) {
		add(value);
	}

	if (ss.fail() && !ss.eof()) { // �������� �� ������ �� �����
		std::cerr << "Warning: some parts of the input were not numbers." << std::endl;
	}
	
	number value;
	while (input >> value) { // ������ �� ������ ������������ �����
		add(value); // ��������� ��� � ������
	}
	//return input;
}
*/

void Array::fill(const std::string& input) {
	std::stringstream ss(input);
	number value;
	clear();  // ������� ������ ����� �����������
	while (ss >> value) {
		add(value);
	}
	if (ss.fail() && !ss.eof()) {
		std::cerr << "������: ������������ ���� ������������ �����." << std::endl;
	}
}



// �������� ������
void Array::show(std::ostream& output) {
	output << "������: ";
	for (size_t i = 0; i < size; i++) {
		output << array[i] << ' ';
	}
	output << '\n';
}

// �������� ������� �� �������
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

// ��������� ������� �������� �������
number Array::average() {
	if (size == 0) return 0; // ������ �� ������� �� 0
	number sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum / size;
}

// ��������� �������������������� ����������
number Array::MSD() {
	if (size < 2) return 0; // ������ �� ������� �� 0
	number avg = average();
	number sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += pow((array[i] - avg), 2);
	}
	return sqrt(sum / (size - 1));
}

// ������������� ������
void Array::reverse() {
	for (size_t i = 0; i < size / 2; i++) {
		std::swap(array[i], array[size - i - 1]);
	}
}

// ��������� ������ � �������������� std::sort
void Array::sort(bool isReversed) {
	std::sort(array, array + size); // ���������� �� �����������
	if (isReversed) {
		reverse(); // �������������, ���� ���������
	}
}
