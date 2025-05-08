/*
  Implementation of a direct access file -Insertion and deletion of a record
from a direct access file
*/




#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Student{
public:
  int roll_no,div;
  char name[20],address[30];

  Student(){
    roll_no=0;
    div=0;
    strcpy(name,"");
    strcpy(address,"");
  }
  void getdata(){
     cout<<"Enter roll no: ";
     cin>>roll_no;
     cout<<"Enter name: ";
     cin.ignore();
     cin.getline(name,20);
     cout<<"Enter division: ";
     cin>>div;
     cout<<"Address: ";
     cin.ignore();
     cin.getline(address,30);
  }

  void display(){
    cout<<"\n---------------------------------------"<<endl;
    cout<<"Roll No: "<<roll_no<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Division: "<<div<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"---------------------------------------"<<endl;
  }
  void insertRecord(){
      fstream file("students.dat",ios::in| ios::out | ios::binary);
      if(!file){
         file.open("students.dat", ios::out | ios::binary);
         file.close();
         file.open("students.dat",ios::in| ios::out | ios::binary);
      }
      Student s;
      s.getdata();
    
      int pos=(s.roll_no-1)*sizeof(Student);
      file.seekp(pos,ios::beg);
      file.write((char*)&s,sizeof(Student));
      cout<<"Record written successfully"<<endl;
      file.close();


  }

  void searchRecord(){
       fstream file("students.dat",ios::binary|ios::in);
       if(!file){
        cout<<"File not found"<<endl;
        return ;
       }
       Student s;
    //    bool found=false;
       cout<<"Enter Roll No to Display it's Details: ";
       int searchRoll;
       cin>>searchRoll;

       int pos=(searchRoll-1)*sizeof(Student);
       file.seekg(pos,ios::beg);
       file.read((char*)&s,sizeof(Student));

       if(s.roll_no==searchRoll && s.roll_no!=0){
        //    found=true;
           s.display();
           

       }
       else{
        cout<<"Record not found"<<endl;
       }

    //    if(!found){
    //     cout<<"Record with roll no "<<searchRoll<<" not found"<<endl;
    //    }
       file.close();



  }

  void deleteRecord(){
    fstream file("students.dat",ios::binary|ios::in|ios::out);
       if(!file){
        cout<<"File not found"<<endl;
        return ;
       }
       Student s;
       bool found=false;
       cout<<"Enter Roll No to delete it's Record: ";
       int searchRoll;
       cin>>searchRoll;

       int pos=(searchRoll-1)*sizeof(Student);
       file.seekg(pos,ios::beg);
       file.read((char*)&s,sizeof(Student));

       if(s.roll_no==searchRoll && s.roll_no!=0){
           found=true;
           Student s2;
           file.seekp(pos,ios::beg);
           file.write((char*)&s2,sizeof(Student));
           cout<<"Record deleted successfully"<<endl;

       }
       else{
        cout<<"Record not found"<<endl;
       }

       
       file.close();
  }

};


int main(){
    Student s1;
       for(int i=0;i<30;i++){
         cout<<"\n----------------- Student Information System ----------------------"<<endl;
         cout<<"1.insert\n2.Search\n3.delete\n4.Exit"<<endl;
         int ch;
         cout<<"\nEnter your Choice: ";
         cin>>ch;
    
         if(ch==1){
              s1.insertRecord();
         }
         if(ch==2){
              s1.searchRecord();
         }
         if(ch==3){
    
           s1.deleteRecord();
        }
        if(ch==4){
            break;
        }
    
    
    
       }
    
    


    return 0;
}









