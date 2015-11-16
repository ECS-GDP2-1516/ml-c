#include "MLP.h"
#include <cstdlib>

MLP::MLP()
{
    //ctor
}

MLP::~MLP()
{
    //dtor
}

double* MLP::distribution()
{
    this->reset();

    double* r = (double*)malloc(sizeof(double) * NUM_CLASSES);

    for (int i = 0; i < NUM_CLASSES; i++)
    {
        r[i] = this->outputs[i].value();
    }

    return r;
}

void MLP::reset()
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        this->outputs[i].reset();
    }
}
