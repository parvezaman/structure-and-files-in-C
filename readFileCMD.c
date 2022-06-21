#include <stdio.h>
int main()
{
    FILE *inputFile = fopen("in.txt", "r");
    FILE *outputFile = fopen("out.txt", "w");
    int a, b;
    fscanf(inputFile, "%d %d", &a, &b);
    int sum = a + b;
    fprintf(outputFile, "%d + %d = %d", a, b, sum);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}