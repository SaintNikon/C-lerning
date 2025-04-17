#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PROG 3

typedef struct
{
    char surname[20];
    char name[20];
    char patronymic[20];
    char gender[20];
    int sch_class;
    char subject_name[20];
    int score_lesson;
} school;

typedef struct
{
    char avtor[50];
    char book_name[50];
    char ISBN[20];
    int publ_date;
} book;

typedef struct
{
    char name[50];
    int age;
    char gender[10];
    char job[50];
} colleague;

void sort (school arr[], int n)
{
    for(int i = 0; i < n-1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].score_lesson > arr[max].score_lesson)
                max = j;
        }
        if (max != i) {
            school temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
        }
    }
}

void sort_coll (colleague arr[], size_t n)
{
    for(int i = 0; i < n-1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].age > arr[max].age)
                max = j;
        }
        if (max != i) {
            colleague temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(void)
{
    #if (PROG == 1)
    {
        int num;
        printf("How many students are in the class?\nStudents: ");
        scanf("%d", &num);
        school people[num];
        for (int i = 0; i < num; i++)
        {
            printf("Surname: ");
            scanf("%s", people[i].surname);
            printf("Name: ");
            scanf("%s", people[i].name);
            printf("Patronymic: ");
            scanf("%s", people[i].patronymic);
            printf("man or woman? ");
            scanf("%s", people[i].gender);
            printf("School class: ");
            scanf("%d", &people[i].sch_class);
            printf("Subject name: ");
            scanf("%s", people[i].subject_name);
            printf("Score lesson: ");
            scanf("%d", &people[i].score_lesson);
        };
        int avr_score = 0, men_score = 0, women_score = 0;
        sort(people, num);
        printf("\nSorted...\n");
        for(int i=0; i<num; i++)
        {
            avr_score += people[i].score_lesson;
            printf("%d %s %s %s\n", people[i].score_lesson, people[i].surname, people[i].name, people[i].patronymic);
            if (people[i].gender[0] == 'm' & people[i].gender[1] == 'a' & people[i].gender[2] == 'n')
                men_score += people[i].score_lesson;
            else women_score += people[i].score_lesson;
        }

        printf("average score: %4.2f\n", (double)avr_score / (double)num);
        printf("Man score: %4.2f\n", (double)men_score / (double)num);
        printf("Woman score: %4.2f\n", (double)women_score / (double)num);
    }
    #elif (PROG == 2)
    {

    int num;
    printf("How many books in the library? ");
    scanf("%d", &num);
    book lib[num];
    scanf("%*c");
    for (int i = 0; i<num; i++)
    {
        printf("Enter avtor: ");
        scanf("%50[^\n]", lib[i].avtor);
        scanf("%*c");
        printf("Enter book name: ");
        scanf("%50[^\n]", lib[i].book_name);
        scanf("%*c");
        printf("Enter ISBN: ");
        scanf("%20[^\n]", lib[i].ISBN);
        scanf("%*c");
        printf("Enter publication date: ");
        scanf("%d", &lib[i].publ_date);
        scanf("%*c");
    }
    char search_lib[20];
    printf("\nlibrary search: ");
    scanf("%s", search_lib);
    int num_book=0;
    for (int i = 0; i < num; i++)
    {
        if (strstr(lib[i].book_name, search_lib) != NULL)
        {
            printf("\"%s\" %s, %d\n", lib[i].book_name, lib[i].avtor, lib[i].publ_date);
            num_book = 1;
        }
    }
    if (num_book == 0) printf("Not found\n");
    }
    #elif (PROG == 3)
    {
        int number = 14, num_man = 0, num_woman = 0;
        colleague work[number];
        int sr_age = 0, sr_age_man = 0, sr_age_woman = 0;
        for (int i = 0; i < number; i++)
        {
            printf("Enter name: ");
            scanf("%50[^\n]", work[i].name);
            scanf("%*c");
            printf("Enter age: ");
            scanf("%d", &work[i].age);
            printf("Man or woman? ");
            scanf("%s", work[i].gender);
            scanf("%*c");
            printf("Enter profession: ");
            scanf("%50[^\n]", work[i].job);
            scanf("%*c");
            sr_age += work[i].age;
            if (strcmp(work[i].gender, "man") == 0) ++num_man;
            else ++num_woman;
        }
        printf("\n");
        colleague work_man[num_man];
        colleague work_woman[num_woman];
        num_man = 0, num_woman = 0;
        for (int i = 0; i < number; i++)
        {
            if (strcmp(work[i].gender, "man") == 0)
            {
                work_man[num_man] = work[i];
                sr_age_man += work[i].age;
                ++num_man;
            }
            else
            {
                work_woman[num_woman] = work[i];
                sr_age_woman += work[i].age;
                ++num_woman;
            }
        }
        size_t length = sizeof(work)/sizeof(work[0]);
        sort_coll(work, number);
        sort_coll(work_man, num_man);
        sort_coll(work_woman, num_woman);
        if ((number % 2) != 0)
        {
            printf("med_age: %d\n", work[number / 2].age);
        }
        else
        {
            printf("med_age: %4.2f\n", ((double)work[number / 2 - 1].age + (double)work[number / 2].age)/2);
        }
        if ((num_man % 2) != 0)
        {
            printf("med_age_man: %d\n", work_man[num_man / 2].age);
        }
        else
        {
            printf("med_age_man: %4.2f\n", ((double)work_man[num_man / 2 - 1].age + (double)work_man[num_man / 2].age)/2);
        }
        if ((num_woman % 2) != 0)
        {
            printf("med_age_woman: %d\n", work_woman[num_woman / 2].age);
        }
        else
        {
            printf("med_age_woman: %4.2f\n", ((double)work_woman[num_woman / 2 - 1].age + (double)work_woman[num_woman / 2].age)/2);
        }
        printf("sr_age: %4.2f\nsr_age_man: %4.2f\nsr_age_woman: %4.2f\n",
            (double)sr_age/(double)number, (double)sr_age_man/(double)num_man, (double)sr_age_woman/(double)num_woman);
        }
    #endif



    return 0;
}
