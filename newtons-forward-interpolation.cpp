/* 1. This program is aimed to implement Newtons Forward
      Intepolation
   2. The first line of input takes the number of data points (n)
   3. Next n lines contains the data points as (x, y)
   4. The last line contains x
   5. Output is the y at given x
*/

#include <bits/stdc++.h>
using namespace std;

class NewtonsForwardInterpolation {
public:
    int n;
    double x[10], y[10][10];
    double ans, given_x;

    NewtonsForwardInterpolation() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>x[i]>>y[i][0];
        }
        cin>>given_x;
    }
    int factorial(int n) {
        if(n) {
            return n * factorial(n-1);
        }
        else return 1;
    }

    double multiply(double u, int n) {
        double value = u;
        for(int i = 1; i < n; i++) {
            value = value * (u - i);
        }
        return value;
    }
    void solve() {
        for(int col = 1; col < n; col++) {
            for(int row = 0; row < n - col; row++) {
                y[row][col] = y[row+1][col-1] - y[row][col-1];
            }
        }
        ans = y[0][0];
        double h = x[1] - x[0];
        double u = (given_x - x[0]) / h;
        for(int i = 1; i < n; i++) {
            ans += (multiply(u, i) * y[0][i]) / factorial(i);
        }
        cout<<"The value at "<<given_x<<" is "<<ans<<'\n';
    }

};

int main(void)
{
    NewtonsForwardInterpolation n = NewtonsForwardInterpolation();
    n.solve();
}
