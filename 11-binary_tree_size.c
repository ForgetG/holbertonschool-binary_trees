#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: it's pointer to the root node of the tree to measure the size
 * Return: size of tree or 0 if it's NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
