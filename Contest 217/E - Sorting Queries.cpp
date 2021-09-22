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

priority_queue <int, vector<int>, greater<int>> pq;
queue <int> buffer;

void solved() {
    int t; cin >> t;
    while (t--) {
        int type; cin >> type;

        if (type == 1) {
            int val; cin >> val;
            buffer.push(val);
        }
        else if (type == 2) {
            if (pq.empty()) {
                pq.push(buffer.front());
                buffer.pop();
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (type == 3) {
            while (!buffer.empty()) {
                pq.push(buffer.front());
                buffer.pop();
            }
        }
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}
