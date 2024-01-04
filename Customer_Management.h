#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct person
{
  int Id;
  string first_name;
  string last_name;
  double balance;
  string branch;
};

void Add();
int Next_ID();
void updateid(int newId);
void search();
void update();
void deleteid();
void view();
void Customer_Menu();

//function Defintions

void Customer_Menu(){
  int choice =0;  //variable to save user's choice
 
  //printing the menu using do while and switch statement
  //the functions are called in the individual cases according to User's choice

  do{
    cout<<"Enter 1 to add\nEnter 2 to Search\nEnter 3 to Update/Edit\nEnter 4 to delete\nEnter 5 to view\nEnter 6 to exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
  
  switch(choice){
    
    case 1:
            Add();           //calling add functio
          break;
    case 2:
           search();          //calling delete function
          break;

    case 3: 
           update();         //callingupdate function
           break;

    case 4:
          deleteid();       //calling delete function
          break;

    case 5: 
          view();           //calling view function
          break;

    case 6: 
           cout<<"\nProgram ends Here"<<endl;    //exiting
           break;

    default:
           cout<<"\nIncorrect option"<<endl;    //default case
  }

}while(choice!=6);

}




void Add() {                   //void function hai so it wont return anything
     person p;
     p.Id= Next_ID();    //assigning value to the newID variable by calling the Next id function

    ofstream file("Bank_management.txt", ios::app);   //ios::app to append in the file

    try{                                                //exception handling
        if(file.fail()){
            throw runtime_error("File not opened");
        }
    }
    catch(runtime_error& e){
        cout<<"\nError "<<e.what()<<endl;
    }

                           // string first_name,last_name,branch;
                           // double balance;

    cout << "\nEnter First name : ";        //taking input of data from user
    cin>>p.first_name;

    cout<<"\nEnter Last Name : ";
    cin>>p.last_name;

    cout << "\nEnter customer balance: ";
    cin >>p.balance;

    cout << "\nEnter bank branch: ";
    cin>>p.branch;

    file<<setw(20)<<left<<p.Id<<setw(20)<<p.first_name<<setw(20)<<p.last_name<<fixed<<setprecision(2)<<setw(20)<<p.balance<<setw(20)<<p.branch<<endl;  //file mai output krwa raha hun

    file.close();    //closing the bank_management file

    cout << "\nEntry added successfully with ID: " << p.Id << endl;    //printing the given id on the console

    updateid(p.Id + 1);                 // Updating the temporary id file for the next ID

}

//function to get next id
int Next_ID() {                          //this function will return an integer
    
    ifstream idFile("last_id.txt");      //opening file to read data from it
                                         
    int lastId = 0;           //initializing the variable with 0

    if(idFile.is_open()){     //for the firs time the program runs
                              //i have used this is_open() function 
        idFile >> lastId;

        idFile.close();

    } 
    else {             //this is only for the first time when the last id file has no value in it
                        // If the file doesn't exist, set the initial ID to 1
        lastId = 1;
        
    }
    
    return lastId;          //returning the integer lastId
}


   //ye function sirf temporary file mai id ki value update krney k liye hai

void updateid(int newId) {

    ofstream idFile;
    idFile.open("last_id.txt");                       //opening the last_id.txt file
                                                      //exception handling
    try{        
        if(idFile.fail()){
            throw runtime_error("File not opened 2");
        }
    }
    catch(runtime_error& e){
        cout<<"\nError!"<<e.what()<<endl;
        exit(1);                                       //exit(1) to show unsuccessful termination
    }

        idFile << newId;            //writing the updated id in the temporary file for future use

        idFile.close();     //closing the last_id.txt file
    }

//search function

void search(){

  int targetid;      //declaring variable
  cout<<"\nEnter the ID that you want to search : ";
  cin>>targetid;

  ifstream fin;
  fin.open("Bank_management.txt");

  try{                                             //exception handling on
      if(fin.fail()){
        throw runtime_error("File not opened");
      }
  }

  catch(runtime_error& e){
    cout<<"\nError"<<e.what()<<endl;
    exit(1);
  }
  
  // int id;
  // string first_name,last_name, branch;
  // double balance;
   person p;
  bool idfound = false;
  //reading data from file
  while(fin>>p.Id>>p.first_name>>p.last_name>>p.balance>>p.branch)
    { 
      if(p.Id== targetid){

      idfound = true;
      break;
    }

    }

    if(idfound){

      cout<<"\nData with ID "<<targetid<<" found in the file"<<endl;
      cout<<"\n";
      cout<<setw(20)<<left<<p.Id<<setw(20)<<p.first_name<<setw(20)<<p.last_name<<fixed<<setprecision(2)<<setw(20)<<p.balance<<setw(20)<<p.branch<<"\n"<<endl;
    }
    else{
    cout<<"\nData with ID "<<targetid<<" not found in the file"<<"\n"<<endl;
    }
    

fin.close(); //closing the opened file

}

