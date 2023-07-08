/* 1. This program is aimed to implement Lagrange's Interpolation Formula
   2. The first line of input takes the number of data points (n)
   3. Next n lines contains the data points as (x, y)
   4. The last line contains x
   5. Output is the y at given x
*/

#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
public:
    int n;
    double x[10], y[10];
    double ans = 0, given_x;
    LagrangeInterpolation() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>x[i]>>y[i];
        }
        cin>>given_x;
    }
    void solve() {
        for(int i = 0; i < n; i++) {
            double temp_ans = y[i];
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    temp_ans *= (given_x - x[j]) / (x[i] - x[j]);
                }
            }
            ans += temp_ans;
        }
        cout<<"The value at "<<given_x<<" is "<<ans<<'\n';
    }
};

int main(void)
{
    LagrangeInterpolation l = LagrangeInterpolation();
    l.solve();
}
