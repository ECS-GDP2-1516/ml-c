#include "NeuralConnection.h"

NeuralConnection::NeuralConnection()
{

}

NeuralConnection::~NeuralConnection()
{
    //dtor
}

double NeuralConnection::value(double* sample)
{
    if (this->val != this->val) this->makeValue(sample);

    return this->val;
}

void NeuralConnection::reset()
{
    if (this->val == this->val)
    {
        this->val = NAN;

        for (int i = 0; i < this->numInputs; i++)
        {
            this->inputs[i]->reset();
        }
    }
}

void NeuralConnection::link(NeuralConnection** _inputs)
{
    this->inputs = _inputs;
}
