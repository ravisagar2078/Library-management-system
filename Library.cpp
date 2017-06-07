#include<iostream>
#include"Employee.h"
#include"Student.h"
#include"IssueReturn.h"
#include"Book.h"
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int main();
int main()
{
    system("color f6");
int choice;
            cout<<"Welcome to Library\n";
            cout<<"Select your choice\n";
                       cout<<"1.          Book Menu\n";
                       cout<<"2.          Employee Menu\n";
                       cout<<"3.          Student Menu\n";
                       cout<<"4.          Issue And Return\n";
                       cout<<"5.          Exit Program\n";
                       cout<<"ENTER YOUR CHOICE    : \n";
                       cin>>choice;
                              if(choice==1)
                                  {
                                  Book b;
                                  b.books();
                                  }
                                 else if(choice==2)
                                 {
                                 Employee e;
                                 e.employees();
                                 }
                                 else if(choice==3)
                                 {
                                 Student s;
                                 s.Students();
                                 }
                                else if(choice==4)
                                {
                                 IssueReturn rs;
                                 rs.transaction();
                                 }
                                 else if(choice==5)
                                 {
                                      exit(0);
                                      }
                               else
                               {
                                   cout<<"Wrong choice\n";
                      }
              system("pause");
}
