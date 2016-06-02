using namespace std;

void welcomeHelp()
{
	cout << "\nWelcome in Simply Address Book\n\nAt the begining please enter the name of book file\n\n";
	return;
}

void help()
{
	//ss
}

void add()
{
	string na, su, ma, nu;
	int n;
	cout << "Please insert Name:\n";
	getline(cin,na);
	cout << "Please insert Surname:\n";
	getline(cin,su);
	cout << "Please insert Mail:\n";
	getline(cin,ma);
	cout << "Please insert Number:\n";
	getline(cin,nu);

	n=0;

	for(int i = 0; i < nu.size(); i++)
	{
		n = n * 10 + nu[i] - 48;
	}

	Book1.add(na,su,ma,n);
}

void print()
{
	cout << "Address book\nNumber of records: " << Book1.size << "\nValues of records:\n";
		for(int i = 0; i < Book1.size; i++)
		{
			cout << i << " " << Book1.book[i].getName() << " " << Book1.book[i].getSurname() << " " << Book1.book[i].getMail() << " " << Book1.book[i].getNumber() << endl;
		} 
}

void deletePerson(int dv) //id od deleted part of vector
{
	Book1.size --;
	Book1.book.erase(Book1.book.begin() + dv);
}

void editPerson(int n)
{
	string na, su, ma, nu;
	int num;

	cout<<"If some value is correct please just press Enter\n";

	cout << "Please insert Name:\n";
	getline(cin,na);
	if(na == "") na = Book1.book[n].getName();

	cout << "Please insert Surname:\n";
	getline(cin,su);
	if(na == "") su = Book1.book[n].getSurname();

	cout << "Please insert Mail:\n";
	getline(cin,ma);
	if(na == "") ma = Book1.book[n].getMail();

	cout << "Please insert Number:\n";
	getline(cin,nu);
	if(na == "") nu = Book1.book[n].getNumber();

	num=0;

	for(int i = 0; i < nu.size(); i++)
	{
		num = num * 10 + nu[i] - 48;
	}

	Book1.book[n].setName(na);
	Book1.book[n].setSurname(su);
	Book1.book[n].setMail(ma);
	Book1.book[n].setNumber(num);
}