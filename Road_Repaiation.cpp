// Kruskal's Algorithm //

#include<bits/stdc++.h>
#define  pb  push_back
#define  ll  long long
using namespace std;

class Edge
{
    public:
        int a;
        int b;
        int w;
 
        Edge(int a, int b, int w){
            this->a = a;
            this->b = b;
            this->w = w;
        }
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}      

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
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    ll sum = 0;
    
    while(e--){
        int a, b, w;
        cin >> a >> b >> w;

        v.pb(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    for(Edge val: v){
        int a = val.a;
        int b = val.b;
        int w = val.w;

        int leaderA = findLeader(a);
        int leaderB = findLeader(b);

        if(leaderA != leaderB){
            ans.pb(val);
            dsu_union(a, b);
        }
    }

    for(Edge value: ans){
        sum += value.w;
    }

    if(ans.size() == n-1) cout << sum << endl;
    else cout << "IMPOSSIBLE" << endl;
    
    return 0;
}


// -------------------------------------------------------------------- //

// Prim's Algorithm //

/*
#include<bits/stdc++.h>
#define  pb  push_back
#define  ll  long long
using namespace std;
 
int const N = 1e5+5;
vector<pair<int, int>> v[N];
bool visited[N];
int cnt;
int n, e;
ll sum = 0;
 
class Edge
{
    public:
        int a;
        int b;
        int w;
 
        Edge(int a, int b, int w){
            this->a = a;
            this->b = b;
            this->w = w;
        }
};
 
class cmp
{
    public:
        bool operator()(Edge a, Edge b){
            return a.w > b.w;       // a.w jodi b.w er theke boro hoy tahole swap kore dibe (choto theke boro swap er jonno) //
        }
};
 
bool prims(int s){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));
 
    vector<Edge> edgeList;
    int cnt = 0;
 
    while(!pq.empty()){
        Edge parent = pq.top();
        pq.pop();
 
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
 
        if(visited[b] == false){
            visited[b] = true;
            cnt++;
            edgeList.pb(parent);
        
            for(int i=0; i<v[b].size(); i++){
                pair<int, int> child = v[b][i];
 
                int childNode = child.first;
                int childCost = child.second;
 
                if(visited[childNode] == false){
                    pq.push(Edge(b, childNode, childCost));
                }
            }
        } 
    }
 
    for(Edge val: edgeList){
        sum += val.w;
    }
 
    if(cnt < n) return false;
    else return true;
}
 
int main()
{
    cin >> n >> e;
 
    while(e--){
        int a, b, w;
        cin >> a >> b >> w;
 
        v[a].pb({b, w});
        v[b].pb({a, w});
    }
 
    if(prims(1)) cout << sum << endl;
    else cout << "IMPOSSIBLE" << endl;
 
    return 0;
}
*/

// ------------------------------------------------------------------------- //

/*
#include<bits/stdc++.h>
#define  pb  push_back
#define  ll  long long
using namespace std;

int const N = 1e5+5;
vector<pair<int, int>> v[N];
bool visited[N];

class Edge
{
    public:
        int a;
        int b;
        int w;

        Edge(int a, int b, int w){
            this->a = a;
            this->b = b;
            this->w = w;
        }
};

class cmp
{
    public:
        bool operator()(Edge a, Edge b){
            return a.w > b.w;       
        }
};

void prims(int s, int n){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));

    vector<Edge> edgeList;
    int cnt = 0;

    while(!pq.empty()){
        Edge parent = pq.top();
        pq.pop();

        int a = parent.a;
        int b = parent.b;
        int w = parent.w;

        if(visited[b] == false){
            visited[b] = true;
            cnt++;
            edgeList.pb(parent);
        
            for(int i=0; i<v[b].size(); i++){
                pair<int, int> child = v[b][i];

                int childNode = child.first;
                int childCost = child.second;

                if(visited[childNode] == false){
                    pq.push(Edge(b, childNode, childCost));
                }
            }
        } 
    }

    ll sum = 0;

    for(Edge val: edgeList){
        sum += val.w;
    }

    if(cnt < n) cout << "IMPOSSIBLE" << endl;
    else cout << sum << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b, w;
        cin >> a >> b >> w;

        v[a].pb({b, w});
        v[b].pb({a, w});
    }

    prims(1, n);

    return 0;
}
*/