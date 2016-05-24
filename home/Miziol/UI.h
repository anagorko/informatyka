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
	int n,p;
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

//przekopiować printa - pytranie do pana Nagórko