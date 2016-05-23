using namespace std;

class Person
{
	string name, surname, mail;
	int id, number;

public:

	void setId(int n)
	{
		id = n;
		cout << id << endl;
	}
	int getId()
	{
		return id;
	}

	void setName(string s)
	{
		name = s;
		cout << name << endl;
	}
	string getName()
	{
		return name;
	}

	void setSurname(string s)
	{
		surname = s;
		cout << surname << endl;
	}
	string getSurname()
	{
		return surname;
	}

	void setMail(string s)
	{
		mail = s;
		cout << mail << endl;
	}
	string getMail()
	{
		return mail;
	}

	void setNumber(int n)
	{
		number = n;
		cout << number << endl;
	}
	int getNumber()
	{
		return number;
	}



};

class Book
{
	int size;
	vector <Person> book;
private:

public:
	void openFile(char* file)
	{
		fstream bk;

		int element;
		string s;

		bk.open(file, ios::app | ios::in | ios::out );
		getline(bk, s);
		for (int i = 0; i < s.size()-1; i++)
		{
			size = size * 10 + s[i];
		}
		for (int j = 0; j < size; j++)
		{
			getline(bk, s);

			for(int i = 0; i < s.size(); i++)
			{
				switch(element)
				{
					case 1:
					if(s[i] == ';')
						element++;
					else
						book[j].setName( book[j].getName() + s[i]);

					break;

					case 2:
					if(s[i] == ';')
						element++;
					else
						book[j].setSurname( book[j].getSurname() + s[i]);

					break;

					case 3:
					if(s[i] == ';')
						element++;
					else
						book[j].setMail( book[j].getMail() + s[i]);

					break;

					case 4:
					if(s[i] == ';')
						element++;
					else
						book[j].setId( (book[j].getId() * 10)+ (int)s[i]);

					break;
				}
			}
		}
	}
	void printBook()
	{
		for(int i = 0; i < size; i++)
		{
			cout << book[i].getId() << " " << book[i].getName() << " " << book[i].getSurname() << " " << book[i].getMail() << " " << book[i].getNumber() << endl;
		} 
	}

	//kolene funkcje
};