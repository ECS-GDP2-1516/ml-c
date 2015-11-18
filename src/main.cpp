#include <stdio.h>


void sigmoid(int* var);
int* getData();
void load(char* path);

int main()
{
    load("../ml-java/data.txt");

    return 0;
}


int classify(int* v)
{
    int* offset=getData();
    int* s1;
    int* e1;
    int* s2=(int*)v;
    int* e2=s2 + 300;

    // Layer 2
    s1=v + 300;
    e1=s1 + 4;
    for (int* i = s1; i < e1; i++){
        *i=*offset++;
        for (int* j=s2; j < e2; j++) {
            *i+=(*offset++**j) >> 8;
        }
        sigmoid(i);
    }

    // Layer 1
    s2=v + 0;
    e2=s2 + 3;
    for (int* i = s2; i < e2; i++){
        *i=*offset++;
        for (int* j=s1; j < e1; j++) {
            *i+=(*offset++**j) >> 8;
        }
        sigmoid(i);
    }

    if (v[0] > v[1] && v[0] > v[2])
    {
        return 0;
    }
    else if (v[1] > v[0] && v[1] > v[2])
    {
        return 1 << 8;
    }
    else
    {
        return 2 << 8;
    }
}

void sigmoid(int* var)
{
    printf("%d\n", *var);

    if (*var < -5 << 8)
    {
        *var = 0;
    }
    else if (*var > 5 << 8)
    {
        *var = 1 << 8;
    }
    else
    {
        *var = ((26 * *var) >> 8) + 128;
    }
}
