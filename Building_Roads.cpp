// By Using BFS //

#include<bits/stdc++.h>
#define      endl            '\n'
#define      yes             "YES"
#define      no              "NO"
#define      ll              long long
#define      pb              push_back
#define      pii             pair <int,int>
#define      pll             pair <long long,long long>
#define      rev(a)          reverse(a, a+n);
#define      Srev(s)         reverse(s.begin(), s.end());
#define      sz(s)           s.size()
#define      gcd(a,b)        __gcd(a,b)
#define      lcm(a,b)        (a*b)/gcd(a,b)
#define      fastIO          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v] == false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    fastIO;       

    int n, e, i;
    cin >> n >> e; 
    vector<int> v;

    while(e--){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int connectedComponants = 0;

    for(i=1; i<=n; i++){
        if(visited[i] == false){
            v.pb(i);
            bfs(i);
        }
    }

    int sz = v.size();

    cout << sz-1 << endl;

    for(i=0; i<sz-1; i++){
        cout << v[i] << " " << v[i+1] << endl;
    }

    return 0;
}

// --------------------------------------------------------------------- //

// By using DFS //

/*
#include<bits/stdc++.h>
#define      endl            '\n'
#define      yes             "YES"
#define      no              "NO"
#define      ll              long long
#define      pb              push_back
#define      pii             pair <int,int>
#define      pll             pair <long long,long long>
#define      rev(a)          reverse(a, a+n);
#define      Srev(s)         reverse(s.begin(), s.end());
#define      sz(s)           s.size()
#define      gcd(a,b)        __gcd(a,b)
#define      lcm(a,b)        (a*b)/gcd(a,b)
#define      fastIO          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;

    for(int v: adj[u]){
        if(visited[v] == false){
            dfs(v);
        }
    }
}

int main()
{
    fastIO;       

    int n, e, i;
    cin >> n >> e; 
    vector<int> vec;

    while(e--){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int connectedComponants = 0;

    for(i=1; i<=n; i++){
        if(visited[i] == false){
            vec.pb(i);
            dfs(i);
            connectedComponants++;
        }
    }

    cout << connectedComponants-1 << endl;

    int val = connectedComponants;

    for(i=0; i<val-1; i++){
        cout << vec[i] << " " << vec[i+1] << endl;
    }

    return 0;
}
*/




