#include <iostream>
#include <chrono>
using namespace std;

// W Workspace > Open Active Project Settings > Compiler > Compiler options dodać: --std=c++11

int a[1000][1000];

int main(int argc, char **argv)
{
    {
        auto begin = chrono::high_resolution_clock::now();
        
        for (int r = 0; r < 1000; r++) {
            for (int x = 0; x < 1000; x++) {
                for (int y = 0; y < 1000; y++) {
                    a[x][y] = x + y;
                }
            }
        }
        
        auto end = chrono::high_resolution_clock::now();    
        auto dur = end - begin;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        cout << "XY:" << ms << endl;
    }
    
    {
        auto begin = chrono::high_resolution_clock::now();
        
        for (int r = 0; r < 1000; r++) {
            for (int x = 0; x < 1000; x++) {
                for (int y = 0; y < 1000; y++) {
                    a[y][x] = x + y;
                }
            }
        }
        
        auto end = chrono::high_resolution_clock::now();    
        auto dur = end - begin;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        cout << "YX:" << ms << endl;
    }
    
    return 0;
}
