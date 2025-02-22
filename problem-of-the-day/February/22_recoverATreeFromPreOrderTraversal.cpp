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
class Solution {
public:
    TreeNode* solve(string s, int n, int& i, int depth){
        if(i >= n) return NULL;
        int j = i;

        while(j < n && s[j] == '-') j++;

        int dash = j - i;
        if(dash != depth) return NULL;

        i = j;
        int num = 0;
        while(i < n && isdigit(s[i])){
            num = (num * 10) + (s[i] - '0');
            i++;
        }

        TreeNode* newNode = new TreeNode(num);
        newNode->left = solve(s, n, i, depth+1);
        newNode->right = solve(s, n, i, depth+1);

        return newNode;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;

        return solve(traversal, n, i, 0);
    }
};