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
    string S[205], T[205], tmp[205];
 
    rep(i, N) {
        cin >> S[i];
        tmp[i] = S[i];
    }
    rep(i, N) cin >> T[i];
 
    int a = 0, b = 0;
    for (; a < N; a++) {
        for (b = 0; b < N; b++) {
            if (T[a][b] == '#') break;
        }
        if (T[a][b] == '#') break;
    }
 
    vector <P> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (T[i][j] == '#') {
                ans.push_back({ i - a, j - b });
            }
        }
    }
 
    int answer = 0;
    for (int i = 0; i < 4; i++) {
        for (int p = 0; p < N; p++) {
            for (int q = 0; q < N; q++) {
                tmp[p][q] = S[N - q - 1][p];
            }
        }
 
        for (int q = 0; q < N; q++) {
            for (int p = 0; p < N; p++) {
                S[q][p] = tmp[q][p];
            }
        }
 
        a = 0, b = 0;
        for (; a < N; a++) {
            for (b = 0; b < N; b++) {
                if (S[a][b] == '#') break;
            }
            if (S[a][b] == '#') break;
        }
 
        int idx = 0;
        bool flag = true;
        for (int q = 0; q < N; q++) {
            for (int p = 0; p < N; p++) {
                if (S[q][p] == '#') {
                    if (ans[idx].x != (q - a) || ans[idx].y != (p - b)) {
                        flag = false;
                    }
                    idx++;
                }
            }
        }
        if (flag && idx == ans.size()) {
            answer = 1;
        }
    }
 
    if (answer)
        cout << "Yes";
    else
        cout << "No";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
