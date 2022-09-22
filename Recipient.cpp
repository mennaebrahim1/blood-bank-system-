#include "Recipient.h"
#include<iostream>
#include <fstream>

Node_r::Node_r()
{
	Recipient r;
	r.ID = r.Age = 0;
	r.Name = r.Mail = r.Password = r.Date_lsdonation = "0";
	r.Gender = '0';
	r.hospital = r.doctorOfCase = "";
	next = NULL;
}

recipientlink::recipientlink()
{
	head = tail = NULL;
}

void recipientlink::get_Recipient_data()
{
	ifstream in_Fl("recipient.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	while (true) {
		Node_r* temp = new Node_r();
		in_Fl >> temp->r.ID;
		in_Fl >> temp->r.Age;
		in_Fl >> temp->r.Name;
		in_Fl >> temp->r.Mail;
		in_Fl >> temp->r.Password;
		in_Fl >> temp->r.Blood_type;
		in_Fl >> temp->r.Gender;
		in_Fl >> temp->r.hospital;
		in_Fl >> temp->r.doctorOfCase;
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

