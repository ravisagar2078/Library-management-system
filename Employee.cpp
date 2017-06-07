#include"Employee.h"
#include<fstream>
#include<iostream>
#include<conio.h>
#include"Employee.h"
int main();
using namespace std;

int Employee::return_code2()//it return the code of employee from file
{
        					 int c=0;
        					 ifstream obj("Employee.txt");
        					 if(!obj)
           					 {
                 			 return 0;
           					 }
        					 while(!obj.eof()){
                         	 				   obj>>code>>name>>age>>address;
                 			 				   c=code;
           									   }
        									   obj.close();
        									   return c;
       										   }
void Employee::add_employee()//for add employees details
{
              				  ofstream obj;
        					  code=return_code2()+1;
        					  obj.open("Employee.txt",ios::app);
        					  if(!obj)
           					  {
                 			  cout<<"File opening error";
                 			  return;
           					  }
               				  cout<<"Code of employee is         : "<<code;
            				  cout<<"\nEnter Enter Name of Employee       : ";
        					  cin>>name;
       						  cout<<"\nEnter Age of Employee       : ";
        					  cin>>age;
         					  cout<<"\nEnter Address of Employee   : ";
        					  cin>>address;
        					  obj<<code<<" ";
        					  obj<<name<<" ";
        					  obj<<age<<" ";
        					  obj<<address<<endl;
        					  obj.close();
							  }
void Employee::list_employee()// for display the details of employee
{
        					   ifstream obj;
        					   obj.open("Employee.txt");
        					   if(!obj)
            				   {
                 			   cout<<"File opening error";
                 			   return;
								}
        						obj.seekg(0);
        						while(!obj.eof()){
                         						  obj>>code>>name>>age>>address;
                 								  if(obj.eof())
                 								  break;
        										  cout<<"\nEmployee Code: ";
          										  cout<<code;
           								   		  cout<<"\nEmployee Name: ";
              									  cout<<name;
                    							  cout<<"\nEmployee Address: ";
                 								  cout<<address;
              									  cout<<"\nEmployee Age: ";
                   								  cout<<age<<endl;
													 }
  											 		 obj.close();
							 }
void Employee::search_employee()//search the specific empolyee detail
{
   	 							 int code1,f=0;
         						 cout<<"\n Enter the code of the employee  : ";
        						 cin>>code1;
        						 ifstream obj;
        						 obj.open("Employee.txt");
        						 if(!obj){
                  				 cout<<"File opening error.....";
               					 return;}
								 
								 obj.seekg(0);
        						 while(!obj.eof()){
								 obj>>code>>name>>age>>address;
               					 if(code1==code){
                       			 f=1;
                                 cout<<"\nEmployee Code    : ";
                       			 cout<<code;
           						 cout<<name;
                    			 cout<<"\nEmployee Age        : ";
                       			 cout<<age;
                           		 cout<<"\nEmployee Address : ";
                       			 cout<<address<<endl;
                         		 break;
                     			 }}
        						 if(f==0){
        						 cout<<"No employee exists with code : "<<code1;
       							 }
								 obj.close();
       							 }
void Employee::delete_employee()//for delete the specfic employee
{
	 							 int code2,f=0;
        						 ifstream obj("Employee.txt");
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
     							  cout<<"Enter the code of employee:";
        						  cin>>code2;
        						  obj.seekg(0);
        						  while(!obj.eof()){
                 				  obj>>code>>name>>age>>address;
			                      
								  if (obj.eof())
                  				  break;
                  				  if(code2!=code)
                 				  obj1<<code<<" "<<name<<" "<<age<<" "<<address<<endl;
							   	  else
                  				  {
                   				  f=1;
                         		  cout<<"Employee deleted";
                   				  continue;
                  				  }
            					  }
        						  if(f==0)
           						  {
            					  cout<<"Employee code not found....";
               					  getch();
           						  }
        						  obj.close();
        						  obj1.close();
        						  remove("Employee.txt");
   						 		  rename("temp.txt","employee.txt");
      							  }
void Employee::update_employee()//for editing the details for specfic employee
{
	 							 int f=0;
       							 ifstream obj("Employee.txt");
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
       							 cout<<"Enter the code of employee:";
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
                     			 cout<<"\nEnter the new name of employee:";
                   				 cin>>name;
                  				 cout<<"\nEnter code:";
                   				 cin>>code;
                       			 cout<<" \nEnter new age:";
                   				 cin>>age;
                    			 cout<<"\nEnter address:";
                   				 cin>>address;
                   				 obj1<<name<<" "<<code<<" "<<age<<" "<<address<<endl;
									}
            						else
                					obj1<<name<<" "<<code<<" "<<age<<" "<<address<<endl;
									}
       								if(f==0)
          							{
       							 	cout<<"Employee code not found....";
       								}

       								obj.close();
       								obj1.close();
       								remove("Employee.txt");
       								rename("temp.txt","Employee.txt");
        							}
 void Employee::employees()
        {
             int choice,choice1;
             do
                 {
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
                                      add_employee();
                               break;
                               case 2:
                                      delete_employee();
                               break;
                               case 3:
                                       search_employee();
                               break;
                               case 4:
                                       update_employee();
                               break;
                               case 5:
                                       list_employee();
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
