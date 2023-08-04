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
int main()
{
    fastIO;        

    int n, m, i;
    cin >> n >> m;
    int a[n+5];
    int b[m+5];
    multiset<int> ms;

    for(i=0; i<n; i++){
        cin >> a[i];
        ms.insert(a[i]);
    }

    for(i=0; i<m; i++){
        cin >> b[i];
    }

    for(i=0; i<m; i++){
        auto it = ms.upper_bound(b[i]);
        if(it == ms.begin()){
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
            ms.erase(it);
        }
    }

    //cout << *ms.upper_bound(4) << endl;
    //cout << *ms.lower_bound(4) << endl;
    
    return 0;
}


