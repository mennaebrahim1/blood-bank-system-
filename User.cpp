#include "User.h"
#include "Blood.h"
#include "Recipient.h"
#include "Doner.h"
#include<iostream>
#include <fstream>
#include <stdio.h>
#include<string.h>
using namespace std;
void User::registration(int chose)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tRegistration Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choose = chose;
	int a, b;
	string c, d, e,f, g;
	char x;
	cout << " => Enter your id :";
	cin >> a;
	cout << " => Enter your age :";
	cin >> b;
	cout << " => Enter your name :";
	cin >> c;
	cout << " => Enter your mail :";
	cin >> d;
	cout << " => Enter your password for your account :";
	cin >> e;
	cout << " => Enter your Blood type :";
	cin >> g;
	cout << " => Enter your Gender :";
	cin >> x;
	if (choose == 1)
	{
		cout << " => Enter date or your last donation :";
	    cin >> f;
		Node_* temp = new Node_();
		temp->b.ID = a;
		temp->b.Age = b;
		temp->b.Name = c;
		temp->b.Mail = d;
		temp->b.Password = e;
		temp->b.Date_lsdonation = f;
		temp->b.Blood_type = g;
		temp->b.Gender = x;
		bool z;
		cout << "If you suffers from any disease  press 1  if no press 0 :" << endl;
		cout << "(blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis) :" ;
		cin >> z;
		cout << endl;
		temp->b.ha_disease = z;
		temp->b.take_medi = z;
		ofstream out_Fl;
		out_Fl.open("doner.txt", ios::app);
		if (out_Fl.fail())
		{
			cout << "The File was not opened successfully check that the file eixst\n";
			exit(1);
		}

		if (temp->b.ha_disease == false && temp->b.take_medi == false && validation(a, e, d, choose) == true) {
			out_Fl << temp->b.ID << "\n" << temp->b.Age << "\n" << temp->b.Name << "\n" << temp->b.Mail << "\n" << temp->b.Password << "\n";
			out_Fl << temp->b.Date_lsdonation << "\n" << temp->b.Blood_type << "\n" << temp->b.Gender << "\n" << temp->b.take_medi << "\n" << temp->b.ha_disease;
			out_Fl << "\n";
			out_Fl.close();
			cout << "\t\t\t***\tRegistration successfully   ***." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
		else
		{
			cout << "Soury You Can't Register Cause You Infected Or Your ID Exist Befor." << endl ;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	else if (choose == 2)
	{
		string y, z;
		cout << " => Enter  hospital  (place where you are available)";
		cin >> y;
		cout << " => Enter name of your doctor : ";
		cin >> z;
		cout << endl;
		Node_r* temp = new Node_r();
		temp->r.ID = a;
		temp->r.Age = b;
		temp->r.Name = c;
		temp->r.Mail = d;
		temp->r.Password = e;
		temp->r.Blood_type = g;
		temp->r.Gender = x;
		temp->r.hospital = y;
		temp->r.doctorOfCase = z;
		ofstream out_Fl;
		out_Fl.open("recipient.txt", ios::app);
		if (out_Fl.fail())
		{
			cout << "The File was not opened successfully check that the file eixst\n";
			exit(1);
		}
		if (validation(a, e, d, choose) == true) {
			out_Fl << temp->r.ID << "\n" << temp->r.Age << "\n" << temp->r.Name << "\n" << temp->r.Mail << "\n" << temp->r.Password << "\n";
			out_Fl << temp->r.Blood_type << "\n" << temp->r.Gender << "\n" << temp->r.doctorOfCase << "\n" << temp->r.hospital;
			out_Fl << "\n";
			out_Fl.close();
			cout << "\t\t\t***\tRegistration successfully   ***." << endl;
			cout << "-------------------------------------------------------------------------------" << endl<<endl;
		}
		else
		{
			cout << "Soury You Can't Register Cause You Infected Or Your ID Exist Befor." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
}

void User::login(int chose)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tlogin Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int choose=chose;
	int x;
	string y;
	cout << "   => Enter your id please : ";
	cin >> x;
	cout << "   => Enter your password please : ";
	cin >> y;
	cout <<  endl;
	if (choose == 1)
	{
		donorlink d;
		d.get_donor_data();
		Node_* temp = new Node_();
			bool z = true;
			temp = d.head;
			while (temp != NULL)
			{
				if (temp->b.ID == x && temp->b.Password == y) {
					cout << "\t\t\t***\tLogin successfully   ***." << endl;
					cout << "-------------------------------------------------------------------------------" << endl << endl;
					z = false;
					break;
				}
				temp = temp->next;
			}
			if (z == true)
			{
				cout << "\t\t\tCan't find your account try again." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
			}

	}
	else if (choose == 2)
	{
		recipientlink r;
		r.get_Recipient_data();
		Node_r* temp = new Node_r();
		bool z = true;
		temp = r.head;
		while (temp != NULL)
		{
			if (temp->r.ID == x && temp->r.Password == y) {
				cout << "\t\t\t***\tLogin successfully   ***." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				z = false;
				break;
			}
			temp = temp->next;
		}
		if (z == true)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	
}

bool User::validation(int x, string y, string z , int choose)
{   
	bool valid = true;
	int ch =choose;
	if (ch == 1)
	{
		donorlink d;
		d.get_donor_data();
		Node_* temp = new Node_();
		
		temp = d.head;
		while (temp != NULL) {
			if (temp->b.ID == x && temp->b.Password == y && temp->b.Mail == z)
			{
				//cout << "ID , Password and Mail Already Exist Try Something Else.";
				valid = false;
				break;
			}
			temp = temp->next;
		}
		
	}
	else if(ch == 2)
	{
		recipientlink r;
		r.get_Recipient_data();
		Node_r* temp = new Node_r();
		temp = r.head;
		while (temp != NULL) {
			if (temp->r.ID == x && temp->r.Password == y && temp->r.Mail == z)
			{
				cout << "ID , Password or Mail Already Exist Try Something Else.";
				valid = false;
				break;
			}
			temp = temp->next;
		}
		
	}
	return valid;
}

void User::updateData(int chose)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tUpdate Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int ch = chose;
	int x;
	string y;
	cout << "   => Enter your id:";
	cin >> x;
	cout << "   => Enter your password please : ";
	cin >> y;
	cout << endl;
	if (ch == 1)
	{
		donorlink d;
		d.get_donor_data();
		int choose = chose;
		if (choose == 1)
		{
			donorlink d;
			d.get_donor_data();
			Node_* temp = new Node_();
			bool z = true;
			temp = d.head;
			ofstream o_Fl("temp.txt");
			while (temp != NULL)
			{
				if (temp->b.ID == x && temp->b.Password == y) {
					string t1, t2,t5;
					bool t3, t4;
					cout << "   => Enter new mail please : ";
					cin >> t1;
					cout << "   => Enter new password please : ";
					cin >> t2;
					cout << "   => press 1 if you inured any disease : ";
					cin >> t3;
					cout << "   => press 1 if you are take any medicine : ";
					cin >> t4;
					cout << "   => Enter last update of donation date: ";
					cin >> t5;
					temp->b.Mail = t1;
					temp->b.Password = t2;
					temp->b.ha_disease = t3;
					temp->b.take_medi = t4;
					temp->b.Date_lsdonation = t5;
					cout << "\t\t\t***\tData updated successfully   ***." << endl;
					cout << "-------------------------------------------------------------------------------" << endl << endl;
					z = false;
				}
				o_Fl << temp->b.ID << endl;
				o_Fl << temp->b.Age << endl;
				o_Fl << temp->b.Name << endl;
				o_Fl << temp->b.Mail << endl;
				o_Fl << temp->b.Password << endl;
				o_Fl << temp->b.Date_lsdonation << endl;
				o_Fl << temp->b.Blood_type << endl;
				o_Fl << temp->b.Gender << endl;
				o_Fl << temp->b.take_medi << endl;
				o_Fl << temp->b.ha_disease << endl;
				temp = temp->next;

			}
			o_Fl.close();
			remove("doner.txt");
			(rename("temp.txt", "doner.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
			if (z == true)
			{
				cout << "\t\t\tCan't find your account try again." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
			}
		}
	}
	else if (ch == 2)
	{
		recipientlink r;
		r.get_Recipient_data();
		Node_r* temp = new Node_r();
		bool z = true;
		temp = r.head;
		ofstream o_Fl("temp.txt");
		while (temp != NULL)
		{
			if (temp->r.ID == x && temp->r.Password == y) {
				string t1, t2,  t3, t4;
				cout << "   => Enter new mail please : ";
				cin >> t1;
				cout << "   => Enter new password please : ";
				cin >> t2;
				cout << "   =>  Enter new hospital please: ";
				cin >> t3;
				cout << "   => Enter new doctor please : ";
				cin >> t4;
				temp->r.Mail = t1;
				temp->r.Password = t2;
				temp->r.hospital = t3;
				temp->r.doctorOfCase = t4;
				cout << "\t\t\t***\tAccount deleted successfully   ***." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				z = false;
			}
			o_Fl << temp->r.ID << endl;
			o_Fl << temp->r.Age << endl;
			o_Fl << temp->r.Name << endl;
			o_Fl << temp->r.Mail << endl;
			o_Fl << temp->r.Password << endl;
			o_Fl << temp->r.Date_lsdonation << endl;
			o_Fl << temp->r.Blood_type << endl;
			o_Fl << temp->r.Gender << endl;
			o_Fl << temp->r.hospital << endl;
			o_Fl << temp->r.doctorOfCase << endl;
			temp = temp->next;
		}
		o_Fl.close();
		remove("recipient.txt");
		(rename("temp.txt", "recipient.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
		if (z == true)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
}

void User::deleteAccount(int chose)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t***\tDelete Form\t***" << endl;
	cout << "-------------------------------------------------------------------------------" << endl << endl;
	int x;
	string y;
	cout << "   => Enter your id:";
	cin >> x;
	cout << "   => Enter your password please : ";
	cin >> y;
	cout << endl;
	int choose = chose;
	if (choose == 1)
	{
		donorlink d;
		d.get_donor_data();
		Node_* temp = new Node_();
		bool z = true;
		temp = d.head;
		ofstream o_Fl("temp.txt");
		while (temp != NULL)
		{
			if (temp->b.ID == x && temp->b.Password == y) {
				Node_* del = new Node_();
				del = temp;
				temp = temp->next;
				del = NULL;
				cout << "\t\t\t***\tAccount deleted successfully   ***." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				z = false;
			}
			o_Fl << temp->b.ID << endl;
				o_Fl << temp->b.Age << endl;
				o_Fl << temp->b.Name << endl;
				o_Fl << temp->b.Mail << endl;
				o_Fl << temp->b.Password << endl;
				o_Fl << temp->b.Date_lsdonation << endl;
				o_Fl << temp->b.Blood_type << endl;
				o_Fl << temp->b.Gender << endl;
				o_Fl << temp->b.take_medi << endl;
				o_Fl << temp->b.ha_disease << endl;
				temp = temp->next;
			
		}
		o_Fl.close();
		remove("doner.txt");
		(rename("temp.txt", "doner.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
		if (z == true)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
	else if (choose == 2)
	{
		recipientlink r;
		r.get_Recipient_data();
		Node_r* temp = new Node_r();
		bool z = true;
		temp = r.head;
		ofstream o_Fl("temp.txt");
		while (temp != NULL)
		{
			if (temp->r.ID == x && temp->r.Password == y) {
				Node_r* del = new Node_r();
				del = temp;
				temp = temp->next;
				del = NULL;
				cout << "\t\t\t***\tAccount deleted successfully   ***." << endl;
				cout << "-------------------------------------------------------------------------------" << endl << endl;
				z = false;
			}
			o_Fl << temp->r.ID << endl;
			o_Fl << temp->r.Age << endl;
			o_Fl << temp->r.Name << endl;
			o_Fl << temp->r.Mail << endl;
			o_Fl << temp->r.Password << endl;
			o_Fl << temp->r.Date_lsdonation << endl;
			o_Fl << temp->r.Blood_type << endl;
			o_Fl << temp->r.Gender << endl;
			o_Fl << temp->r.hospital << endl;
			o_Fl << temp->r.doctorOfCase << endl;
			temp = temp->next;
		}
		o_Fl.close();
		remove("recipient.txt");
		(rename("temp.txt", "recipient.txt") == 0) ? cout << "\t\t\t***\tDone   ***." << endl : cout << "\t\t\t***\tError in rename of files   ***." << endl;
		if (z == true)
		{
			cout << "\t\t\tCan't find your account try again." << endl;
			cout << "-------------------------------------------------------------------------------" << endl << endl;
		}
	}
}


