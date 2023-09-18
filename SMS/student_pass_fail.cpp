#include<stdio.h>
#include<stdlib.h>

//#typedef marks float


struct Student{
    char firstName[15];
    char lastName[15];
    float marksCpp;
    float marksJava;
    float marksDSA;  
};

int max_student = 2;

int main(){

    Student studentList[max_student];

    printf("\n[i] Welcome ! \n");

    //input loop
    for(int i = 0 ; i < max_student; i++ ){
        printf("\n[i] Enter Details for Student [%i]\n",i);
        printf("\n[?] Name : ");
        scanf("%s %s",&studentList[i].firstName, &studentList[i].lastName);
        printf("\n[>] Marks in C++ : ");
        scanf(" %f",&studentList[i].marksCpp);
        printf("\n[>] Marks in Java : ");
        scanf(" %f",&studentList[i].marksJava);
        printf("\n[>] Marks in Data Structure : ");
        scanf(" %f",&studentList[i].marksDSA);
    }

    //output loop  
    for(int i = 0; i < max_student; i++){
        printf("\n********Student %i******",i);
        int percentage = (((studentList[i].marksCpp + studentList[i].marksDSA + studentList[i].marksJava) / 300)) * 100;
        if (percentage < 60)
        {
            printf("\nStatus : Failed");
        }else{
            printf("\nStatus : Passed");
        }
        
        printf("\n[>] Name : %s %s",studentList[i].firstName, studentList[i].lastName);
        printf("\n[>] Marks in C++ : %f", studentList[i].marksCpp);
        printf("\n[>] Marks in Java : %f", studentList[i].marksJava);
        printf("\n[>] Marks in Datastructure : %f", studentList[i].marksDSA);
    }




    return 0;
}