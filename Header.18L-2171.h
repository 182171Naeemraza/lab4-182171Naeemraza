#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
class cricketteam
{
string *membernames;
int no_of_members;
char *teamName;
int Scoreinlast10matches[10];
int Rank;
string Captain;

public:
void cricketteam::inputFromConsole(int size);
void cricketteam::inputScore(int score);
cricketteam::cricketteam();
cricketteam::cricketteam(string teamName, int no_of_members);
cricketteam::cricketteam(string filepath);
void cricketteam::teamnamesize(int size);
void cricketteam::totalmember(int size);
void cricketteam::printteaminfo();
int cricketteam::averagescore();
void cricketteam::print();
bool cricketteam::compare(int team1,int team2);
void cricketteam::input();
//~cricketteam();
};
