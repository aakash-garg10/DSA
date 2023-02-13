class Solution {
public:
    double myPow(double x, long int n) {
        if(x==0)    return 0;
        if(n==0)    return 1;        
         if(n<0){
            n = -n;
            x = 1/x;
        }
        // 1ST APPROACH
        // //since we had half the power we are doing x*x in case of even
        // // in case of odd we just had to multiply by an extra x
        // return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    
        // 2nd APPROACH
    double res = 1;
    while (n > 0){
        if (n & 1)  res = res * x;  //odd h toh
        n = n >> 1;   //divide by 2
        x = x * x;
    }
    return res;
    }
};