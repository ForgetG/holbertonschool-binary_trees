#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node:  it's a pointer to the node to find the sibling
 * Return: NULL if the node or parent is NULL else return the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
