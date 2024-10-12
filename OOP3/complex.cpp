#include "complex.h"
#include <cmath>

// Конструкторы
Complex::Complex(double re) : re(re) {}

Complex::Complex(double re, double im) : re(re), im(im) {}

// Модуль комплексного числа
double Complex::mod() const
{
	return std::hypot(re, im); // Используем std::hypot для более точных вычислений
}

// Аргумент комплексного числа
double Complex::arg() const
{
	return std::atan2(im, re); // atan2 автоматически учитывает знак и деление на ноль
}

// Возведение в степень
Complex Complex::pow(double exponent) const
{
	double r = std::pow(mod(), exponent);
	double theta = arg() * exponent;
	return Complex{ r * std::cos(theta), r * std::sin(theta) };
}

Complex pow(const Complex& base, double exponent)
{
	return base.pow(exponent);
}

Complex sqrt(const Complex& base)
{
	return base.pow(0.5);
}

// Операторы ввода/вывода
std::ostream& operator<<(std::ostream& output, const Complex& complex)
{
	output << complex.re << " + " << complex.im << "i";
	return output;
}

std::istream& operator>>(std::istream& input, Complex& complex)
{
	input >> complex.re >> complex.im;
	return input;
}

// Оператор присваивания
Complex& Complex::operator=(const Complex& other)
{
	if (this != &other) {
		re = other.re;
		im = other.im;
	}
	return *this;
}

// Арифметические операторы
Complex Complex::operator+(const Complex& other) const
{
	return Complex{ re + other.re, im + other.im };
}

Complex Complex::operator-(const Complex& other) const
{
	return Complex{ re - other.re, im - other.im };
}

Complex Complex::operator*(const double coef) const
{
	return Complex{ re * coef, im * coef };
}

Complex Complex::operator*(const Complex& other) const
{
	return Complex{ re * other.re - im * other.im, re * other.im + im * other.re };
}

Complex Complex::operator/(const double coef) const
{
	return Complex{ re / coef, im / coef };
}

Complex Complex::operator/(const Complex& other) const
{
	double denominator = other.re * other.re + other.im * other.im;
	return Complex{ (re * other.re + im * other.im) / denominator,
					(im * other.re - re * other.im) / denominator };
}

// Оператор унарного минуса
Complex Complex::operator-() const
{
	return Complex{ -re, -im };
}

// Операторы присваивания с арифметикой
Complex& Complex::operator+=(const Complex& other)
{
	re += other.re;
	im += other.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	re -= other.re;
	im -= other.im;
	return *this;
}

Complex& Complex::operator*=(const double coef)
{
	re *= coef;
	im *= coef;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double newRe = re * other.re - im * other.im;
	im = re * other.im + im * other.re;
	re = newRe;
	return *this;
}

Complex& Complex::operator/=(const double coef)
{
	re /= coef;
	im /= coef;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	double denominator = other.re * other.re + other.im * other.im;
	double newRe = (re * other.re + im * other.im) / denominator;
	im = (im * other.re - re * other.im) / denominator;
	re = newRe;
	return *this;
}

// Логические операторы
bool Complex::operator==(const Complex& other) const
{
	return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex& other) const
{
	return !(*this == other);
}

// Операторы сравнения по модулю
bool Complex::operator>(const Complex& other) const
{
	return mod() > other.mod();
}

bool Complex::operator>=(const Complex& other) const
{
	return mod() > other.mod() || (mod() == other.mod() && arg() >= other.arg());
}

bool Complex::operator<(const Complex& other) const
{
	return mod() < other.mod();
}

bool Complex::operator<=(const Complex& other) const
{
	return mod() < other.mod() || (mod() == other.mod() && arg() <= other.arg());
}
