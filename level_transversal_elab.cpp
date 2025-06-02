#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

// Main recursive function that stores the
// spiral traversal in vector res.
void getLevel(Node* root, int level, bool ltr, vector<int>& res) {
    if (root == nullptr) return;
    if (level == 1)
        res.push_back(root->data);
    else if (level > 1) {
        if (ltr) {
            getLevel(root->left, level - 1, ltr, res);
            getLevel(root->right, level - 1, ltr, res);
        } else {
            getLevel(root->right, level - 1, ltr, res);
            getLevel(root->left, level - 1, ltr, res);
        }
    }
}

vector<int> findSpiral(Node* root) {
    vector<int> res;
    int h = height(root);
    bool ltr = false;
    for (int i = 1; i <= h; i++) {
        getLevel(root, i, ltr, res);
        ltr = !ltr;
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = findSpiral(root);
    for (int x : res)
        cout << x << " ";
    return 0;
}