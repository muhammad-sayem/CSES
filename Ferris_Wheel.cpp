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

    int n, x, i, cnt = 0;
    cin >> n >> x;
    int a[n+5];

    for(i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    int l = 0;
    int r = n-1;

    while(l<=r){
        if(a[l]+a[r] <= x){
            cnt++;
            l++;
            r--;
        }
        else{
            cnt++;
            r--;
        }
    }

    cout << cnt << endl;
    
    return 0;
}


