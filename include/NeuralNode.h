#ifndef NEURALNODE_H
#define NEURALNODE_H

#include <NeuralConnection.h>


class NeuralNode : protected NeuralConnection
{
    public:
        NeuralNode();
        virtual ~NeuralNode();
    protected:
        void makeValue();
    private:
        float threshold;
        float* weights;
};

#endif // NEURALNODE_H
