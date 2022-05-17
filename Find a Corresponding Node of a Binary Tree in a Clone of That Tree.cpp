class Solution 
{
  public:
     void copy(TreeNode* original,TreeNode* cloned,TreeNode* target,TreeNode* &temp)
     {
            if(original == NULL)
               return;
            if(original->val == target->val)
            {
                temp = cloned;
                return;
            }
            copy(original->left,cloned->left,target,temp);
            copy(original->right,cloned->right,target,temp);   
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        TreeNode* temp = NULL;
        copy(original,cloned,target,temp);
        return temp;
    }
};
