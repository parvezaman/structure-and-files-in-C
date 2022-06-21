#include <stdio.h>

int makeSum(int n, FILE *input)
{
    int sum = 0, arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &arr[i]);
        sum += arr[i];
    }
    return sum;
}
int main()
{
    FILE *inputFile = fopen("testCases.txt", "r");
    FILE *outputFile = fopen("text cases output.txt", "w");

    int n;
    fscanf(inputFile, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        fscanf(inputFile, "%d", &x);
        int sum = makeSum(x, inputFile);
        fprintf(outputFile, "case %d : %d\n", i + 1, sum);
    }

    return 0;
}