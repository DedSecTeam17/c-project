#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include <mem.h>





///**
//TODO:a record for student info
///
///
/// ///
struct StudentInformation {
    int Student_ID;
    int Student_Number;
    char  studentName[8];
    char national_number[8];
    char  Department[8];
    char  Gender[8];
    int  OS;
    int  DB;
};

struct  indexing{
    int in_dex;
};
void  writeInFile(struct StudentInformation  studentinformation,int ID);
void  ReadDataFile(struct StudentInformation   studentinformation);
void  UdateFileItem(struct StudentInformation  studentinformation);
void DeleteAllFileContent();
int  currentKey(struct StudentInformation studentinformation);
void searchingForstudent(struct StudentInformation studentinformation);
void checkfortextinfile(struct StudentInformation studentinformation);
void  deleteStudent(struct StudentInformation studentinformation,struct  indexing index,int deletestudent);
void  ReadSorted(struct StudentInformation studentinformation,  int vv[],int size);
void  ReadLastStudentAdded(struct StudentInformation studentinformation);
void  Read_Index_File(struct indexing ind);
void  ReadAllFile(struct indexing ind,struct StudentInformation studentinformation);
int  get_index( struct StudentInformation studentinformation,struct indexing ind,const  int input);
void  Setup_IndexItem(struct StudentInformation studentinformation,int numbof);
void  Write_In_IndexFile(struct StudentInformation studentinformation,int itm[],int size);
void  Up_To_Down(struct StudentInformation studentinformation,  int vv[],int size);
bool check_if_student_in_the_system(int Student_Number);
void  merge_sort(struct StudentInformation studentinformation,int run);
void  Internal_sorting(struct StudentInformation studentinformation[],int counter);
void  write_in_merge_files_to_Be_sorted(struct StudentInformation studentinformation,char *file,int from);
int  get_id_with_index(struct StudentInformation studentinformation,int index);

void insertStd(struct StudentInformation studentinformation);

int main() {
    struct  StudentInformation studentinformation = {0,0, "", "", "","",0,0};
    struct   indexing ind={0};
    int choice;
    int ID=currentKey(studentinformation);
//    Setup_IndexItem(ind,studentinformation);
//    printf("Your index pos: %d \n",get_index(ind,5));
    printf("Enter number of records per block \n");
    int numb;
    scanf("%d",&numb);

//    MessageBox(0,"Hello","Welcome Message",1);

    while (true){

        Setup_IndexItem(studentinformation,numb);
        printf("__________________________________________________________________________________________________________________ \n");
        printf("%s","|1-Enter Data\n|2-Show Data\n|3-update\n|4-delete student\n|5-search\n|6-initilaztion\n|7-Sort with merge sort \n|8-Exit  \n ");
        printf("__________________________________________________________________________________________________________________ \n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("%s","     Writing  process  \n");
                ID+=1;
//                insertStd(studentinformation);
                writeInFile(studentinformation,ID);
                break;
            case 2:
                printf("%s","     Reading  process \n");
                ReadAllFile(ind,studentinformation);
                break;
            case 3:
                printf("%s","    Update process process \n");
                UdateFileItem(studentinformation);
                break;
            case 4:

                printf("%s","    Deleting  Student process \n");
                int deletestudent;
                printf("%s", "Enter Student Number to deleted \n");
                scanf("%d", &deletestudent);
                deleteStudent(studentinformation,ind,deletestudent);
                break;

            case 5:
              printf("%s","Search");
                searchingForstudent(studentinformation);
                break;
            case 6:
                printf("Delete All student...");
                ID=0; ///reset the pointer in the file to zero
                checkfortextinfile(studentinformation);///delete all file text
                break;

            case 7:
                printf("Enter Your Run: \n");
                int run;
                scanf("%d",&run);

                merge_sort(studentinformation,run);
                break;

            case 8:
                printf("Exit ...");
            exit(1);
            default:
                printf("%s","Please input valid choice \n");
        }
    }
}
///*
 /// TODO:to write in student file include {student name and id / his/her national_number / Department main Gender}
 /// @param  studentinformation reference into student Record Data in block in file
 /// @param  ID to order student in file as there ID,s
 /// **
 /// //
