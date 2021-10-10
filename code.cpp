#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 1e9+7;
 
int max(int x, int y)
{
    return (x>y)?x:y;
}
// std::vector<pair<int,int> unecces;
void dfs(int u, vector<int> adj[], 
    vector<bool> &visited) {
    visited[u] = true;
    for (int v : adj[u])
    {
        if(!visited[v])
            dfs(v,adj,visited);
    }
}
 
int gcd(int a, int b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
 
void fillDepth(int parent[], int i, int depth[]) 
{
    if (depth[i]) 
        return; 
    if (parent[i] == -1) 
    { 
        depth[i] = 1; 
        return; 
    } 
    if (depth[parent[i]] == 0) 
        fillDepth(parent, parent[i], depth);  
    depth[i] = depth[parent[i]]  + 1; 
} 
 
int findHeight(int parent[], int n) 
{
    int depth[n]; 
    for (int i = 0; i < n; i++) 
        depth[i] = 0;
 
    for (int i = 0; i < n; i++) 
        fillDepth(parent, i, depth); 
 
    int ht = depth[0]; 
    for (int i=1; i<n; i++) 
        if (ht < depth[i]) 
            ht = depth[i]; 
    return ht; 
} 
string fun(string ans, string s, int n, int k, int c0, int c1, int cQ)
{
    for(int i=k;i<n;i++)
        {
            if(s[i] == '1')
                c1++;
            else if(s[i] == '0')
                c0++;
            
            if(s[i-k] == '1')
                c1--;
            else if(s[i-k] == '0')
                c0--;
              
            // cout << c0-c1 << endl;
            if(s[i] == '?')
            {
                if(s[i-k] == '1')
                {
                    s[i] = '1';
                    c1= 0;
                    c0 = 0;
 
                }
                else if(s[i-k] == '0')
                {
                    s[i] = '0';
                    c1= 0;
                    c0 = 0;
 
                }
                else
                {
                    ans = "NO";
                    break;
                }
            }
            if(c1 != c0)
            {
                int diff = abs(c1-c0);
                if(diff>cQ)
                {
                    ans = "NO";
                    break;
                }
            }
        }
        return ans;
}
 
// int gcd(int a, int b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b % a, a); 
// } 
  
// Function to find gcd of array of 
// numbers 
// int findGCD(int arr[], int n) 
// { 
//     int result = arr[0]; 
//     for (int i = 1; i < n; i++) 
//     { 
//         result = gcd(arr[i], result); 
  
//         if(result == 1) 
//         { 
//            return 1; 
//         } 
//     } 
//     return result; 
// } 
 
bool isPowerOfTwo (int x) 
{ 
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1))); 
} 
bool funCheck(int x)
{
    vector<int> v;
    int m = x;
    while(m)
    {
        int temp = m%10;
        if(temp!=0)
        v.push_back(temp);
        m = m/10;
    }
    int s = v.size();
    for(int i= s-1;i>=0;i--)
    {
        if(x%v[i])
        {
            return false;
        }
    }
    return true;
}
int checkNUM(int n, int d)
{
    while(n)
    {
        int temp = n%10;
        if(temp==d)
            return 1;
        n/=10;
    }
    return 0;
}
string hackTag(string s, vector<int> a)
{
    int n = a.size();
    vector<string> subs;
    int ini = 0;
    for (int i = 0; i < n; i++)
    {
        int len = a[i];
        string temp = s.substr(ini, len);
        ini+=len;
        subs.push_back(temp);
        // cout << temp << endl;
    }
    string ans = "";
    int f = 0;
    vector<string> oddPlaces;
    vector<string> evePlaces;
    // cout << "size = "<< subs.size() << endl;
    for (int i = 0; i < n; i+=2)
    {
        string temp = subs[i];
        oddPlaces.push_back(temp);
        // cout << temp << endl;
    }
    // cout << " " << endl;
    for (int i = 1; i < n; i+=2)
    {
        string temp = subs[i];
        // cout << temp << endl;
        evePlaces.push_back(temp);
    }
    for (int i = 0; i < n/2; i++)
    {
        ans+=evePlaces[i]+oddPlaces[i];
    }
    // cout << ans << endl;
    if(n%2)
    {
        // cout << ans << endl;
        ans+=oddPlaces.back();   
    }
    return ans;
}
 
