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

    ll n, x, i, j, val1, val2;
    cin >> n >> x;
    ll a[n+5];
    pair<ll, ll> p[n+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }

    for(i=0; i<n; i++){
        p[i].first = a[i];
        p[i].second = i+1;
    }

    sort(p, p+n);

    bool flag = false;

    i = 0;
    j = n-1;

    while(i<j){
        if(p[i].first+p[j].first == x){
            val1 = p[i].second;
            val2 = p[j].second;
            flag = true;
            break;
        }
        else if(p[i].first+p[j].first > x){
            j--;
        }
        else{
            i++;
        }
    }

    if(flag) cout << min(val1, val2) << " " << max(val1, val2) << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}


