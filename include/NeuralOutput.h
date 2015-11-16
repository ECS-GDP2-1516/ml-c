#ifndef NEURALOUTPUT_H
#define NEURALOUTPUT_H

#include <NeuralConnection.h>


class NeuralOutput : public NeuralConnection
{
    public:
        NeuralOutput();
        virtual ~NeuralOutput();
    protected:
        void makeValue();
    private:
};

#endif // NEURALOUTPUT_H
