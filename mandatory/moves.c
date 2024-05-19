/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:53 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/18 23:27:25 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head, int n)
{
	t_list	*node;
	int		tmp;

	if (!(*head) || !(*head)->next)
		return ;
	node = *head;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
	if (n)
		write (1, "sa\n", 3);
	else
		write (1, "sb\n", 3);
}

void	push(t_list **src, t_list **dst, int n)
{
	t_list	*node;

	if (!(*src))
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = *dst;
	*dst = node;
	if (n)
		write (1, "pa\n", 3);
	else
		write (1, "pb\n", 3);
}

void	rotate(t_list **head, int n)
{
	t_list	*node;

	if (!(*head) || !(*head)->next)
		return ;
	node = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, node);
	node->next = NULL;
	if (n)
		write (1, "ra\n", 3);
	else
		write (1, "rb\n", 3);
}

void	revrotate(t_list **head, int n)
{
	t_list	*node;
	t_list	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	node = *head;
	while (node->next)
	{
		if (!node->next->next)
			tmp = node;
		node = node->next;
	}
	ft_lstadd_front(head, node);
	tmp->next = NULL;
	if (n)
		write (1, "rra\n", 4);
	else
		write (1, "rrb\n", 4);
}
