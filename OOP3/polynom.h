#ifndef POLYNOM_H
#define POLYNOM_H

#include "array.h"

class Polynom
{
private:
    number An;
    Array roots;
    Array coefs;


public:
    Polynom() {
        string input;
        cout << "Write the 'An' coefficient: ";
        cin >> An;
        cout << "\nWrite the roots of the polynom: ";
        cin >> input;
        roots.fill(input);
        cout << "\nPolynom is completed" << endl;
    }
    /*
    void show() {
        cout << "Current polynom: ";
        cout << An;
        for (int i = 0; i < roots.getSize(); i++) {
            cout << "(x-" << roots[i] << ")";
        }
    }
        Polynom(int n) {
        Array roots(n);
        Array coefs(n);
        int An;
        roots[0] = -4;
        roots[1] = 3;
        roots[2] = 1;
        Pn = An(x-roots[0])(x-roots[1])(x-roots[2]);
        Xn = An*

    }
    */

};

#endif // POLYNOM_H
