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
    os << p.get_id()<< " " << p.get_name() << " " << p.get_surname() << " " << p.get_mail() <<endl;
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

		int l = 1;
		for(int i = 0; i < book.size(); i++)
		{
			if(book[i].get_id() >= l)  l = book[i].get_id() + 1;
		}

	    book[book.size() - 1].set_id(l);
        cout << book[0]<<endl<<"book.size = "<<book.size()<<endl;
		cout << "dodano wpis" << endl;
	}

	void dilejt(int x)
	{
        if (x > (book.size()) || book[x].get_id() == 0) cout << "Nie mam takich danych" << endl;
        for(int i = 0; i < book.size(); i++)
        {
			cout << i << " " << book[i].get_id() << endl;
            if(book[i].get_id() == x)
            {
                book[i].set_id(0);
                cout << "Usunięto wpis o numerze" << x << endl;
            }
        }
	}

	void modify(int x, string what, string new_content)
	{
        if (x > (book.size())) cout << "Nie mam takich danych" << endl;
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_id() == x)
            {
                if(what == "imie")
                {
                    book[i].set_name(new_content);
                    cout <<"Zmodyfikowano wpis o numerze" << x <<endl;
                }
                if(what == "nazwisko")
                {
                    book[i].set_surname(new_content);
                    cout <<"Zmodyfikowano wpis o numerze" << x <<endl;
                }
                if(what == "mail")
                {
                    book[i].set_mail(new_content);
                    cout <<"Zmodyfikowano wpis o numerze" << x <<endl;
                }
                else
                {
                    cout << "Prawdopodobnie zrobiles literowke przy odpowiedzi na drugie pytanie." << endl;
                   // int wyjatek = 98;
                   // throw wyjatek;
                }
            }
        }
	}



	void write(string bookname)
	{
    	ofstream bookfile;
        bookfile.open(bookname.c_str(), ios::trunc);

        bookfile << book.size()<<endl;
        for (int i = 0; i < book.size(); i++)
			{
            if(book[i].get_id() != 0)  bookfile << book[i];
        	}

        bookfile.close();
    }

	void read(string bookname)
	{
    	ifstream bookfile;
        bookfile.open(bookname.c_str(), ios::in);

        int counting;
        bookfile >> counting;

        book.resize(counting, Person("nic", "nic", "nic"));

        for (int i = 0; i < book.size(); i++)
        {
            bookfile >> book[i];
        }
        bookfile.close();
    }

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

	int looking_for(string sb)
    {
        for(int i = 0; i < book.size(); i++)
        {
            if(book[i].get_surname() == sb && book[i].get_id() != 0)
            {
                Person q = get_Person(book[i].get_id());
                cout<<q;
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
        cout<< "W linii komend wpisujemy nazwe ksiazki adresowej. Po drugie, co zrobić..."<<endl<<endl<< "   dodaj"<<endl<< "   zmien"<<endl<< "   usun"<<endl<< "    znajdz - Wyswietla wpisy osob o danym nazwisku. Potrzebne do znalezienia numeru zadanego wpisu."<<endl<<"  nowa_ksiazka - tworzy nową ksiazke adresowa o nazwie podanej jako pierwszy argument."<<endl<<endl<<"Przy braku dodatkowej zmiennej program wypisze cala ksiazke.";
    }

    //try
    //{
        void modify(AdressBook& bk)
        {
            int x;
            string data_to_change, new_data;
            cout<< "Wpis o ktorym numerze zmienic?";
            cin>>x;
            cout<<"Co chcesz zmienić? (imie/nazwisko/mail)";
            cin>>data_to_change;
            cout<<"Nowe dane:";
            cin>>new_data;

            bk.modify(x, data_to_change, new_data);
        }
    //}
    //catch(int w)
    //{
     //   .modify(ksiazka);
    //}

    void dilejt(AdressBook& bk)
    {
        int x;
        cout<<"Który wpis usuwamy?";
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
        cout<<"Jakiego nazwiska szukamy?";
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
    
    /*UI iface;
    if (argc == 1  || (argc > 1 && string(argv[1]) == "help"))
    {
        iface.help();
        return 0;
    }


    if(argc > 3)
        cout<<"Nie wszystko na raz.";
    if (argc == 3)
    {
        if(string(argv[2]) == "nowa_ksiazka")
        {
            AdressBook ksiazka;

            ksiazka.write(string(argv[1]) + "txt");
            return 0;
        }
        AdressBook ksiazka;

        ksiazka.read(string(argv[1]) + ".txt");

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

        ksiazka.write(string(argv[1]) + ".txt");
    }*/
    UI iface;

    AdressBook ksiazka;

    iface.help();
    cout<<endl<<"Słucham..."<<endl;
    string nazwa_ksiazki, komenda;
    cin>>nazwa_ksiazki>>komenda;

    if(komenda == "nowa_ksiazka")
    {
        ksiazka.write(nazwa_ksiazki + ".txt");
    }

    ksiazka.read(nazwa_ksiazki + ".txt");

    if(komenda == "dodaj")
        iface.add(ksiazka);
    if(komenda == "zmien")
        iface.modify(ksiazka);
    if(komenda == "usun")
        iface.dilejt(ksiazka);
    if(komenda == "znajdz")
        iface.looking_for(ksiazka);
    if(komenda == "wyswietl")
        iface.print(ksiazka);

    ksiazka.write(nazwa_ksiazki + ".txt");

	return 0;
}
