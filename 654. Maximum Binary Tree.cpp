/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        else
        {
            auto max = nums.begin();
            for(auto iter = nums.begin(); iter!=nums.end(); iter++)
            {
                if(*iter > *max)
                    max = iter;
            }
            auto head = new TreeNode(*max);
            vector<int> left = vector<int>(nums.begin(),max);
            vector<int> right = vector<int>(max+1,nums.end());
            head->left = constructMaximumBinaryTree(left);
            head->right = constructMaximumBinaryTree(right);
            return head;
        }
        
    }
    
};