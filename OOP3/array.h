#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"
#include <iostream>
//#include <stdexcept>

class Array {
private:
	int size = 0;
	int capacity = 2; // Начальная емкость
	number* array = nullptr;

public:
	Array();
	Array(int initCapacity);
	~Array();
	void clear();
	void resize(int newCapacity);
	void add(number value);
	void remove();
	void fill(const std::string& input);
	void show(std::ostream& output);
	number& operator[](int index);
	number average();
	number MSD();
	void reverse();
	void sort(bool isReversed = false);
};

#endif // ARRAY_H
