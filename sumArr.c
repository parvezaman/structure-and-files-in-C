#include <stdio.h>
int main()
{
    FILE *inputFile = fopen("inputArr.txt", "r");
    FILE *outputFile = fopen("output sum arr.txt", "w");

    int n, sum = 0;
    fscanf(inputFile, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
        sum += arr[i];
    }

    fprintf(outputFile, "the sum is: %d", sum);

    return 0;
}