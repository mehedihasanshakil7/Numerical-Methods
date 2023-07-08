/*  1. This program is aimed to derive an approximating
       function that broadly fits the given data
    2. The first line of input is number of data points (n)
    3. The next n lines contains data as (x, y)
*/
#include <bits/stdc++.h>
using namespace std;

class CurveFitting {
public:
    int n;
    double x[10], y[10];
    double a0, a1;

    CurveFitting() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>x[i]>>y[i];
        }
    }

    void solve() {
        double all_x = 0, all_y = 0, all_xy = 0, all_xx = 0;
        for(int i = 0; i < n; i++) {
            all_x = all_x + x[i];
            all_y = all_y + y[i];
            all_xy = all_xy + (x[i] * y[i]);
            all_xx = all_xx + (x[i] * x[i]);            
        }
        cout<<"x = "<<all_x<<" y = "<<all_y<<" xy = "<<all_xy<<" xx = "<<all_xx; cout<<"\n";
        a0 = ((n * all_xy) - (all_x * all_y)) / ((n * all_xx) - (all_x * all_x));
        a1 = (all_y - a0 * all_x) / n;

        cout<<"\nThe curve that fits the given data is\n";
        if(a1 < 0)
            cout<<"y = "<<a0<<"x - "<<abs(a1);
        else
            cout<<"y = "<<a0<<"x + "<<a1;
    }
};

int main() {
    CurveFitting c = CurveFitting();
    c.solve();
}
