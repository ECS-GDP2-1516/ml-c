#ifndef MLP_H
#define MLP_H

#define NUM_CLASSES 3

#include "NeuralConnection.h"

class MLP
{
    public:
        MLP();
        virtual ~MLP();
        double* distribution();
    protected:
    private:
        NeuralConnection* outputs;
        void reset();
};

#endif // MLP_H
