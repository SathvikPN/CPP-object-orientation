#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}

// https://leetcode.com/problems/maximum-subarray/description/ --------------------------------------
int maxSubArray(vector<int>& nums) {
    int best=nums[0], sum=nums[0];
    for(int i=1; i<nums.size(); i++){
        sum = max(sum+nums[i], nums[i]);
        best = max(best, sum);
    }
    return best;
}

// https://leetcode.com/problems/insert-interval/ --------------------------------------
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n=intervals.size(), i=0;
    vector<vector<int>> result;
    while(i<n && intervals[i][1] < newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }

    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}


// https://leetcode.com/problems/01-matrix/ --------------------------------------
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    // multisource BFS
    int r=mat.size(), c=mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(r, vector<int>(c,-1));
    int dy[4] = {0,0,1,-1};
    int dx[4] = {-1,1,0,0};
    
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(mat[y][x]==0){
                q.push({y,x});
                dist[y][x]=0;
            }
        }
    }

    while(!q.empty()){
        auto [y,x] = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            bool inbound = (ny>=0 && nx>=0 && ny<r && nx<c);
            if(!inbound) continue;
            if(dist[ny][nx]==-1){
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return dist;
}


// https://leetcode.com/problems/k-closest-points-to-origin/ --------------------------------------
// learn: k closest or k smallest or k largest it's a heap question
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // priority queue: minHeap
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<points.size(); i++){
        auto point = points[i];
        // distsq = (x2-x1)^2 + (y2-y1)^2
        int dist = pow(point[0],2) + pow(point[1],2); 
        pq.push({-dist, i});
    }

    vector<vector<int>> result;
    while(k--){
        auto[dist,i] = pq.top(); pq.pop();
        result.push_back(points[i]);
    }
    return result;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// learn: input maybe letters, digits, spaces ==> ASCII charset 128
// 'a' → 97
// 'z' → 122
// 'A' → 65
// 'Z' → 90
// ' ' (space) → 32
int lengthOfLongestSubstring(string s) {
    int mxlen=0, len=0;
    vector<int> charIdx(128,-1);
    int left=0;
    for(int right=0; right<s.size(); right++){
        // if char within substring
        if(charIdx[s[right]] >= left){
            left = charIdx[s[right]]+1;
        }
        charIdx[s[right]] = right;
        mxlen = max(mxlen, right-left+1);
    }
    return mxlen;
}


// https://leetcode.com/problems/3sum/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    if(nums.size()<3) return {};
    if(nums[0]>0) return {};

    int n = nums.size();
    for(int i=0; i<n; ++i){
        if(nums[i]>0) break;
        if(i>0 && nums[i-1]==nums[i]) continue;
        int j=i+1, k=n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum == 0){
                result.push_back({nums[i], nums[j], nums[k]});
                int last_low = nums[j], last_high = nums[k];
                while(j<k && nums[j]==last_low) j++;
                while(j<k && nums[k]==last_high) k--;
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
    return result;
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    queue<TreeNode*> q; q.push(root);
    while(!q.empty()){
        int lsize = q.size();
        vector<int> level;
        while(lsize--){
            auto node = q.front();  q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}


// https://leetcode.com/problems/clone-graph/ -----------------------
unordered_map<Node*, Node*> mp;
Node* cloneGraph(Node* node) {
    if(!node) return node;

    Node* nodecopy = new Node(node->val, {});
    mp[node] = nodecopy;
    queue<Node*> q; q.push(node);
    while(!q.empty()){
        Node* node = q.front(); q.pop();
        for(auto nxtnode:node->neighbors){
            if(!mp.count(nxtnode)){
                mp[nxtnode] = new Node(nxtnode->val, {});
                q.push(nxtnode);
            }
            mp[node]->neighbors.push_back(mp[nxtnode]);
        }
    }
    return nodecopy;
}


// https://leetcode.com/problems/product-of-array-except-self/
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


// https://leetcode.com/problems/number-of-islands/submissions/1546487834/
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int y, int x, vector<vector<char>>& grid){
    grid[y][x] = '0';
    for(int i=0; i<4; i++){
        int ny = y+dy[i], nx=x+dx[i];
        bool inbound = (ny>=0 && nx>=0 && ny<grid.size() && nx<grid[0].size());
        if(inbound && grid[ny][nx]=='1') dfs(ny,nx,grid);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int islandCount = 0;
    for(int y=0; y<grid.size(); y++){
        for(int x=0; x<grid[0].size(); x++){
            if(grid[y][x]=='1'){
                islandCount++;
                dfs(y,x, grid);
            }
        }
    }
    return islandCount;
}


// https://leetcode.com/problems/rotting-oranges/
int orangesRotting(vector<vector<int>>& grid) {
    // multi-source BFS
    queue<pair<int,int>> q; // y,x
    vector<pair<int,int>> direction = {{0,1},{0,-1}, {1,0}, {-1,0}};
    int m=grid.size(), n=grid[0].size();
    int freshCount=0;
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(grid[y][x]==2) q.push({y,x}); // rotten-oranges
            if(grid[y][x]==1) freshCount++;
        }
    }

    if(!freshCount) return 0;
    if(q.empty()) return -1;

    int t=-1;
    while(!q.empty()){
        t++;
        int s=q.size();
        while(s--){
            auto[y,x] = q.front(); q.pop();
            for(auto [dy,dx]:direction){
                int ny=y+dy, nx=x+dx;
                if(ny>=0 && nx>=0 && ny<m && nx<n && grid[ny][nx]==1){
                    grid[ny][nx]=2;
                    q.push({ny,nx});
                    freshCount--;
                }
            }
        }
        
    }
    if(freshCount) return -1;
    return t;
}


