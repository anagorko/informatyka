#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Person;
{
	int id;
	string name, surname;

public:

	Person(int i, string n, string s)
	{
		id = i;
		name = n;
		surname = s;
	}

	Person getid()

	ostream operator<<(ostream & os, Person p)
	{
		return os << id << name << surname;
	}
};

class AdressBook
{
	vector<Person> book;

public:

	void add(Person p)
	{
		p.id
	}
	void write(string bookname) 
	{
    	ofstream bookfile;

        bookfile.open(bookname, ios::trunc);

        for (Person& p: bk) 
		{
            bookfile << p;
        }

        bookfile.close();
    }
};

int main()
{
	Person p(1, Krzysiu, Blankiewicz);

	
}
