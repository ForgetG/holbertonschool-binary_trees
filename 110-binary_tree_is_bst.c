#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to check if a binary tree is BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value allowed.
 * @max: Maximum value allowed.
 *
 * Return: 1 if tree is valid BST,
 *	   0 otherwise.
 */
int	is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is
 *			A valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if valid BST,
 *	   0 otherwise.
 */
int	binary_tree_is_bst(const binary_tree_t *tree)
{
	int	min = -2147483648, max = 2147483647;

	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, min, max));
}
