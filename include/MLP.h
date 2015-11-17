#ifndef MLP_H
#define MLP_H

#define NUM_CLASSES 3
#define SAMPLE_SIZE 600

#include "NeuralConnection.h"

class MLP
{
    public:
        MLP();
        virtual ~MLP();
        double classify(double* sample);
        void link(NeuralConnection** _outputs);
        NeuralConnection** outputs;
    protected:
    private:
        void reset();
};

#endif // MLP_H
