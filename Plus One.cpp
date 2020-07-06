/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int i = digits.size()-1;
       int count = 0;
       
       while(i >= 0){
           if(digits[i] == 9) {
                count++;
                i--;
           }
           else 
               break;
       }
       if(count == 0) {
           digits[digits.size()-1] = digits[digits.size()-1] + 1;
       }
       else {
           i++;
           if(i == 0) {
                digits[i] = 1;
                i++;
                digits.push_back(0);
           }
           else 
               digits[i-1] = digits[i-1] + 1;
                
           while(i < digits.size()) {
                digits[i] = 0;
                i++;
           }
           
       }
        return digits;
    }
};