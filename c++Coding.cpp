#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<string, int>map1;
	map<string, int>::iterator i;
	ifstream fin;
	string name;
	int phno;
	fin.open("file1.txt", ios::in | ios::out);
	while (fin.tellg() >= 0)
	{
		fin >> name >> phno;
		map1.insert(pair<string, int>(name, phno));
	}
	fin.close();

	int choice;
	cout << "***************select the option you want to do************" << endl;
	cout << "1 new entry" << endl;
	cout << "2 update entry" << endl;
	cout << "3 search entry" << endl;
	cout << "4 delete entry" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	
		cout << "enter new entry ";
		cin >> name >> phno;
		map1.insert(pair<string, int>(name, phno));

		break;
	case 2:
	
		cout << "enter the new phno with old name ";
		cin >> name >> phno;
		map1[name] = phno;

		break;
	case 3:
	
		cout << "enter the name to search ";
		cin >> name;
		i = map1.find(name);
		if (i == map1.end())
		{
			cout << "***not found***"<<endl;
		}
		else 
		{
			cout << "***found***"<<endl;
		}
		break;
	case 4:
	
		cout << "enter the name  to delete ";
		cin >> name;
		map1.erase(name);
		cout << "***deleted succesfully***" << endl;
		break;
	
	}
	//remove("file1.txt");
	ofstream fout;
	fout.open("file1.txt",ios::out);
	
	for (i = map1.begin(); i != map1.end(); ++i)
	{
		fout << i->first << " " << i->second;
	}
	fout.close();

	
	fin.open("file1.txt", ios::in);
	cout << "***************final information in the file************"<< endl;
	while (fin.tellg() >= 0)
	{
		fin >> name >> phno;
		cout << name <<" "<< phno<<endl;
	}
	fin.close();
}
