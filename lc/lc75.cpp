#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; // 10^9 + 7
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s="hello";
    sort(s.begin(), s.end());
    cout << s ;


    return 0;
}

class Solution_1768 {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> result(word1.size()+word2.size());
        int i=0, j=0, k=0, msize=min(word1.size(), word2.size());
        while(i<msize && j<msize){
            result[k++]=word1[i++];
            result[k++]=word2[j++];
        }
        while(i<word1.size()) result[k++]=word1[i++];
        while(j<word2.size()) result[k++]=word2[j++];
        return string(result.begin(), result.end());
    }
};

class Solution_1071 {
public:
    string gcdOfStrings(string str1, string str2) {
        // if x is ans then str1=xxx str2=xx 
        if(!(str1+str2 == str2+str1)) return "";        

        // find len(x)
        int xlen = min(str1.size(), str2.size());
        while(xlen>=0){
            if(str1.size()%xlen==0 && str2.size()%xlen==0) break;
            xlen--;
        }

        return str1.substr(0, xlen);
    }
};





































