#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
void solve(int t) {
    string a; cin >> a;
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
        cout << "Weak\n";
    else if ((a[0] - '0' + 1) % 10 == a[1] - '0' && (a[1] - '0' + 1) % 10 == a[2] - '0'
        && (a[2] - '0' + 1) % 10 == a[3] - '0')
        cout << "Weak\n";
    else
        cout << "Strong\n";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solve(1);
    return 0;
}
