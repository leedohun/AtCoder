#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
map <char, char> m;
 
void solve(int t) {
    m['h'] = 'c'; m['o'] = 'h'; m['k'] = 'o'; m['u'] = 'k';
    m['d'] = 'u'; m['a'] = 'd'; m['i'] = 'a';
 
    string S; cin >> S;
 
    map <char, ll> ret;
 
    ret['c'] = 0; ret['h'] = 0; ret['o'] = 0; ret['k'] = 0;
    ret['u'] = 0; ret['d'] = 0; ret['a'] = 0; ret['i'] = 0;
 
    rep(i, S.size()) {
        if (S[i] == 'c') {
            ret['c']++;
        }
        else if (m.find(S[i]) != m.end()) {
            ret[S[i]] += ret[m[S[i]]] % 1000000007;
        }
    }
 
    cout << ret['i'] % 1000000007;
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    //int t; cin >> t;
    //rep(i, t)
        solve(1);
}
