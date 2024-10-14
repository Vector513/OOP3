#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"
#include <iostream>

class Array {
private:
	size_t size;
	size_t capacity;
	number* array;

public:
	Array();
	Array(size_t initCapacity);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();
	void clear();
	void resize(size_t newCapacity);
	void add(const number value);
	void remove();
	void fill(const std::string& input);
	void show(std::ostream& output);
	number& operator[](size_t index);
	const number& operator[](size_t index) const;
	size_t getSize() const;
	number average();
	number MSD();
	void reverse();
	void sort(bool isReversed = false);
};

#endif // ARRAY_H
