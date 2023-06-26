/* 1. This program is aimed to find root of non-linear
      function using bisection method.
   2. It doesn't take any input.
   3. The specified function is given in it.
*/
#include <bits/stdc++.h>
using namespace std;

class BisectionMethod
{
private:
    const double tolerence = 0.0001;
    double a, b;

    // the given function is x^3 + x^2 - 1 = 0
    double functional_value(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }

public:
    void solve()
    {
        srand(time(0));
        while (1) //This loop is to guess a (negative) and b (positive)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (functional_value(a) * functional_value(b) <= 0)
            {
                break;
            }
        }
        int k = 1; //The variable 'k' is to keep track of
                   //number of iterations to reach the desired accuracy
        double root = a;
        while (1)
        {
            cout << "Root = " << root << " at iteration " << k++ << "\n";
            if (functional_value(root) == 0.0)
            {
                break;
            }
            if (abs((root - (a+b)/2)) < tolerence)
            {
                break;
            }
            root = (a + b) / 2;
            if (functional_value(root) * functional_value(a) > 0)
            {
                a = root;
            }
            else
            {
                b = root;
            }
        }
        cout<<"\nThe root is "<<root <<" (correct upto 3 decimal palces)\n";
    }
};

int main(void)
{
    BisectionMethod bisect = BisectionMethod();
    bisect.solve();
}