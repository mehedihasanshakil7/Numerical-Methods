/* 1. This program is aimed to solve ordinary differential
      equation in form of set of tabulated values using
      Euler's Method
   2. The first line of input takes two initial values of x and y
   3. Next line is step size h
   4. The last line is the given x where y to be determined
*/

#include <bits/stdc++.h>
using namespace std;

class EulersMethod {
public:
    double x0, y0, given_x, h;

    EulersMethod() {
        cin>>x0>>y0>>h>>given_x;
    }

    double f(double x, double y) {
        return -y;
    }

    void solve() {
        double yn;
        int i = 0;
        while(x0 < given_x) {
            yn = y0 + h * f(x0, y0);
            printf("x%d = %6f  y%d = %6f  y%d = %6f\n", i, x0, i, y0, i+1, yn);
            y0 = yn;
            x0 += h;
            i++;
        }
        cout<<"\nValue of y at x = "<< given_x<< " is " << y0;
    }
};

int main(void)
{
    EulersMethod e = EulersMethod();
    e.solve();
}
