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
void beautiful_permutations();
void number_spiral();

int main() {
    // iofile();
    hello();
    return 0;
}

void number_spiral() {
    int t; cin >> t;
    for (;t>0; t--) {
        ll y; cin >> y;
        ll x; cin >> x;

        ll d = max(x,y);
        ll dmax = (d*d);
        if (d&1) {
            cout << dmax-y+1 - (d-x) << endl;
        } else {
            cout << dmax-x+1 - (d-y) << endl;
        }
    }
    
}

void beautiful_permutations() {
    int n; cin >> n;
    if ((n < 4) && (n!=1)) {
        cout << "NO SOLUTION";
        return;
    }

    int start;
    start = (n&1) ? 1 : 2;
    for (int i=start; i<=n; i+=2) {
        cout << i << " ";
    }

    start = (start==1) ? (start+1) : (start-1); 
    for (int i=start; i<=n; i+=2) {
        cout << i << " ";
    }
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