// https://leetcode.com/problems/validate-binary-search-tree/
bool isBST(TreeNode* root, TreeNode* nmin, TreeNode* nmax){
    if(!root) return true;
    if(nmax && root->val >= nmax->val) return false;
    if(nmin && root->val <= nmin->val) return false;
    bool isLeftBST = isBST(root->left, nmin, root);
    bool isRightBST = isBST(root->right, root, nmax);
    return isLeftBST && isRightBST;
}
// learn: every node on right nested tree > root for BST
bool isValidBST(TreeNode* root) {
    return isBST(root, NULL, NULL);
}


// https://leetcode.com/problems/search-in-rotated-sorted-array/
// 6 7 1 2 3 4 5
// 3 4 5 6 7 1 2
// learn: sorted but rotated ==>
// left < mid         ==> left-sorted
//        mid < right ==> right-sorted 
int search(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;

        if(nums[left] < nums[mid]){
            // left-half sorted
            if(nums[left]<=target && target < nums[mid]){
                right = mid-1;
            } else {
                left = mid+1;
            }
        } else {
            // right-half sorted
            if(nums[mid]<target && target<=nums[right]){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
    }
    return -1;
}



// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q) return root;
    auto aleft = lowestCommonAncestor(root->left,p,q);
    auto aright = lowestCommonAncestor(root->right,p,q);
    if(!aleft) return aright;
    if(!aright) return aleft;
    return root;
}




// https://leetcode.com/problems/course-schedule/
// detect cycle in Directed Graph
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses,0); // edge incoming
    vector<vector<int>> adj(numCourses);
    for(auto x:prerequisites){
        int a=x[0], b=x[1];
        adj[b].push_back(a);
        indegree[a]++;
    }

    queue<int> q; int count=0;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0) { q.push(i); count++;}
    }

    while(q.size()){
        int p = q.front(); q.pop();
        for(auto x:adj[p]){
            indegree[x]--;
            if(indegree[x]==0) { q.push(x); count++;}
        }
    }

    return (count==numCourses);
}



// https://leetcode.com/problems/permutations/
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    do {
        result.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end())); // learn: req sorted vector

    return result;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> chosen(nums.size(), false);
    vector<int> p;
    function<void()> search = [&](void){
        if(p.size()==nums.size()){
            result.push_back(p); return;
        }

        for(int i=0; i<nums.size(); i++){
            if(chosen[i]) continue;
            chosen[i]=true; p.push_back(nums[i]);
            search();
            chosen[i]=false; p.pop_back();
        }
    };
    search();
    return result;
}



// https://leetcode.com/problems/coin-change/submissions/
int coinChange(vector<int>& coins, int amount) {
    vector<long> dp(amount+1, INT_MAX);
    dp[0]=0;
    // for(auto c:coins){
    //     for(int x=c; x<=amount; x++){
    //         dp[x]=min(dp[x], 1+dp[x-c]);
    //     }
    // }
    for(int x=1; x<=amount; x++){
        for(auto c:coins){
            if(x-c>=0) dp[x]=min(dp[x], 1+dp[x-c]);
        }
    }

    if(dp[amount]==INT_MAX) return -1;
    return dp[amount];
}


// https://leetcode.com/problems/combination-sum/ ------------
// backtrack complete search 
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // complete search - backtrack
    vector<int> v;
    vector<vector<int>> result;
    function<void(int,int)> search = [&](int i, int sum){
        if(sum==target) {result.push_back(v); return;}
        if(sum>target || i>=candidates.size()) return;
        v.push_back(candidates[i]);
        search(i, sum+candidates[i]); // re-use candidate
        v.pop_back();
        search(i+1, sum); // drop current candidate
    };
    search(0,0);
    return result;
}


// backtrack with tree 
// https://leetcode.com/problems/path-sum-ii/
vector<vector<int>> result;
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    result.clear(); 
    if(!root) return result;
    function<void(TreeNode*,int,vector<int>&)> dfs = [&](TreeNode* root, int target, vector<int>& path){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == target) result.push_back(path);
        dfs(root->left, target-root->val, path);
        dfs(root->right, target-root->val, path);
        path.pop_back();
    };
    vector<int> path;
    dfs(root, targetSum, path);
    return result;
}



// learn: directions instead of dy, dx 
// d[] = {0, 1, 0, -1, 0};
// ny=y+dy[k] nx=x+dx[k+1]


// https://leetcode.com/problems/merge-k-sorted-lists/
// learn: merge sort (hard)
ListNode* merge2List(ListNode* a, ListNode* b){
    if(!a) return b;
    if(!b) return a;
    if(a->val <= b->val){
        a->next = merge2List(a->next, b);
        return a;
    } else {
        b->next = merge2List(a, b->next);
        return b;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return NULL;
    int n = lists.size();
    while(n>1){
        for(int i=0; i<n/2; i++){
            lists[i] = merge2List(lists[i], lists[n-1-i]);
        }
        n=(n+1)/2;
    }
    return lists[0];
}


