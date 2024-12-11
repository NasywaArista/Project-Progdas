/**
 * Project Untitled
 */


#ifndef _CUSTOMER_H
#define _CUSTOMER_H

class Customer {
public: 
    
void getid();
    
void setid();
    
void getname();
    
void setname();
    
void getaddress();
    
void setaddress();
    
void setnoTelp();
    
void getnoTelp();
private: 
    int idCustomer;
    string name;
    string address;
    int noTelp;
};

#endif //_CUSTOMER_H