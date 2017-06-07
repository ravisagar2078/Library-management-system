#ifndef Student_h 
#define Student_h
class Student{
	  public:
        	 char name[25],address[30];
        	 int code,age;
 	 public:
        	void add_Student();
        	void delete_Student();
        	void search_Student();
        	void update_Student();
        	void list_Student();
        	int return_code1();
        	 void Students();   
        	int ret_code(){
             return(code);
             }
   };
#endif
