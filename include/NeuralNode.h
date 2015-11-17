#ifndef NEURALNODE_H
#define NEURALNODE_H

#include <NeuralConnection.h>


class NeuralNode : public NeuralConnection
{
    public:
        NeuralNode(double _threshold, int _size, double* _weights);
        virtual ~NeuralNode();
    protected:
        void makeValue(double* sample);
    private:
        double threshold;
        double* weights;
};

#endif // NEURALNODE_H
