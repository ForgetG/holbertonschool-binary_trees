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
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if the binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect.
 * Else: 0.
 */

int	binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t	left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
}
