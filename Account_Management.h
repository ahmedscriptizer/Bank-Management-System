#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
using namespace std;

const int MAX_ACCOUNTS = 20; // Maximum number of accounts in the array

// Define the structure for account details
struct Account {
    int accountNumber;
    string accountType;
    double InterestRate;
    
};

 

// Function prototypes
void loadAccounts(Account[], int&);
void saveAccounts(const Account[], int);
void displayAllAccounts(const Account[], int);
void addAccount(Account[], int&);
void searchAccount(const Account[], int);
void updateAccount(Account[], int);
void deleteAccount(Account[], int&);
void Account_Menu();

//function Definitions

   //menu function
    void Account_Menu(){
   
    Account accounts[MAX_ACCOUNTS];  //instance of struc Array
    int numAccounts = 0;           

    // Load existing accounts from the file
    loadAccounts(accounts, numAccounts);

    int choice;
    do {
        // Display menu
        cout << "===== Account Management System =====" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. View All Accounts" << endl;
        cout << "3. Search Account" << endl;
        cout << "4. Update Account" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAccount(accounts, numAccounts);
                break;
            case 2:
                displayAllAccounts(accounts, numAccounts);
                break;
            case 3:
                searchAccount(accounts, numAccounts);
                break;
            case 4:
                updateAccount(accounts, numAccounts);
                break;
            case 5:
                deleteAccount(accounts, numAccounts);
                break;
            case 6:
                // Save accounts to file before exiting
                saveAccounts(accounts, numAccounts);
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
 
    }


// Function to load accounts from the file
void loadAccounts(Account accounts[], int& numAccounts) {
    ifstream inputFile("accounts.txt");
    if (inputFile.is_open()) {
        while (inputFile >> accounts[numAccounts].accountNumber >> accounts[numAccounts].accountType >> accounts[numAccounts].InterestRate) {
            numAccounts++;
            if (numAccounts == MAX_ACCOUNTS) {
                cout << "Maximum number of accounts reached. Cannot load more." << endl;
                break;
            }
        }
        inputFile.close();
    }
}

// Function to save accounts to the file

void saveAccounts(const Account accounts[], int numAccounts) {
    ofstream outputFile("accounts.txt",ios::trunc);

    if (outputFile.is_open()) {
        for (int i = 0; i < numAccounts; i++) {
            outputFile <<setw(20)<<left<<accounts[i].accountNumber <<setw(20) << accounts[i].accountType <<setw(20)<< accounts[i].InterestRate << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to save accounts to file." << endl;
    }
}


// Function to display details of all accounts

void displayAllAccounts(const Account accounts[], int numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts to display." << endl;
    } else {
        cout<<setw(20)<<left<<"Account Number"<<setw(20)<<"AccountType"<<setw(20)<<"Account Interest rate "<<endl;

        for (int i = 0; i < numAccounts; i++) {
            cout<<setw(20)<<left<<accounts[i].accountNumber<<setw(20)<<accounts[i].accountType<<setw(20)<<accounts[i].InterestRate<<endl;
        }
    }
}



// Function to add a new account

void addAccount(Account accounts[], int& numAccounts) {
    if (numAccounts < MAX_ACCOUNTS) {
        cout<<"Enter 5 digit Account Number:";
        cin>>accounts[numAccounts].accountNumber;
        cout << "Enter Account Type:\nEnter 1 for Savings and 2 for Current Account : ";
        cin >> accounts[numAccounts].accountType;
        cout << "Enter Account Interest Rate: ";
        cin >> accounts[numAccounts].InterestRate;

        // Display the added account details
        cout << "Account added successfully." << endl;
        cout<<setw(20)<<left<<"Account Number"<<setw(20)<<"AccountType"<<setw(20)<<"Account Interest rate "<<endl;
        cout<<setw(20)<<left<<accounts[numAccounts].accountNumber<<setw(20)<<accounts[numAccounts].accountType<<accounts[numAccounts].InterestRate<<"%"<<endl;
        cout << endl;

        // Increment the number of accounts
        numAccounts++;
       
    } else {
        cout << "Maximum number of accounts reached! Sorry Cannot add more." << endl;
    }
}

// Function to search for an account based on account number

void searchAccount(const Account accounts[], int numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts to search." << endl;
    } 
    else {
        int target_account;
        cout << "Enter Account Number to Search: ";
        cin >> target_account;
        bool present = false;

        for(int i=0;i<numAccounts;i++){

            if(accounts[i].accountNumber == target_account){
            
            present = true;
            cout<<"Account Number Found!"<<endl;
             cout<<setw(20)<<left<<"Account Number"<<setw(20)<<"AccountType"<<setw(20)<<"Account Interest rate "<<endl;
            cout<<setw(20)<<left<<accounts[i].accountNumber<<setw(20)<<accounts[i].accountType<<setw(20)<<accounts[i].InterestRate<<"%"<<endl;
            cout << endl;
            break;
            }
        }

        if(!present){
            cout<<"Account with account number "<<target_account<<" not found"<<endl;
        }    
    }
}

// Function to update an existing account

void updateAccount(Account accounts[], int numAccounts) {

    if (numAccounts == 0) {
        cout << "No accounts to update." << endl;
    } 
    else {

        int updateAccountNumber,i=0;
        bool check = false;
        cout << "Enter Account Number to Update: ";
        cin >> updateAccountNumber;
         
         for(;i<numAccounts;i++){

            if(updateAccountNumber == accounts[i].accountNumber){
            
            cout << "Enter New Account Type: ";
            cin >> accounts[i].accountType;
            cout << "Enter New Account Interest Rate: ";
            cin >> accounts[i].InterestRate;
            check = true;
            break;

            }
         }
            
            if(check){
                cout<<"Account Updated Successfully"<<endl;
                cout<<setw(20)<<left<<"Account Number"<<setw(20)<<"AccountType"<<setw(20)<<"Account Interest rate "<<endl;
                cout<<setw(20)<<left<<accounts[i].accountNumber<<setw(20)<<accounts[i].accountType<<setw(20)<<accounts[i].InterestRate<<endl;
            }
            else
            cout<<"Account number entered not found "<<endl;
         }

    }


// Function to delete an account based on account number

void deleteAccount(Account accounts[], int& numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts to delete." << endl;
    } 
    else {

        int deleteAccountNumber;
        cout << "Enter Account Number to Delete: ";
        cin >> deleteAccountNumber;
        
        int index = -1;
        for(int i=0;i< numAccounts;i++){
            if(deleteAccountNumber == accounts[i].accountNumber){
                index = i;
                break;   //loop exit kr jata hai jab account number match hojata hai
            }
        }

        if (index != -1) {
            // Shifting elements to fill the gap

            for (int i = index; i < numAccounts - 1; i++) {
                accounts[i] = accounts[i + 1];
            }

            // Decrement the number of accounts
            numAccounts--;

            cout<<"Account Deleted Successfully"<<endl;
            
        }
         else 
            cout << "Account not found." << endl;
        
    }
}
