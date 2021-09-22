#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
void solve(int t) {
    int A, B; cin >> A >> B;
 
    if (0 < A && 0 < B)
        cout << "Alloy\n";
    else if (A == 0)
        cout << "Silver\n";
    else
        cout << "Gold\n";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solve(1);
    return 0;
}
