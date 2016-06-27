/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<int,int> PI;
class Solution {
public:

    bool is_valid=false;
    map<TreeNode*,PI> DP;
    bool dfs(TreeNode* root){
        bool left,right;
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL){ 
            DP[root]=PI(root->val,root->val);
            return true;
        }
        if(root->left==NULL){
            if(root->right->val>root->val){
                right=dfs(root->right);
                PI minmax=DP[root->right];
                DP[root]=PI(min(root->val,minmax.first),max(root->val,minmax.second));
                return right && (root->val<minmax.first);
            }
            
            else{
                dfs(root->right);
                PI minmax=DP[root->right];
                DP[root]=PI(min(root->val,minmax.first),max(root->val,minmax.second));
                return false;
            }
        }    
        if(root->right==NULL){
          //  if(root->left->val<root->val) return dfs(root->left);
            //else return false;

            if(root->left->val<root->val){
                left=dfs(root->left);
                PI minmax=DP[root->left];
                DP[root]=PI(min(root->val,minmax.first),max(root->val,minmax.second));
                return left && (root->val>minmax.second);
            }
            
            else{
                dfs(root->left);
                PI minmax=DP[root->left];
                DP[root]=PI(min(root->val,minmax.first),max(root->val,minmax.second));
                return false;
            }            
            
        }    
        if( root->left->val < root->val && root->right->val > root->val){
            left=dfs(root->left);
            right=dfs(root->right);
            
            
            PI minmax_left=DP[root->left];
            PI minmax_right=DP[root->right];
            DP[root]=PI(    min( root->val , min(minmax_left.first,minmax_right.first) ) , max( root->val , max(minmax_left.second,minmax_right.second)) );
            return left && right && (root->val>minmax_left.second) && (root->val<minmax_right.first);
        }
        else{
            left=dfs(root->left);
            right=dfs(root->right);
            
            
            PI minmax_left=DP[root->left];
            PI minmax_right=DP[root->right];
            DP[root]=PI(    min( root->val , min(minmax_left.first,minmax_right.first) ) , max( root->val , max(minmax_left.second,minmax_right.second)) );
            return false;
        }    
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};