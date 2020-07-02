/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        else{
            int lh = height(root->left);
            int rh = height(root->right);
            if(lh > rh)
                return(lh+1);
            else
                return(rh+1);
        }
    }
    void printCurrentLevel(TreeNode* root, int level,vector<int>&res) {
        if(root == NULL)
            return ;
        if(level == 1){
            res.push_back(root->val);
            //cout<<root->val;
        }
            
        else if (level > 1) { 
            printCurrentLevel(root->left, level-1,res); 
            printCurrentLevel(root->right, level-1,res); 
        } 
        
    }
public:
   
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);                   //finding height of tree
        
        vector<vector<int>>result;
        vector<int> res;

        vector<int> res1;
        int i; 
        for (i=1; i<=h; i++) {
            printCurrentLevel(root, i,res);
            
            result.push_back(res);
            res.clear();
           
        }
        reverse(result.begin(),result.end());      //reversing vector to get bottom-up level order traversal
        return result;
    }
};