#pragma once
#include "User.h"
#include<iostream>
#include<string.h>
using namespace std;
class Recipient :public User
{
public:
	string hospital;
	string doctorOfCase;

};
class Node_r :public User {
public:
	Recipient r;
	Node_r* next;
	Node_r();
};

class recipientlink :public Recipient {
public:
	Node_r* head;
	Node_r* tail;
public:
	recipientlink();
	void get_Recipient_data();
};

