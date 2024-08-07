#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if binary tree is complete.
 * @tree: Pointer to the root of the tree to check.
 *
 * Return: If complete: 1.
 * Else: 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, **new_queue, *node;
	size_t front = 0, back = 0, size = 1024;
	int found_null = 0;

	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL || tree == NULL)
		return (0);
	queue[back++] = (binary_tree_t *)tree;
	while (front < back)
	{
		node = queue[front++];
		if (node == NULL)
			found_null = 1;
		else
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue[back++] = node->left;
			queue[back++] = node->right;
			if (back >= size)
			{
				size *= 2;
				new_queue = realloc(queue, sizeof(*queue) * size);
				if (new_queue == NULL)
				{
					free(queue);
					return (0);
				}
				queue = new_queue;
			}
		}
	}
	free(queue);
	return (1);
}