void  writeInFile(struct StudentInformation studentinformation,int ID){
    FILE *myfile;
             if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "a+")) == NULL) {
                puts("File Dose,t created Yet ");
                   } else {

//                 Read Data from user
                                   printf("%s", "Enter Student Number \n");
                                   fscanf(stdin,"%d", &studentinformation.Student_Number);
                               if (studentinformation.Student_Number!=0 && check_if_student_in_the_system(studentinformation.Student_Number)==true) {
                                   printf("%s", "Enter Student Info    : \n ");
                                   printf("Enter Student name          : \n");
                                   fscanf(stdin, "%s", studentinformation.studentName);
                                   ////////////////////
                                   printf("Enter Your national_number name  : \n");
                                   fscanf(stdin, "%s", studentinformation.national_number);
                                   ////////////////////
                                   printf("Enter Your Department name     : \n");
                                   fscanf(stdin, "%s", studentinformation.Department);
                                   ////////////////////
                                   printf("Entery Your Gender         : \n");
                                   fscanf(stdin, "%s", studentinformation.Gender);
                                   printf("Entery Student DataBase mark        : \n");
                                   fscanf(stdin, "%d", &studentinformation.DB);
                                   printf("Entery Student OperationSystem Mark         : \n");
                                   fscanf(stdin, "%d", &studentinformation.OS);
                                   studentinformation.Student_ID=ID;
//put data into File
                                   fseek(myfile,
                                         (studentinformation.Student_Number - 1) * sizeof(struct StudentInformation),
                                         SEEK_SET);
                                   fwrite(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
                               } else{
                                   printf("Can,t Write student number with 0 ID,s or student already exist !! \n ");
                               }
//                              close the file
                 fclose(myfile);

                              }
                          }
void insertStd(struct StudentInformation studentinformation){
    FILE *DataFile ;
    DataFile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt","a");

    printf("%s", "Enter Student Number \n");
    scanf("%d", &studentinformation.Student_Number);
    printf("%s", "Enter Student Info    : \n ");
    printf("Enter Student name          : \n");
    scanf( "%s", studentinformation.studentName);
    ////////////////////
    printf("Enter Your national_number name  : \n");
    scanf( "%s", studentinformation.national_number);
    ////////////////////
    printf("Enter Your Department name     : \n");
    scanf( "%s", studentinformation.Department);
    ////////////////////
    printf("Entery Your Gender         : \n");
    scanf( "%s", studentinformation.Gender);
    printf("Entery Student DataBase mark        : \n");
    scanf("%d", &studentinformation.DB);
    printf("Entery Student OperationSystem Mark         : \n");
    scanf( "%d", &studentinformation.OS);



    fprintf(DataFile," %-15d %-15s %-15s %-15s %-15s %-15d %-15d \n",studentinformation.Student_Number,studentinformation.studentName,studentinformation.national_number,studentinformation.Department,studentinformation.Gender,studentinformation.DB,studentinformation.OS);

    fclose(DataFile);

}
///**
///TODO:to Read student file include {student name and id / his/her national_number / Department main Gender}
///@param  studentinformation reference into student Record Data in block in file
///
/// **/
void  ReadDataFile(struct StudentInformation studentinformation){
    int result;
    FILE *student_Data_File;
    int student_Data_Arr[currentKey(studentinformation)];
    int Student_indexes_Counter=0;
    FILE *oldFile;
    oldFile=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt","rb+");
    if ((student_Data_File = fopen("ff.txt", "rb+")) == NULL) {
     puts("File Dose,t created Yet ");
            } else {
//        read file from front to end
                printf(" SORTED FILE:   Ascending order : \n");
printf("_________________________________________________________________________________________\n");
printf("|STUDENT NUMBER |STUDENTNAME |NATIONAL_NUMBER |DEPARTMENT_NAME |GENDER | DB_MARK |OSMARK|\n");
                        while (!feof(student_Data_File)) {
                          result = fread(&studentinformation, sizeof(struct StudentInformation), 1, student_Data_File);
                              if (result != 0 && studentinformation.Student_Number != 0) {
                                  student_Data_Arr[Student_indexes_Counter]=studentinformation.Student_Number;
                                  Student_indexes_Counter+=1;
                             printf("|%d             |%s          |%s              |%s              |%s     |%d       |%d    |\n",
                          studentinformation.Student_Number, studentinformation.studentName,
                       studentinformation.national_number, studentinformation.Department,studentinformation.Gender,studentinformation.DB,studentinformation.OS);
                                  printf("_________________________________________________________________________________________\n");
                    }
                  }
//        read file from back to front
        printf(" SORTED FILE:   Unascending order : \n");
        printf("_________________________________________________________________________________________\n");
        printf("|STUDENT NUMBER |STUDENTNAME |NATIONAL_NUMBER |DEPARTMENT_NAME |GENDER | DB_MARK |OSMARK|\n");
        for (int z = Student_indexes_Counter; z>=0; z-- ) {
            Up_To_Down(studentinformation,student_Data_Arr,z);
        }

//     Read old data

        printf(" SORTED FILE:   Ascending order : \n");
        printf("_________________________________________________________________________________________\n");
        printf("|STUDENT NUMBER |STUDENTNAME |NATIONAL_NUMBER |DEPARTMENT_NAME |GENDER | DB_MARK |OSMARK|\n");
        while (!feof(oldFile)) {
            result = fread(&studentinformation, sizeof(struct StudentInformation), 1, oldFile);
            if (result != 0 && studentinformation.Student_Number != 0) {
                printf("|%d             |%s          |%s              |%s              |%s     |%d       |%d    |\n",
                       studentinformation.Student_Number, studentinformation.studentName,
                       studentinformation.national_number, studentinformation.Department,studentinformation.Gender,studentinformation.DB,studentinformation.OS);
                printf("_________________________________________________________________________________________\n");
            }
        }
//        close the file
        fclose(student_Data_File);
        fclose(oldFile);
           }
         }
