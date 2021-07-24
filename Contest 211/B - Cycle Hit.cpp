#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
void solve(int t) {
    vector <string> v(4);
 
    rep(i, 4) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    if (v[0] == "2B" && v[1] == "3B" && v[2] == "H" && v[3] == "HR")
        cout << "Yes";
    else
        cout << "No";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    //int t; cin >> t;
    //rep(i, t)
        solve(1);
}
