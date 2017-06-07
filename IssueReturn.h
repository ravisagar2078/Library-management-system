#ifndef IssueReturn_h
#define IssueReturn_h
#include"Date.h"
class IssueReturn{
	private:
   			int m_code,b_code;
        	Date id;
        	char status;
	public:
		   int return_bcode(){
			   return(b_code);
			  }
		   int return_mcode(){
          	   return(m_code);
			  }
		   void issue_book();
           void return_book();
           void list_book();
           void transaction();
   };
#endif
