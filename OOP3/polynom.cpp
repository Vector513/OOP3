#include "polynom.h"
#include <sstream>
#include <iomanip>
#include <vector>

Polynom::Polynom() : degree(0), An(), roots(), coefs() {}

Polynom::~Polynom() {}

void Polynom::clear() {}

void Polynom::fillRoots(const std::string& input) {
    roots.fill(input);
    degree = roots.getSize();
    calculateCoefs();
}

Array Polynom::multiplyPolynomials(const Array& poly1, const Array& poly2) {
    Array result;
    size_t newSize = poly1.getSize() + poly2.getSize() - 1;

    result.resize(newSize);

    for (size_t i = 0; i < poly1.getSize(); ++i) {
        for (size_t j = 0; j < poly2.getSize(); ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

void Polynom::calculateCoefs() {
    Array currentPoly;
    currentPoly.add(An);

    for (size_t i = 0; i < roots.getSize(); ++i) {
        Array factor;
        factor.add(-roots[i]);
        factor.add(1.0);

        currentPoly = multiplyPolynomials(currentPoly, factor);
    }

    coefs = currentPoly;
}

std::string Polynom::formatComplex(const number& num) const {
    double re = num.getRe();
    double im = num.getIm();

    std::ostringstream result;
    result << std::fixed << std::setprecision(2);

    if (re != 0) {
        result << re;
    }

    if (im > 0) {
        result << (re != 0 ? " + " : "") << im << "i"; // Добавляем мнимую часть с " + "
    }
    else if (im < 0) {
        result << (re != 0 ? " - " : "") << -im << "i"; // Добавляем мнимую часть с " - "
    }

    return result.str();
}


void Polynom::show(std::ostream& output, bool isFirstForm) const {
    if (isFirstForm) {
        output << "p(x) = ";
        bool firstTerm = true;
        for (size_t i = coefs.getSize() - 1; i != static_cast<size_t>(-1); --i) {
            if (coefs[i].getRe() != 0 || coefs[i].getIm() != 0) { // Пропускаем нулевые коэффициенты
                if (!firstTerm) {
                    output << (coefs[i].getRe() > 0 ? " + " : " - ");
                }
                firstTerm = false;

                // Выводим абсолютное значение коэффициента, чтобы знак был отдельным
                if ((coefs[i].mod() != 1 || i == 0)) {
                    output << formatComplex(coefs[i]);
                }

                // Добавляем переменную и степень
                if (i > 0) {
                    output << "x";
                    if (i > 1) {
                        output << "^" << i;
                    }
                }
            }
        }

        if (firstTerm) {
            output << "0";  // Если все коэффициенты нулевые
        }
        output << '\n';
    }
    else {
        output << "p(x) = ";

        // Выводим старший коэффициент An
        if (An.getRe() != 0 || An.getIm() != 0) {
            output << "(" << formatComplex(An) << ")";
        }

        // Обрабатываем каждый корень
        for (size_t i = 0; i < roots.getSize(); ++i) {
            output << "(x ";

            double reRoot = roots[i].getRe();  // Действительная часть корня
            double imRoot = roots[i].getIm();  // Мнимая часть корня

            // Обработка действительной части
            if (reRoot != 0) {
                output << (reRoot > 0 ? "- " : "+ ") << std::abs(reRoot);  // Прямой вывод действительной части
            }
            else {
                output << "- 0";  // Если действительная часть равна 0
            }

            // Обработка мнимой части с правильным знаком
            if (imRoot != 0) {
                if (imRoot > 0) {
                    output << " + " << imRoot << "i";  // Положительная мнимая часть добавляется с "+"
                }
                else {
                    output << " + " << -imRoot << "i";  // Отрицательная мнимая часть все равно выводится с "+"
                }
            }

            output << ")";
        }

        // Если все коэффициенты равны 0
        if (roots.getSize() == 0 && (An.getRe() == 0 && An.getIm() == 0)) {
            output << "0";
        }

        output << '\n';

    }
}
