#include<iostream>
#include<string>

using namespace std;

int main()
{
    string h = "grr";           // haslo
    string t = "abrakadabra";   // tekst jawny
    string s = "";              // szyfrogram (do wygenerowania)
    int d_h = h.length();        // długość hasła
    int d_t = t.length();        // długość tekstu jawnego

	for (int i = 0; i < d_t; i++) {
		char c = t[i];
		char p = h[i % d_h] - 'a'; // czy tu nie powinno być +1?

		if (c + p> 'z') { 
            c = c - 26; 
        }

        c = c + p;

		s = s + c;
	}

	cout << "Szyfrogram: " << s << endl;

	return 0;
}