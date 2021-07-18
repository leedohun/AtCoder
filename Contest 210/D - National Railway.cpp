#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    int H, W;
    ll  C;
    
    cin >> H >> W;
    cin >> C;

    vector <vector<int>> a(H, vector<int>(W));

    rep(i, H) rep(j, W) cin >> a[i][j];

    ll ret = INF;
    
    rep(_, 2) {
        vector <vector<ll>> dp(H, vector<ll>(W, INF));
        rep(i, H) rep(j, W) { //dp : 인덱스 i, j보다 작은 (철도역 + 철도도리)값과 현재 (철도역 + 철도도리)값들 중에 가장 작은 값
            if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);

            ret = min(ret, a[i][j] + (i + j) * C + dp[i][j]);
            dp[i][j] = min(dp[i][j], a[i][j] - (i + j) * C); //dp의 값 갱신
        }

        reverse(a.begin(), a.end());
    }

    cout << ret << "\n";
    return 0;
}

/*
수식
= a[i][j] + a[i'][j'] + C * (|i - i'| + |j - j'|)
= a[i][j] + a[i'][j'] + C * (i - i' + j - j') (단, i' < i && j' < j)
= a[i][j] + C * (i + j) + a[i'][j'] - C * (j - j') (단, i' < i && j' < j)
따라서, dp[i][j] = min(dp[i][j], a[i][j] - (i + j) * C
*/
