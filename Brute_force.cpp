/**
 * Definition for a binary tree node.
 * Each node stores an integer value and has pointers to left and right children.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with only value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxans = 0; // Stores the maximum length of any ZigZag path found

    /**
     * Recursive helper to explore ZigZag paths in the tree.
     * @param root: Current node
     * @param steps: Current count of steps in ZigZag path
     * @param goleft: Direction of next expected move (true = left, false = right)
     */
    void maxan(TreeNode* root, int steps, bool goleft)
    {
        if (!root)
            return;

        // Update the maximum ZigZag length found so far
        maxans = max(maxans, steps);

        if (goleft) {
            // If previous move was to the right, move left to continue ZigZag
            maxan(root->left, steps + 1, false);

            // Restart from right child
            maxan(root->right, 1, true);
        } else {
            // If previous move was to the left, move right to continue ZigZag
            maxan(root->right, steps + 1, true);

            // Restart from left child
            maxan(root->left, 1, false);
        }
    }

    /**
     * Initiates ZigZag path search from both directions (left & right).
     * @param root: Root node of the binary tree
     * @return Maximum length of ZigZag path
     */
    int longestZigZag(TreeNode* root) {
        maxan(root, 0, false);  
        return maxans;
    }
};
