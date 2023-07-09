/* 1. This program is aimed to solve n linear equations with
      n unknowns using Gauss Jordan
   2. The first line of input is the number of n unknowns
   3. The next n lines is an augmented matrix corresponding to
      the n linear equations
*/

#include <bits/stdc++.h>
using namespace std;

class GaussJordan {
public:
    int n;
    double augmented_matrix[10][10], x[10];

    // The equations are provided as augmented matrix
    GaussJordan() {
        cin>>n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cin>>augmented_matrix[i][j];
            }
        }
    }

    void solve() {

        // Gauss Jordan Formmula
        for(int i = 0; i < n; i++) {
            if(augmented_matrix[i][i] == 0.0) {
                cout<<"Can't be solved using Gauss Jordan Formula\n";
                exit(0);
            }
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    double ratio = augmented_matrix[j][i] / augmented_matrix[i][i];
                    for(int k = 0; k <= n; k++) {
                        augmented_matrix[j][k] -= augmented_matrix[i][k] * ratio;
                    }
                }
            }
        }

        // Calculation of Solution
        for(int i = 0; i < n; i++) {
            x[i] = augmented_matrix[i][n] / augmented_matrix[i][i];
        }
        

        // Display the values of x
        for(int i = 0; i < n; i++) {
            cout<<"x"<<i<<" = "<<x[i];
            cout<<"\n";
        }
    }
};

int main(void)
{
    GaussJordan g = GaussJordan();
    g.solve();
}
