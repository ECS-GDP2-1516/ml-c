#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 60

void sigmoid(int* var);
int* getData();
void load(char* path);
int classify();

int8_t rear = 0;
int16_t buffer[BUFFER_SIZE]; //the buffer is just used to read values into

float total = 0;
float outside = 0;

// inserts the next set of values read from the sensor into the buffer
void insert_reading(int16_t x, int16_t y, int16_t z) {
    buffer[rear++] = x;
    buffer[rear++] = y;
    buffer[rear++] = z;
    rear= rear %BUFFER_SIZE;
}

int main()
{
    insert_reading(1, 2, 3);
    insert_reading(1, 2, 3);
    load("../ml-java/data.txt");

    return 0;
}

int classify()
{
    int32_t* offset=(int32_t*)getData();

    int32_t nodeA = *offset++;
    int32_t nodeB = *offset++;
    //int32_t nodeC = *offset++;
    int8_t j      = rear;

    do
    {
        nodeA += (*offset++ * buffer[j]) >> 12;
        nodeB += (*offset++ * buffer[j]) >> 12;
        //nodeC += (*offset++ * buffer[j]) >> 12;
        j      = (j + 1) % BUFFER_SIZE;
    } while (j != rear);

    sigmoid(&nodeA);
    sigmoid(&nodeB);
    //sigmoid(&nodeC);

    int32_t v[3];

    for (int32_t* i = v; i < v + 3; i++)
    {
        *i  = *offset++;
        *i += (*offset++ * nodeA) >> 12;
        *i += (*offset++ * nodeB) >> 12;
        sigmoid(i);
    }

    // Detects peak or trough
    if (v[0] > v[2] && v[0] > v[1])
    {
        return 0;
    }
    else if (v[1] > v[2])
    {
        return 1 << 12;
    }
    else //Not exercise
    {
        return 2 << 12;
    }
}

void sigmoid(int* var)
{
    total += 1;

    if (*var < -5 << 12)
    {
        outside += 1;
        *var = 0;
    }
    else if (*var > 5 << 12)
    {
        outside += 1;
        *var = 1 << 12;
    }
    else
    {
        *var = ((410 * *var) >> 12) + 2048;
    }
}
