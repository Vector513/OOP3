#include "polynom.h"
#include <sstream>
#include <iomanip>

Polynom::Polynom() : degree(0), An(), roots(), coefs() {}

Polynom::~Polynom() {}

void Polynom::clear()
{
}

void Polynom::fillRoots(const std::string& input)
{
	roots.fill(input);
	degree = roots.getSize();
	calculateCoefs();
}

Array multiplyPolynomials(const Array& poly1, const Array& poly2) {
    size_t newSize = poly1.getSize() + poly2.getSize() - 1;
    if (newSize < 0) {
        throw std::invalid_argument("Invalid polynomial size");
    }

    Array result;
    result.resize(newSize);

    for (size_t i = 0; i < result.getSize(); ++i) {
        result[i] = 0.0;
    }

    for (size_t i = 0; i < poly1.getSize(); ++i) {
        for (size_t j = 0; j < poly2.getSize(); ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

void Polynom::calculateCoefs() {
    coefs.resize(degree + 1);
    coefs[degree] = An;

    Array currentPoly;
    currentPoly.resize(1);
    currentPoly[0] = An;

    for (size_t i = 0; i < roots.getSize(); ++i) {
        Array factor;
        factor.resize(2);
        factor[0] = -roots[i];
        factor[1] = 1.0;

        currentPoly = multiplyPolynomials(currentPoly, factor);
    }

    coefs.resize(currentPoly.getSize());
    for (size_t i = 0; i < currentPoly.getSize(); ++i) {
        coefs[i] = currentPoly[i];
    }
}
std::string Polynom::formatComplex(const number& num) const {
    double re = num.getRe();
    double im = num.getIm();

    std::ostringstream result; // Используем ostringstream для форматирования

    // Устанавливаем точность до 2 знаков после запятой
    result << std::fixed << std::setprecision(2);

    if (re != 0) {
        result << re; // Действительная часть
    }

    if (im > 0) {
        result << " + " << im; // Мнимая часть
    }
    else if (im < 0) {
        result << " - " << -im; // Мнимая часть
    }

    return result.str();
}

void Polynom::show(std::ostream& output, bool isFirstForm) const {
    if (isFirstForm) {
        output << "p(x) = ";
        bool firstTerm = true; // Для обработки первого члена полинома

        for (size_t i = coefs.getSize() - 1; i != static_cast<size_t>(-1); --i) {
            if (coefs[i].getRe() != 0 || coefs[i].getIm() != 0) { // Пропускаем нулевые коэффициенты
                if (!firstTerm) {
                    // Определяем знак перед членом
                    if (coefs[i].getRe() > 0) {
                        output << " + ";
                    }
                    else {
                        output << " - ";
                    }
                }
                firstTerm = false;

                // Выводим абсолютное значение коэффициента, чтобы знак был отдельным
                if ((coefs[i].mod()) != 1 || i == 0) {
                    output << formatComplex(coefs[i]);
                }

                if (i > 0) {
                    output << "x";
                    if (i > 1) {
                        output << "^" << i;
                    }
                }
            }
        }

        if (firstTerm) {
            // Если все коэффициенты были нулями, выводим "0"
            output << "0";
        }

        output << '\n';
    }
    else {
        output << "p(x) = (";

        // Добавляем An с учетом мнимой части
        output << formatComplex(An);

        // Если An имеет мнимую часть, добавляем её в скобки
        if (An.getIm() != 0) {
            output << "i";
        }

        output << ")";

        for (size_t i = 0; i < roots.getSize(); i++) {
            // Выводим корень, следя за знаками
            output << "(x ";
            double reRoot = roots[i].getRe();
            double imRoot = roots[i].getIm();

            // Обрабатываем действительную часть
            if (reRoot != 0) {
                output << "- " << reRoot; // Для действительной части всегда выводим "-"
            }
            else {
                // Если действительная часть равна 0, проверяем мнимую
                if (imRoot > 0) {
                    output << "- " << imRoot; // Печатаем мнимую часть с "i"
                }
                else if (imRoot < 0) {
                    output << "+ " << -imRoot; // Печатаем мнимую часть с "i"
                }
            }

            // Добавляем мнимую часть, если она не равна 0
            if (imRoot != 0) {
                output << " + " << std::abs(imRoot) << "i"; // Печатаем мнимую часть с "i"
            }

            output << ')';
        }
        output << '\n';
    }
}