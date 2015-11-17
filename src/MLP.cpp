#include "MLP.h"
//#include <cstdlib>

MLP::MLP()
{
    //ctor
}

MLP::~MLP()
{
    //dtor
}

double MLP::classify(double* sample)
{
    this->reset();

    double winningClass = -1;
    double winningProb  = -1;

    for (int i = 0; i < NUM_CLASSES; i++)
    {
        double probability = this->outputs[i]->value(sample);

        if (probability > winningProb)
        {
            winningProb  = probability;
            winningClass = i;
        }
    }

    return winningClass;
}

void MLP::reset()
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        this->outputs[i]->reset();
    }
}

void MLP::link(NeuralConnection** _outputs)
{
    this->outputs = _outputs;
}
