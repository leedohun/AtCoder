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
const int mod = 1000000007;
const int MOD = 998244353;
const int MAX = 1000005;
 
struct P {
    ll x; ll y;
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
 
vector <ll> to[200010];
vector <ll> dis(200010), si(200010), delta(200010);
 
void dfs1(int now, int fa) {
    si[now] = 1;
    for (int i = 0; i < to[now].size(); i++) {
        if (to[now][i] == fa) {
            continue;
        }
        dfs1(to[now][i], now);
        si[now] += si[to[now][i]];
        dis[1] += si[to[now][i]];
    }
    return;
}
 
void dfs2(int now, int fa) {
    for (int i = 0; i < to[now].size(); i++) {
        if (to[now][i] == fa) {
            continue;
        }
        dis[to[now][i]] = dis[now] + delta[to[now][i]];
        dfs2(to[now][i], now);
    }
    return;
}
 
void solved() {
    int N; cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
 
    dfs1(1, 0);
    for (int i = 2; i <= N; i++) {
        delta[i] = si[1] - si[i] * 2;
    }
    dfs2(1, 0);
    for (int i = 1; i <= N; i++) {
        cout << dis[i] << endl;
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
