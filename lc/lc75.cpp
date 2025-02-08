#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; // 10^9 + 7
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1,2,3};
    cout << *max_element(a.begin(), a.end());

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
        return string(result.begin(), result.end()); // see
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

        return str1.substr(0, xlen); // see
    }
};

class Solution_1431 {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        int cmax = *max_element(candies.begin(), candies.end()); // see
        for(int i=0; i<result.size(); i++){
            if(candies[i]+extraCandies >= cmax) result[i]=true;
        }
        return result;
    }
};

class Solution_605 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]) continue;
            if(i-1>=0 && flowerbed[i-1]) continue;
            if(i+1<flowerbed.size() && flowerbed[i+1]) continue;
            flowerbed[i]=1;  n--;
            if(n==0) return true;
        }
        return false;
    }
};

































