#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int N, K;
int ret = 0;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    vector <int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    map <int, int> m;
    for (int i = 0; i < K; i++)
        if (m.find(c[i]) != m.end())
            m[c[i]]++;
        else
            m[c[i]] = 1;

    ret = m.size();

    for (int i = K; i < N; i++) {
        if (1 < m[c[i - K]])
            m[c[i - K]]--;
        else
            m.erase(c[i - K]);

        if (m.find(c[i]) != m.end())
            m[c[i]]++;
        else
            m[c[i]] = 1;
        
        int size = m.size();

        ret = max(ret, size);
    }

    cout << ret;
}
