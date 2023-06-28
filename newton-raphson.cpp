/* 1. This program is aimed to find root of non-linear
      function using newton-raphson method.
   2. It doesn't take any input.
   3. The specified function is given in it.
   4. The derivative is calculated manually
*/

#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
private:
    const double tolerence = 0.00001;

    // Given function is x^3 + x^2 - 1 = 0
    double functional_value(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }
    double derivative(double x)
    {
        return 3 * x * x + 2 * x;
    }

public:
    double root, new_root;
    void solve()
    {
        srand(time(0));
        while (1)
        {
            root = rand() % 10;
            if (derivative(root) != 0)
            {
                break;
            }
        }
        int k = 1; //The variable 'k' keeps track of number of iterations
        while (1)
        {   
            printf("Iteration %2d    root = %9f\n", k++, root);
            if (functional_value(root) == 0.0)
            {
                break;
            }
            new_root = root - functional_value(root) / derivative(root);
            if (abs(root - new_root) < tolerence)
            {
                break;
            }
            root = new_root;
            if (derivative(root) == 0)
            {
                root++;
            }
        }
        printf("Iteration %2d    root = %9f\n", k++, new_root);
        cout<<"\n\nThe root is "<<new_root <<" (correct upto 3 decimal palces)\n";
    }
};

int main(void)
{
    NewtonRaphson n = NewtonRaphson();
    n.solve();
}
