#include <iostream>

#include "python.hpp"

PythonInterface::PythonInterface()
{
    mModel = nullptr;
}
PythonInterface::~PythonInterface()
{
    // Destructor implementation
}

int main(int argc, char *argv[])
{
    PythonInterface py;
    std::cout << "Python interface initialized." << std::endl;
    return 0;
}
