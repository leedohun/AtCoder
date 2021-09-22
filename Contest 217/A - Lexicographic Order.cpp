#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (n); i++)
 
typedef long long ll;
 
using namespace std;
 
const ll _INF = 1e18;
const ll INF = 1e9;
 
vector <string> a(2), b(2);
 
void solved() {
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
 
    sort(a.begin(), a.end());
 
    if (a[0] == b[0])
        cout << "Yes";
    else
        cout << "No";
}
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solved();
    return 0;
}
