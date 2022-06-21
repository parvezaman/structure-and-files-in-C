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

void printStruct(struct Student st)
{
    printf("name : %s; marks: %d; roll: %d; section: %c; class: %d\n", st.name, st.marks, st.roll, st.section, st.whichClass);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Student arr[n];
    for (int i = 0; i < n; i++)
    {
        char stName[100];
        char temp;
        scanf("%s", stName);
        strcpy(arr[i].name, stName);
        scanf("%d", &arr[i].marks);
        scanf("%d", &arr[i].roll);
        scanf("%c", &temp);
        scanf("%c", &arr[i].section);
        scanf("%d", &arr[i].whichClass);
    }

    for (int i = 0; i < n; i++)
    {
        printStruct(arr[i]);
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
    printf("\nHigest: - ");
    printStruct(arr[highestIndex]);

    printf("\nLowest: - ");
    printStruct(arr[lowestIndex]);

    return 0;
}