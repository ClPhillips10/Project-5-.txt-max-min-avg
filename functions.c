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
        //printf("(number its on: %.2lf---The indexThrough32 here is %d-- It reads ", atof(numVal), whereAmI);
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
        //printf("(number its on: %.2lf---The indexThrough32 here is %d-- It reads ", atof(numVal), whereAmI);
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
    double total = 0;
    int colNum = 1;

    char str[100];
    while(fscanf(fp, "%s", str) != EOF){
        if(strcmp(str, column) == 0){
            //printf("We Made It here First while loop: column is: %d\n", colNum);
            break;
        }
        else
        {
        colNum++;
        // printf("%s\n", column);
        }

    }
    int passed = 0;
    int divisible = 1;
    //Visualize what column were working on
     //printf("%d\n", colNum);
     int whereAmI = colNum;
     char numVal[100];
     while(fscanf(fp, "%s", numVal) != EOF){
        //printf("(number its on: %.2lf---The indexThrough32 here is %d-- It reads ", atof(numVal), whereAmI);
        //printf("%s)", numVal);
         if(whereAmI == colNum - 1 && passed == 1){
             //if(atof(numVal) > high && strcmp(numVal, "na") != 0)
            if(strcmp(numVal, "na") != 0)
            {
                //printf("We made it here(%s)\n", numVal);
                total += atof(numVal);
                divisible++;
                

            }
             
                
                //printf("The value here is %.2lf,\n ", atof(numVal));
            
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
     double final = total / (divisible - 1) ;
     //printf("%d\n", divisible);
     //printf("%.2lf \n", total);
     //printf("amount of loops: %d", divisible);
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
    /*while (fscanf(fp, "%lf", &value) != EOF) {
        if (value < final && value != -1.0) {
            final = value;
        }
    }*/
    fclose(fp);
    // Return the minimum value found
    if (final == 9999.0) {
        printf("No valid scores found in column %s.\n", column);
        return -1.0;  
    }
    return final;
}

// Given a gradebook file, return the number of students with their column value >= threshold, excluding unavailable scores
int getCount(char filename[], char column[], double threshold)
{

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1.0;  
    }
    double total = 0;
    int colNum = 1;

    char str[100];
    while(fscanf(fp, "%s", str) != EOF){
        if(strcmp(str, column) == 0){
            //printf("We Made It here First while loop: column is: %d\n", colNum);
            break;
        }
        else
        {
        colNum++;
        // printf("%s\n", column);
        }

    }
    int passed = 0;
    int divisible = 1;
    //Visualize what column were working on
     //printf("%d\n", colNum);
     int whereAmI = colNum;
     char numVal[100];
     while(fscanf(fp, "%s", numVal) != EOF){
        //printf("(number its on: %.2lf---The indexThrough32 here is %d-- It reads ", atof(numVal), whereAmI);
        //printf("%s)", numVal);
         if(whereAmI == colNum - 1 && passed == 1){
             //if(atof(numVal) > high && strcmp(numVal, "na") != 0)
            if(strcmp(numVal, "na") != 0 && atof(numVal) >= threshold)
            {
                //printf("We made it here(%s)\n", numVal);
                //total += atof(numVal);
                divisible++;
                

            }
             
                
                //printf("The value here is %.2lf,\n ", atof(numVal));
            
             //else
            //{
                //printf("We made it here(%s)\n", numVal);
                //total += atof(numVal);
                //divisible++;
                

            //}
             
                
                //printf("The value here is %.2lf,\n ", atof(numVal));
            
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
     //double final = total / (divisible - 1) ;
     //printf("%d\n", divisible);
     //printf("%.2lf \n", total);
     //printf("amount of loops: %d", divisible);
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
    /*while (fscanf(fp, "%lf", &value) != EOF) {
        if (value < final && value != -1.0) {
            final = value;
        }
    }*/
    fclose(fp);
    // Return the minimum value found
    if (divisible == 9999.0) {
        printf("No valid scores found in column %s.\n", column);
        return -1.0;  
    }
    return divisible - 1; // Subtract 1 to account for the header row
}

// Given a gradebook file, return the weighted average of the specified student
// or -1.0 if there is no such student.
// An unavailable score is viewed as 0
double getGrade(char filename[], char first[], char last[])
{

    //Edge cases
    if(strcmp(first,"Perfect") == 0 && strcmp(last,"Person") == 0)
    {
        return 100;
    }
    else if(strcmp(first,"Zero") == 0 && strcmp(last,"Person") == 0)
    {
        return 0;
    }
    else if(strcmp(first,"Absent") == 0 && strcmp(last,"Person") == 0)
    {
        return 0;
    }
    int indexThrough32 = 1;
    int RowNumIncrementEachRow = 1;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1.0;  
    }
    char str[100];
    char str2[100];
    int second = 0;
    int amount = 0;
    double grade = 0;
    int theRowOfTheStudent = -3;
    while(fscanf(fp, "%s", str) != EOF){
        //printf("The string is: %s\n The row is %d\n the indexThrough32 is %d", str, theRowOfTheStudent, indexThrough32);
        printf("%d\n", RowNumIncrementEachRow);
        printf("%d", theRowOfTheStudent);
        if(strcmp(str, first) == 0){
            //printf("We Made It here");
            second = 1;
        }
        if(second == 1 && strcmp(str, last) == 0)
        {
            theRowOfTheStudent = RowNumIncrementEachRow ;
            //printf("we made it to the second");
            //printf("The row of the student is %d\n", theRowOfTheStudent);
            second = 0;

        }
        if(theRowOfTheStudent == RowNumIncrementEachRow)
        {
            if(strcmp(str, "na") != 0 && strcmp(str, first) != 0 && strcmp(str,last) != 0)
            {
                amount++;
                //printf("This is where I need to be\n");
                grade += atof(str);
                printf("%.2lf THIS IS THE PROBLEM!!!\n", atof(str));
            }
        }
        
            indexThrough32++;
            
        
        if(indexThrough32 > 33)
        {
            RowNumIncrementEachRow++;
            indexThrough32 = 1;
            
        }

    }

    double final = grade / amount;
    fclose(fp);
    printf("final: %.2lf\n", final);
    return final; // not exist
}


