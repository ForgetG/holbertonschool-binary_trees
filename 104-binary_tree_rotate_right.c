#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation
 * on a binary tree
 * @tree: Pointer to the root of the tree
 * Return: new_root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right != NULL)
		new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	if (new_root->parent != NULL)
	{
		if (new_root->parent->right == tree)
			new_root->parent->right = new_root;
		else
			new_root->parent->left = new_root;
	}
	return (new_root);
}
