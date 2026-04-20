
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo(int x) {
    auto check = [&] (int i, int j) -> bool {
        string x = to_string (i);
        string y = to_string (j);

        if (x.size() != y.size()) return false;
        int ok1 = 1, ok2 = 1;
        for (char & cx : x) {
            if (cx >= '0' && cx < '5') {
                ok1 = 0;
                break;
            }
        }
        for (char & cx : y) {
            if (cx >= '0' && cx < '5') {
                ok2 = 0;
                break;
            }
        }        

        if (ok1 && ok2) return true;
        return false;
    };
    
    int t = x / 2, str = 1;
    while (t) {
        str *= 10;
        t /= 10;
    }


    str /= 10;
    // cerr << str << '\n';
    for (int i = str; i <= x / 2; i ++) {
        int j = x - i;
        int ok = check (i, j);
        if (ok) {
            cout << x << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) {
        for (int i = 5; i <= 10000; i ++) {
            ovo(i);
        }
    }
}