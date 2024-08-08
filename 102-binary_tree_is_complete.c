#include "binary_trees.h"

/**
 * count_nodes - Counts the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Total number of nodes.
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete_recursive - Helper function to check,
 * If a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 * @index: Current index of the node.
 * @node_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int is_complete_recursive(const binary_tree_t *tree, size_t index,
		size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
			is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node_count;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);
	return (is_complete_recursive(tree, 0, node_count));
}
