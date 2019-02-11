
#include<iostream>
#include<conio.h>
#include<string>
#include<stdio.h>
#include"Header.h"
using namespace std;
int main()
{
	cricketteam firstteam,secondteam;
	int size=0;
	firstteam.inputFromConsole(size);
	firstteam.input();
	firstteam.print();
	firstteam.printteaminfo();
	
	int a=firstteam.averagescore();
	cout<<"\n***************Output of File*************************\n";
	string path="file.txt";
	secondteam=cricketteam(path);//destructor invoke here and delete memory of teamName
	secondteam.print();
	secondteam.printteaminfo();
	secondteam.inputScore(50);
	int b=secondteam.averagescore();
	
	if(a>=b)
		cout<<"\nInput team is better:"<<endl;
	else
		cout<<"\nInput team is not better:"<<endl;
	system("pause");
	
}
