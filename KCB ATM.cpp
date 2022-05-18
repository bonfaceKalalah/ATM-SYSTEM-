# include<stdio.h>
# include<iostream>
# include<string.h>
using namespace std;

//Global variables
char option,escape,code;
string Name;
int userPin,Pin,Option;
float initialAmount;
float balance,drawings,deposit;

//Global function declaration
void mainMenu();

// Global functions
//This function check to ensure you use a four number pin
int pinCheck(int ret){
	int count=0;
	while(ret>0){
		ret=ret/10;
		count++;
	}
	return count;
}

//This function introduces the main interface of the ATM system where you can create account or log in to an account
void intro(){
	system("cls");
	cout<<"**********WELCOME TO KCB ATM SYSTEM**********\n";
	printf("(a) Create Account\n");
	printf("(b) Log in to an Account\n\n");
	cout<<"*********************************************\n";
	printf("Option: \n");
	cin>>option;
	
}

//This function creates an account as defined by its control elements
void createAccount(){
	system("cls");
	printf("Please enter your Name: \n");
	cin>>Name;
	if(Name.length()>=3&&Name.length()<=32){
	printf("Please enter your Pin: \n");
	cin>>userPin;
	if(pinCheck(userPin)==4){
	printf("Please confirm your Pin: \n");
	cin>>Pin;
	printf("Please enter your initial Amount(MUST BE GREATER THAN 500): \n");
	cin>>initialAmount;
	balance=initialAmount;
	if(Pin==userPin&&initialAmount>=500){
		cout<<"Your account is succesfully created and your user name is"<<" "<<Name<<"."<<endl;;
	}
	else{
		printf("FAILED! please try again.\n");
	}
	}
	else{
		printf("Pin MUST be a four character and MUST not start with a ZERO.\n");
	}
	}
	else{
		printf("Your Name MUST be atleast 3 characters and utmost 32. \n");
		
	}

}

//This is the function which facilitate the log in process
void logIn(){
	system("cls");
	printf("Please enter your Pin: ");
	cin>>Pin;
	if(Pin==userPin){
		mainMenu();
	}
	else{
		printf("Wrong Pin! Please try again.\n");
		printf("Enter any character to continue\n");
		cin>>escape;
	}
}

// This function control the menu options using switch statement
void menuOptions(){
	switch(Option){
		case 1:
			printf("Please enter Amount to deposit: \n");
			cin>>deposit;
			balance=balance+deposit;
			cout<<"Your Account is credited with Kshs. "<<deposit<<" Account Balance is Kshs. "<<balance<<" as at now. Thank you for banking with us.\n";
			printf("Enter any character to continue\n");
			cin>>escape;
			break;
		case 2:
			printf("Please enter Amount to withdraw: \n");
			cin>>drawings;
			if(drawings<balance){
				balance=balance-drawings;
				cout<<"You have succesfully withdraw Kshs. "<<drawings<<" from your Account."<<" Account Balance is Kshs. "<<balance<<" as at now.\n";
			}
			else{
				cout<<"Sorry, No OVERDRAFT allowed. Thank you for choosing KCB.\n";
				balance=balance;
			}
			printf("Enter any character to continue\n");
			cin>>escape;
			break;
		case 3:
			cout<<"Your Account balance is Kshs. "<<balance<<" as at now. Thank you for choosing KCB.\n";
			printf("Enter any character to continue\n");
			cin>>escape;
			break;
		case 4:
			break;
		default:
			cout<<"Invalid Option \n";
			cout<<"Enter any character to continue\n";
			cin>>escape;
			
	}
}

// This function display main menu Options to the user, if card is available it should be the first to be implemented
void mainMenu(){
	system("cls");
	cout<<"**********MAIN MENU**********\n";
	printf("1. Deposit\n");
	printf("2. Withdraw\n");
	printf("3. Check Balance\n");
	printf("4. Exit\n");
	cout<<"*****************************\n";
	printf("Option: \n");
	cin>>Option;
	menuOptions();
}

//Main function
int main(){
	do{
	intro();
	if(option=='a'){
		createAccount();
		cout<<"Enter any character to continue or 4 to Exit\n";
		cin>>code;
		
	}
	else if(option=='b'){
		logIn();
	}
	else
	{
	printf("Invalid Options\n");
	cout<<"Enter any character to continue\n";
	cin>>escape;
	}
}while(code!='4');
	system("pause>0");
	return 0;
}
