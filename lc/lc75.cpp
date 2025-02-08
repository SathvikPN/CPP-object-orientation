#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; // 10^9 + 7

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

class Solution_345 {
public:
    string reverseVowels(string s) {
        set<char> vset={'a','e','i','o','u','A','E','I','O','U'};
        int i=0, j=s.size()-1;
        while(i<j){
            while(i<j && !vset.count(s[i])) i++;
            while(i<j && !vset.count(s[j])) j--;
            // i==j OR (si,sj vowels)
            swap(s[i++], s[j--]); // see
        }
        return s;
    }
};

class Solution_151 {
public:
    string reverseWords(string s) {
        vector<string> words;
        vector<char> word;
        for(char c:s){
            if(!isspace(c)) {word.push_back(c); continue;}
            words.push_back(string(word.begin(), word.end()));
            word.clear();
        }
        words.push_back(string(word.begin(), word.end()));
        s.clear();
        for(int i=words.size()-1; i>=0; i--) {
            if(words[i]=="") continue;
            s = s + words[i] + " ";
        }
        s.pop_back(); // see
        return s;
    }
};

class Solution_238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        vector<int> pp(n+2, 1); // prefixProduct 0 1..n n+1
        vector<int> sp(n+2, 1); // suffixProduct

        for(int i=1; i<=n; i++) pp[i] = nums[i-1] * pp[i-1];
        for(int i=n; i>=1; i--) sp[i] = nums[i-1] * sp[i+1];

        for(int i=1; i<=n; i++) answer[i-1] = pp[i-1] * sp[i+1];
        return answer;
    }
};

class Solution_334 {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;

        int low = INT_MAX;
        int mid = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid) return true;

            if(nums[i]<low)                 low = nums[i]; 
            if(nums[i]>low && nums[i]<mid)  mid = nums[i]; 
            // printf("[%d] %d   %d %d\n", i, nums[i], low, mid);
        }
        return false;
    }
};

class Solution_443 {
public:
int compress(vector<char>& chars) {
        int n = chars.size();
        if(n <= 1) return n;

        int i = 0;
        for(int j=0; j<n; j++){
            int count = 1;
            while(j < n-1 && chars[j] == chars[j+1]){
                count++;
                j++;
            }

            chars[i++] = chars[j];  
            if(count!=1){
                for(auto d: to_string(count)) chars[i++] = d;
            }
        }
        return i;
    }
};

class Solution_283 {
public:
    void moveZeroes(vector<int>& nums) {
        int next = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]) swap(nums[i], nums[next++]);
        }
    }
};

class Solution_392 {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        if(i==s.size()) return true;
        while(j<t.size()){
            if(s[i]==t[j]){
                i++; j++;
                if(i==s.size()) return true;
            } else {
                j++;
            }
        }
        return false;
    }
};

class Solution_11 {
public:
    int maxArea(vector<int>& height) {
        int hmin, i=0, j=height.size()-1;
        int amax=0;
        while(i<j){
            hmin = min(height[i], height[j]);
            amax = max(amax, hmin*(j-i));
            if(hmin == height[i]) i++;
            else j--;
        }
        return amax;
    }
};

class Solution_1679 {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count=0;
        int i=0, j=nums.size()-1;
        while(i<j){
            int s=nums[i]+nums[j];
            if(s==k) {count++; i++; j--; continue;}
            if(s<k) i++;
            else j--;
        }
        return count;
    }
};

class Solution_643 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int j,msum=0, csum=0;
        for(j=0;j<k; j++) csum+=nums[j];
        msum = csum;
        for(j=k;j<nums.size();j++){
            csum = csum + nums[j] - nums[j-k];
            msum = max(msum, csum);
        }

        return double(msum)/double(k);
    }
};

class Solution_1456 {
public:
    int maxVowels(string s, int k) {
        int j, vcount=0, vmax=0; 
        set<char> vset = {'a','e','i','o','u'};
        for(j=0; j<k; j++){
            if(vset.count(s[j])) vcount++;
        }

        vmax = max(vmax, vcount);
        for(j=k; j<s.size(); j++){
            if(vset.count(s[j-k])) vcount--;
            if(vset.count(s[j])) vcount++;
            vmax = max(vmax, vcount);
        }
        return vmax;
    }
};


class Solution_1004 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, n=nums.size();
        while(right<n){
            if(nums[right]==0) k--; // use k-token
            if(k<0) {
                if(nums[left]==0) k++; // release k-token
                left++;
            }
            right++;
        }

        return right-left;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, result=0, zcount=0;

        for(int right=0; right < n; right++){
            if(nums[right]==0) zcount++;
            while(zcount>1){
                if(nums[left]==0) zcount--;
                left++;
            }
            result = max(result, right - left + 1 - zcount);
        }

        return (result == n) ? result-1 : result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution_334 Solution_334;
    vector<int> nums = {2,1,5,0,4,6};
    Solution_334.increasingTriplet(nums);
    return 0;
}


























