#include <stdio.h>
#include <string.h>

struct student_t
{
    char email[38];
    char branch_name[4];
    char id[14];
};
typedef struct student_t student;

void main()
{
    student s;
    scanf("%s", s.email);
    scanf("%s", s.branch_name);
    strncpy(s.id, s.email+1, 4);
    s.id[4] = 'A';
    if(strcmp(s.branch_name, "CS") == 0) s.id[5] = '7';
    else if(strcmp(s.branch_name, "ECE") == 0) s.id[5] = 'A';
    else if(strcmp(s.branch_name, "EEE") == 0) s.id[5] = '3';
    s.id[6] = 'P';
    s.id[7] = 'S';
    strncpy(s.id+8, s.email+5, 4);
    s.id[12] = 'H';
    s.id[13] = '\0';
    printf("%s\n", s.id);
}