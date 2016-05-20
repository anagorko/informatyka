#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Person{

    int id;

    vector<char> name;
    vector<char> surname;
    vector<char> mail;
    vector<int> phone;

};
class adressbook {

	vector<Person> bk;

    void read(string bookname);
	void write(string bookname);


};
class UI {//User Interface
public:
	void help();

    void list();//TODO
    void add();//TODO
    void modify();//TODO
    void del();//TODO

};

void UI::help(){
    cout<<"Witaj w ksiazce adresowej!\n";
}

void adressbook::write(string bookname){
    
    fstream bookfile;

    bookfile.open(bookname, ios::trunc);

    int p = 1;
    bookfile << p;

    bookfile.close();
}

    

int main(int argc, char* argv[])
{
    UI iface;

    if (argc == 1 || (argc > 1 && string(argv[1]) == "help")) {
        iface.help(); 
        return 0;
    }
}