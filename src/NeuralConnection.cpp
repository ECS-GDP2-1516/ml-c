#include "NeuralConnection.h"


NeuralConnection::NeuralConnection()
{

}

NeuralConnection::~NeuralConnection()
{
    //dtor
}

double NeuralConnection::value()
{
    if (this->val == NAN)

    this->makeValue();

    return this->val;
}

void NeuralConnection::reset()
{
    if (this->val != NAN)
    {
        this->val = NAN;

        for (int i = 0; i < this->numInputs; i++)
        {
            this->inputs[i].reset();
        }
    }
}
