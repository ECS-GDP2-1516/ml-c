#ifndef NEURALCONNECTION_H
#define NEURALCONNECTION_H
#include <cmath>

class NeuralConnection
{
    public:
        NeuralConnection();
        virtual ~NeuralConnection();
        virtual double value(double* sample);
        void reset();
        void link(NeuralConnection** _inputs);
    protected:
        virtual void makeValue(double* sample) { };
        double val = NAN;
        int numInputs = 0;
        NeuralConnection** inputs;
    private:

};

#endif // NEURALCONNECTION_H
