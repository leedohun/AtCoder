#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
const string a[4] = {
    "ABC",
    "ARC",
    "AGC",
    "AHC"
};
 
void solved() {
    bool visit[4] = { false };
 
    for (int i = 0; i < 3; i++) {
        string tmp; cin >> tmp;
 
        for (int j = 0; j < 4; j++) {
            if (tmp == a[j]) {
                visit[j] = true;
            }
        }
    }
 
    for (int i = 0; i < 4; i++) {
        if (!visit[i]) {
            cout << a[i];
        }
    }
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
