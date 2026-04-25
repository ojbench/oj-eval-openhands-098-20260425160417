#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;
    
    void insert(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val);
            return;
        }
        if (val < node->val) {
            insert(node->left, val);
        } else {
            insert(node->right, val);
        }
    }
    
    void reverseInorder(TreeNode* node, int& cnt, int& result) {
        if (node == nullptr || cnt == 0) return;
        
        // Visit right subtree first (larger values)
        reverseInorder(node->right, cnt, result);
        
        // Visit current node
        if (cnt > 0) {
            cnt--;
            if (cnt == 0) {
                result = node->val;
                return;
            }
        }
        
        // Visit left subtree (smaller values)
        reverseInorder(node->left, cnt, result);
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(int val) {
        insert(root, val);
    }
    
    int findKthLargest(int k) {
        int result = -1;
        reverseInorder(root, k, result);
        return result;
    }
};

int main() {
    BST bst;
    
    // Read 7 nodes
    for (int i = 0; i < 7; i++) {
        int val;
        cin >> val;
        bst.insert(val);
    }
    
    // Read cnt
    int cnt;
    cin >> cnt;
    
    // Find and output the cnt-th largest
    cout << bst.findKthLargest(cnt) << endl;
    
    return 0;
}
