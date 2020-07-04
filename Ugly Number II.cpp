/* Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.  */

class Solution {
   int minimum(int x,int y,int z) {
       if(x <= y && x <= z) {
           return x;
       }
       else{
           if(y < x && y < z) {
               return y;
           }
       }
       return z;
   }
public:
    int nthUglyNumber(int n) {
       vector<int>result;
       result.push_back(1);
       int i = 0,j = 0,k = 0;
       while(result.size() < n) {
           int m2 = result[i]*2;
           int m3 = result[j]*3;
           int m5 = result[k]*5;
           int min = minimum(m2, m3, m5);
           result.push_back(min);
           if(min==m2)
            i++;
           if(min==m3)
            j++;
           if(min==m5)
            k++;
       }
       for(int i = 0;i < n;i++) {
           cout<<result[i];
       }
       return result[result.size()-1];
        
    }
};