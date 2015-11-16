#ifndef NEURALINPUT_H
#define NEURALINPUT_H

#include <NeuralConnection.h>


class NeuralInput : public NeuralConnection
{
    public:
        NeuralInput();
        virtual ~NeuralInput();
        double value();
    protected:
    private:
};

#endif // NEURALINPUT_H
