using namespace std;

class Person
{
	string name, surname, mail;
	int id, number;

	void changeId(int n)
	{
		id = n;
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
		for (int i = 1; i < s.size()-1; i++)
		{
			size = size * 10 + s[i];
		}
		for (int i = 0; i < size; i++)
		{
			getline(bk, s);

			switch(element)
			{
				case 1:
				if(s[i] == ';')
				element++;
				break;

				case 2:
			}

		}
	}
};