#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Person
{
	int id;
	string name, surname, mail;

public:

	/*Person(string n, string s, string m)
	{
        int i = -1;
        id = i;
		name = n;
		surname = s;
		mail = m;

	}*/

	int get_id()
	{
	    return id;
	}

	string get_name()
	{
	    return name;
	}

	string get_surname()
	{
	    return surname;
	}

    string get_mail()
	{
	    return mail;
	}
    void set_id(int i)
    {
        id = i;
    }

    void set_name(string n)
    {
        name = n;
    }

    void set_surname(string s)
    {
        surname = s;
    }

    void set_mail(string m)
    {
        mail = m;
    }
};

ostream& operator<<(ostream& os, Person& p)
{
    os << p.get_id() << p.get_name() << p.get_surname() << p.get_mail();
    return os;
}

istream& operator>>(istream& is, Person& p)
{
    is >> p.get_id() >> p.get_name() >> p.get_surname() >> p.get_mail();
    return is;
}


class AdressBook
{
	vector<Person> book;

public:

	void add(string new_name, string new_surname, string new_mail)
	{
	    Person new_Person (new_name, new_surname, new_mail)

	    book.resize(book.size() + 1, NIE WIEM CO TU WPISAĆ)
	    book[book.size() - 1] = new_Person;
	    new_Person.set_id(liczba_wpisow + 1);

		cout << "dodano wpis";
	}

	void dilejt(int x)
	{
        if (x > (book.size() - 1)) cout << "Nie mam takich danych";
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                book[i].set_id(0);
                cout << "Usunięto wpis o numerze" x;
            }
        }
        cout << "Nie amm takich danych"
	}

	void modify(int x, string what, string new_content)
	{
        if (x > (book.size() - 1)) cout << "Nie mam takich danych";
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                if(book[i].get_id(x) == 0)cout << "Nie mam takich danych";
                if(what == "name") book[i].set_name(new_content);
                if(what == "surname") book[i].set_surname(new_content;
                if(what == "mail") book[i].set_mail(new_content);
                else cout << "błąd w komendzie";
            }
        }
        cout <<"Zmodyfikowano wpis o numerze"
	}


	/*void write(string bookname)
	{
    	ofstream bookfile;

        bookfile.open(bookname, ios::trunc);

        for (int i = 0; i < book.size(); i++)
		{
            bookfile << book[i];
        }

        bookfile.close();
    }
    */
    void robocze_write()
    {
         for (int i = 0; i < book.size(); i++)
		{
		    if()
            cout << book[i];
        }
    }

    int looking_for(string sb)
    {
        if (x > (book.size() - 1) || book[x].get_id() == 0) return "Nie mam takich danych";

        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_surname() == sb)
            {
                cout<<get_Person(book[i].get_id());
            }
        }
    }

    Person get_Person(int x)
    {

        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                return book[i];
            }
        }
    }


};

class UI
{
    int niewiempocoto;

public:

    void help()
    {
        cout<< "W linii komend wpisujemy nazwę książki adresowej. Po drugie komendę z poniższych: 1.dodaj 2.zmień 3.usuń 4.znajdź ";
    }

    void modify(AdressBook book)
    {
        int x;
        cout<< "który wpis?"
        cin>>x;
        book.modify(x);
    }

    void dilejt(AdressBook book)
    {
        int x;
        cout<<"który wpis?";
        cin>>x;
        book.dilejt(x);
    }

    void add(AdressBook book)
    {
        string new_name, new_surname, new_mail;
        cout<<"Imię:";
        cin>>new_name;

        cout<<"Nazwisko:";
        cin>>new_surname;

        cout<<"Mail:";
        cin>>new_mail;

        book.add(new_name, new_surname, new_mail)
    }

    void looking_for(AdressBook book)
    {
        string sb;
        cout<<"kogo szukamy?";
        cin>>sb;
        looking_for(book, sb);
    }

    void print(AdressBook book)
    {
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() != 0)
            {
                cout<<book[i];
            }
        }
    }

};

/*int main()
{
	Person p;
	p.set_id(1);
	string n = "Krzysiu";
	p.set_name(n);
	string s = "Blankiewicz";
	p.set_surname(s);

    AdressBook book;

    book.add(p);

    book.write();
}*/

int main(int argc, char* argv[])
{
    UI iface;

    if (argc == 1 || (argc > 1 && string(argv[1]) == "help"))
    {
        iface.help();
        return 0;
    }

    if(argc > 3)
        cout<<"Nie wszystko na raz."

    if (argc == 3)
    {
        string book;
        book = string(argv[1]);

        WCZYTAJ KSIĄŻKĘ Z PLIKU BOOK.TXT

        if(string(argv[2]) == "dodaj")
            iface.add(book);
        if(string(argv[2]) == "zmień")
            iface.modify(book);
        if(string(argv[2]) == "usuń")
            iface.dilejt(book);
        if(string(argv[2]) == "znajdź")
            iface.looking_for(book);
        if(string(argv[2]) == "wyświetl")
            iface.print(book);

       ZAPISZ KSIĄŻKĘDO PLIKU
    }
}

