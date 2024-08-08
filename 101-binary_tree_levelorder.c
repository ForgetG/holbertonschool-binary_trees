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
 * process_level - Processes nodes at a given level.
 * @tree: Pointer to the root node of the tree.
 * @level: Level to process.
 * @func: Pointer to a function to call for each node.
 */
void process_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		process_level(tree->left, level - 1, func);
		process_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree,
 * Using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t	height, index;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (index = 1; index <= height + 1; index++)
		process_level(tree, index, func);
}
