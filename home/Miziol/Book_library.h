using namespace std;

class Person
{
	string name, surname, mail; // save af Name;Surname;Mail;Id;Number;
	int id, number;

public:

	void setId(int n)
	{
		id = n;
	}
	int getId()
	{
		return id;
	}

	void setName(string s)
	{
		name = s;
	}
	string getName()
	{
		return name;
	}

	void setSurname(string s)
	{
		surname = s;
	}
	string getSurname()
	{
		return surname;
	}

	void setMail(string s)
	{
		mail = s;
	}
	string getMail()
	{
		return mail;
	}

	void setNumber(int n)
	{
		number = n;
	}
	int getNumber()
	{
		return number;
	}



};

class Book
{
public:
	int size;
	vector <Person> book;

private:

public:
	void openFile(char* file)
	{
		fstream bk;

		int element = 1;
		string s;

		bk.open(file, ios::in );
		getline(bk, s);
		for (int i = 0; i < s.size()-1; i++)
		{
			size  = 0;
			size = size * 10 + s[i] - 48;
		}

		book.resize(size);

		for (int j = 0; j < size; j++)
		{
			getline(bk, s);

			element = 1;

			for(int i = 0; i < s.size(); i++)
			{
				switch(element)
				{
					case 1:
					if(s[i] == ';')
					{
						element++;
					}else{
						book[j].setName( book[j].getName() + s[i]);
					}

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
						book[j].setId( (book[j].getId() * 10) + s[i] - 48);

					break;

					case 5:
					if(s[i] == ';')
						element++;
					else
						book[j].setNumber( (book[j].getNumber() * 10) + s[i] - 48);

					break;

				}
			}
		}

		bk.close();
	}

	void saveFile(char* file)
	{
		fstream bk;

		remove(file);

		bk.open(file, ios::out | ios::app );

		bk << size << ";\n";

		for(int i = 0; i < size; i++)
		{
			bk << book[i].getName() << ";" << book[i].getSurname() << ";" << book[i].getMail() << ";" << book[i].getId() << ";" << book[i].getNumber() << ";";
			bk << endl;
		}

		bk.close();
	}

	void add(string na, string su, string ma, int nu)
	{
		size++;
		int i = book.size() + 1;
		book.resize(i);
		
		i--;
		book[i].setName(na);
		book[i].setSurname(su);
		book[i].setMail(ma);
		book[i].setId(i+1);
		book[i].setNumber(nu);
	}

	//kolene funkcje
};