/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_tree_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:16:06 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 18:06:59 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_tree	*left_rot(t_tree *parent)
{
	t_tree	*tmp;

	tmp = parent->left;
	parent->left = tmp->right;
	tmp->right = parent;
	return (tmp);
}

static t_tree	*right_rot(t_tree *parent)
{
	t_tree	*tmp;

	tmp = parent->right;
	parent->right = tmp->left;
	tmp->left = parent;
	return (tmp);
}

static int		get_diff(t_tree *node)
{
	int		left_h;
	int		right_h;

	left_h = tt_tree_h(node->left);
	right_h = tt_tree_h(node->right);
	return (left_h - right_h);
}

static t_tree	*balance(t_tree *node)
{
	int		diff;
	t_tree	*tmp;

	diff = get_diff(node);
	if (diff > 1)
	{
		if (get_diff(node->left) > 0)
			node = left_rot(node);
		else
		{
			tmp = node->left;
			node->left = right_rot(tmp);
			node = left_rot(node);
		}
	}
	else if (diff < -1)
	{
		if (get_diff(node->right) > 0)
		{
			tmp = node->right;
			node->right = left_rot(tmp);
		}
		node = right_rot(node);
	}
	return (node);
}

t_tree			*tt_tree_add
	(t_tree *root, t_tree *node, int (*cmp)(void *, void *))
{
	if (root == NULL)
		return (node);
	else if ((*cmp)(node->content, root->content) <= 0)
	{
		root->left = tt_tree_add(root->left, node, cmp);
		root = balance(root);
	}
	else if ((*cmp)(node->content, root->content) > 0)
	{
		root->right = tt_tree_add(root->right, node, cmp);
		root = balance(root);
	}
	return (root);
}
