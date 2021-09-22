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
    int x; int y; int cnt;
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

int getParent(int parent[], int node) {
    if (parent[node] == node) {
        return node;
    }
    return getParent(parent, parent[node]);
}

int unionParent(int parent[], int x, int y) {
    x = getParent(parent, x);
    y = getParent(parent, y);

    if (x < y) {
        parent[y] = x;
        return x;
    }
    else {
        parent[x] = y;
        return y;
    }
}

int findParent(int parent[], int x, int y) {
    x = getParent(parent, x);
    y = getParent(parent, y);
    if (x == y) {
        return 1;
    }
    else {
        return 0;
    }
}

class Edge {
public:
    int node[2];
    ll distance;
    Edge(int x, int y, int distance) {
        this->node[0] = x;
        this->node[1] = y;
        this->distance = distance;
    }
    bool operator <(Edge& edge) {
        return this->distance < edge.distance;
    }
};

void solved() {
    int N, M; cin >> N >> M;
    vector <Edge> v;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }
    sort(v.begin(), v.end());

    int parent[200005] = { 0, };
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        if (!findParent(parent, v[i].node[0], v[i].node[1])) {
            unionParent(parent, v[i].node[0], v[i].node[1]);
        }
        else {
            ans += max((ll)0, v[i].distance);
        }
    }
    cout << ans;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
