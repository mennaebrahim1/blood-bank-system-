#include "blood.h"
#include <iostream>
#include<fstream>
using namespace std;
Node::Node()
{
	Blood b;
	b.type = "0";
	b.quantity = 0;
	b.Expiry_date = "0";
	b.Received_date = "0";
	next = NULL;
}

bloodlink::bloodlink()
{
	head = tail = NULL;
}

void bloodlink::get_blood_data()
{
	ifstream in_Fl("blood.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	while (true) {
		Node* temp = new Node();
		in_Fl >> temp->b.type;
		in_Fl >> temp->b.Received_date;
		in_Fl >> temp->b.Expiry_date;
		//in_Fl >> temp->b.quantity;
		if (in_Fl.fail()) {
			delete temp;
			break;
		}
		if (head == NULL) {
			head = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
	}
	in_Fl.close();
}

void bloodlink::display_data()
{
	Node* temp = new Node();
	temp = head;
	while (temp != NULL) {
		cout << "The Blood Type Name " << "||" << " The Received date " << "||" << " The Expiry date name " << "||" << " Quantity Of Blood Type " << " \n";
		cout << temp->b.type << " || " << temp->b.Received_date << temp->b.Expiry_date << " || " << "  \n";
		temp = temp->next;
	}
}

void bloodlink::insert(string bloodType, string recivedDate, string expiryDate)
{
	Node* temp = new Node();
	temp->b.type = bloodType;
	temp->b.Received_date = recivedDate;
	temp->b.Expiry_date = expiryDate;
	ofstream o_Fl;
	o_Fl.open("blood.txt", ios::app);
	o_Fl << temp->b.type << endl;
	o_Fl << temp->b.Received_date << endl;
	o_Fl << temp->b.Expiry_date << endl;
	o_Fl.close();
}
