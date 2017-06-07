#ifndef Book_h 
#define Book_h
class Book{
	  public:
        	 int code,num_of_copies;
        	 char title[20];
        //	 float price;
	  public:
             void books();
        	 void add_book();
        	 void delete_book();
        	 void search_book();
        	 void update_book();
        	 void list_book();
        	 int return_code();
        	 
        	 int ret_copies(){return(num_of_copies);}
        	 void increase_copies(){num_of_copies++;}
        	 void reduce_copies(){num_of_copies--;}
        	 int ret_bcode(){return code;}
   };
#endif
