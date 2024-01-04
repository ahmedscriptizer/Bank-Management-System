#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Customer_Management.h"
#include "Account_Management.h"
#include "Transaction_Management.h"
using namespace std;
int main(){

  int user_choice=0;
  do{
    cout<<"Enter 1 to run Customer Management System\nEnter 2 to run Account Management System\nEnter 3 to run Transaction Management System\nEnter 4 to Exit "<<endl;
    cout<<"Choose your choice : ";
    cin>>user_choice;

    switch(user_choice){
      case 1:
             Customer_Menu();
             break;
      
      case 2:
             Account_Menu();
             break;

      case 3:
             Transaction_Menu();
             break;
      case 4:
             cout<<"Program ends here "<<endl;
    }
    
  }while(user_choice!= 4);

  }
