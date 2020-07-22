/* Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
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
  
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> result;
        vector<int> vec;
        stack<TreeNode*> current;
        stack<TreeNode*>next;
        current.push(root);
        bool L2R = true;  //to keep track of left to right order
        while(!current.empty()) {
            TreeNode* temp = current.top();
            current.pop();
            if(temp) {
                vec.push_back(temp->val);
                if(L2R) {
                    if(temp->left)
                        next.push(temp->left);
                    if(temp->right)
                        next.push(temp->right);
                    
                }
                else {
                     if(temp->right)
                        next.push(temp->right);
                    
                     if(temp->left)
                        next.push(temp->left);
                }
            }
            if(current.empty()) {
                result.push_back(vec);
                vec.clear();
                L2R = !L2R;
                swap(current,next);
            }
            
        }
        return result;
    }
};