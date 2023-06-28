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

    // Given function is x^3 + x^2 - 1 = 0
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
            if (functional_value(a) * functional_value(b) < 0)
            {
                break;
            }
        }

        double root;
        while (1)
        {
            root = (a + b) / 2;
            printf("a = %9f     b = %9f     root = %9f\n", a, b, root);
            if (functional_value(root) == 0.0)
            {
                break;
            }
            if (functional_value(root) * functional_value(a) > 0)
            {
                a = root;
            }
            else
            {
                b = root;
            }
            if (abs((root - (a+b)/2)) < tolerence)
            {
                break;
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
