#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if binary tree is complete.
 * @tree: Pointer to the root of the tree to check.
 *
 * Return: If complete: 1.
 * Else: 0.
 */

int	binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	binary_tree_t **queue;
	int	is_complete = 1;
	size_t	front = 0, rear = 0, size = 1024;

	queue = malloc(sizeof(*queue) * size);
	if (tree == NULL || queue == NULL)
		return (0);
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current)
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
		else
		{
			while (front < rear)
			{
				if (queue[front++] != NULL)
				{
					is_complete = 0;
					break;
				}
			}
		}
	}
	free(queue);
	return (is_complete);
}
