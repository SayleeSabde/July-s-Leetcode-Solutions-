/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

class Solution {
    
public:
    int climbStairs(int n) {
       if(n <= 2)
           return n;
        int n1 = 1;
        int n2 = 2;
        int i = 0;
        int res;
        while(i < n-2) {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
            i++;
        }
        return res;
    }
};