
bool BST(Node *root, int &prev)
{
    if (!root)
        return 1;

    if (!BST(root->left, prev))
        return 0;

    if (root->data <= prev)
        return 0;

    prev = root->data;

    return BST(root->right, prev);
}

bool isBST(Node *root)
{
    int prev = INT_MIN;
    BST(root, prev);
}
}
;