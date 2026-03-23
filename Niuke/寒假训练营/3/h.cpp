#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double x;

    if (y1 == y2) {
        double sum = abs (y1) * abs (x1 - x2) * 1.0 / 2;
        if (fabs(sum - 2) <= 0.001) {
            cout << max (x1, x2) + 1 << '\n';
        } else {
            cout << "no answer" << '\n';
        }
        return;
    }


    if (y1 * y2 > 0) {
        if (x1 > x2) {
            swap (x1, x2); swap (y1, y2);
        }
        double sum = abs (y1 + y2) * abs (x2 - x1) * 1.0 / 2;
        y1 = abs(y1), y2 = abs (y2);
        x = (2 * (sum - 2) + x1 * y1 - x2 * y2) * 1.0 / (y1 - y2);
    } else {
        if (x1 == x2) {
            int h = abs (y1 - y2);
            x = 4.0 / h + x1;
        } else {
            y1 = abs (y1), y2 = abs (y2);
            double xx = (x1 * y2 + x2 * y1) * 1.0 / (y1 + y2);
            x = 4.0 / (y1 + y2) + xx;
        }
    }

        cout << fixed << setprecision(4) << x << '\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}