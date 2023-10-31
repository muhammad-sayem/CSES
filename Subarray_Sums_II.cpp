#include<bits/stdc++.h>
#define      endl            '\n'
#define      yes             (cout << "YES\n")
#define      no              (cout << "NO\n")
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

    int n, x, i, j;
    cin >> n >> x;
    int a[n+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }

    map<ll, ll> mp;
    ll sum = 0, cnt = 0;
    mp[sum] = 1;

    for(i=0; i<n; i++){
        sum += a[i];
        cnt += mp[sum-x];
        mp[sum]++;
    }

    cout << cnt << endl;
    
    return 0;
}