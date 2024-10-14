#ifndef POLYNOM_H
#define POLYNOM_H

#include "array.h"

class Polynom
{
public:
    size_t degree;
    number An;
    Array roots;
    Array coefs;

    Polynom();
    ~Polynom();

    void clear();

    void fillRoots(const std::string& input);
    //void multiplyByRoots(const Array& roots);
    Array multiplyPolynomials(const Array& poly1, const Array& poly2);
    void calculateCoefs();

    std::string formatComplex(const number& complex) const;
    void show(std::ostream& output, bool isFirstForm = true) const;
};

#endif // POLYNOM_H
