#include "Doner.h"
#include "Blood.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

Node_::Node_()
{
	Donor b;
	b.ID = b.Age = 0;
	b.Name = b.Mail = b.Password = b.Date_lsdonation = "0";
	b.Gender = '0';
	b.take_medi = b.ha_disease = false;
	next = NULL;
}

donorlink::donorlink()
{
	head = tail = NULL;
}

void donorlink::get_donor_data()
{
	ifstream in_Fl("doner.txt", ios::binary);
	if (in_Fl.fail())
	{
		cout << "The File was not opened successfully check that the file eixst\n";
		exit(1);
	}
	while (true) {
		Node_* temp = new Node_();
		in_Fl >> temp->b.ID;
		in_Fl >> temp->b.Age;
		in_Fl >> temp->b.Name;
		in_Fl >> temp->b.Mail;
		in_Fl >> temp->b.Password;
		in_Fl >> temp->b.Date_lsdonation;
		in_Fl >> temp->b.Blood_type;
		in_Fl >> temp->b.Gender;
		in_Fl >> temp->b.take_medi;
		in_Fl >> temp->b.ha_disease;
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

bool Donor::checkDateOfLastestDonation()
{
	bool flag=true;
	/*
	int day, month, year;
	
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
#pragma warning( disable : 4996 )
	nowLocal = *localtime(&now);
	cout << "Today is: " << nowLocal.tm_mday << " /" << nowLocal.tm_mon + 1 << " /" << nowLocal.tm_year + 1900 << endl;
	cout << "Enter Date Of Lastest Donation: ";
	cin >> day >> month >> year;
	cin.get();
	if (nowLocal.tm_year + 1900 > year)
	{
		if (month - nowLocal.tm_mon + 1 >= 3)
		{
			flag = true;
			cout << "Enough Time To Donate." << endl;
		}
		else
		{
			flag = false;
			cout << "Not Enough Time To Donate." << endl;
		}
	}
	else if (nowLocal.tm_year + 1900 == year)
	{
		if (nowLocal.tm_mon + 1 - month >= 3)
		{
			flag = true;
			cout << "Enough Time To Donate." << endl;
		}
		else
		{
			flag = false;
			cout << "Not Enough Time To Donate." << endl;
		}
	}
	else
	{
		flag = false;
		cout << "Not Enough Time To Donate." << endl;
	}*/
	return flag;
	
}

bool Donor::checkRequesetOfDonner()
{ 
	bool flag = true;
	/*
	double weight;
	double hemoglobin_ratio;
	double heartBeat;
	double temprature;
	double blood_pressure;
	int AmountOfDonation;
	
	if (Age <= 16 || Age >= 60)
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	
	if (checkDateOfLastestDonation() == false)
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	
	cout << "Enter your weight :" << endl;
	cin >> weight;
	if (weight <= 50)
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	cout << "Enter your hemoglobin_ratio :" << endl;
	cin >> hemoglobin_ratio;
	if (Gender = 'm' && (hemoglobin_ratio <= 14 || hemoglobin_ratio >= 17))
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	if (Gender = 'f' && (hemoglobin_ratio <= 12 || hemoglobin_ratio >= 14))
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	cout << "Enter your heartBeat & blood pressure:" << endl;
	cin >> heartBeat >> blood_pressure;
	if ((heartBeat <= 50 || heartBeat >= 100) && (blood_pressure >= (80 / 120)))
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
	cout << "Enter your temprature:" << endl;
	cin >> temprature;
	if (temprature > 37)
	{
		flag = false;
		return flag;
	}
	else
		flag = true;
		*/
	return flag;
}

bool Donor::checkRequeset_Level2()
{
	bool flag =true;
	/*
	//if (checkRequesetOfDonner())
	//{
		if (take_medi == true)
		{
			flag = false;
			return flag;
		}
		else
			flag = true;
		if (ha_disease == true)
		{
			bool chose1;
			cout << "Do you suffer from blood pressure disorders" << endl;
			cin >> chose1;
			if (chose1 == true)
			{
				flag = false;
				return flag;
			}
			else flag = true;
			bool chose2;
			cout << "Do you suffer from  thyroid disease" << endl;
			cin >> chose2;
			if (chose2 == true)
			{
				flag = false;
				return flag;
			}
			else flag = true;
			bool chose3;
			cout << "Do you suffer from diabetes" << endl;
			cin >> chose3;
			if (chose3 == true)
			{
				flag = false;
				return flag;
			}
			else
				flag = true;
			bool chose4;
			cout << "Do you suffer from cancer" << endl;
			cin >> chose4;
			if (chose4 == true)
			{
				flag = false;
				return flag;
			}
			else
				flag = true;
			bool chose6;
			cout << "Do you suffer from  heart disorders" << endl;
			cin >> chose6;
			if (chose6 == true)
			{
				flag = false;
				return flag;
			}
			else
				flag = true;
			bool chose7;
			cout << "Do you suffer from hepatitis" << endl;
			cin >> chose7;
			if (chose7 == true)
			{
				flag = false;
				return flag;
			}
			else flag = true;
		}
		else
			flag = true;
	//}
	//else
	//	flag = false;
	*/
	return flag;
}

string Donor::recrecivedDate()
{
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
    #pragma warning( disable : 4996 )
	nowLocal = *localtime(&now);
	string Today = to_string(nowLocal.tm_mday) + "/ " + to_string(nowLocal.tm_mon + 1) + "/ " + to_string(nowLocal.tm_year + 1900);
	return Today;
}

string Donor::expireDateOfBlood()
{
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
    #pragma warning( disable : 4996 )
	nowLocal = *localtime(&now);
	string expireDate;
	if ((nowLocal.tm_mday + 15) > 30)
	{
		expireDate = to_string(nowLocal.tm_mday - 15) + "/ " + to_string(nowLocal.tm_mon + 2) + "/ " + to_string(nowLocal.tm_year + 1900);
	}
	else
	{
		expireDate = to_string(nowLocal.tm_mday + 15) + "/ " + to_string(nowLocal.tm_mon + 1) + "/ " + to_string(nowLocal.tm_year + 1900);
	}
	return expireDate;
}

void Donor::Donation_request()
{
	donorlink b;
	if (b.checkRequeset_Level2() == true)
	{
		cout << "Request Is Accebt" << endl;
		string db;
		cout << "Enter your Blood Typr :" << endl;
		cin >> db;
		bloodlink b;
		b.insert(db, recrecivedDate() , expireDateOfBlood());
		cout << "Done" << endl;
	}
	else
		cout << "Donor Is Not Suitable For Blood Donation" << endl;
}





