#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
int ret = INF;
 
void solve(int t) {
    int N, M; cin >> N >> M;
 
    vector <int> A(N);
    vector <int> B(M);
 
    rep(i, N)
        cin >> A[i];
    rep(i, M)
        cin >> B[i];
 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
 
    int a = 0, b = 0;
    while (a < N && b < M) {
        ret = min(abs(A[a] - B[b]), ret);
        if (A[a] < B[b])
            a++;
        else
            b++;
    }
 
    cout << ret;
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solve(1);
    return 0;
}
