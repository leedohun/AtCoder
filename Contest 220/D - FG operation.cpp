#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*#include <iostream>
#include <string>
#include <queue>
#include <set>*/
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
struct P {
    int x; int y;
};
 
/*struct compare {
    bool operator()(P& a, P& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
};
priority_queue <P, vector<P>, compare> pq;*/
 
bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}
 
ll dp[100005][10] = { 0, };
 
void solved() {
    int N; cin >> N;
    vector <ll> v(N);
    rep(i, N) cin >> v[i];
 
    ll x = v[0], y = v[1];
    dp[1][(x + y) % 10]++;
    dp[1][(x * y) % 10]++;
 
    for (int i = 2; i < N; i++) {
        y = v[i];
        for (int j = 0; j < 10; j++) {
            if (dp[i - 1][j] != 0) {
                dp[i][(y * j) % 10] += dp[i - 1][j];
                dp[i][(y + j) % 10] += dp[i - 1][j];
 
                dp[i][(y + j) % 10] %= 998244353;
                dp[i][(y * j) % 10] %= 998244353;
            }
        }
    }
 
    for (int i = 0; i < 10; i++) {
        cout << dp[N - 1][i] << "\n";
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
