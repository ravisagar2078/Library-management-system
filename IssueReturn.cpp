#include<fstream>
#include<iostream>
#include<conio.h>
#include"IssueReturn.h"
#include"Student.h"
#include"Book.h"
int main();
using namespace std;
void IssueReturn::issue_book()//function use for issuing books 
       {
          Student mem;
          Date d;
          int f=0;
          Book o;
          int cd,cd1;
          ifstream obj;
          obj.open("Student.txt");
          if(!obj)
               {
                     cout<<"File opening error";
                     return;
               }
          cout<<"Enter Student code:";
          cin>>cd;
          obj.seekg(0);
          while(!obj.eof())
               {
                           obj>>mem.code>>mem.name>>mem.age>>mem.address;
               
                     if(obj.eof())
                     break;
                     if(cd==mem.ret_code())
                          {
                            f=1;
                            break;
                          }
               }
           obj.close();
           if(f==0)
               {
                   cout<<"\nStudent code not found.....";
                   getch();
                   return;
               }

           f=0;
           obj.open("Book.txt");
           if(!obj)
               {
                     cout<<"File opening error";
                     return;
               }
           cout<<"Enter book code:";
           cin>>cd1;
           obj.seekg(0);
           while(!obj.eof())
               {
                            obj>>o.code>>o.title>>o.price>>o.num_of_copies;
             
               if(obj.eof())
               break;
               if(cd1==o.ret_bcode())
                   {
                       if(o.ret_copies()>0)
                           {
                               f=1;
                               cout<<"Book issued.....\nEntere date :";
                               status='I';
                           
                              cin>>id.dd >>id.mm>> id.yy;
                             
                               cout<<"Issue date is : "<<id.dd<<"/"<<id.mm<<"/"<<id.yy;
                               getch();
                           }
                   }
               }
           obj.close();
           if(f==0)
               {
                   cout<<"Book not available....";
                   getch();
                   return;
               }
           Book n;
           obj.open("Book.txt");
           ofstream obj1("temp.txt");
           obj.seekg(0);
           while(!obj.eof())
               {
                            obj>>n.code>>n.title>>n.price>>n.num_of_copies;
               if(obj.eof())
               break;
               if(cd1==n.ret_bcode())
               n.reduce_copies();
              obj1<<n.code<<" "<<n.title<<" "<<n.price<<" "<<n.num_of_copies<<endl;
               
              }
           obj.close();
           obj1.close();
           remove("Book.txt");
           rename("temp.txt","Book.txt");
           m_code=cd;
           b_code=cd1;
           ofstream obj2("Issue.txt",ios::app);
           if(!obj2)
           {
           cout<<"file opening error....";
           getch();
           return;
           }
           obj2<<m_code <<" "<<b_code<<endl;

           obj2.close();
    }
   void IssueReturn::list_book()//function display the details of issued students
       {
            ifstream obj;
            obj.open("Issue.txt");
            if(!obj)
                {
                    cout<<"File opening error";
                    return;
                }
            obj.seekg(0);
            while(!obj.eof())
                {obj>>m_code;
                obj>>b_code;
                                                           
                      if(obj.eof())
                      break;                                                
                 cout<<"\nStudent code:";
                    cout<<m_code;
                    cout<<"\nBook code:";
                    cout<<b_code;
                      cout<<"\nDate:";
                     cout<<id.dd<<"/"<<id.mm<<"/"<<id.yy;
                       cout<<"Status:";
              cout<<status;
                   }
            getch();
            obj.close();
       }
   void IssueReturn::return_book()//for return book
       {
        int d1,m;
        Date d;
          int f=0;
          int cd,cd1;
          ifstream obj;
          obj.open("Issue.txt");
          if(!obj)
               {
                     cout<<"File opening error";
                     return;
               }
          cout<<"\nEnter Student code:";
          cin>>cd;
           cout<<"\nEnter book code:";
          cin>>cd1;
          obj.seekg(0);
          while(!obj.eof())
               {
                           obj>>m_code;
                           obj>>b_code;
                     
                     if(obj.eof())
                     break;
                     if(cd==m_code&&cd1==b_code)
                          {
                              f=1;
                              break;
                          }
               }
           obj.close();
           if(f==0)
               {
                  cout<<"Student code not found.....";
                   getch();
                   return;
               }
 cin>>id.dd>>id.mm>>id.yy;  
         cout<<"Book returned.....";
             cout<<"Return date is:"<<id.dd<<"/"<<id.mm<<"/"<<id.yy;
               getch();
           Book n;
           obj.open("Book.txt");
           ofstream obj1("temp.txt");
           obj.seekg(0);
           while(!obj.eof())
               {
                    obj>>n.code>>n.title>>n.price>>n.num_of_copies;        
               obj.read((char*)&n,sizeof(Book));
               if(obj.eof())
               break;

               if(cd1==n.ret_bcode())
               n.increase_copies();
obj1<<n.code<<" "<<n.title<<" "<<n.price<<" "<<n.num_of_copies<<endl;
           
              }
           obj.close();
           obj1.close();
           remove("Book.txt");
           rename("temp.txt","Book.txt");
           ifstream obj3;
           obj3.open("Issue.txt");
           obj1.open("temp.txt");
           obj3.seekg(0);
           while(!obj.eof())
               {
               obj3.read((char*)this,sizeof(IssueReturn));
               if(obj3.eof())
               break;

               if(cd==m_code&&cd1==b_code)
                    status='R';
obj1<<cd <<" "<<cd1<<endl;

              }
           obj3.close();
           obj1.close();
           remove("Issue.txt");
           rename("temp.txt","Issue.txt");
       }
       void IssueReturn::transaction()
        {
             int choice;
             do
                 {              
                      cout<<"1.    \n  Issue Book\n";
                      cout<<"2.      Return Book\n";
                      cout<<"3.      List Book\n";
                      cout<<"4.      Return To Main Menu\n";
                      cout<<"5.      Exit Program\n";
                      cout<<"ENTER YOUR CHOICE    : ";
                      cin>>choice;
                      switch(choice)
                          {
                               case 1:
                                        issue_book();
                               break;
                               case 2:
                                        return_book();
                               break;
                               case 3:
                                         list_book();
                               break;
                               case 4:
                                        main();
                               case 5:
                                        exit(0);
                               break;
                          }
                 }while(choice!=4);
}
