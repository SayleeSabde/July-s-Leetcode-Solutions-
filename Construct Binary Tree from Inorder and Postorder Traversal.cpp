/* Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int in_start,int in_End,int*post_ind) {
        if(in_start > in_End)
            return NULL;
        TreeNode* node = new TreeNode(postorder[*post_ind]);

        (*post_ind)--;
        if(in_start == in_End)
            return node;
        int in_index = Search(inorder,in_start,in_End,node->val);
       
         node->right= build(inorder,postorder,in_index+1,in_End,post_ind);
         node->left = build(inorder,postorder,in_start,in_index-1,post_ind);
        return node;
    }
    int Search(vector<int>& inorder,int in_start,int in_End,int val) {
        int i;
        for(i = in_start;i <= in_End;i++) {
            if(inorder[i] == val)
                break;
            
        }
        return i;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size()-1;
        return build(inorder,postorder,0,size,&size);
    }
};