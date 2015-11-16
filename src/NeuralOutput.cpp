#include "NeuralOutput.h"

NeuralOutput::NeuralOutput()
{
    //ctor
}

NeuralOutput::~NeuralOutput()
{
    //dtor
}

void NeuralOutput::makeValue()
{
    for (int i = 0; i < this->numInputs; i++)
    {
        this->val += this->inputs[i].value();
    }
}
