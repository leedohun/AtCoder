#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
int L, Q;
set <int> v;
 
void solved() {
    cin >> L >> Q;
 
    v.insert(0);
    v.insert(L);
 
    rep(i, Q) {
        int x, y; cin >> x >> y;
        if (x == 1) {
            v.insert(y);
        }
        else {
            set<int>::iterator fir;
            
            fir = v.upper_bound(y);
            
            int ans = *fir;
            fir--;
            ans -= *fir;
 
            cout << ans << "\n";
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
