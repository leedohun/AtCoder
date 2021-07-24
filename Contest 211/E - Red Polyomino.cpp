#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

using vs = vector<string>;

const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int N, K;
int ans = 0;

void dfs(vs s) {
    int cnt = 0;
    rep(i, N) rep(j, N) if (s[i][j] == 'o') cnt++;

    if (cnt == K) {
        ans++;
        return;
    }
    rep(i, N) rep(j, N) {
        if (s[i][j] != '.') continue;
        if (cnt != 0) {
            bool ok = false;
            rep(v, 4) {
                int x = i + dx[v], y = j + dy[v];
                if (x < 0 || y < 0 || N <= x || N <= y) continue;
                if (s[x][y] == 'o') ok = true;
            }
            if (!ok) continue;
        }
        s[i][j] = 'o';
        dfs(s);
        s[i][j] = '#';
        dfs(s);
        return;
    }
}

void solve(int t) {
    cin >> N >> K;

    vs s(N);
    rep(i, N) cin >> s[i];

    dfs(s);

    cout << ans << "\n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    //int t; cin >> t;
    //rep(i, t)
    solve(1);

    return 0;
}
