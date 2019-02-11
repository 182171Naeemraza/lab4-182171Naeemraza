#include<iostream>
#include<string>
#include<stdio.h>
#include"Header.h"
#include<fstream>
using namespace std;
cricketteam::cricketteam()
{
	membernames=nullptr;
	no_of_members=0;
	teamName=nullptr;
	for(int i=0;i<10;i++)
	{
	Scoreinlast10matches[i]=0;
	}
	int rank=-1;
	Captain="nothing";
}
void cricketteam::teamnamesize(int size)
{
	teamName=new char[size+1]; 
}
void cricketteam::totalmember(int size)
{
	membernames=new string [size];
}
/*cricketteam::~cricketteam()
{

	cout<<"Destructor is invoked"<<endl;
	if(teamName!=nullptr)
	delete[]teamName;
	if(membernames!=nullptr)
	delete[]membernames;
}*/
cricketteam::cricketteam(string filepath)
{
	string teamname,totalmembers,membername,rank,captain,score;
	
	
	ifstream fin(filepath.c_str());
	getline(fin,teamname,':');
	getline(fin,teamname,'\n');
	int m=teamname.length();
	teamnamesize(m);
	int i;
	for(i=0;i<m;i++)
	{
	teamName[i]=teamname[i];
	}
	teamName[i]='\0';
	getline(fin,totalmembers,':');
	getline(fin,totalmembers,'\n');
	int a=stoi(totalmembers);
	no_of_members=a;
	totalmember(a);
	for(int i=0;i<a;i++)
	{
		getline(fin,membername,'\n');
		membernames[i]=membername;
	}
	
	getline(fin,rank,':');
	getline(fin,rank,'\n');
	Rank=stoi(rank);
	getline(fin,captain,':');
	getline(fin,captain,'\n');
	Captain=captain;
	getline(fin,score,':');
	for(int i=0;i<10;i++)
	{
	getline(fin,score,',');
	Scoreinlast10matches[i]=stoi(score);
	}

	
}
void cricketteam::print()
{
	cout<<endl<<"Teamname:"<<teamName<<endl;
	cout<<"Captain name:"<<Captain<<endl;
	cout<<"Latest score:"<<Scoreinlast10matches[9]<<endl;
}
void cricketteam::printteaminfo()
{
	cout<<endl<<"******************************Team Information*****************************"<<endl;
	cout<<endl<<"Teamname:"<<teamName<<endl;
	cout<<"Teamrank:"<<Rank<<endl;
	if(no_of_members!=0)
	cout<<"Number of members:"<<no_of_members<<endl;
	cout<<"Captain name:"<<Captain<<endl;
	if(Scoreinlast10matches[9]!=-0)
	cout<<"Latest score:"<<Scoreinlast10matches[9]<<endl;
}
void cricketteam::inputFromConsole(int size)
{
	cout<<"Enter size of teamname:";
	int s;cin>>s;
	teamnamesize(s);
	cout<<"Enter teamname:";cin>>teamName;
	cout<<"Enter the size of team members:";cin>>size;
	totalmember(size);
	cout<<"Enter member names:";
	for(int i=0;i<size;i++)
	{
		cin>>membernames[i];
		if(i==size-1)
			cout<<"There is no place for new team member: \n";
	}
	cout<<"Enter Rank of team:";
	cin>>Rank;
	cout<<"Enter Name of Captain:";
	cin>>Captain;
}
void cricketteam::input()
{
	cout<<"Enter score of ten matches:"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>Scoreinlast10matches[i];
	}
}
void cricketteam::inputScore(int score)
{
	int array[10];
	for(int i=1;i<10;i++)
	{
		array[i-1]=Scoreinlast10matches[i];
	}
	int i=10;
	Scoreinlast10matches[i]=score;
	array[i-1]=Scoreinlast10matches[i];
}
int cricketteam::averagescore()
{
	int sum=0,average=0;
	for(int i=0;i<10;i++)
	{
		sum+=Scoreinlast10matches[i];
	}
	 average=sum/10;
	 return average;
}
bool cricketteam::compare(int team1,int team2)
{
	
	if(team1>=team2)
		return true;
	else
		return false;
}