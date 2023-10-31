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

bool isValid(ll a[], ll n, ll mid, ll t){
    ll sum = 0, i;

    for(i=0; i<n; i++){
        sum += mid/a[i];
        if(sum >= t) return true;
    }
    return false;
}

int main()
{
    fastIO;

    ll n, t, i, ans;
    cin >> n >> t;  
    ll a[n+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }
    
    ll l = 0;
    ll r = LLONG_MAX;

    while(l<=r){
        ll mid = l + (r-l)/2;

        if(isValid(a, n, mid, t)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}