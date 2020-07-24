/*Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.*/

class Solution {
    void helper(vector<vector<int>>&res, vector<vector<int>>& graph, int cur,vector<int> tmp) {
        if(cur == graph.size()-1) {
            res.push_back(tmp);
            return;
        }
        for(int next : graph[cur]) {
            tmp.push_back(next);
            helper(res,graph,next,tmp);
            tmp.erase(tmp.begin()+(tmp.size()-1));
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> tmp;
        tmp.push_back(0);
        helper(res,graph,0,tmp);
        return res;
    }
};