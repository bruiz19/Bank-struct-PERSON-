//Brandon Ruiz CWID:890130156
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

struct PERSON{

char Name[20];
float Balance;

};

void Display(PERSON *P, int N);  //(Name, Balance)

void FindRichest(PERSON *P, int N);  //(RName, RBalance)

void Deposit(char Pdeposit[],PERSON *P, int N);  //(Person Depositing, Name, New Balance)

void NewCopy(string FirstName, PERSON *P, int N);  //(Person, Name, Balance)

int main(){

int N = 0;

ifstream myFile;  //file access. //change in to myFile

myFile.open("data.txt");

if(myFile.fail()){

cout << "Cannot open the file." << endl;  //if incorrect

return 0;

}

string line;

while(getline(myFile, line)){  //character by character

N++;

}

myFile.clear();


myFile.seekg(0, ios::beg);  //starts reading character from the begining.

PERSON *P = new PERSON[N]; //new person in array

string FirstName;
string LastName;

int i = 0;

while(myFile >> FirstName){  //checks if person name actually exists

myFile >> LastName >> P[i].Balance; //true add last name and balance

strcpy(P[i].Name, (FirstName + " " + LastName).c_str());  //displays name + whitespace

i++;

}

Display(P, N);

FindRichest(P, N);

char Pdeposit[20];

cout << "Enter your full name to deposit money: ";

cin.getline(Pdeposit, 20);

Deposit(Pdeposit, P, N);

NewCopy("data.txt", P, N);

return 0;

}



void Display(PERSON *P, int N){

cout << "Name" << " Balance" << endl;

cout << "-------------------------------------" << endl;

for(int i = 0; i < N; i++){

cout << P[i].Name << " " << P[i].Balance << endl;

}

}

void FindRichest(PERSON *P, int N){

int max = 0; //start at zero 

for(int i = 0; i < N; i++){

if(P[max].Balance < P[i].Balance) //checks numbe that is greatest in balance

max = i; //greatest value is now max

}

cout << "The customer with the maximum balance is: "<< P[max].Name << endl;

}

void Deposit(char Pdeposit[],PERSON *P, int N){

int check = -1;

for(int i = 0; i < N; i++){

if(strcmp(Pdeposit, P[i].Name) == 0){  //compare value to check

check = i;

break;

}

}

if(check == -1)  //false

cout << "Customer Name is not found." << endl;

else{  //true

double deposit;

cout << " " << Pdeposit << ", how much would you like to deposit? ";

cin >> deposit;

P[check].Balance += deposit;

cout << "Now your new balance is: " << P[check].Balance << endl;

}

}

void NewCopy(string FirstName, PERSON *P, int N){

ofstream myFile;  //changed out to myFile



myFile.open(FirstName.c_str());

for(int i = 0; i < N; i++){

myFile << P[i].Name << " "<< P[i].Balance << endl;

}

myFile.close();

}
