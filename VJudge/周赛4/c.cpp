
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
        if (s[0] == 'o' || s[0] == 'x') {
            cout << "Yes" << '\n';
            return;
        } else {
            cout << "No" << '\n';
            return;
        }
    }

    if (s[0] == 'o') {
        for (int i = 0; i < n; i += 3) {
            if (s[i] != 'o') {
                cout << "No" << '\n';
                return;
            }

             if (i + 1 < n && s[i + 1] != 'x') {
                cout << "No" << '\n';
                return;
             }

             if (i + 2 < n && s[i + 2] != 'x') {
                cout << "No" << '\n';
                return;   
             }    
        }
        cout << "Yes" << '\n';
    } else if (s[0] == 'x' && s[1] == 'x') {
        for (int i = 2; i < n; i += 3) {
            if (s[i] != 'o') {
                cout << "No" << '\n';
                return;
            }

             if (i + 1 < n && s[i + 1] != 'x') {
                cout << "No" << '\n';
                return;
             }

             if (i + 2 < n && s[i + 2] != 'x') {
                cout << "No" << '\n';
                return;   
             }             
        }

        cout << "Yes" << '\n';
    } else if (s[0] == 'x' && s[1] == 'o') {
        for (int i = 1; i < n; i += 3) {
            if (s[i] != 'o') {
                cout << "No" << '\n';
                return;
            }

             if (i + 1 < n && s[i + 1] != 'x') {
                cout << "No" << '\n';
                return;
             }

             if (i + 2 < n && s[i + 2] != 'x') {
                cout << "No" << '\n';
                return;   
             }             
        }

        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}