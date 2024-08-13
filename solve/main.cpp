#include <bits/stdc++.h>

using namespace std;

// function declarations 
void iofile();
void hello();

int main() {
    iofile();

    hello();

    return 0;
}

// Redirect standard input and output
void iofile() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

// Read line
void hello() {
    string line;
    getline(cin, line);
    cout << "hello [" << line << "]\n" << endl;
}
