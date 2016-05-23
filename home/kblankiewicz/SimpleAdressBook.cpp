#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class Person
{
	int id;
	string name, surname, mail;

public:

	Person(string n, string s, string m)
	{
        int i = -1;
        id = i;
		name = n;
		surname = s;
		mail = m;

	}

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
    int i;
    string n, s, m;
    is >> i >> n >> s >> m;
    p.set_id(i);
    p.set_name(n);
    p.set_surname(s);
    p.set_mail(m);
    return is;
}


class AdressBook
{
	vector<Person> book;

public:

	void add(string new_name, string new_surname, string new_mail)
	{
	    Person new_Person = Person(new_name, new_surname, new_mail);

	    book.resize(book.size() + 1, Person("nic", "nic", "nic"));
	    book[book.size() - 1] = new_Person;
	    book[book.size() - 1].set_id(book.size());
        cout << book[0]<<endl<<"book.size = "<<book.size()<<endl;
		cout << "dodano wpis";
	}

	void dilejt(int x)
	{
        if (x > (book.size()) || book[x].get_id() == 0) cout << "Nie mam takich danych";
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                book[i].set_id(0);
                cout << "Usunięto wpis o numerze" << x;
            }
        }
	}

	void modify(int x, string what, string new_content)
	{
        if (x > (book.size())) cout << "Nie mam takich danych";
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                if(what == "name") book[i].set_name(new_content);
                if(what == "surname") book[i].set_surname(new_content);
                if(what == "mail") book[i].set_mail(new_content);
                else cout << "błąd w komendzie";
            }
        }
        cout <<"Zmodyfikowano wpis o numerze" << x;
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
		    if(book[i].get_id() != 0)
            {
                cout << endl << book[i];
            }
        }
    }

    int looking_for(string sb)
    {
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_surname() == sb && book[i].get_id() != 0)
            {
                //cout<<get_Person(book[i].get_id()); MA PROBLEM Z OPERATOREM
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


    vector<Person> get_vector()
    {
        return book;
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

    void modify(AdressBook& bk)
    {
        int x;
        string data_to_change, new_data;
        cout<< "który wpis?";
        cin>>x;
        cout<<"co chcesz zmienić?";
        cin>>data_to_change;
        cout<<"Nowe dane:";
        cin>>new_data;

        bk.modify(x, data_to_change, new_data);
    }

    void dilejt(AdressBook& bk)
    {
        int x;
        cout<<"który wpis?";
        cin>>x;
        bk.dilejt(x);
    }

    void add(AdressBook& bk)
    {

        string new_name, new_surname, new_mail;
        cout<<"Imię:";
        cin>>new_name;

        cout<<"Nazwisko:";
        cin>>new_surname;

        cout<<"Mail:";
        cin>>new_mail;

        bk.add(new_name, new_surname, new_mail);
    }

    void looking_for(AdressBook bk)
    {
        string sb;
        cout<<"kogo szukamy?";
        cin>>sb;
        bk.looking_for(sb);
    }

    void print(AdressBook bk)
    {
        vector<Person> a;
        a = bk.get_vector();
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i].get_id() != 0)
            {
                cout<<a[i];
            }
        }
    }

};

int main(int argc, char* argv[])
{
    /*Person p = Person("Krzysiu", "Blankiewicz", "kblankiewicz5");

    AdressBook ksiazka;

    UI iface;

    iface.add(ksiazka);
    iface.add(ksiazka);
    iface.add(ksiazka);
    iface.dilejt(ksiazka);
    iface.modify(ksiazka);

    ksiazka.robocze_write();

*/
    UI iface;

    if (argc == 1 || (argc > 1 && string(argv[1]) == "help"))
    {
        iface.help();
        return 0;
    }

    if(argc > 3)
        cout<<"Nie wszystko na raz.";

    if (argc == 3)
    {
        string ksiazka_name;
        ksiazka_name = string(argv[1]);

        string file_name = ksiazka_name + "txt";

  //      OTWÓRZ KSIĄŻKĘ Z PLIKU I STWÓRZ ADRESSBOOK book

        AdressBook ksiazka;

        if(string(argv[2]) == "dodaj")
            iface.add(ksiazka);
        if(string(argv[2]) == "zmień")
            iface.modify(ksiazka);
        if(string(argv[2]) == "usuń")
            iface.dilejt(ksiazka);
        if(string(argv[2]) == "znajdź")
            iface.looking_for(ksiazka);
        if(string(argv[2]) == "wyświetl")
            iface.print(ksiazka);

   //     ksiazka.write(test.txt);
    }
}

