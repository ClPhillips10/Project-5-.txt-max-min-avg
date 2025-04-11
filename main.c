#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "functions.c"

// Given a gradebook file, return the minimum of the specified column, excluding unavailable scores
double getMin(char filename[], char column[]);

// Given a gradebook file, return the maximum of the specified column, excluding unavailable scores
double getMax(char filename[], char column[]);

// Given a gradebook file, return the average of the specified column, excluding unavailable scores
double getAvg(char filename[], char column[]);

// Given a gradebook file, return the number of students with their column value >= threshold, excluding unavailable scores
int getCount(char filename[], char column[], double threshold);

// Given a gradebook file, return the weighted average of the specified student
// or -1.0 if there is no such student.
// An unavailable score is viewed as 0
double getGrade(char filename[], char first[], char last[]);

int isValidColumn(char column[])
{
    char type;
    int num;
    sscanf(column, "%c%d", &type, &num);
    switch (type) {
    case 'L':
        if (num<1 || num>10) return 0;
        break;
    case 'E':
        if (num<1 || num>4) return 0;
        break;
    case 'B':
        if (num<1 || num>10) return 0;
        break;
    case 'P':
        if (num<1 || num>6) return 0;
        break;
    default:
        return 0;
    }

    char column2[strlen(column)+1];
    sprintf(column2, "%c%d", type, num);
    if (strcmp(column, column2)!=0) return 0;

    return 1;
}

void printHelp()
{
    printf("\nThe valid commands:\n\n");
    printf("\tmin column\n");
    printf("\t*** find the minimum of the specified column, excluding unavailable scores\n");
    printf("\t*** for example: min P4\n");
    printf("\tmax column\n");
    printf("\t*** find the maximum of the specified column, excluding unavailable scores\n");
    printf("\t*** for example: max E1\n");
    printf("\tavg column\n");
    printf("\t*** find the average of the specified column, excluding unavailable scores\n");
    printf("\t*** for example: avg B10\n");
    printf("\tcount column threshold\n");
    printf("\t*** find the number of rows with its column value >= threshold, excluding unavailable scores\n");
    printf("\t*** for example: count L2 60\n");
    printf("\tgrade firstname lastname\n");
    printf("\t*** find the weighted average of the specified student. An unavailable score is viewed as 0\n");
    printf("\t*** for example: grade John Smith\n");
    printf("\tquit\n");
    printf("\t*** quit this program\n");
    printf("\thelp\n");
    printf("\t*** print this list\n");
}

int main(int argc, char *argv[])
{
    if (argc!=2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE *fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 2;
    }
    fclose(fp);

    while (1) {
        char cmd[30];
        char column[30];
        char line[300];
        printf("\nEnter a command: ");
        scanf("%s", cmd);
        if (strcmp(cmd, "quit")==0) break;
        if (strcmp(cmd, "grade")==0) {
            char first[30], last[30];
            scanf("%s%s", first, last);
            double grade=getGrade(argv[1], first, last);
            if (grade>=0)
                printf("grade(%s %s)=%g\n", first, last, grade);
            else
                printf("No student named %s %s\n", first, last);
        }
        else if (strcmp(cmd, "min")==0) {
            scanf("%s", column);
            if (isValidColumn(column)) {
                double min=getMin(argv[1], column);
                printf("min(%s)=%g\n",column, min);
            }
            else {
                printf("%s: invalid column name.\n", column);
                fgets(line, 300, stdin); // skip the rest of line
            }
        }
        else if (strcmp(cmd, "max")==0) {
            scanf("%s", column);
            if (isValidColumn(column)) {
                double max=getMax(argv[1], column);
                printf("max(%s)=%g\n", column, max);
            }
            else {
                printf("%s: invalid column name.\n", column);
                fgets(line, 300, stdin); // skip the rest of line
            }
        }
        else if (strcmp(cmd, "avg")==0) {
            scanf("%s", column);
            if (isValidColumn(column)) {
                double avg=getAvg(argv[1], column);
                printf("avg(%s)=%g\n", column, avg);
            }
            else {
                printf("%s: invalid column name.\n", column);
                fgets(line, 300, stdin); // skip the rest of line
            }
        }
        else if (strcmp(cmd, "count")==0) {
            scanf("%s", column);
            if (isValidColumn(column)) {
                double threshold;
                scanf("%lf", &threshold);
                int count=getCount(argv[1], column, threshold);
                printf("count(%s>=%g)=%d\n", column, threshold, count);
            }
            else {
                printf("%s: invalid column name.\n", column);
                fgets(line, 300, stdin); // skip the rest of line
            }
        }
        else if (strcmp(cmd, "help")==0) {
            printHelp();
        }
        else {
            printf("%s: invalid commmand. Type help for help.\n", cmd);
            fgets(line, 300, stdin); // skip the rest of line
        }
    }
    return 0;
}

