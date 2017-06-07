#include"Book.h"
#include<fstream>
#include<iostream>
#include<conio.h>
int main();
using namespace std;
   int Book::return_code()// it returns the code which is read from file 
       {
            int c=0;
            ifstream obj("Book.txt");
            if(!obj)
                 {
                     return 0;
                 }
            while(!obj.eof())
                {
                             obj>>code>>title>>num_of_copies;
           
                     c=code;
                }
            obj.close();
            return c;
       }
   void Book::add_book()//for add books
       {
       ofstream obj;
            code=return_code()+1;
            obj.open("Book.txt",ios::app);
            if(!obj)
                {
                     cout<<"File opening error";
                     return;
                }
            cout<<"\nCode of book is             : "<<code;
             cout<<"\nEnter title of book         : ";
            cin>>title;
        //    cout<<"\nEnter price of book         : ";
          //  cin>>price;
             cout<<"\nEnter the number of copies  : ";
            cin>>num_of_copies;
            obj<<code<<" "<<title<<" "<<num_of_copies<<endl;
           
            obj.close();
           }
   void Book::list_book()//for display the record of books
       {
            ifstream obj;
            obj.open("Book.txt");
            if(!obj)
                {
                    cout<<"File opening error";
                    return;
                }
            obj.seekg(0);
            while( !obj.eof())
                {
                              obj>>code>>title>>num_of_copies;
                              if(obj.eof())
                              break;
                              
                  cout<<"\nBook Code:";
                    cout<<code;
                    cout<<"\nBook Title:";
                      cout<<title;
                 //  cout<<"\nBook Price:";
                   //     cout<<price;
                    cout<<"\nNumber Of Copies:";
                       cout<<num_of_copies<<endl<<endl;
                   
                }
            obj.close();
            getch();
      }
   void Book::search_book()//function is used for searching books
       {
            int code1,f=0;
 cout<<"\n Enter the code of the book that you wanted to search:";
            cin>>code1;
            ifstream obj;
            obj.open("Book.txt");
            if(!obj)
                {
                   cout<<"\nfile opening error.....";
                   return;
                }
            obj.seekg(0);
            while(!obj.eof())
                {
                             obj>>code>>title>>num_of_copies;
           
                     if(code1==code)
                          {
                               f=1;
                               cout<<"\n\t\t\t Book code        : ";
                               cout<<code;
                               cout<<"\n\t\t\t Book title       : ";
                               cout<<title;
                          //     cout<<"\n\t\t\t Book price       : ";
                         //      cout<<price;
                               cout<<"\n\t\t\t Number of copies : ";
                               cout<<num_of_copies;
                               getch();
                               break;
                          }
                }
             if(f==0)
                 {
                      cout<<"\n\t\t\tNo book exists with code "<<code1;
                      getch();
                 }
             obj.close();
     }
   void Book::delete_book()//delete the specific book
       {
       int code2,f=0;
            ifstream obj("Book.txt");
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
                              cout<<"Enter the code of book:";
            cin>>code2;
            obj.seekg(0);
            while(!obj.eof())
                {
                             obj>>code>>title>>num_of_copies;
               
                      if (obj.eof())
                      break;
                      if(code2!=code)
                      obj1<<code<<" "<<title<<" "<<num_of_copies<<endl;
                     
                      else
                          {
                           f=1;
         cout<<"Book deleted";
                           continue;
                          }
                }
            if(f==0)
                {
                      cout<<"\n\t\t\t\tBook code not found....";
                      getch();
                }
            obj.close();
            obj1.close();
            remove("Book.txt");
            rename("temp.txt","Book.txt");
       }
   void Book::update_book()//function for editing the book details
       {
            int f=0;
            ifstream obj("Book.txt");
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
          cout<<"\n Enter the code of book that you wanted to update:";
            cin>>code2;
            obj.seekg(0);
            while(!obj.eof())
                {
                             obj>>code>>title>>num_of_copies;
               
                      if(obj.eof())
                      break;

                      if(code2==code)
                       {
                           f=1;
                         cout<<"\nEnter the title of book        : ";
                           cin>>title;
              //    cout<<"\nEnter price of the book        : ";
                  //         cin>>price;
                               cout<<"\nEnter number of copies of book : ";
                           cin>>num_of_copies;
                          obj1<<code<<" "<<title<<" "<<num_of_copies<<endl;
                           
                       }
                     else
                     obj1<<code<<" ";
                      obj1<<title<<" ";
                  //    obj1<<price<<" ";
                      obj1<<num_of_copies<<endl;
                     
                }
             if(f==0)
               {
                cout<<"\n\t\t\tBook code not found....";
                  getch();
               }
             obj.close();
             obj1.close();
             remove("Book.txt");
             rename("temp.txt","Book.txt");
       }
 void Book::books()
        {
             int choice;
             do
                 {
                      cout<<"1.     Add Record\n";
                      cout<<"2.      Delete Record\n";
                      cout<<"3.      Search Record\n";
                      cout<<"4.      Update Record\n";
                      cout<<"5.      List Record\n";
                      cout<<"6.      Return To Main Menu\n";
                      cout<<"7.      Exit Program\n";
                      cout<<"ENTER YOUR CHOICE        : ";
                      cin>>choice;
                      switch(choice)
                          {
                               case 1:
                                    add_book();
                               break;
                               case 2:
                                    delete_book();
                               break;
                               case 3:
                                    search_book();
                               break;
                               case 4:
                                     update_book();
                               break;
                               case 5:
                                      list_book();
                               break;
                               case 6:
                                      main();
                               case 7:
                                      exit(0);
                               break;

                          }
                 }
                                while(choice!=6);
             }
