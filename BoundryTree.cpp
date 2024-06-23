class Solution
{
public:
    void LeftSub(Node *root, vector<int> &ans)
    {
        if (!root || (!root->left && !root->right))
            return;

        ans.push_back(root->data);
        if (root->left)
            LeftSub(root->left, ans);
        else
            LeftSub(root->right, ans);
    }

    void Leaf(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }

        Leaf(root->left, ans);

        Leaf(root->right, ans);
    }

    void RightSub(Node *root, vector<int> &ans)
    {

        if (!root || (!root->left && !root->right))
            return;

        if (root->right)
            RightSub(root->right, ans);
        else
            RightSub(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        // root element
        ans.push_back(root->data);
        // Left boundry ko print araw
        LeftSub(root->left, ans);
        // Leff ko print
        if (root->left || root->right)
            Leaf(root, ans);
        // right sub tree ko print karaw
        RightSub(root->right, ans);

        return ans;
    }
};