#ifndef NEURALCONNECTION_H
#define NEURALCONNECTION_H
#include <cmath>

class NeuralConnection
{
    public:
        NeuralConnection();
        virtual ~NeuralConnection();
        virtual double value();
        void reset();
    protected:
        void makeValue();
        double val = NAN;
        int numInputs;
        NeuralConnection* inputs;
    private:

};

#endif // NEURALCONNECTION_H
