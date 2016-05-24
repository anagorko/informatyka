#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Person{
public:

    vector<char> name;
    vector<char> surname;
    vector<char> mail;
    vector<int> phone;

};
class adressbook {
public:
	vector<Person> bk;

    void read(string bookname);
	void write(string bookname);

    void sort();


} ab;
class UI {//User Interface
public:
	void help();

    void list(string l);
    void add();
    void modify();//TODO
    void del();//TODO

};

void adressbook::sort(){
    std::sort(bk.begin(), bk.end(), [] (const Person& lhs, const Person& rhs) { return lhs.name < rhs.name; });
}

void UI::list(string l){

    ab.read(l);
    for(int i=0;i<ab.bk.size();i++){
        for(int q=0;q<ab.bk[i].name.size();q++) cout<<ab.bk[i].name[q];
        cout<<" ";
        for(int q=0;q<ab.bk[i].surname.size();q++) cout<<ab.bk[i].surname[q];
        cout<<" ";
        for(int q=0;q<ab.bk[i].mail.size();q++) cout<<ab.bk[i].mail[q];
        cout<<" ";
        for(int q=0;q<ab.bk[i].phone.size();q++) cout<<ab.bk[i].phone[q];
        cout<<"\n";
    }
}
void UI::add(){

    Person p;
    string s;

    cout<<"Podaj Nazwę Książki Telefonicznej: ";
    
    string bookname;
    cin>>bookname;
    ab.read(bookname);

    cout<<"Podaj Imię: ";
    cin>>s;
    for(int i=0;i<s.length();i++) p.name.push_back(s[i]);

    cout<<"Podaj Nazwisko: ";
    cin>>s;
    for(int i=0;i<s.length();i++) p.surname.push_back(s[i]);

    cout<<"Podaj mail: ";
    cin>>s;
    for(int i=0;i<s.length();i++) p.mail.push_back(s[i]);

    cout<<"Podaj numer telefonu: ";
    cin>>s;
    for(int i=0;i<s.length();i++) p.phone.push_back((int)s[i]-'0');
    
    ab.bk.push_back(p);

    ab.write(bookname);
}

void UI::help(){
    cout<<"Witaj w ksiazce adresowej!\n\nAby dodać kontakt dopisz na końcu polecenia 'add'\n";
    cout<<"Aby pokazac książkę napisz na koncu polecenia 'list + nazwa_książki\n\n";
}

void adressbook::write(string bookname){
    sort();
    string ss;
    for(int i=0;i<ab.bk.size();i++){
        for(int q=0;q<ab.bk[i].name.size();q++) ss += ab.bk[i].name[q];
        ss += ";";
        for(int q=0;q<ab.bk[i].surname.size();q++) ss += ab.bk[i].surname[q];
        ss += ";";
        for(int q=0;q<ab.bk[i].mail.size();q++) ss += ab.bk[i].mail[q];
        ss += ";";
        for(int q=0;q<ab.bk[i].phone.size();q++) ss += ab.bk[i].phone[q] + '0';
        ss += ";";
    }

    fstream bookfile;

    bookfile.open(bookname, ios::trunc | ios::in | ios::out);


    bookfile << ss;

    bookfile.close();
}
void adressbook::read(string bookname){
    string s;
    Person p;
    int nper=0;//nr persony
    int phase=0;

    fstream bookfile;

    bookfile.open(bookname, ios::in);

    while(bookfile.is_open() && !bookfile.eof()){

        getline(bookfile, s, ';');

        for(int i=0;i<s.length();i++){
            if(phase==0)p.name.push_back(s[i]);//name
            else if(phase==1)p.surname.push_back(s[i]);//surname
            else if(phase==2)p.mail.push_back(s[i]);//mail
            else if(phase==3)p.phone.push_back(s[i]-'0');//phone
        }
        phase++;
        if(phase>3){
            ab.bk.push_back(p);
            p.name.clear();
            p.surname.clear();
            p.mail.clear();
            p.phone.clear();
            phase=0;
            nper++;
        }
    }
    bookfile.close();
}

    

int main(int argc, char* argv[])
{
    UI iface;

    bool show_help = 1;
    for(int i=1;i<argc;i++){
        if (string(argv[i]) == "help"){
            break; 
        }else if(string(argv[i]) == "add"){ //dodawanie adresow
            show_help = 0;
            iface.add();
        }else if(string(argv[i]) == "list" && (i+1)<argc){
            i++;
            show_help = 0;
            iface.list(string(argv[i]));
        }else{
            cout<<"Niepoprawne dane\n\n";
            break;
        }
    }
    if(show_help)iface.help();
    return 0;
}
