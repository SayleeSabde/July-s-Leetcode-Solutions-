/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int i = digits.size()-1;
       while(i >= 0 && digits[i] == 9){
            digits[i] = 0;
            i--;
       }
      if(i == -1) {
            digits[i+1] = 1;
            digits.push_back(0);
      }
      else 
            digits[i] = digits[i] + 1;
           
        return digits;
    }
};
