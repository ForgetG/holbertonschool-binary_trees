#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: it's pointer to the root node of the tree to measure the height
 * Return: height of tree or 0 if it's NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left);

	if (tree->right)
		right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root of the node of the tree.
 *
 * Return: If success: balance factor,
 * If tree is NULL, return: 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int	left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = ((int)binary_tree_height(tree->left));
	right_height = ((int)binary_tree_height(tree->right));
	return (left_height - right_height);
}
