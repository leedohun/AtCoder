#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <bitset>
#include <queue>
#include <map>

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;

    vector <string> sa(n), sb(n);          //sa : 문자열 앞에 3글자, sb : 문자열 뒤에 3글자
    rep(i, n) {
        string s; cin >> s;
        sa[i] = s.substr(0, 3);
        sb[i] = s.substr(s.size() - 3);
    }

    map <string, int> mp;
    rep(i, n) {
        mp[sa[i]] = 0, mp[sb[i]] = 0;      //mp : map을 통해서 sa, sb 문자열 중복 제거
    }

    int m = 0;
    for (auto& p : mp) p.second = m++;     //mp : map에 있는 문자열에 cont 부여

    vector<vector<int>> to(m);
    vector<int> deg(m);
    rep(i, n) {                            //to : map의 숫자를 통해 start - end 표시
        int a = mp[sa[i]];
        int b = mp[sb[i]];
        to[b].push_back(a);
        deg[a]++;
    }

    queue<int> q;
    vector<int> ans(m);
    rep(i, m) {
        if (deg[i] == 0) {
            ans[i] = -1;
            q.push(i);
        }
    }
    while (q.size()) {
        int v = q.front(); q.pop();

        if (ans[v] == -1) {
            for (int u : to[v]) {
                if (ans[u]) continue;
                ans[u] = 1;
                q.push(u);
            }
        }
        else {
            for (int u : to[v]) {
                if (ans[u]) continue;
                deg[u]--;
                if (deg[u] == 0) {
                    ans[u] = -1;
                    q.push(u);
                }
            }
        }
    }

    rep(i, n) {
        int b = mp[sb[i]];
        if (ans[b] == -1) cout << "Takahashi\n";
        else if (ans[b] == 0) cout << "Draw\n";
        else cout << "Aoki\n";
    }

    return 0;
}
