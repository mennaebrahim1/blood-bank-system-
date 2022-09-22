#pragma once
#include<iostream>
#include<string>
using namespace std;
class Blood
{
public:
	string type;
	string Received_date;
	string Expiry_date;
	int quantity;

};
class Node {
public:
	Blood b;
	Node* next;
	Node();
};
class bloodlink {

	Node* head;
	Node* tail;
public:
	bloodlink();
	void insert(string bloodType, string recivedDate, string expiryDate);
	void get_blood_data();
	void display_data();

};