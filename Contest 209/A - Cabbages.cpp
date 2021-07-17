#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int N, A, X, Y;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> A >> X >> Y;

    if (A <= N)
        cout << A * X + (N - A) * Y;
    else
        cout << N * X;
}
