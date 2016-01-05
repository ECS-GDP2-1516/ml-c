#include <stdio.h>


void sigmoid(int* var);
int* getData();
void load(char* path);

int main()
{
    load("data.txt");

    return 0;
}


int classify(int* v)
{
int* offset=(int*)getData();
int* s1;
int* e1;
int* s2=v;
int* e2=s2 + 30;

// Layer 2
s1=v + 30;
e1=s1 + 2;
for (int* i = s1; i < e1; i++){
    *i=*offset++;
    for (int* j=s2; j < e2; j++) {
        *i+=(*offset++**j) >> 12;
    }
    sigmoid(i);
}

// Layer 1
s2=v + 0;
e2=s2 + 3;
for (int* i = s2; i < e2; i++){
    *i=*offset++;
    for (int* j=s1; j < e1; j++) {
        *i+=(*offset++**j) >> 12;
    }
    sigmoid(i);
}

    if (v[0] > v[1] && v[0] > v[2])
    {
        return 0;
    }
    else if (v[1] > v[0] && v[1] > v[2])
    {
        return 1 << 12;
    }
    else
    {
        return 2 << 12;
    }
}

void sigmoid(int* var)
{
    if (*var < -5 << 12)
    {
        *var = 0;
    }
    else if (*var > 5 << 12)
    {
        *var = 1 << 12;
    }
    else
    {
        *var = ((410 * *var) >> 12) + 2048;
    }
}
