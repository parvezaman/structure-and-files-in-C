#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Student
{
    char name[100];
    int id;
    int marks;
};
struct unique_Students
{
    char name[100];
    int id;
    int total;
};

void printStudent(struct Student st)
{
    printf("name: %s; id: %d; marks: %d\n", st.name, st.id, st.marks);
}

void printUnique(struct unique_Students st, FILE *output)
{
    fprintf(output, "name: %s; id: %d; total mark: %d\n", st.name, st.id, st.total);
}

int main()
{
    FILE *inputFile = fopen("inputOfStudents.txt", "r");
    FILE *outputFile = fopen("unique students marks sum sorted.txt", "w");
    if (inputFile == NULL)
    {
        fprintf(outputFile, "Invalid input file\n");
        return 0;
    }

    int n;
    fscanf(inputFile, "%d", &n);
    struct Student students[n];
    // now we are going to find out sum of marks of an individual student but this time we will find for unoque students
    struct unique_Students uniqueStudentsArr[n];
    int k = 0; // k means ekhon porjonto koita unique student paiche

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        fscanf(inputFile, "%s %d %d", students[i].name, &students[i].id, &students[i].marks);
        for (int j = 0; j < k; j++)
        {
            if (uniqueStudentsArr[j].id == students[i].id)
            {
                uniqueStudentsArr[j].total += students[i].marks;
                found = true;
            }
        }
        if (found == false)
        {
            strcpy(uniqueStudentsArr[k].name, students[i].name);
            uniqueStudentsArr[k].id = students[i].id;
            uniqueStudentsArr[k].total = students[i].marks;
            k++;
        }
    }

    // lets sort unique students
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (uniqueStudentsArr[i].total < uniqueStudentsArr[j].total)
            {
                struct unique_Students temp = uniqueStudentsArr[i];
                uniqueStudentsArr[i] = uniqueStudentsArr[j];
                uniqueStudentsArr[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        printUnique(uniqueStudentsArr[i], outputFile);
        ;
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}