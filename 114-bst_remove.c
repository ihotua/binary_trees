#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the smallest value in a tree.
 * @node: The root node of the tree.
 *
 * Return: A pointer to the node with the smallest value.
 */
bst_t *min_value_node(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**
 * bst_remove - Removes a node with a specific value from a BST.
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *successor;

    if (root == NULL)
        return NULL;

    if (value < root->n)
    {
        root->left = bst_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = bst_remove(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            bst_t *right_child = root->right;
            if (right_child != NULL)
                right_child->parent = root->parent;
            free(root);
            return right_child;
        }
        else if (root->right == NULL)
        {
            bst_t *left_child = root->left;
            if (left_child != NULL)
                left_child->parent = root->parent;
            free(root);
            return left_child;
        }

        successor = min_value_node(root->right);
        root->n = successor->n;
        root->right = bst_remove(root->right, successor->n);
    }

    return root;
}
