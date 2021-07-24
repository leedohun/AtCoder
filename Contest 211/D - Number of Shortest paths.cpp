#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

const ll _INF = 1e18;
const ll INF = 1e9;

const int mint = 1000000007;

void solve(int t) {
    int N, M; cin >> N >> M;

    vector<vector<int>> to(N);
    
    rep(i, M) {
        int x, y; cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }

    const int INF = 1001001001;
    vector<int> dist(N, INF);

    queue <int> q;
    q.push(0); dist[0] = 0;

    vector<int> vs;
    while (q.size()) {
        int v = q.front(); q.pop();

        vs.push_back(v);
        for (int u : to[v]) {
            if (dist[u] != INF) continue;

            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    vector<int> dp(N);
    dp[0] = 1;
    for (int v : vs) { //v에는 방문 순서대로 들어가 있음.
        for (int u : to[v]) { //v에 순서대로 연결된 노드를 탐색하면서 확인
            if (dist[u] == dist[v] + 1) {
                dp[u] += dp[v] % mint;
            }
        }
    }
    
    cout << dp[N - 1] % mint;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    //int t; cin >> t;
    //rep(i, t)
        solve(1);

        return 0;
}

/*
1 ~ N의 노드를 몇개의 최소 도로를 통해서 갈 수 있는지 집합 형석으로 제작한 뒤 dp 실행
*/
