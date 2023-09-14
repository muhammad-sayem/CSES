// BFS //

#include<bits/stdc++.h>
#define  pii  pair<int, int>
using namespace std;

int n, m;
const int N = 1e3+5;
bool visited[N][N];
char a[N][N];
vector<pii> path = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int cI, int cJ){
    if(cI>=0 && cI<n && cJ>=0 && cJ<m && a[cI][cJ] == '.'){
        return true;
    }
    else{
        return false;
    }
}

void bfs(int si, int sj){
    queue<pii> q;
    q.push({si, sj});

    visited[si][sj] = true;

    while(!q.empty()){
        pii parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();

        for(int i=0; i<4; i++){
            pii p = path[i];

            int cI = p.first + pI;
            int cJ = p.second + pJ;

            if(isValid(cI, cJ)){
                if(visited[cI][cJ] == false){
                    visited[cI][cJ] = true;
                    q.push({cI, cJ});
                }
            }
        }
    }
}

int main()
{
    int i, j;
    cin >> n >> m;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(visited[i][j] == false && a[i][j] == '.'){
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

// ------------------------------------------------------------------------ //

// DFS //

/*
#include<bits/stdc++.h>
#define pii  pair<int,int>
using namespace std;

int n, m;
const int N = 1e3+5;
bool visited[N][N];
char a[N][N];
vector<pii> path = {{-1,0}, {1,0}, {0,-1}, {0,1}};


bool isValid(int cI, int cJ){
    if(cI>=0 && cI<n && cJ>=0 && cJ<m && a[cI][cJ] == '.'){
        return true;
    }
    else{
        return false;
    }
}

void dfs(int si, int sj){
    visited[si][sj] = true;

    for(int i=0; i<4; i++){
        pii p = path[i];

        int cI = si + p.first;
        int cJ = sj + p.second;

        if(isValid(cI, cJ)){
            if(visited[cI][cJ] == false){
                dfs(cI, cJ);
            }
        }

    }
}

int main()
{
    int i, j;
    cin >> n >> m;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(visited[i][j] == false && a[i][j] == '.'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
*/

// ----------------------------------------------------------------------- //

// Using DSU //

/*

#include<bits/stdc++.h>
using namespace std;
 
int parent[100005];
int parentSize[100005];
 
void dsu_set(int n){
    for(int i=1; i<=n; i++){
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
 
int findLeader(int node){
    while(parent[node] != -1){
        node = parent[node];
    }
    return node;
}
 
void dsu_union(int a, int b){
    int leaderA = findLeader(a);
    int leaderB = findLeader(b);
 
    if(leaderA != leaderB){
 
        if(parentSize[leaderA] > parentSize[leaderB]){
            parent[leaderB] = leaderA; 
            parentSize[leaderA] += parentSize[leaderB];
        }
 
        else{
            parent[leaderA] = leaderB; 
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
 
int main()
{
    int n, e, i;
    cin >> n >> e;
    dsu_set(n);
 
    while(e--){
        int a, b;
        cin >> a >> b;
 
        dsu_union(a, b);
    }
 
    set<int> s;
 
    for(i=1; i<=n; i++){
        int leader = findLeader(i);
        s.insert(leader);
    }
 
    vector<int> v;
 
    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);
    }
    
    cout << v.size()-1 << endl;
 
    for(i=0; i<v.size()-1; i++){
        cout << v[i] << " " << v[i+1] << endl;
    }
 
    return 0;
}


*/