//Update Function

void update(){
  ifstream i_file("Bank_management.txt");   // have to read data from this file
  ofstream o_file("updated_file.txt");      //have to write the extracted data in this file
 
  try{                                        //exception handling performed on both files
      if(i_file.fail() || o_file.fail()){
        throw runtime_error("File not opened");
      }
  }

  catch(runtime_error& e){
    cout<<"\nError! "<<e.what()<<endl;
    exit(1);                                   //exit(1) to show unsuccessful termination
  } 

  // int id;                                     //declaration of variables
  // string first_name,last_name,branch;
  // double balance;
  person p;
  bool present=false;

  int change_id;                                   //taking input of id from user
  cout<<"\nEnter the ID you want to update : ";
  cin>>change_id;

  while(i_file>>p.Id>>p.first_name>>p.last_name>>p.balance>>p.branch){              //reading from the bank_management file 
        
        if(p.Id == change_id){                             //comparing the id with the user entered id
          
          present = true;
          int choice;
          cout<<"\nEnter 1 for updating name\nEnter 2 for updating balance\nEnter 3 for updating branch ";
          cout<<"\nEnter your choice : ";
          cin>>choice;

          switch(choice){                              //switch statement to give user the option to change either of the three entities

            case 1: 
                   cout<<"\nEnter updated first name : ";        //updating name
                   cin>>p.first_name;
                   cout<<"\nEnter updated last name : ";
                   cin>>p.last_name;
                   break;

            case 2: 
                    cout<<"\nEnter updated balance : ";         //updating balance
                    cin>>p.balance;
                    break;

            case 3: 
                    cout<<"\nEnter updated branch : ";           //updating branch name
                    cin>>p.branch;
                    break;

            default: 
                    cout<<"\nIncorrect option chosen\n"<<endl;

          }

        }

        //writing data to the new file

        o_file<<setw(20)<<left<<p.Id<<setw(20)<<p.first_name<<setw(20)<<p.last_name<<fixed<<setprecision(2)<<setw(20)<<p.balance<<setw(20)<<p.branch<<endl;
  }

  i_file.close();                            //closing both the files

  o_file.close();

  remove("Bank_management.txt");                      //removing the original file
  rename("updated_file.txt","Bank_management.txt");   //renaming the updated_file to bank_management 

  if(!present)
  cout<<"\nNo such ID was found in the file.\n"<<endl;

}

//delete function

void deleteid() {
     
    ifstream file("Bank_management.txt");    //opening file bank_management

    ofstream tempfile("temporary.txt");      //opening temporary file to write in it

    try{                                        //exception handling performed on both files
      if(file.fail() || tempfile.fail()){
        throw runtime_error("File not opened");
      }
  }

  catch(runtime_error& e){
    cout<<"\nError! "<<e.what()<<endl;
    exit(1);
  }

    person p;   // created instance
    // int id;
    // string first_name,last_name, branch;
    // double balance;
    int target_id=0;
    bool check = false;
    cout<<"\nEnter the ID you want to delete : ";
    cin>>target_id;

    while (file>>p.Id>>p.first_name>>p.last_name>>p.balance>>p.branch) {
            
            if(p.Id == target_id){                            //checking whether the id is present in the file or not
                check = true;
            }

            if (p.Id  !=  target_id) {
                 //writing data to temp file
                tempfile<<setw(20)<<left<<p.Id<<setw(20)<<p.first_name<<setw(20)<<p.last_name<<fixed<<setprecision(2)<<setw(20)<<p.balance<<setw(20)<<p.branch<<endl;
            }
        }
        
    tempfile.close();    //closing both files
    file.close();

         remove("Bank_management.txt");                //removing the original file
         rename("temporary.txt","Bank_management.txt");//renaming the temp file
        
        if(check)
        cout << "\nEntry with ID " <<target_id<< " deleted successfully.\n" << endl;  //confirmation msg print kiya hai console pr
        else
        cout<<"\nNo such entry is present in the file .\n"<<endl;                    //if the id was not present in the file

    } 

    //view function

    void view(){
  
  string line;                              //declaring a string to read the data into
  ifstream fin;
  fin.open("Bank_management.txt");          //opening the file bank management

  try{                                       //exception handling
    if(fin.fail()){
      throw runtime_error("File not found");
    }
  }
  catch(runtime_error& e){
    cout<<"\nError "<<e.what()<<endl;
    exit(1);
  }

  cout<<setw(20)<<left<<"ID"<<setw(20)<<"FirstName"<<setw(20)<<"LastName"<<setw(20)<<"Balance"<<setw(20)<<"Branch"<<endl;   //column headings
  

  while(getline(fin,line)){       //reading data from file and printing it on the console
    cout<<line<<endl;
  }

  fin.close();

 }
