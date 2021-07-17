#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;
string S;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (i % 2 == 0) {
                cout << "Takahashi";
                break;
            }
            else {
                cout << "Aoki";
                break;
            }
        }
    }
}
