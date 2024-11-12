#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value) : val(value), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(vector<char>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == '-') {
        index++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[index++]);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);
    return node;
}


void Inorder(TreeNode* node, vector<char>& inorder) {
    if (!node) return;
    Inorder(node->left, inorder);
    inorder.push_back(node->val);
    Inorder(node->right, inorder);
}

void Postorder(TreeNode* node, vector<char>& postorder) {
    if (!node) return;
    Postorder(node->left, postorder);
    Postorder(node->right, postorder);
    postorder.push_back(node->val);
}

int main() {
    string input;
    getline(cin, input);
    istringstream ss(input);
    vector<char> preorder;
    char val;

    while (ss >> val) {
        preorder.push_back(val);
    }

    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    vector<char> inorder;
    Inorder(root, inorder);
    cout << "Inorder: ";
    for (char c : inorder) {
        cout << c << " ";
    }
    cout << endl;

    vector<char> postorder;
    Postorder(root, postorder);
    cout << "Postorder: ";
    for (char c : postorder) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

