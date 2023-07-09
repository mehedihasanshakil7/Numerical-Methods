/* 1. This program is aimed to compute the definite integral
      for a given set of data points using Trapezoidal Rule
   2. The first line of input takes the number of data points (n)
   3. Next n lines contains the data points as (x, y)
*/

#include <bits/stdc++.h>
using namespace std;

class TrapezoidalRule {
public:
    int n;
    double x[10], y[10];
    double ans = 0, y0, yn, h;
    TrapezoidalRule() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>x[i]>>y[i];
        }
        yn = y[n-1];
        y0 = y[0];
        h = x[1] - x[0];
    }

    void solve() {
        ans = y0 + yn;
        for(int i = 1; i < n - 1; i++) {
            ans += 2 * y[i];
        }
        ans *= h / 2;
        cout<<"Answer = "<<ans;
    }
};

int main(void)
{
    TrapezoidalRule t = TrapezoidalRule();
    t.solve();
}
