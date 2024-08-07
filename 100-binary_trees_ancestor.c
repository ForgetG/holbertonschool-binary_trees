#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: On success: Pointer to the lowest common ancestor node.
 * On failure: NULL.
 */

binary_tree_t	*binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t	*ancestor, *temp;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	ancestor = first;
	while (ancestor)
	{
		temp = second;
		while (temp)
		{
			if (ancestor == temp)
				return ((binary_tree_t *)ancestor);
			temp = temp->parent;
		}
		ancestor = ancestor->parent;
	}
	return (NULL);
}
