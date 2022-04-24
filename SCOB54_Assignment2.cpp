//================================Name:-VAIBHAV SAWANT **** Roll no:-SCOB54==========================================//
/*
Problem statement :-Department maintains a student information. The file contains roll number, name, 
           division and address. Allow user to add, delete information of student. Display 
           information of particular employee. If record of student does not exist an appropriate 
           message is displayed. If it is, then the system displays the student details. Use sequential 
           file to main the data.*/
#include <iostream>        // standard input-output stream.
#include<fstream>          // fstream header file for ifstream, ofstream,fstream classes
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX=20;
class Student
{
 int rollno;
 char name[20],address[20];
 char div;
 int year;
public:
 Student()
{
  strcpy(name,"");
  strcpy(address,"");
  rollno=year=div=0;
}
 Student(int rollno,char name[MAX],int year,char div,char address[MAX])
 {
  strcpy(this->name,name);
  strcpy(this->address,address);
  this->rollno=rollno;
  this->year=year;
  this->div=div;
 }
 int getRollNo()
 {
  return rollno;
 }
 void displayRecord()
 {

  cout<<endl<<setw(5)<<rollno<<setw(20)<<name<<setw(5)<<year<<setw(5)<<div<<setw(10)<<address;
 }
};
//==========**************File Operations *****************===========//
class FileOperations
{
 fstream file;
public:
 FileOperations(char* filename)
{
file.open(filename,ios::in|ios::out|ios::ate|ios::binary); //member constants in,out,atend,append
}
 void insertRecord(int rollno, char name[MAX],int year, char div,char address[MAX])
 {
  Student s1(rollno,name,year,div,address);
  file.seekp(0,ios::end);
  file.write((char *)&s1,sizeof(Student));
  file.clear();
 }
 void displayAll()
 {
  Student s1;
  file.seekg(0,ios::beg);
  while(file.read((char *)&s1, sizeof(Student)))   // typecasting:- the conversion of one data type to another in a program.
  {
   s1.displayRecord();
  }
  file.clear();
 }
 void displayRecord(int rollNo)
 {
  Student s1;
  file.seekg(0,ios::beg);
  bool flag=false;
  while(file.read((char*)&s1,sizeof(Student)))
  {
   if(s1.getRollNo()==rollNo)
   {
    s1.displayRecord();
    flag=true;
    break;
   }
  }
  if(flag==false)
  {
   cout<<"\nRecord of "<<rollNo<<"is not present.";
  }
  file.clear();
 }
 void deleteRecord(int rollno)  //to delete a record from a file is to copy the file 
                                //to another temporary file and then copy the records to the same file again by skipping the record that u need to delete
 {
  ofstream outFile("new.dat",ios::binary);
  file.seekg(0,ios::beg);
  bool flag=false;
  Student s1;

  while(file.read((char *)&s1, sizeof(Student)))
  {
   if(s1.getRollNo()==rollno)
   {
    flag=true;
    continue;
   }
   outFile.write((char *)&s1, sizeof(Student));
  }
  if(!flag)
  {
   cout<<"\nRecord of "<<rollno<<" is not present.";
  }
  file.close();
  outFile.close();
  remove("student.dat");
  rename("new.dat","student.dat");
  file.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
 }
 ~FileOperations()
 {
  file.close();
  cout<<"\nFile Closed.";
 }
};
int main() {
 ofstream newFile("student.dat",ios::app|ios::binary);
  newFile.close();
  FileOperations file((char*)"student.dat");
     int rollNo,year,choice=0;
     char div;
     char name[MAX],address[MAX];
     while(choice!=5)
     {
         //clrscr();
         cout<<"\n*****Student Database*****\n";
         cout<<"1) Add New Record\n";
         cout<<"2) Display All Records\n";
         cout<<"3) Display by RollNo\n";
         cout<<"4) Deleting a Record\n";
         cout<<"5) Exit\n";
         cout<<"Choose your choice : ";
         cin>>choice;
         switch(choice)
         {
             case 1 : //New Record
               cout<<endl<<"Enter RollNo :\n";
               cin>>rollNo;
               cout<<endl<<"Enter your Name :\n";
               cin>>name ;
               cout<<endl<<"Enter Year :\n";
               cin>>year;
               cout<<endl<<"Enter your Division  : \n";
               cin>>div;
               cout<<endl<<"Enter address :\n";
               cin>>address;
               file.insertRecord(rollNo,name,year,div,address);
               cout<<"\nRecord Inserted.";
               break;
             case 2 :
              cout<<endl<<setw(5)<<"ROLL"<<setw(20)<<"NAME"<<setw(5)<<"YEAR"<<setw(5)<<"DIV"<<setw(10)<<"address";
               file.displayAll();
               break;
             case 3 :
               cout<<"Enter Roll Number :-";
               cin>>rollNo;
                file.displayRecord(rollNo);

               break;
             case 4:
               cout<<"Enter rollNo :-";
               cin>>rollNo;
               file.deleteRecord(rollNo);
               break;
            case 5 :break;
         }

     }

 return 0;
}           
