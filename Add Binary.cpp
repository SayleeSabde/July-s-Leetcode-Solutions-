/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.*/
class Solution {

public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int s = 0;
        while(i >= 0 || j >= 0 || s == 1) {
            s += ((i >= 0)? a[i] - '0': 0); 
            s += ((j >= 0)? b[j] - '0': 0); 
            res = char(s % 2 + '0') + res; 
            s /= 2;           
            i--;
            j--;
        }
        return res;
    }
};