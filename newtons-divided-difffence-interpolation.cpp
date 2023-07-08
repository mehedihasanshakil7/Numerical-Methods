/* 1. This program is aimed to implement Newton's Divided Difference
      Interpolation Formula
   2. The first line of input takes the number of data points (n)
   3. Next n lines contains the data points as (x, y)
   4. The last line contains x
   5. Output is the y at given x
*/

#include <bits/stdc++.h>
using namespace std;

class NewtonsDividedDifferenceInterpolation {
public:
    int n;
    double x[10], y[10][10];
    double ans = 0, given_x;
    NewtonsDividedDifferenceInterpolation() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>x[i]>>y[i][0];
        }
        cin>>given_x;

        // Create the divided difference table
        for (int col = 1; col < n; col++) {
            for (int row = 0; row < n - col; row++) {
                y[row][col] = (y[row + 1][col - 1] - y[row][col - 1]) / (x[row + col] - x[row]);
            }
        }
    }

    // Terms to be multiplied with y[i]
    double multiply(int i) {
        double value = 1;
        for(int k = 0; k < i; k++) {
            value *= given_x - x[k];
        }
        return value;
    }
        
    void solve() {
        ans = y[0][0];
        for(int i = 1; i < n; i++) {
            ans += multiply(i) * y[0][i];
        }
        cout<<"The value at "<<given_x<<" is "<<ans<<'\n';
    }
};

int main(void)
{
    NewtonsDividedDifferenceInterpolation n = NewtonsDividedDifferenceInterpolation();
    n.solve();
}
