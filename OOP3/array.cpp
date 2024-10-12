#include "array.h"
#include <sstream>
#include <algorithm>

// ������������ � ����������
Array::Array() : size(0), capacity(2) {
	array = new number[capacity];
}

Array::Array(int initCapacity) : size(0), capacity(initCapacity) {
	array = new number[capacity];
}

Array::~Array() {
	delete[] array;
}

// ������� ������ � ���������� ��� ������
void Array::clear() {
	size = 0;
	resize(2); // ���������� ������� �� ���������
}

// �������� ������� �������
void Array::resize(int newCapacity) {
	if (newCapacity <= 0) return; // ��������� ������������� �������

	// ����������� ������� �� ����� �������
	number* temp = new number[newCapacity];
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	capacity = newCapacity;
}

// ��������� ������� � ������
void Array::add(number value) {
	if (size >= capacity) {
		resize(capacity * 2);
	}
	array[size++] = value; // ����������� size ����� ����������
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

// ��������� ������ ���������� �� ������
void Array::fill(const std::string& input) {
	std::stringstream ss(input);
	number value;
	while (ss >> value) {
		add(value);
	}

	if (ss.fail() && !ss.eof()) { // �������� �� ������ �� �����
		std::cerr << "Warning: some parts of the input were not numbers." << std::endl;
	}
}

// �������� ������
void Array::show(std::ostream& output) {
	output << "������: ";
	for (int i = 0; i < size; i++) {
		output << array[i] << ' ';
	}
	output << '\n';
}

// �������� ������� �� �������
number& Array::operator[](int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

// ��������� ������� �������� �������
number Array::average() {
	if (size == 0) return 0; // ������ �� ������� �� 0
	number sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum / size;
}

// ��������� �������������������� ����������
number Array::MSD() {
	if (size < 2) return 0; // ������ �� ������� �� 0
	number avg = average();
	number sum = 0;
	for (int i = 0; i < size; i++) {
		sum += pow((array[i] - avg), 2);
	}
	return sqrt(sum / (size - 1));
}

// ������������� ������
void Array::reverse() {
	for (int i = 0; i < size / 2; i++) {
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
