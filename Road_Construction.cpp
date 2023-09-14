#include<bits/stdc++.h>
using namespace std;
 
int parent[100005];
int parentSize[100005];
 
int maxx = -1;
 
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
            maxx = max(maxx, parentSize[leaderA]);
        }
 
        else{
            parent[leaderA] = leaderB; 
            parentSize[leaderB] += parentSize[leaderA];
            maxx = max(maxx, parentSize[leaderB]);
        }
    }
}
 
int main()
{
    int n, m, i;
    cin >> n >> m;
    dsu_set(n);
    
    int component = n;
    
    while(m--){
        int a, b;
        cin >> a >> b;
 
        int leaderA = findLeader(a);
        int leaderB = findLeader(b);
 
        if(leaderA != leaderB){
            component--;
            dsu_union(a, b);
        }
        cout << component << " " << maxx << endl;
    }

    // for(i=1; i<=n; i++){
    //     cout << "Leader of " << i << ": " << findLeader(i) << endl; 
    // }
    
    return 0;
}