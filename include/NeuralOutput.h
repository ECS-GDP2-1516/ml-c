#ifndef NEURALOUTPUT_H
#define NEURALOUTPUT_H

#include <NeuralConnection.h>


class NeuralOutput : public NeuralConnection
{
    public:
        NeuralOutput(int _size);
        virtual ~NeuralOutput();
    protected:
        void makeValue(double* sample);
    private:
};

#endif // NEURALOUTPUT_H
