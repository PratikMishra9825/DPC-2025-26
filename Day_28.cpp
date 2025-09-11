#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

TreeNode* buildTree(vector<int> &arr) {
    if (arr.empty()) return NULL;
    vector<TreeNode*> nodes;
    for (int val : arr) {
        if (val == -1) nodes.push_back(NULL); 
        else nodes.push_back(new TreeNode(val));
    }
    int j = 1;
    for (int i = 0; i < nodes.size() && j < nodes.size(); i++) {
        if (nodes[i]) {
            if (j < nodes.size()) nodes[i]->left = nodes[j++];
            if (j < nodes.size()) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

int main() {
    vector<int> arr = {1,2,2,3,4,4,3};
    TreeNode* root = buildTree(arr);
    cout << (isSymmetric(root) ? "true" : "false") << endl;
    return 0;
}
