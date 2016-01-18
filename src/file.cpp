#include <stdio.h>
#include <stdint.h>

int classify();
void insert_reading(int16_t x, int16_t y, int16_t z);

void load(char* path)
{
    FILE * file = fopen(path, "r");
    if (file == NULL)
    {
        fprintf(stderr, "[ERROR] Impossible to open object file: '%s'!\n", path);
        return;
    }

    int* data = new int[305];
    float success = 0;
    float total   = 0;
    int i = 0;

    while (!feof(file))
    {
        int a;
        int b;
        int c;

        fscanf(file, "%d,%d,%d,", &a, &b, &c);
        insert_reading(a, b, c);

        i++;

        if (i == 20)
        {
            total++;
            int expected;
            int got = classify();

            fscanf(file, "%d,\n", &expected);
            i = 0;
            printf("%d %d %d\n", got, expected, got == expected);

            success += (got==expected);
        }
    }

    printf("%f\n", success / total * 100);
}
