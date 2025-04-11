#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Given a gradebook file, return the minimum of the specified column, excluding unavailable scores
double getMin(char filename[], char column[])
{
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1.0;  
    }
    double low = 999999;
    int colNum = 1;

    char str[100];
    while(fscanf(fp, "%s", str) != EOF){
        if(strcmp(str, column) == 0){
            //printf("We Made It here");
            break;
        }
        else
        {
        colNum++;
        // printf("%s\n", column);
        }

    }
    int passed = 0;
    //Visualize what column were working on
     //printf("%d\n", colNum);
     //testing where am I at 1 ..... previously  int whereAmI = colNum + 1;
     //int whereAmI = 1;
     int whereAmI = colNum + 1;
     char numVal[100];
     while(fscanf(fp, "%s", numVal) != EOF){
        //printf("(number its on: %.2lf---The index here is %d-- It reads ", atof(numVal), whereAmI);
        //printf("%s)", numVal);
         if(whereAmI == colNum && passed == 1){
             if(atof(numVal) < low && strcmp(numVal, "na") != 0)
            {
                low = atof(numVal);
                //printf("The value here is %.2lf,\n ", atof(numVal));
            }
             //else
            //printf("Trying this: %.2lf\n", atof(numVal));
     }
            
         if(whereAmI > 31)
         {
            passed = 1;
            
            whereAmI = 1;
        }
        else
            whereAmI++;
        
         //printf("%d\n", whereAmI);
         char numVal[100];
         
     }
    //printf("%d\n", colNum);
    /*char line[300];
    while (fgets(line, 300, fp)) {
        for (int i = 0; i <= colNum; i++) {
            sscanf(line, "%s", str);
        }
        printf("trying this: %s\n ", str);
    }

    // You know the colNum, 
    */
    // Read the column values for the specified column
    double value;
    while (fscanf(fp, "%lf", &value) != EOF) {
        if (value < low && value != -1.0) {
            low = value;
        }
    }
    fclose(fp);
    // Return the minimum value found
    if (low == 9999.0) {
        printf("No valid scores found in column %s.\n", column);
        return -1.0;  
    }
    return low;
        
    
}
// Given a gradebook file, return the maximum of the specified column, excluding unavailable scores
double getMax(char filename[], char column[])
{

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1.0;  
    }
    double high = 0;
    int colNum = 1;

    char str[100];
    while(fscanf(fp, "%s", str) != EOF){
        if(strcmp(str, column) == 0){
            //printf("We Made It here");
            break;
        }
        else
        {
        colNum++;
        // printf("%s\n", column);
        }

    }
    int passed = 0;
    //Visualize what column were working on
     //printf("%d\n", colNum);
     //testing where am I at 1 ..... previously  int whereAmI = colNum + 1;
     //int whereAmI = 1;
     int whereAmI = colNum + 1;
     char numVal[100];
     while(fscanf(fp, "%s", numVal) != EOF){
        //printf("(number its on: %.2lf---The index here is %d-- It reads ", atof(numVal), whereAmI);
        //printf("%s)", numVal);
         if(whereAmI == colNum && passed == 1){
             if(atof(numVal) > high && strcmp(numVal, "na") != 0)
            {
                high = atof(numVal);
                //printf("The value here is %.2lf,\n ", atof(numVal));
            }
             //else
            //printf("Trying this: %.2lf\n", atof(numVal));
     }
            
         if(whereAmI > 31)
         {
            passed = 1;
            
            whereAmI = 1;
        }
        else
            whereAmI++;
        
         //printf("%d\n", whereAmI);
         char numVal[100];
         
     }
    //printf("%d\n", colNum);
    /*char line[300];
    while (fgets(line, 300, fp)) {
        for (int i = 0; i <= colNum; i++) {
            sscanf(line, "%s", str);
        }
        printf("trying this: %s\n ", str);
    }

    // You know the colNum, 
    */
    // Read the column values for the specified column
    double value;
    while (fscanf(fp, "%lf", &value) != EOF) {
        if (value < high && value != -1.0) {
            high = value;
        }
    }
    fclose(fp);
    // Return the minimum value found
    if (high == 9999.0) {
        printf("No valid scores found in column %s.\n", column);
        return -1.0;  
    }
    return high;
}

// Given a gradebook file, return the average of the specified column, excluding unavailable scores
double getAvg(char filename[], char column[])
{

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1.0;  
    }
    double high = 0;
    int colNum = 1;

    char str[100];
    while(fscanf(fp, "%s", str) != EOF){
        if(strcmp(str, column) == 0){
            //printf("We Made It here");
            break;
        }
        else
        {
        colNum++;
        // printf("%s\n", column);
        }

    }
    int passed = 0;
    //Visualize what column were working on
     //printf("%d\n", colNum);
     int whereAmI = colNum + 1;
     char numVal[100];
     while(fscanf(fp, "%s", numVal) != EOF){
        //printf("(number its on: %.2lf---The index here is %d-- It reads ", atof(numVal), whereAmI);
        //printf("%s)", numVal);
         if(whereAmI == colNum && passed == 1){
             if(atof(numVal) > high && strcmp(numVal, "na") != 0)
            {
                high = atof(numVal);
                //printf("The value here is %.2lf,\n ", atof(numVal));
            }
             //else
            //printf("Trying this: %.2lf\n", atof(numVal));
     }
            
         if(whereAmI > 31)
         {
            passed = 1;
            
            whereAmI = 1;
        }
        else
            whereAmI++;
        
         //printf("%d\n", whereAmI);
         char numVal[100];
         
     }
    //printf("%d\n", colNum);
    /*char line[300];
    while (fgets(line, 300, fp)) {
        for (int i = 0; i <= colNum; i++) {
            sscanf(line, "%s", str);
        }
        printf("trying this: %s\n ", str);
    }

    // You know the colNum, 
    */
    // Read the column values for the specified column
    double value;
    while (fscanf(fp, "%lf", &value) != EOF) {
        if (value < high && value != -1.0) {
            high = value;
        }
    }
    fclose(fp);
    // Return the minimum value found
    if (high == 9999.0) {
        printf("No valid scores found in column %s.\n", column);
        return -1.0;  
    }
    return high;
}

// Given a gradebook file, return the number of students with their column value >= threshold, excluding unavailable scores
int getCount(char filename[], char column[], double threshold)
{

    return 4;
}

// Given a gradebook file, return the weighted average of the specified student
// or -1.0 if there is no such student.
// An unavailable score is viewed as 0
double getGrade(char filename[], char first[], char last[])
{

    return -1.0; // not exist
}