int  get_index( struct StudentInformation studentinformation,struct  indexing ind, const int input) {
    int result;
    FILE *index;
    int i=0;
   ;
int index_arr[currentKey(studentinformation)/2];
    if ((index = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt","rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
        while (!feof(index)) {
            result = fread(&ind, sizeof(struct indexing), 1, index);
            if (result != 0 && ind.in_dex!=0) {

index_arr[i]=ind.in_dex;
i+=1;

            }
        }


        for (int from = 0; from < (currentKey(studentinformation)/2)+1 ; ++from) {
            if (index_arr[from]<input){
                continue;
            } else if(index_arr[from]>input) {
                printf("%d \n",input);
                return index_arr[from-1];


            } else if (index_arr[from]==input){
                printf("%d \n",input);
                return index_arr[from];

            }
            printf("%d \n",index_arr[from]);

        }
        fclose(index);
    }
}
///**
///
//TODO:to get File Current Index or seeker when exe stop write second exe we could start write from last index written
///@param studentinformation reference into student Record Data in block in file
///
/// **/8
int  currentKey(struct StudentInformation studentinformation){
    int result;
    FILE *myfile;
         if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
              puts("File Dose,t created Yet ");
              } else {

                    while (!feof(myfile)) {
                    result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
                    if (result != 0 && studentinformation.Student_Number!=0 ) {
                    }
                  }
              fclose(myfile);
           }
     return studentinformation.Student_ID;
   }
