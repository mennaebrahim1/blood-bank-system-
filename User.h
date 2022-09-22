#pragma once
#include<iostream>
#include<string.h>
using namespace std; 
class User 
{
public:
	int ID, Age;
	string Name, Mail, Password, Date_lsdonation, Blood_type;
	char Gender;
	void registration(int);
    bool validation(int, string, string , int);
	void login(int);
	void updateData(int);
	void  deleteAccount(int);
};