#ifndef Employee_h 
#define Employee_h
class Employee{
	private:
			char name[25],address[25];
 			int code,age;
    public:
           void add_employee();
           void delete_employee();
           void search_employee();
           void update_employee();
           void list_employee();
           int return_code2();
           void employees();
        };
#endif
