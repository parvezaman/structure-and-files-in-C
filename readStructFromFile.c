#include <stdio.h>
#include <string.h>
struct Student
{
    char name[100];
    int marks;
    int roll;
    char section;
    int whichClass;
};

void printStruct(struct Student st, FILE *output)
{
    fprintf(output, "name : %s; marks: %d; roll: %d; section: %c; class: %d\n", st.name, st.marks, st.roll, st.section, st.whichClass);
}

int main()
{
    FILE *inputFile = fopen("arrayStructInput.txt", "r");
    if (inputFile == NULL)
    {
        printf("input file not found!\n");
        return 0;
    }

    FILE *outputFile = fopen("arrayStructOutput.txt", "w");

    int n;
    fscanf(inputFile, "%d", &n);
    struct Student arr[n];
    for (int i = 0; i < n; i++)
    {
        char stName[100];
        char temp;
        fscanf(inputFile, "%s", stName);
        strcpy(arr[i].name, stName);
        fscanf(inputFile, "%d", &arr[i].marks);
        fscanf(inputFile, "%d", &arr[i].roll);
        fscanf(inputFile, "%c", &temp);
        fscanf(inputFile, "%c", &arr[i].section);
        fscanf(inputFile, "%d", &arr[i].whichClass);
    }

    for (int i = 0; i < n; i++)
    {
        printStruct(arr[i], outputFile);
    }

    int highest = 0, highestIndex, lowest = arr[0].marks, lowestIndex;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].marks > highest)
        {
            highest = arr[i].marks;
            highestIndex = i;
        }
        if (arr[i].marks < lowest)
        {
            lowest = arr[i].marks;
            lowestIndex = i;
        }
    }
    fprintf(outputFile, "\nHigest: - ");
    printStruct(arr[highestIndex], outputFile);

    fprintf(outputFile, "\nLowest: - ");
    printStruct(arr[lowestIndex], outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}