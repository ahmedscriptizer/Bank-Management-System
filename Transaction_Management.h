#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include "Account_Management.h"
#include "Customer_Management.h"
using namespace std;

struct Transaction{
  int customer_id;
  int account_number;
  int deposit;
  int withdrawal;
};

Account accounts[MAX_ACCOUNTS];

void Add_Transaction(Account accounts[],person b[],Transaction transact);
void viewTransaction(Transaction transact);
void loadfiles(Account accounts[], person b[]);
void Transaction_Menu(){

void loadfiles(Account accounts[], person b[]);

Transaction transact;

int choice = 0;

person b[MAX_ACCOUNTS];

cout<<"------Transaction Management System--------"<<endl;
do{
   cout<<"Enter 1 to add\nEnter 2 to View\n Enter 3 to exit"<<endl;
   cout<<"Enter your choice : ";
   cin>>choice;

   switch(choice){
    case 1: 
           Add_Transaction(accounts, b, transact);
           break;
    case 2: 
           viewTransaction(transact);
           break;
    case 3: 
           cout<<"Program Ends here "<<endl;
            
   }
}while(choice!=3);

}

//function definitions

void loadfiles(Account accounts[], person b[]){
  int i=0;
  ifstream inputfile("accounts.txt");
  if (inputfile.is_open()) {
        while (inputfile >> accounts[i].accountNumber >> accounts[i].accountType >> accounts[i].InterestRate){
        i++;
        }
}
inputfile.close();

i=0;
ifstream InputFile("Bank_management.txt");
if(InputFile.is_open()){
  while(InputFile>>b[i].Id>>b[i].first_name>>b[i].last_name>>b[i].balance>>b[i].branch){
    i++;
  }
}
InputFile.close();

}


void Add_Transaction(Account accounts[],person b[],Transaction transact){
  
  bool check=false;
  cout<<"Enter customer Id: ";
  cin>>transact.customer_id;
  for(int i=0;i<MAX_ACCOUNTS;i++){
    if(transact.customer_id == b[i].Id){
      cout<<"ID entered is present in the customer file "<<endl;
      check = true;
      break;
    }
  }
  bool flag=false;
  cout<<"Enter Account Number : ";
  cin>>transact.account_number;
  for(int i=0;i<MAX_ACCOUNTS;i++){
    if(transact.account_number == accounts[i].accountNumber){
      cout<<"Entered Account Number is present in the accounts file "<<endl;
      flag = true;
      break;
    }
  }
  
   if(check && flag){
    cout<<"Enter Amount Deposited in this month : ";
    cin>>transact.deposit;
    cout<<"\nEnter Amount Withdrawn in this month : ";
    cin>>transact.withdrawal;

    ofstream file("Transaction_record.txt",ios::app);
    file<<setw(20)<<left<<transact.customer_id<<setw(20)<<transact.account_number<<setw(20)<<transact.deposit<<setw(20)<<transact.withdrawal<<endl;
    file.close();
   }
   else
   cout<<"The entered customer ID and Account Number is not present in the previous record "<<endl;
    
  }


  void viewTransaction(Transaction transact){

    ifstream inputfile("Transaction_record.txt");
    cout<<setw(20)<<left<<"Customer ID"<<setw(20)<<"Account Number"<<setw(20)<<"Deposit"<<setw(20)<<"Withdrawn"<<endl;
    while(inputfile>>transact.customer_id>>transact.account_number>>transact.deposit>>transact.withdrawal){
      cout<<setw(20)<<left<<transact.customer_id<<setw(20)<<transact.account_number<<setw(20)<<transact.deposit<<setw(20)<<transact.withdrawal<<endl;
    }
  }


