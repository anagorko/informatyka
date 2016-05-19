#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person{

};
class adressbook {

	vector<Person> bk;

	void write(string bookname) {
        
        fstream bookfile;

        bookfile.open(bookname, ios::trunc);

        for (Person& p: bk) {
            bookfile << p;
        }

        bookfile.close();
    }

};
class UI {

	void help();
};

    

int main(int argc, char* argv[])
{
    UI iface;

//    if (argc == 1 || (argc > 1 && string(argv[1]) == "help")) {
//        iface.help(); 
//        return 0;
//    }
}