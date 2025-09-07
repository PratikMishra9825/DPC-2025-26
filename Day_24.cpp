#include <iostream>
#include<vector>
#include<queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& nodes) {
    if(nodes.empty() || nodes[0]==-1)
     return NULL;
    TreeNode* root=new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if(i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if(i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q)
 return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right) return root;
    return left ? left : right;
}


TreeNode* findNode(TreeNode* root, int val) {
    if(!root) return NULL;
    if(root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if(left) return left;
    return findNode(root->right, val);
}
int main() {
    vector<int> nodes = {3,5,1,6,2,0,8,-1,-1,7,4};
    int pVal = 5, qVal = 1;
    TreeNode* root = buildTree(nodes);
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);
    TreeNode* ans = lowestCommonAncestor(root, p, q);
    if(ans)
        cout<< "LCA of " << pVal << " and " << qVal << " is: " << ans->val << endl;
    else
        cout<<"Nodes not found in the tree."<<endl;
    return 0;
}
