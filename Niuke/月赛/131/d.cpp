#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;

    vector <arr2> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }


    int ok3 = 1;

    int fmk, fzk, fmc, fzc;
    for (int i = 2; i <= n; i ++) {
        auto [a1, b1] = a[i - 1];
        auto [x, y] = a[i];        

        if (i == 2) {
                fzk = (y * a1 - x * b1);
                fmk = (a1 * a1 + b1 * b1);
                fzc = (y * b1 + x * a1);
                fmc = (a1 * a1 + b1 * b1);
        } else {
            if ((y * a1 - x * b1) * fmk == (a1 * a1 + b1 * b1) * fzk && (y * b1 + x * a1) * fmc == (a1* a1 + b1 * b1) * fzc) {
                continue;
            } else {
                ok3 = 0;
                break;
            }
        }        
    }

    if (ok3) {
        cout << "Yes" << '\n';
        return;
    }

    cout << "No" << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}