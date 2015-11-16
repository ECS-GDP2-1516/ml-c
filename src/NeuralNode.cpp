#include "NeuralNode.h"

NeuralNode::NeuralNode()
{
    //ctor
}

NeuralNode::~NeuralNode()
{
    //dtor
}

void NeuralNode::makeValue()
{
    this->val = this->threshold;

    for (int i = 0; i < this->numInputs; i++)
    {
        this->val += this->inputs[i].value() * this->weights[i];
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
        //this.val = 1 / (1 + Math.exp(-this.val));
    }
}
