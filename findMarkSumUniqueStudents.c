#include <stdio.h>
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

void printUnique(struct unique_Students st)
{
    printf("name: %s; id: %d; total mark: %d\n", st.name, st.id, st.total);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Student students[n];
    // now we are going to find out sum of marks of an individual student but this time we will find for unoque students
    struct unique_Students rakib = {"Rakib", 17256, 0};
    struct unique_Students sakib = {"Sakib", 17259, 0};

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", students[i].name, &students[i].id, &students[i].marks);
        if (students[i].id == rakib.id)
        {
            rakib.total += students[i].marks;
        }
        else
        {
            sakib.total += students[i].marks;
        }
    }

    /*  for (int i = 0; i < n; i++)
     {
         printStudent(students[i]);
     } */

    printUnique(rakib);
    printUnique(sakib);

    return 0;
}