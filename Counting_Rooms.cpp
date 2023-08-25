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