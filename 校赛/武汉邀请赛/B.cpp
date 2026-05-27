#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <int> a (n);

    int cnt0 = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] == 0) {
            cnt0++;
        }
    }

    vector <int> c (m), x (m);

    int cm = 0, cg = 0, c0 = 0;
    int allg = 0;

    int cpos = -1;
    for (int i = 0; i < m; i ++) {
        cin >> c[i] >> x[i];
        if (c[i] == 0) {
            c0++;
            if (cpos == -1) {
                cpos = i;
            }
        } else if (c[i] == 1) {
            cm++;
        } else {
            cg++;
            allg = gcd (allg, x[i]);
        }
    }

    // cout << c0 << ' ' << cm << ' ' << cg << '\n';
    if (cm == m) {
        if (cnt0 == 0 || cnt0 == n) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return; 
    }

    if (cg == m) {
        int nm = gcd (a[0], allg);
        int ok = 1;

        for (int i = 1; i < n; i ++) {
            int x = gcd (a[i], allg);
            if (x != nm) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }        
        return;
    }

    if (c0 >= 2) {
        cout << "Yes" << '\n';
        return;
    }

    if (cm == 0) {
        // cout << "Yes" << '\n';
        if (c0 > 0) {
            cout << "Yes" << '\n';
            return;
        } 

        int nm = gcd (a[0], allg);
        int ok = 1;
        for (int i = 1; i < n; i ++) {
            int x = gcd (a[i], allg);
            if (x != nm) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
            return;
        }
        cout << "No" << '\n';
        return;
    }

    if (cg == 0) {
        // mex
        if (cnt0 == 0 || cnt0 == n) {
            cout << "Yes" << '\n';
            return;
        }

        if (x[m - 2] == 1 && (x[m - 1] == 1 || x[m - 1] == 2)) {
            cout << "Yes" << '\n';
            return;
        }

        if (x[m - 2] > 1 && (x[m - 1] == 1)) {
            cout << "Yes" << '\n';
            return;
        }

        cout << "No" << '\n';
        return;
    }

    cerr << "c0 : " << c0 << '\n';
    if (c0 == 0) {
        bool preg = 0, okk = 0;
        // gcd - mex
        for (int i = 0; i < m; i ++) {
            if (c[i] == 2) {
                preg = 1;
            }

            if (preg && (c[i] == 1)) {
                okk = 1;
                break;
            }
        }

        cerr << "???";
        if (okk) {
            cout << "Yes" << '\n';
            return;
        }      

        // mex
        cerr << "c0 = 0" << '\n';
        if (cnt0 == 0) {
            cout << "Yes" << '\n';
            return;
        }  

        // mex - gcd
        int xx = x[cm - 1];
        for (int i = 0; i < n; i ++) {
            if ((cm & 1)) {
                if (a[i] != 0) {
                    a[i] = 0;
                } else {
                    if (xx == 1) {
                        a[i] = 2;
                    } else {
                        a[i] = 1;
                    }
                }
            } else {
                if (a[i] == 0) {
                    a[i] = 0;               
                } else {
                    if (xx == 1) {
                        a[i] = 2;
                    } else {
                        a[i] = 1;
                    }     
                }
            }

            cerr << "i : " << a[i] << '\n';
        }

        int nm = gcd (a[0], allg);
        int ok = 1;
        for (int i = 1; i < n; i ++) {
            int x = gcd (a[i], allg);
            if (x != nm) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }        
        return;        
    } else if (c0 == 1) {

        cerr << "c0 = 1" << '\n';

        bool preg = 0, okk = 0;
        // gcd - mex
        for (int i = 0; i < m; i ++) {
            if (c[i] == 2 || c[i] == 0) {
                preg = 1;
            }

            if (preg && (c[i] == 1 || c[i] == 0)) {
                okk = 1;
                break;
            }
        }

        if (okk) {
            cout << "Yes" << '\n';
            return;
        }      

        // mex
        if (cnt0 == 0) {
            cout << "Yes" << '\n';
            return;
        }  

        int xx = x[cm - 1];

        // mex-origin
        for (int i = 0; i < n; i ++) {
            if ((cm & 1)) {
                if (a[i] != 0) {
                    a[i] = 0;
                } else {
                    if (xx == 1) {
                        a[i] = 2;
                    } else {
                        a[i] = 1;
                    }
                }
            } else {
                if (a[i] == 0) {
                    a[i] = 0;                  
                } else {
                    if (xx == 1) {
                        a[i] = 2;
                    } else {
                        a[i] = 1; 
                    }
                }
            }
        }

        // gcd
        int ok1 = 1;
        int gg = gcd (allg, x[cpos]);

        // cerr << "pos : " << cpos << ' ' << x[cpos] << '\n';
        int nm = gcd (a[0], gg);

        cerr << "gcd : " << gg << " nm : " << nm << '\n';
        for (int i = 1; i < n; i ++) {
            int x = gcd (a[i], gg);
            if (x != nm) {
                ok1 = 0;
                break;
            }
        }

        if (ok1) {
            cout << "Yes" << '\n';
            return;
        } 
        
        // mex
        xx = x[cpos];
        
        // cerr << "xx : " << cm << ' ' << xx << '\n';
        for (int i = 0; i < n; i ++) {
            if (a[i] == 0) {
                if (xx == 1) a[i] = 2;
                else a[i] = 1;
            } else {
                a[i] = 0;
            }

            cerr << "i : " << i << ' ' << a[i] << '\n';
        }       

        ok1 = 1;
        nm = gcd (a[0], allg);
        for (int i = 1; i < n; i ++) {
            int x = gcd (a[i], allg);
            if (x != nm) {
                ok1 = 0;
                break;
            }
        }
        
        if (ok1) {
            cout << "Yes" << '\n';
            return;
        }         

        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while(_--)
    {
        solve();
    }
}