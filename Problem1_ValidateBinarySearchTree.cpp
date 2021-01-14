/**
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

// Below is Iterative solution 
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
        
//         //first write normal inorder traversal
// //         if(root==NULL) return true;
        
// //         stack<TreeNode*> st;
        
// //         while(root != NULL || !st.empty()){
// //             while(root!=NULL){
// //                 st.push(root);
// //                 root=root->left;
// //             }
// //             root=st.top(); // same as peek
// //             st.pop(); // in C++ it just deletes
// //             root=root->right;
// //         }       
//            // return true;
        
        
//         // after writing inorder traversal implement the previous node as NULL
//         // then check if the previous node value is greater than the root value
//         // if the condition fails we must return fall
//         //also should check the first edge case where in the beginning the previous node value is null so we must start comparing after the previous node value is not null.
        
        

        
//         if(root==NULL) return true;
        
//         TreeNode* prev = NULL; 
        
//         stack<TreeNode*> st;
        
//         while(root != NULL || !st.empty()){
//             while(root!=NULL){
//                 st.push(root);
//                 root=root->left;
//             }
//             root=st.top();
//             if(prev != NULL && prev->val >= root->val) return false;
//             prev=root;
            
//             st.pop();
//             root=root->right;
//         }
        
//         return true;
        
//     }
// };


class Solution {
    
    TreeNode* prev;
    
    
public:
    bool isValidBST(TreeNode* root) {
        
        
        if(root==NULL) return true;
        
   
        return inorder(root);
        
    }
    
private: 
    bool inorder(TreeNode* root){
        
        // stack<TreeNode*> st; // taken care by recursive task 
        
        // while(root != NULL || !st.empty()){
        
        if(root==NULL) return true;
        
        
            // while(root!=NULL){
            //     st.push(root);
            //     root=root->left;
            // }
            
            if(inorder(root->left)==false) return false; // all the left is done here which is the inner while loop 
            
            // root=st.top();
            if(prev != NULL && prev->val >= root->val) return false;
            prev=root;
            
            //st.pop();
            // root=root->right;
            return inorder(root->right);
        
        
    }
       
};