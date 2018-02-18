// Bisection

#include <bits/stdc++.h>
#define EPS 0.01

using namespace std;

int n, a[100];          // Maximum power of function

double F(int x) {              // The Function
    double sum = 0;
    
    for(int i = n; i >= 1; --i)
        sum += a[i] * (int)pow(x, i);
    
    return sum+a[0];
}

// Finding Maximum Absolute Value of root
// let, f(x) = a(n) * x^n + a(n-1) * x^(n-1) + ..... + a(1) x^0                 [where a(n-1), a(n-2), .... a(1) : are constant values]
// then,
//          |x_MAX] = sqrt( (a(n-1)/a(n))^2 - 2 * (a(n-2)/ a(n)) )
//

void StartValue(double &hi, double &low) {
    double tmp = pow((double)a[n-1]/a[n], 2) - (2 * (a[n-2]/a[n]));
    tmp = sqrt(tmp);
    
    hi = tmp, low = -tmp;
}


// Finds a root of nonlinear equation in the interval [a, b] using bisection method

void Bisect(double &hi, double &low, double &root, int &s, int &count, int iter=-1) {         // Set iter to nonzero if number of iter is fixed
    double x0, x1, x2, f0, f1, f2;
    
    x1 = hi;
    x2 = low;
    f1 = F(x1);
    f2 = F(x2);
    
    if(f1*f2 > 0) {         // Test if initial values bracket a SINGLE root
        s = 0;
        return;
    }
    
    count = 0;
    
    while(iter--) {
        x0 = (x1+x2)/2;
        f0 = F(x0);
        
        printf("x0 : %.2lf     x1 : %.2lf     x2 : %.2lf\n", x0, x1, x2);
        printf("f0 : %.2lf     f1 : %.2lf     f2 : %.2lf\n", f0, f1, f2);
        
        if(f0 == 0) {
            s = 1;
            root = x0;
            return;
        }
        
        if(f1*f0 < 0) {
            x2 = x0;
        }
        else {
            x1 = x0;
            f1 = f0;
        }
        
        if(fabs(x2-x1)/x2 < EPS) {
            s = 1;
            root = (x1+x2)/2;
            return;
        }
        
        count++;
    }
}


// Default input: 2
// 1 -4 -10

void FunctionInput() {
    printf("Enter Degree of Function: ");
    scanf("%d", &n);
    
    printf("Enter Constants n, n-1, ... 1 : ");
    
    for(int i = n; i >= 1; --i)
        scanf("%d", &a[i]);
    scanf("%d", &a[0]);
}
    

int main() {
    int valid, iter;
    double hi, low, root;

    // INPUT value
    FunctionInput();
    StartValue(hi, low);
    
    //hi = 0.66667, low = 0;
    
    printf("Lower Bound : %.2lf\nUpper Bound : %.2lf\n\n", low, hi);
    
    for(int i = low; i < (int)hi; ++i) {
        //printf("F(%d) : %.2lf\nF(%d) : %.2lf\n", i, F(i), i+1, F(i+1));
        
        if(F(i)*F(i+1) < 0) {
            double val1 = i+1, val2 = i;
            
            if(val1 < val2)
                swap(val1, val2);
            
            printf("\n\nBisection at %.2lf %.2lf\n", val1, val2);
            
            Bisect(val1, val2, root, valid, iter);
    
            if(!valid) {
                printf("Starting point do not bracket any root\n");
                printf("Check wheather they bracket EVEN roots\n");
            }
            else {
                printf("\nRoot : %.9lf\n", root);
                printf("F(root) : %.9lf\n", F(root));
                printf("Iterations : %d\n", iter);
            }
        }
    }
    
    return 0;
}

