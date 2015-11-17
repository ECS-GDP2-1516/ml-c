#include "NeuralOutput.h"

NeuralOutput::NeuralOutput(int _size)
{
    this->numInputs = _size;
}

NeuralOutput::~NeuralOutput()
{
    //dtor
}

void NeuralOutput::makeValue(double* sample)
{
    this->val = 0;

    for (int i = 0; i < this->numInputs; i++)
    {
        this->val += this->inputs[i]->value(sample);
    }
}
