#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
private:
    double re = 0;
    double im = 0;

public:
    // Конструкторы
    Complex() = default;
    Complex(double re);
    Complex(double re, double im);

    // Деструктор
    ~Complex() = default;

    // Методы
    double mod() const;
    double arg() const;
    Complex pow(double exponent) const;

    // Дружественные функции
    friend Complex pow(const Complex& base, double exponent);
    friend Complex sqrt(const Complex& base);

    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& output, const Complex& complex);
    friend std::istream& operator>>(std::istream& input, Complex& complex);

    // Операторы присваивания
    Complex& operator=(const Complex& other);

    // Арифметические операторы
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const double coef) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const double coef) const;
    Complex operator/(const Complex& other) const;
    Complex operator-() const;

    // Операторы присваивания с арифметикой
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const double coef);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const double coef);
    Complex& operator/=(const Complex& other);

    // Логические операторы
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Операторы сравнения по модулю
    bool operator>(const Complex& other) const;
    bool operator>=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator<=(const Complex& other) const;
};

#endif // COMPLEX_H
