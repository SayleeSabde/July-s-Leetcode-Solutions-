/*You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
        vector<int> charmap(26);
        int size = tasks.size();
        for(char c : tasks) {
           charmap[c-'A']++; 
        }
       
        sort(charmap.begin(),charmap.end());
       
        int maxval = charmap[charmap.size()-1]-1;
        int idleslots = (maxval)*n;
        for(int i = 24;i >= 0;i--) {
            idleslots -= min(charmap[i],maxval);
        }
       return idleslots>0?idleslots+tasks.size():tasks.size();
    }
};