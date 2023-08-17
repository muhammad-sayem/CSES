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

    ll n, m, k, i, j, cnt = 0;
    cin >> n >> m >> k;

    int a[n+5];
    int b[m+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }

    for(i=0; i<m; i++){
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    i = 0;
    j = 0;

    while(1){
        ll val1 = a[i]-k;
        ll val2 = a[i]+k;

        if(b[j] >= val1 && b[j] <= val2){
            j++;
            i++;
            cnt++;
        }
        else if(b[j] < val1){
            j++;
        }
        else if(b[j] > val2){
            i++;
        }

        if(i == n || j == m) break;
    }
    
    cout << cnt << endl;

    return 0;
}


