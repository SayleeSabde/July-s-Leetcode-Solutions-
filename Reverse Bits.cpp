/*Reverse bits of a given 32 bits unsigned integer.*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       
        uint32_t no_of_bits = sizeof(n) * 8; 
        uint32_t reverse_num = 0,  temp; 
        vector<int> res;
         for (int i = 0; i < no_of_bits; i++) { 
             temp = n&1;
             res.push_back(temp);
             n = n >> 1;
         }
        for(int i = 0;i < res.size();i++) {
            reverse_num = reverse_num << 1;
            reverse_num |= res[i];
            
        }
        return reverse_num;
    }
};