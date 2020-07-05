/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.*/

class Solution {
    int toBinary(int n) {
        string r;
        int cnt = 0;
        while(n!=0) {
          //  r=(n%2==0 ?"0":"1")+r;
            if(n%2 == 1)
                cnt++;
            n/=2;
        }
        return cnt;
    }
public:
    int hammingDistance(int x, int y) {
        int res = toBinary((x | y) & (~x | ~y));
        return res;
    }
};