vector<int> hackTag4(int n , int m, vector<vector<int>> queries)
{
    int qSize = queries.size();
    int board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = (i+1)*(j+1);
        }
    }
    
}
 
int maxPow2(int n) {
    int c = 0;
    while(n>1)
    {
        c++;
        n/=2;
    }
    return c;
} 
int powOf2(int n) {
    int c = 1;
    while(n) {
        c*=2;
        n--;
    }
    return c;
} 
void findNext(string &next, string s) {
    int n = s.length();
    next = s;
    next[n-1] = '0';
    for (int i = n-2; i >= 0; i--)
    {
        // if(s[i+1] == s[i] || s[i] == 'F' || s[i+1] == 'F')
        //     next[i] = '0';
        // else
        //     next[i] = '1';
        int j = i+1;
        int flag = 0;
        while((s[j] == 'F') && j < n) {
            if(s[j] == s[i]) {
                flag = 1;
                next[i] = '0';
            }
            j++;
        }
        if(flag == 0)
            next[i] = '1';
    }
}
int minSwitch(string s) {
    int n = s.length();
    char last = 'F';
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'F')
            continue;
        else {
            if(s[i] != last) {
                if(last != 'F')
                    ans++;
                last = s[i];
            }
        }
    }
    return ans;
}
bool func(vector<int> v) {
    sort(v.begin(), v.end());
    int a = v[0];
    int b = v[1];
    int c = v[2];
    a = a*2;
    c-=a;
    if((a == b && a!=c) || (a == c && a!=b))
        return false;
    if(a == b && a == c)
        return true;
    else {
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        return func(v);
    }
}
int solve1(vector<int> a) 
{
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i+=2)
    {
        // if(a[i]<0)
            ans+=a[i];
    }
    return ans;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    
    int p = 998244353;
    int t;
    cin >> t;
    int test = 1;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '0') {
                int left = i, right = i;
                while(left>=0 && s[left] == '0') {
                    left--;
                    if(left < 0)
                        left = INT_MAX;
                }
                while(right<n && s[right] == '0') {
                    right++;
                    if(right >= n)
                        right = INT_MAX;
                }
                int leftDis = abs(left-i);
                int rightDis = abs(right-i);
                ans += min(leftDis, rightDis);
            }
        }
        cout << "Case #" << test << ": " << ans << endl;
        test++;
    }
    ////////////////////////////      input      ////////////////////////////
    
 
    return 0;
}


boolean helper(vector<vector<int>> maze, int i, int j){
    if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || maze[i][j]==0)
        return false;
    if(maze[i][j]==9)
        return true;
    maze[i][j]=0;
    boolean op1,op2,op3,op4;
    op1 = helper(maze,i+1,j);
    op2 = helper(maze,i,j+1);
    op3 = helper(maze,i-1,j);
    op4 = helper(maze,i,j-1);
    maze[i][j] = 1;
    return (op1|| op2 || op3 || op4);
}
int chunkOfCheese(vector<vector<int>> maze){
    
    if(helper(maze,0,0))
        return 1;
    return 0;

}


struct BSTNode
{
    struct BSTNode *left;
    int data;
    int freq;
    struct BSTNode *right;
};
struct dataFreq
{
    int data;
    int freq;
};
int compare(const void *a, const void *b)
{
    return ( (*(const dataFreq*)b).freq - (*(const dataFreq*)a).freq );
}
BSTNode* newNode(int data)
{
    struct BSTNode* node = new BSTNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->freq = 1;
    return (node);
}
BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data == root->data)
        root->freq += 1;
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
void store(BSTNode *root, dataFreq count[], int *index)
{
    if (root == NULL) return;
    store(root->left, count, index);
  
    count[(*index)].freq = root->freq;
    count[(*index)].data = root->data;
    (*index)++;
  
    store(root->right, count, index);
}
vector<int> sortByFrequency(vector<int> &arr)
{
    int n = arr.size();
    struct BSTNode *root = NULL;
    for (int i = 0; i < n; ++i)
        root = insert(root, arr[i]);
  
    dataFreq count[n];
    int index = 0;
    store(root, count, &index);
  
    qsort(count, index, sizeof(count[0]), compare);
  
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        for (int freq = count[i].freq; freq > 0; freq--)
            arr[j++] = count[i].data;
    }
    return arr;
}