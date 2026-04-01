
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <int> a (n + m + 2), b (n + m + 2), cho (n + m  + 2);
    for (int i = 1; i <= n + m + 1; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n + m + 1; i ++) {
        cin >> b[i];
    }

    // A : 1, 2 B : 3, 4

    int c1 = 0, c2 = 0, pasa = 0, pasb = 0, fira = -1, firb = -1;

    for (int i = 1; i <= n + m; i ++) {
        if (a[i] > b[i]) {
            if (c1 < n) {
                cho[i] = 1;
                c1++;
                pasa += a[i];
            } else {
                if (fira == -1) {
                    fira = i;
                }
                cho[i] = 2;
                c2++;
                pasb += b[i];
            }
        } else {
            if (c2 < m) {
                cho[i] = 3;
                c2++;
                pasb += b[i];
            } else {
                if (firb == -1) {
                    firb = i;
                }
                cho[i] = 4;
                pasa += a[i];
            }
        }
    }

    vector <int> ans (n + m + 2);

    for (int i = 1; i <= n + m + 1; i ++) {
        if (i == n + m + 1) {
            ans[i] = pasa + pasb;
        } else {
            int nowa = pasa, nowb = pasb;
            if (cho[i] == 1) {
                if (fira == -1) {
                    nowa -= a[i];
                    nowa += a[n + m + 1];
                } else {
                    nowa -= a[i];
                    nowa += a[fira];
                    nowb -= b[fira];
                    nowb += b[n + m + 1];
                }
            } else if (cho[i] == 2) {
                nowb -= b[i];
                nowb += b[n + m + 1];
            } else if (cho[i] == 3) {
                nowb -= b[i];
                if (firb == -1) {
                    nowb += b[n + m + 1];
                } else {
                    nowb += b[firb];
                    nowa -= a[firb];
                    nowa += a[n + m + 1];
                }
            } else {
                nowa -= a[i];
                nowa += a[n + m + 1];
            }

            ans[i] = nowa + nowb;
        }
    }

    for (int i = 1; i <= n + m + 1; i ++) {
        cout << ans[i] << " \n"[i == n + m + 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}