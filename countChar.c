#include <stdio.h>
int main()
{
    FILE *inputFile = fopen("arrayStructInput.txt", "r");
    if (inputFile == NULL)
    {
        printf("input file does not exist\n");
        return 0;
    }

    FILE *outputFile = fopen("charCount.txt", "w");

    int count = 0;
    while (1)
    {
        char ch = fgetc(inputFile);
        if (ch == EOF)
        {
            break;
        }

        count++;
    }
    fprintf(outputFile, "there are %d charecters in the input file", count);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}