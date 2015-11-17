#include "NeuralNode.h"
#include <math.h>

NeuralNode::NeuralNode(double _threshold, int _size, double* _weights)
{
    this->numInputs = _size;
    this->weights   = _weights;
    this->threshold = _threshold;
}

NeuralNode::~NeuralNode()
{
    //dtor
}

void NeuralNode::makeValue(double* sample)
{
    this->val = this->threshold;

    for (int i = 0; i < this->numInputs; i++)
    {
        this->val += this->inputs[i]->value(sample) * this->weights[i];
    }

    if (this->val < -45.)
    {
        this->val = 0;
    }
    else if (this->val > 45)
    {
        this->val = 1;
    }
    else
    {
        this->val = 1 / (1 + exp(-this->val));
    }
}
