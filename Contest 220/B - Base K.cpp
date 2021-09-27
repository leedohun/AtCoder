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
 
void solved() {
    ll k; cin >> k;
    ll a, b; cin >> a >> b;
 
    ll tmpa = 0;
    ll tmpb = 0;
 
    for (ll i = a, j = 1; i != 0; i /= 10, j *= k) {
        tmpa += (i % 10) * j;
    }
    for (ll i = b, j = 1; i != 0; i /= 10, j *= k) {
        tmpb += (i % 10) * j;
    }
 
    cout << tmpa * tmpb;
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
