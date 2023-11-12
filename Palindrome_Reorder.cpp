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

    string s;
    cin >> s;

    int fre[26] = {0}, i, letters = 0, even = 0, odd = 0;
    int n = s.size();

    for(i=0; i<n; i++){
        fre[s[i]-'A']++;
    }

    for(i=0; i<26; i++){
        if(fre[i] > 0) letters++;

        if(fre[i] > 0 && fre[i]%2 == 0) even++;
        else if(fre[i]%2 != 0) odd++;
    }

    // for(i=0; i<26; i++){
    //     cout << fre[i] << " ";
    // }

    // cout << nl << letters << nl << even << nl << odd << nl;

    string str1;
    string str2;
    string oddChar;

    if(letters == 1) cout << s << nl;

    else if(n%2 == 0){
        if(odd > 0) cout << "NO SOLUTION" << nl;
        
        else{
            map<char, int> mp;

            for(i=0; i<n; i++){
                mp[s[i]]++;
            }

            for(char ch = 'A'; ch <= 'Z'; ch++){
                int temp = mp[ch];
                int tm = mp[ch]/2;

                while(temp > tm){
                    str1.pb(ch);
                    temp--;
                }
            }
            cout << str1;
            reverse(str1.begin(), str1.end());
            cout << str1 << nl;
        }
    }

    else{
        if(odd > 1) cout << "NO SOLUTION" << nl;
        
        else{
            map<char, int> mp;

            for(i=0; i<n; i++){
                mp[s[i]]++;
            }

            for(char ch = 'A'; ch <= 'Z'; ch++){
                if(mp[ch]%2 == 0){
                    int temp = mp[ch];
                    int tm = mp[ch]/2;

                    while(temp > tm){
                        str1.pb(ch);
                        temp--;
                    }
                }
                else{
                    while(mp[ch] != 0){
                        oddChar.pb(ch);
                        mp[ch]--;
                    }
                }
            }

            cout << str1 << oddChar;
            reverse(str1.begin(), str1.end());
            cout << str1 << nl;
        }
    }

    return 0;
}