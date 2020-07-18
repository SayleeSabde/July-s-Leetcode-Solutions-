/*Given an input string, reverse the string word by word.*/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        //converting multiple spaces into one
        int space_cnt = 0;
        int word_cnt = 0;
        if(s == "")
            return "";
        for(int i = 0;i < s.length();i++) {
            if(s[i] == ' ') {
                if(word_cnt > 0) {
                    res.push_back(' ');
                    word_cnt = 0;
                }
                space_cnt++;
            }
            else {
                res.push_back(s[i]);
                word_cnt++;
            }
        }
        
        if(space_cnt > 0 && res.size() == 0)
            return "";
        if(res[res.length()-1] == ' ') {
            res.erase(res.length()-1);
        }
        string result;
        int j = 0;
        for(int i = res.length()-1;i >= 0;i--) {
            if(res[i] == ' ') {
                int k = 0;
                while(k < j) {
                    result.push_back(res[i+1+k]);
                    k++;
                }
                result.push_back(' ');
                j = 0;
            }
            else {
                j++;
            }
        }
        int k = 0;
        cout<<j;
        while(k < j) {
            result.push_back(res[k]);
            k++;
        }
        return result;
    }
};