#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a leaf
 * @node: It's a pointer to the node to check
 * Return: 1 if node is a root or 0 if it's NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	if (node->parent == NULL)
	{
		return (1);
	}
	return (0);
}
