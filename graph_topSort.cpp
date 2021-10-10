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

const int Maxn = 300005;
 
int n, m;
char str[Maxn];
// string str;
vector <int> neigh[Maxn];
int tk[Maxn];
vector <int> seq;
int dp[Maxn];
int res;

bool findLoop(int v)
{
    if (tk[v] == 2)
        return false;
    if (tk[v] == 1)
        return true;
    tk[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++)
        if (findLoop(neigh[v][i]))
            return true;
    tk[v] = 2;
    seq.push_back(v);
    return false;
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

    // cin >> n >> m;

    // cin >> str;
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!tk[i])
            if (findLoop(i))
            { 
                printf("-1\n");
                return 0;
            }
    for (char let = 'a'; let <= 'z'; let++)
    {
        for (int i = 0; i < seq.size(); i++)
        {
            int v = seq[i];
            int my = (str[v] == let);
            dp[v] = my;
            for (int j = 0; j < neigh[v].size(); j++)
                dp[v] = max(dp[v], dp[neigh[v][j]] + my);
            res = max(res, dp[v]);
        }
    }

    printf("%d\n", res);
    ////////////////////////////      input      ////////////////////////////
    

    return 0;
}