void  UdateFileItem(struct StudentInformation  studentinformation) {
    FILE *myfile;
    int result;
    struct indexing ind = {0};
    FILE *index;
    index = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt", "rb+");
    printf("Enter Your Number you wont to Updata:");
    int input;
    scanf("%d", &input);
    if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
//        delete the last one
//        deleteStudent(studentinformation,ind,get_id_with_index(studentinformation,input));
//        fseek(myfile, (get_index(studentinformation,ind, get_id_with_index(studentinformation,input)) - 1) * sizeof(struct StudentInformation), SEEK_SET);
//
//        while (!feof(myfile)) {

//            result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
//            if (result!=0 && studentinformation.Student_Number==get_id_with_index(studentinformation,input)) {

                printf("%s", "Enter Student Number \n");
                fscanf(stdin, "%d", &studentinformation.Student_Number);
                printf("%s", "Enter Student Info    : \n ");
                printf("Enter Student name          : \n");
                fscanf(stdin, "%s", studentinformation.studentName);
                ////////////////////
                printf("Enter Your national_number name  : \n");
                fscanf(stdin, "%s", studentinformation.national_number);
                ////////////////////
                printf("Enter Your Department name     : \n");
                fscanf(stdin, "%s", studentinformation.Department);
                ////////////////////
                printf("Entery Your Gender         : \n");
                fscanf(stdin, "%s", studentinformation.Gender);
                printf("Entery Student DataBase mark        : \n");
                fscanf(stdin, "%d", &studentinformation.DB);
                printf("Entery Student OperationSystem Mark         : \n");
                fscanf(stdin, "%d", &studentinformation.OS);

                fseek(myfile, (studentinformation.Student_Number - 1) * sizeof(struct StudentInformation), SEEK_SET);
                fwrite(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
//                close the file
                fclose(index);
                fclose(myfile);

//                break;
//            }
//        }
//        fclose(myfile);
//        fclose(index);
    }
}
void DeleteAllFileContent() {

        FILE *myfile;
        myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "w");

        fprintf(myfile, "%s", "");

        fclose(myfile);

    }
void checkfortextinfile(struct StudentInformation studentinformation) {
        int result;
        FILE *myfile;
        if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {
            while (!feof(myfile)) {
                result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
                if (result != 0 && studentinformation.Student_ID != 0) {
                    DeleteAllFileContent();
                }
            }
            fclose(myfile);
        }
    }
