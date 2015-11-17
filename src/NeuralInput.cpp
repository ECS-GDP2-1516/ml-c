#include "NeuralInput.h"

NeuralInput::NeuralInput(int _attr)
{
    this->attr = _attr;
}

NeuralInput::~NeuralInput()
{
    //dtor
}

double NeuralInput::value(double* sample)
{
    return (sample[this->attr] - attributeBases[this->attr]) / attributeRanges[this->attr];
}
