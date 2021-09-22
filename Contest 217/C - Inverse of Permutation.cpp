#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
int N;
 
void solved() {
    cin >> N;
    vector <int> v(N);
 
    rep(i, N)
        cin >> v[i];
 
    vector <int> ans(N);
    rep(i, N) {
        ans[v[i] - 1] = i + 1;
    }
 
    rep(i, N)
        cout << ans[i] << " ";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
