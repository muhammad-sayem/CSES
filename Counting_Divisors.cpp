// Prime Factorization //

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

    int test;
    cin >> test;

    while(test--){
        int n, i;
        cin >> n;
        map<ll, ll> mp;
        
        for(i=2; i*i<=n; i++){
            while(n%i == 0){
                mp[i]++;
                n /= i;
            }
        }

        if(n > 1){
            mp[n]++;
        }

        ll ans = 1;

        for(auto pair: mp){
            ans *= (pair.second+1);
        }
        cout << ans << endl;
    }

    return 0;
}

// ------------------------------------------------------------------ //

// Normal Approach //

/*
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

    int test;
    cin >> test;

    while(test--){
        int n, i;
        cin >> n;
        map<ll, ll> mp;
        
        for(i=2; i*i<=n; i++){
            while(n%i == 0){
                mp[i]++;
                n /= i;
            }
        }

        if(n > 1){
            mp[n]++;
        }

        ll ans = 1;

        for(auto pair: mp){
            ans *= (pair.second+1);
        }
        cout << ans << endl;
    }

    return 0;
}
*/