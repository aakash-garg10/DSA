// gcd(a,b)=gcd(a-b,b);
// or if we simplify
// gcd(a,b)=gcd(a%b,b);

// lcm(a,b)=a*b/gcd(a,b);
// or
// lcm(a,b)*gcd(a,b)=a*b;

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int result = min(a, b); // Find Minimum of a & b
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result; // return gcd of a nd b
}

int main(){
    int a, b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    cout << "The GCD of " << a << " & " << b << " is: " << gcd(a,b) << endl;
    //STL BASED
    cout << "gcd(6, 20) = " << __gcd(6, 20) << endl; 

    return 0;
}