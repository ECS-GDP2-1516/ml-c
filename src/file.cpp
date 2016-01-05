#include <stdio.h>

int classify(int* v);

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
        fscanf(file, "%d,", &data[i++]);

        if (i == 30)
        {
            total++;
            int expected;
            int got = classify(data);

            fscanf(file, "%d,\n", &expected);
            i = 0;
            printf("%d %d %d\n", got, expected, got == expected);

            success += (got==expected);
        }
    }

    printf("%f\n", success / total * 100);
}
