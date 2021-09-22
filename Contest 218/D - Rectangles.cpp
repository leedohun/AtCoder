#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
using namespace std;
 
typedef long long ll;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
struct P {
    int x; int y;
};
 
bool cmp(const P& a, const P& b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
    }
    return false;
}
 
void solved() {
    int N; cin >> N;
 
    vector <P> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y;
 
    sort(v.begin(), v.end(), cmp);
 
    vector <int> ans[2005];
    int idx = 0;
    ans[idx].push_back(v[0].y);
    for (int i = 1; i < N; i++) {
        if (v[i - 1].x == v[i].x) {
            ans[idx].push_back(v[i].y);
        }
        else {
            idx++;
            ans[idx].push_back(v[i].y);
        }
    }
 
    int answer = 0;
    for (int i = 0; i <= idx; i++) {
        for (int j = i + 1; j <= idx; j++) {
            if (ans[i].size() > 1 && ans[j].size() > 1) {
                int p = 0, q = 0;
 
                int tmp = 0;
                while (p < ans[i].size() && q < ans[j].size()) {
                    if (ans[i][p] < ans[j][q]) p++;
                    else if (ans[i][p] > ans[j][q]) q++;
                    else {
                        tmp++; p++; q++;
                    }
                }
 
                answer += (tmp * (tmp - 1)) / 2;
            }
        }
    }
 
    cout << answer;
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