void searchingForstudent(struct StudentInformation studentinformation) {
        int result;
        FILE *myfile;
        struct indexing ind;
        int id;
        FILE *index;

        index = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt", "rb+");
        printf("Enter Student Number that will search with:");
        scanf("%d", &id);
        if ((myfile = fopen("ff.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {
            printf("%-6d||   %16s|| %11s|| %20.20s|||| %20.20s||\n",
                   1, "Student name", "national_number name", "Department name", "Gender");
            fseek(myfile, (get_index(studentinformation,ind, id)) - 1 * sizeof(struct StudentInformation), SEEK_SET);

            while (!feof(myfile)) {
                result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
                if (studentinformation.Student_Number == id) {
                    if (result != 0 && studentinformation.Student_Number != 0) {
                        printf("%-6d||   %16s|| %11s|| %20.20s|||| %20.20s|||| %-6d|| %-6d\n",
                               studentinformation.Student_Number, studentinformation.studentName,
                               studentinformation.national_number, studentinformation.Department,
                               studentinformation.Gender, studentinformation.DB, studentinformation.OS);
                        printf("_________________________________________________________________________________________________ \n");
                    }
                } else {
                }
            }
            fclose(myfile);
        }
    }
void deleteStudent(struct StudentInformation studentinformation, struct indexing index, int deletestudent) {
        FILE *myfile;
        FILE *ind;
        ind = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt", "rb+");
        struct StudentInformation bstd = {0, 0, "", "", "", "", 0, 0};
        struct indexing indexing = {0};
        if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {
//            fseek(myfile, (get_index(indexing, deletestudent) - 1) * sizeof(struct StudentInformation), SEEK_SET);

//            fseek(ind, (get_index(indexing, deletestudent)) * sizeof(struct indexing), SEEK_SET);
//            fread(&indexing, sizeof(struct indexing), 1, ind);

            fseek(myfile, (get_id_with_index(studentinformation,deletestudent) - 1) * sizeof(struct StudentInformation), SEEK_SET);
            fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);

            if (studentinformation.Student_Number == 0) {
                printf("student dose,t exist ");
            } else {
                //// delete it from data file


                    fseek(myfile, (get_id_with_index(studentinformation,deletestudent)-1 ) * sizeof(struct StudentInformation), SEEK_SET);
                    fwrite(&bstd, sizeof(struct StudentInformation), 1, myfile);


                /// delete from index file

//    if (!studentinformation.Student_ID%2==0){
//        fseek(ind, (get_index(indexing, deletestudent)-1) * sizeof(struct indexing), SEEK_SET);
//        fwrite(&indexing, sizeof(struct indexing), 1, ind);
//    }
            }
            fclose(myfile);
            fclose(ind);
        }
    }
void ReadSorted(struct StudentInformation studentinformation, int vv[], int size) {
        int result;
        FILE *myfile;

        FILE *index;

        struct  indexing ind;


        index=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt","rb+");
        int id = 0;
//    printf("Enter Student Number that will search with:");
//    scanf("%d",&id);
        if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {

            while (!feof(myfile)) {
                result = fread(&studentinformation, sizeof(studentinformation), 1, myfile);
                id += 1;
//
//                if (studentinformation.Student_Number){
                if (result != 0 && studentinformation.Student_Number == vv[size]) {
//                    if (studentinformation.Student_ID % 2==0){
//                        printf("can,t write even number ");
//                    } else{
                        ind.in_dex=vv[size];
                        fseek(index, (ind.in_dex - 1) * sizeof(struct indexing), SEEK_SET);
                        fwrite(&ind, sizeof(struct  indexing), 1, index);
//                    }

//                    printf("|%d             |%s          |%s              |%s              |%s     |%d       |%d    |\n",
//                           studentinformation.Student_Number, studentinformation.studentName,
//                           studentinformation.national_number, studentinformation.Department, studentinformation.Gender,
//                           studentinformation.DB, studentinformation.OS);
//                    printf("_________________________________________________________________________________________\n");

                }

//                } else{
//
//
//                }




            }


            fclose(myfile);
            fclose(index);

        }
    }
void ReadLastStudentAdded(struct StudentInformation studentinformation) {
        int result;
        FILE *myfile;


        if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {
            printf("%-6d||   %16s|| %11s|| %20.20s|||| %20.20s||\n",
                   1, "Student name", "national_number name", "Department name", "Gender");
            while (!feof(myfile)) {
                result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
                if (studentinformation.Student_Number == currentKey(studentinformation)) {
                    if (result != 0 && studentinformation.Student_Number != 0) {
                        printf("%-6d||   %16s|| %11s|| %20.20s|||| %20.20s|||| %-6d|| %-6d\n",
                               studentinformation.Student_Number, studentinformation.studentName,
                               studentinformation.national_number, studentinformation.Department,
                               studentinformation.Gender, studentinformation.DB, studentinformation.OS);
                        printf("_________________________________________________________________________________________________ \n");
                    }
                } else {


                }

            }
            fclose(myfile);
        }

    }
void Read_Index_File(struct indexing ind) {
        int result;
        FILE *index;
        if ((index = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt", "rb+")) == NULL) {
            puts("File Dose,t created Yet ");
        } else {
            printf("|INDEX|\n");
            while (!feof(index)) {
                result = fread(&ind, sizeof(struct indexing), 1, index);
                if (result != 0 && ind.in_dex != 0) {
                    printf("|_____|\n");
                    printf("| %d   |\n", ind.in_dex);
                    printf("|_____|\n");
                }
            }
            fclose(index);
        }
    }
void ReadAllFile(struct indexing ind, struct StudentInformation studentinformation) {
        printf("1-DataFile\n2-Index FIle \n");
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1:
                ReadDataFile(studentinformation);
                break;
            case 2:
                printf("INDEXING USING PRIMARY KEY \n");
                Read_Index_File(ind);
                break;
            default:
                printf("invalid choice back to main menu...");

        }
    }
void  Setup_IndexItem(struct StudentInformation studentinformation,int numbof){
    int result;
    FILE *myfile;
    struct  indexing ind;
    FILE *index;

    struct StudentInformation stdInfo[40];



    index=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\index.txt","w");

    int ides[currentKey(studentinformation)];
    int i=0;
    if ((myfile = fopen("ff.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {

//                printf("%-6d||%16s||%11s||%20.20s||%20.20s||%20.20s||%20.20s \n",
//                   0, "Student name","national_number name"
//                     , "Department name","Gender","DB mark","OS mark");
        while (!feof(myfile)) {
            result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
            if (result != 0 && studentinformation.Student_Number != 0) {
                strcpy(stdInfo[i].studentName,studentinformation.studentName);
                stdInfo[i].Student_Number=studentinformation.Student_Number;
                stdInfo[i].Student_Number=studentinformation.Student_Number;
                stdInfo[i].Student_ID=studentinformation.Student_ID;
                strcpy(stdInfo[i].Department,studentinformation.Department);
                strcpy(stdInfo[i].Gender,studentinformation.Gender);
                strcpy(stdInfo[i].national_number,studentinformation.national_number);
                stdInfo[i].OS=studentinformation.OS;
                stdInfo[i].DB=studentinformation.DB;
                ides[i] = studentinformation.Student_Number;
                i += 1;
            }

            for (int z = 0; z <= i; z += numbof) {
//            if (!z%2==0){
                ReadSorted(studentinformation, ides, z);


//            }
            }

//move to show file
            FILE *sf;
            FILE *sIndex;
            sIndex=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\indexShow","w");
            sf=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\testShow","w");
            fprintf(sf,"%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","[Number ]","[Name]","[NN]","[Depa]","[gender]","           [OS]","             [DB]");
            fprintf(sIndex,"%s \n","[INDEXES]");
            for (int from = 0; from <i; ++from) {
                fprintf(sf," %-15d %-15s %-15s %-15s %-15s %-15d %-15d \n",stdInfo[from].Student_Number,stdInfo[from].studentName,stdInfo[from].national_number,stdInfo[from].Department,stdInfo[from].Gender,stdInfo[from].OS,stdInfo[from].DB);
                fprintf(sf,"%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","__________________","__________________","__________________","__________________","________________________________","________________","________________"
                        "");

            }
            for (int k = 0; k < i; k+=2) {
                fprintf(sIndex,"%s","|____");
                fprintf(sIndex,"%d ",stdInfo[k].Student_Number);
                fprintf(sIndex,"%s \n","____|");
            }





            fclose(sf);
            fclose(sIndex);
        }
        fclose(myfile);
    }
}
void  Up_To_Down(struct StudentInformation studentinformation,  int vv[],int size){
    int result;
    FILE *myfile;
    int id = 0;
    if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
//        read the file in backward session
        while (!feof(myfile)) {
            result = fread(&studentinformation, sizeof(studentinformation), 1, myfile);
            id += 1;
            if (result != 0 && studentinformation.Student_Number == vv[size]) {
                printf("|%d             |%s          |%s              |%s              |%s     |%d       |%d    |\n",
                       studentinformation.Student_Number, studentinformation.studentName,
                       studentinformation.national_number, studentinformation.Department,studentinformation.Gender,studentinformation.DB,studentinformation.OS);
                printf("_________________________________________________________________________________________\n");

        }
        }




//        close the file
        fclose(myfile);
    }
}
bool check_if_student_in_the_system(int Student_Number){
    struct StudentInformation studentInformation;
    int result;
    FILE *student_Data_File;
    if ((student_Data_File = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
        while (!feof(student_Data_File)) {
            result = fread(&studentInformation, sizeof(struct StudentInformation), 1, student_Data_File);
            if (result != 0 && studentInformation.Student_Number ==Student_Number) {
                return  false;
            }
        }




        fclose(student_Data_File);
        return true;
    }
}
void  merge_sort(struct StudentInformation studentinformation,int run) {

    FILE *new_sorted_File;

    struct StudentInformation stdInfo[40];
    struct StudentInformation Aside[40];
    struct StudentInformation Bside[40];
    struct StudentInformation Cside[40];



    new_sorted_File = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\smSA1", "rb+");


    int result;
    FILE *student_Data_File;
    int student_Data_Arr[currentKey(studentinformation)];
    int i = 0;
    int newI=0;
    int o = 0;
    int q = 0;
    int mer=0;

    if ((student_Data_File = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
//        read file from front to end
//        while (!feof(student_Data_File)) {
//            fscanf(student_Data_File," %d %s %s %s %s %d %d \n",&stdInfo[i].Student_Number,stdInfo[i].studentName,stdInfo[i].national_number,stdInfo[i].Department,stdInfo[i].Gender,&stdInfo[i].OS,&stdInfo[i].DB);
//            i+=1;
//        }


        while (!feof(student_Data_File)) {
            result = fread(&studentinformation, sizeof(struct StudentInformation), 1, student_Data_File);
            if (result != 0 && studentinformation.Student_Number != 0) {
                strcpy(stdInfo[i].studentName, studentinformation.studentName);
                stdInfo[i].Student_Number = studentinformation.Student_Number;
                stdInfo[i].Student_Number = studentinformation.Student_Number;
                stdInfo[i].Student_ID = studentinformation.Student_ID;
                strcpy(stdInfo[i].Department, studentinformation.Department);
                strcpy(stdInfo[i].Gender, studentinformation.Gender);
                strcpy(stdInfo[i].national_number, studentinformation.national_number);
                stdInfo[i].OS = studentinformation.OS;
                stdInfo[i].DB = studentinformation.DB;
                student_Data_Arr[i] = studentinformation.Student_Number;
                i += 1;
            }
        }
//        Internal_sorting(stdInfo, i);
        struct  StudentInformation temp[i];
        fclose(student_Data_File);
        FILE *files[1];




//        level one
        for (int i1 = 0; i1 <i ; i1+=run) {
if (i1%run==0){
    char snum[64];
    const char* extension = ".txt";
    char* name_with_extension;
    name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
    strcpy(name_with_extension, snum); /* copy name into the new var */
    strcat(name_with_extension, extension); /* add the extension */
    itoa(i1, snum, 10);
    files[i1]=fopen(name_with_extension,"w");
    fclose(files[i1]);

}


}
// level 3
 int cout=(run+2)/2;
printf("%d",cout);
        FILE *newLev[1];
for (int i1 = 0; i1 <i ; i1+=run+run) {
    char snum[5];
    const char* extension = "nl.txt";
    char* name_with_extension;
    name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
    strcpy(name_with_extension, snum); /* copy name into the new var */
    strcat(name_with_extension, extension); /* add the extension */
    itoa(i1, snum, 10);
    newLev[i1]=fopen(name_with_extension,"w");
    fclose(newLev[i1]);
        }


// level 3
        int new_count=(run+2 )/4;
        printf("%d",cout);
        FILE *newLev2[1];
        for (int i1 = 0; i1 <i ; i1+=run+run+run) {

            char snum[5];
            const char* extension = "ll.txt";
            char* name_with_extension;
            name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(name_with_extension, snum); /* copy name into the new var */
            strcat(name_with_extension, extension); /* add the extension */
            itoa(i1, snum, 10);
            newLev2[i1]=fopen(name_with_extension,"w");
            fclose(newLev2[i1]);


        }
// level 4
        FILE *final[1];
        char snum[5];
        const char* extension = "ff.txt";
        char* name_with_extension;
        name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
        strcpy(name_with_extension, snum); /* copy name into the new var */
        strcat(name_with_extension, extension); /* add the extension */
        itoa(1, snum, 10);
        final[1]=fopen(name_with_extension,"w");
        fclose(final[1]);


        // level 1 implementation
        int from;
        for (int p = 0; p < i; p+=run) {
            char snum[5];
            int Run=0;
            int MaxRun=0;
            int MR=3;
            int bg=0;
            struct  StudentInformation temp[i];
            const char* extension = ".txt";
            char* name_with_extension;
            name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(name_with_extension, snum); /* copy name into the new var */
            strcat(name_with_extension, extension); /* add the extension */
            itoa(p, snum, 10);
            for (from=p; from <run+p; from++) {
                if (from<=i-1){
                    write_in_merge_files_to_Be_sorted(studentinformation,name_with_extension,stdInfo[from].Student_Number);
                }

            }
        }



// level 2 implementation
        int new_reun=run+run;
        for (int p = 0; p < i; p+=new_reun) {
            char snum[5];
            int Run=0;
            int MaxRun=0;
            int MR=3;
            int bg=0;
            const char* extension = "nl.txt";
            char* name_with_extension;
            name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(name_with_extension, snum); /* copy name into the new var */
            strcat(name_with_extension, extension); /* add the extension */
            itoa(p, snum, 10);
            for (from=p; from <run+run+p; from++) {
                if (from<=i-1){
                    write_in_merge_files_to_Be_sorted(studentinformation,name_with_extension,stdInfo[from].Student_Number);
                }

            }

        }


//level 3 implementation
        int new_reun2=run+run+run;
        for (int p = 0; p < i; p+=new_reun2) {
            char snum[5];
            const char* extension = "ll.txt";
            char* name_with_extension;
            name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(name_with_extension, snum); /* copy name into the new var */
            strcat(name_with_extension, extension); /* add the extension */
            itoa(p, snum, 10);

            for (from=p; from <run+run+run+p; from++) {
                if (from<=i-1){
                    write_in_merge_files_to_Be_sorted(studentinformation,name_with_extension,stdInfo[from].Student_Number);
                }

            }

        }

// level 4 implementation
        for (int p = 0; p < i; p+=i) {
            char snum[5];
            const char* extension = "ff.txt";
            char* name_with_extension;
            name_with_extension = malloc(strlen(snum)+1+4); /* make space for the new string (should check the return value ...) */
            strcpy(name_with_extension, snum); /* copy name into the new var */
            strcat(name_with_extension, extension); /* add the extension */
            itoa(p, snum, 10);
            for (from=p; from <i; from++) {
                if (from<=i-1){
                    write_in_merge_files_to_Be_sorted(studentinformation,name_with_extension,stdInfo[from].Student_Number);
                }

            }
        }

}
    }
void  Internal_sorting(struct StudentInformation studentinformation[],int counter){
        for(int i=0 ; i<counter-1 ; i++){
        for(int from= i+1 ; from<counter ;from++){


            int id1 ,id2;
            id1 = studentinformation[i].Student_Number;
            id2 = studentinformation[from].Student_Number;
            if (id1>id2){
                struct StudentInformation temp = studentinformation[i];
                studentinformation[i] = studentinformation[from];
                studentinformation[from] = temp;
            }
        }
    }
}
void  write_in_merge_files_to_Be_sorted(struct StudentInformation studentinformation,char *file, int from){
    FILE *mainfile;
    mainfile=fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt","rb+");
    FILE *newFile=fopen(file,"rb+");

    while (!feof(mainfile)){
        fread(&studentinformation, sizeof(studentinformation), 1, mainfile);
if (studentinformation.Student_Number==from){
    fseek(newFile,    (studentinformation.Student_Number-1) * sizeof(struct StudentInformation),    SEEK_SET);
    fwrite(&studentinformation, sizeof(struct StudentInformation), 1, newFile);
}
    }
    fclose(newFile);
    fclose(mainfile);
}
int  get_id_with_index(struct StudentInformation studentinformation,int index){
    int result;
    FILE *myfile;
    if ((myfile = fopen("C:\\Users\\mohamed\\CLionProjects\\untitled8\\test.txt", "rb+")) == NULL) {
        puts("File Dose,t created Yet ");
    } else {
        while (!feof(myfile)) {
            result = fread(&studentinformation, sizeof(struct StudentInformation), 1, myfile);
            if (studentinformation.Student_Number == index) {
                if (result != 0 && studentinformation.Student_Number != 0) {
                    return  studentinformation.Student_ID;
                }
            } else {
            }

        }
        fclose(myfile);

    }
}