#ifndef APPLICATION_H
#define APPLICATION_H

#include "polynom.h"

class Application
{
public:
    Application();
    ~Application();
    void exec(Polynom& polynom);
};

#endif //APPLICATION_H