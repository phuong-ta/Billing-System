#include <iostream>
#include<fstream>
#include<string>
#include "../Header/Menu.h"
using namespace std;
void welcome(){
	cout<<"Wellcome to my restaurant!"<<endl;
}
void showMenu(){
	welcome();
	
	fstream myFile;
	myFile.open("C:/Users/phuon/Desktop/C++/Billing System/Recourse/txt/Menu.txt", ios::in);
	
	if(myFile.is_open()){
		string line, name, price;
		int lineNumber=1, tem=1;
		while(getline(myFile, line)){
			if(lineNumber%2==1){
				name = line;
			}else{
				price=line;
				cout<<tem<<"."<<name<<"\t\t"<< price<<endl;
				tem++;
			}
			lineNumber++;			
		}
		cout<<"0. Count total"<<endl;
		cout<<"----------------------"<<endl;
		myFile.close();
	}
}
double listOption(int option){
	double price;
	fstream myFile;	
	myFile.open("C:/Users/phuon/Desktop/C++/Billing System/Recourse/txt/Menu.txt", ios::in);
	if(option ==0){
		return price;
	}
	if(myFile.is_open()){	
		string line, name;
		int lineNumber=1;
		
		while(getline(myFile, line)){
			if(lineNumber==(option*2)-1){
				name=line;
			}else if(lineNumber==(option*2)){
				price= stod(line);
			}
			lineNumber++;
		}
		cout<< name<<"\t"<<price<<endl;
	}
	return price;
}

void option(){
	int option;
	double total;
	while(1){
		cout<<"Enter customer option!";	
		cin>> option;
		total += listOption(option);
		if(option ==0){	
			break;
		}
	}
	cout<<"Total: "<<total<<endl;
}