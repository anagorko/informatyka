#include<iostream>
using namespace std;

// argc -- argument count
// argv -- argument values (tablica napisów)

int main(int argc, char* argv[])
{
    cout << "Liczba argumentów: " << argc << endl;
    
    for (int i = 0; i < argc; i++) {
        cout << "Argument nr " << i << ": " << argv[i] << endl;
    }

    if (argc > 1 && string(argv[1]) == "help") {
        cout << "Programu używa się tak a tak" << endl;
    }
        
    return 0;
}

