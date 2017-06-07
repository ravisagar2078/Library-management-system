#include"Student.h"
#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
int main();
int Student::return_code1()//it return the code of last student 
       {
            int c=0;
            ifstream obj("Student.txt");
            if(!obj)
                 {
                     return 0;
                 }
            while(!obj.eof())
                {
                  obj>>code>>name>>age>>address;
                 
                     c=code;
                }
            obj.close();
            return c;
       }
   void Student::add_Student()//for add students details
       {
            ofstream obj;
            code=return_code1()+1;
            obj.open("Student.txt",ios::app);
            if(!obj)
                {
                     cout<<"File opening error";
                     return;
                }
     cout<<" \nCode Of Student Is        : "<<code;
          cout<<" \nEnter Student Name        : ";
            cin>>name;
            cout<<" \nEnter Student Age         : ";
            cin>>age;
                         cout<<" \nEnter Address Of Student  : ";
            cin>>address;
            obj<<code<<" "<<name<<" "<<age<<" "<<address<<endl;
           
            obj.close();
}
   void Student::list_Student()//it display  the details of students
       {
             ifstream obj;
            obj.open("Student.txt");
            if(!obj)
                {
                    cout<<"File opening error";
                    return;
                }
            obj.seekg(0);
            while(!obj.eof())
                {
      obj>>code>>name>>age>>address;
                   
                    if(obj.eof())
                    break;
                  cout<<"\nStudent Code:";
                    cout<<code;
                    cout<<"\nStudent Name:";
                    cout<<name;
                    cout<<"\nStudent Address:";
                    cout<<address;
                    cout<<"\nStudent Age:";
                    cout<<age<<endl;
                 
                }
            obj.close();
            getch();
       }
   void Student::search_Student()//it display the specific student detail
       {
           int code1,f;
            cout<<"Enter the code of the Student:";
            cin>>code1;
            ifstream obj;
            obj.open("Student.txt");
            if(!obj)
                {                      
                cout<<"File opening error.....";
                   return;
                }
            obj.seekg(0);
            while(!obj.eof())
                {
                             obj>>code>>name>>age>>address;

                     if(code1==code)
                          {
                               f=1;
                                       cout<<"\nStudent Code         : ";
                               cout<<code;
                               cout<<"\nStudent Name         : ";
                               cout<<name;
                               cout<<"\nStudent Address     : ";
                               cout<<address;
                                 cout<<"\nStudent Age         : ";
                               cout<<age<<endl;
                                break;
                          }
                }
             if(f==0)
                {
                   cout<<"No Student exists with code "<<code1;
                      getch();
                }
             obj.close();
       }
   void Student::delete_Student()//it delete the specific student
       {
       int code2,f=0;
            ifstream obj("Student.txt");
            ofstream obj1("temp.txt");
            if(!obj)
                 {
                      cout<<"File opening error";
                      return;
                 }
            if(!obj1)
                 {
                      cout<<"File opening error";
                      return;
                 }
                              cout<<"Enter the code of Student:";
            cin>>code2;
            obj.seekg(0);
            while(!obj.eof())
                {
                             obj>>code>>name>>age>>address;
               
                      if (obj.eof())
                      break;
                      if(code2!=code)
                       obj1<<code<<" "<<name<<" "<<age<<" "<<address<<endl;
               
                      else
                          {
                           f=1;
                cout<<"Student deleted";
                           getch();
                           continue;
                          }
                }
            if(f==0)
               {
                   cout<<"Student code not found....";
                   getch();
               }
            obj.close();
            obj1.close();
            remove("Student.txt");
            rename("temp.txt","student.txt");
       }
   void Student::update_Student()//it update specific student details 
       {
       
            int f=0;
            ifstream obj("Student.txt");
            ofstream obj1("temp.txt");
            if(!obj)
                 {
                      cout<<"File opening error";
                      return;
                 }
            if(!obj1)
                 {
                      cout<<"File opening error";
                      return;
                 }
            int code2;
          cout<<"Enter the code of Student:";
            cin>>code2;
            obj.seekg(0);
            while(!obj.eof())
                {
                      obj>>code>>name>>age>>address;
               
                      if(obj.eof())
                      break;

                     if(code2==code)
                       {
                           f=1;
                           cout<<"\nEnter the new name of Student:";
                           cin>>name;
                             cout<<"\nEnter code:";
                           cin>>code;
                         cout<<"\nEnter address:";
                           cin>>address;
                              cout<<"\nEnter age:";
                           cin>>age;
                            obj1<<code<<" "<<name<<" "<<age<<" "<<address<<endl;
                           
                       }
                     else
                      obj1<<code<<" "<<name<<" "<<age<<" "<<address<<endl;
                         
                }

            if(f==0)
               {
                      cout<<"Student code not found....";
                   getch();
               }

           obj.close();
           obj1.close();
           remove("Student.txt");
           rename("temp.txt","student.txt");
 }
  void Student::Students()
        {
             int choice,choice1;
             do
                 {
                     int d,m;
                   cout<<"1.      Add Record\n";
                   cout<<"2.      Delete Record\n";
                   cout<<"3.      Search Record\n";
                   cout<<"4.      Update Record\n";
                   cout<<"5.      List Record\n";
                   cout<<"6.      Return To Main Menu\n";
                   cout<<"7.      Exit Program\n";
                   cout<<"ENTER YOUR CHOICE    : ";
                   cin>>choice;
                   switch(choice)
                          {
                               case 1:
                                   add_Student();
                               break;
                               case 2:
                                   delete_Student();
                               break;
                               case 3:
                                   search_Student();
                               break;
                               case 4:
                                   update_Student();
                               break;
                               case 5:
                                    list_Student();
                               break;
                               case 6:
                                     main();
                               case 7:
                                     exit(0);
                               break;
                     }
                     }
                                while(choice1!=6);
       }
