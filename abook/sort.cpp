#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    vector<int> v = { 3, 1, 4, 1, 5, 9 };
    
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;

    sort(begin(v), end(v));
    
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;    
}
