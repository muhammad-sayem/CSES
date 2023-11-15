#include<bits/stdc++.h>
#define      nl              '\n'
#define      yes             (cout << "YES\n")
#define      no              (cout << "NO\n")
#define      yy              (cout << "Yes\n")
#define      nn              (cout << "No\n")
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

    int n, x, i;
    cin >> n >> x;
    int a[n+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }

    map<ll, ll> mp;
    mp[0]++;

    ll sum = 0, ans = 0;

    for(i=0; i<n; i++){
        sum += a[i];
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout << ans << endl;

    return 0;
}