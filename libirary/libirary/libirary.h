#pragma once
using namespace std;
#include <iostream>
#include <string>
class libirary
{
public:
	int id;
	string B_name;
	string Author;
	int n_book;
public:
	virtual ~libirary() = default;
	libirary(int i, string B_n, string A, int n) :B_name(B_n), Author(A), id(i), n_book(n) {};

	virtual void display()
	{
		cout << "Book name : " << B_name << endl;
		cout << "Book Id : " << id << endl;
		cout << "Name Author : " << Author << endl;
		cout << "Num of Book : " << n_book << endl;
	};

	void updata(string new_name, int new_id, string new_author, int new_numper)
	{
			id = new_id;
			B_name = new_name;
			Author = new_author;
			n_book = new_numper;
		new libirary(new_id, new_name, new_author, new_numper);
	};

};

