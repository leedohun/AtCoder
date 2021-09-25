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
    string x;
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

map <char, int> m;

bool cmp(const P& a, const P& b) {
    for (int i = 0; i < min(a.x.size(), b.x.size()); i++) {
        if (m[a.x[i]] < m[b.x[i]]) return true;
        else if (m[a.x[i]] > m[b.x[i]]) return false;
    }
    if (a.x.size() < b.x.size()) return true;
    return false;
}

void solved() {
    string X; cin >> X;
    for (int i = 0; i < 26; i++) {
        m[X[i]] = i;
    }

    int N; cin >> N;
    vector <P> v(N);
    rep(i, N) cin >> v[i].x;

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << v[i].x << "\n";
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
