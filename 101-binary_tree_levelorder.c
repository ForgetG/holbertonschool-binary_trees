#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree,
 * Using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, **new_queue, *node;
	size_t front = 0, back = 0, size = 1024;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL)
		return;

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		node = queue[front++];
		func(node->n);

		if (node->left != NULL)
			queue[back++] = node->left;
		if (node->right != NULL)
			queue[back++] = node->right;

		if (back >= size)
		{
			size *= 2;
			new_queue = realloc(queue, sizeof(*queue) * size);
			if (new_queue == NULL)
			{
				free(queue);
				return;
			}
			queue = new_queue;
		}
	}

	free(queue);
}
