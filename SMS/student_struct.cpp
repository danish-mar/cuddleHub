#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//defining student structure student -- name, rollNo, Stream
struct StudentInfo{
    int rollNo;
    char name[40];
    char stream[40];
};

char filename[] = "Student.csv";

int main(){
    //Max Value is set to 1
    int max_student = 1;
    char askStudentName[40];
    //creating max student object
    StudentInfo Students[max_student];

    FILE * fileptr;

    char choice;

    printf("====== Welcome =====\n");

    //Getting the values

    for(int i = 0;i < max_student;i++){
        
        printf("\n[i] Entring Details for Student %i",i);
        printf("\n[?] Name : ");
        scanf("%s",&Students[i].name);
        printf("\n[?] Stream : ");
        scanf("%s",&Students[i].stream);
        printf("\n[?] RollNo : ");
        scanf("%i",&Students[i].rollNo);
        printf("\n[i] Added Student %i Details",i);
    }

    for(int j = 0; j < max_student; j++){
        printf("\n------Student %i------",j);
        printf("\nName : %s",Students[j].name);
        printf("\nRoll No : %i",Students[j].rollNo);
        printf("\nStream : %s",Students[j].stream);
    }

    // printf("\n[?] Enter Student Name : ");
    // scanf("%s",&askStudentName);

    // for(int k = 0; k < max_student; k++){
    //     if(strcmp(askStudentName,Students[k].name)==0){
    //         printf("\n------Student %i------",k);
    //         printf("\nName : %s",Students[k].name);
    //         printf("\nRoll No : %i",Students[k].rollNo);
    //         printf("\nStream : %s",Students[k].stream);
    //     }else{
    //         printf("\n[!] 404 Student Not found");
    //         break;
    //     }
    // }

    
    
    

    //saving to a *.dat file
    fileptr = fopen(filename,"a+");

    printf("\n[i] Do you want to save the %i student records\n",max_student);
    printf("[?] (y/n): ");
    scanf(" %c",&choice);

    if (choice == 'y')
    {
        for(int i = 0; i < max_student; i++){
            fprintf(fileptr,"\n%d,%s,%s",Students[i].rollNo,Students[i].name,Students[i].stream);
            printf("\n[i] Saved Student %d",i);
        }
    }else{
        printf("\n[!] Data Discarded!");
    }
    fclose(fileptr);
    return 0;

}