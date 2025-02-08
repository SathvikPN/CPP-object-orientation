#include <bits/stdc++.h>

using namespace std;

// type definitions
typedef long long ll;

// function declarations 
void iofile();
void hello();
void weird_algorithm();
void missing_number();
void repetitions();
void increasing_array();

int main() {
    // iofile();
    increasing_array();

    return 0;
}

void increasing_array() {
    int n; cin >> n;
    ll arr[n], moves=0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<n; i++) {
        if (arr[i-1] > arr[i]) {
            moves += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    
    cout << moves;
}

void repetitions() {
    string s;
    cin >> s;
    ll r=1, most=1;
    for (unsigned long i=1; i<s.size(); i++) {
        if (s[i] == s[i-1]) {
            r+=1;
        } else {
            most = max(most, r);
            r = 1;
        }
    }
    cout << max(most, r) << endl;
}

void missing_number() {
    ll n; cin >> n;

    ll inpTotal = 0;
    ll x = 0;
    for (ll i=0; i<(n-1); i++) {
        cin >> x;
        inpTotal = inpTotal + x;

    }
    ll expectedTotal = (n * (n+1))/2;
    cout << expectedTotal - inpTotal;
}

void weird_algorithm() {
    ll n;
    cin >> n;

    while (n > 1) {
        cout << n << " ";
        n = (n&1) ? ((n*3)+1) : n/2;   
    }
    
    cout << 1 << "\n";
}

// Redirect standard input and output
void iofile() {
    if (freopen("input.txt", "r", stdin) == nullptr) {
        perror("Error opening input file");
        exit(1);
    }
    if (freopen("output.txt", "w", stdout) == nullptr) {
        perror("Error opening input file");
        exit(1);
    }
}

// Read line
void hello() {
    string line;
    getline(cin, line);
    cout << "hello [" << line << "]\n" << endl;
}
