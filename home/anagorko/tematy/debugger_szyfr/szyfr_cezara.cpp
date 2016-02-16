#include<iostream>
#include<string>

using namespace std;

int main()
{
    char s[] = "";              // szyfrogram (do wygenerowania)
    char h[] = "grr";           // haslo
    int d_h = sizeof(h);        // długość hasła
    char t[] = "abrakadabra";   // tekst jawny
    int d_t = sizeof(t);        // długość tekstu jawnego

	for (int i = 0; i < d_t; i++) {
		char c = t[i];
		char p = h[i % d_h] - 'a';

		c = c + p;
		if (c > 'z') { 
            c = c - 26; 
        }

		s[i] = c;
	}

	cout << "Szyfrogram: " << s << endl;

	return 0;
}