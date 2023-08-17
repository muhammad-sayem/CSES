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

    ll n, i, j, cnt = 0;
    cin >> n;
    vector<pair<ll, ll>> v;

    while(n--){
        ll a, b;
        cin >> a >> b;

        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());

    ll maxx = -1;

    for(i=0; i<v.size(); i++){
        if(v[i].second == 1){
            cnt++;
            maxx = max(maxx, cnt);
        }
        else{
            cnt--;
            maxx = max(maxx, cnt);
        }
    }

    cout << maxx << endl;

    return 0;
}


