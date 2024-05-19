/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:41:58 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/18 17:00:56 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	maxtoup(t_list **b, t_list *max)
{
	t_list	*node;
	int		counter;
	int		index;

	counter = ft_lstsize((*b));
	index = 0;
	node = (*b);
	if ((*b) == max)
		return ;
	while (node != max)
	{
		index++;
		node = node->next;
	}
	if (index <= counter / 2)
	{
		while ((*b) != max)
			rotate(b, 0);
	}
	else if (index > counter / 2)
	{
		while ((*b) != max)
			revrotate(b, 0);
	}
}

void	mintoup(t_list **a, t_list *min)
{
	t_list	*node;
	int		counter;
	int		index;

	counter = ft_lstsize((*a));
	index = 0;
	node = (*a);
	if ((*a) == min)
		return ;
	while (node != min)
	{
		index++;
		node = node->next;
	}
	if (index <= counter / 2)
	{
		while ((*a) != min)
			rotate(a, 1);
	}
	else if (index > counter / 2)
	{
		while ((*a) != min)
			revrotate(a, 1);
	}
}

void	smallsort(t_swap *s)
{
	t_list	*min;
	int		i;

	i = 5;
	while (ft_lstsize(s->stacka) > 3)
	{
		getmin(s->stacka, &min);
		mintoup(&s->stacka, min);
		push(&s->stacka, &s->stackb, 0);
	}
	if (!issorted(s->stacka) && ft_lstsize(s->stacka) == 3)
		sortthree(s);
	while (s->stackb)
		push(&s->stackb, &s->stacka, 1);
}

void	sortthree(t_swap *s)
{
	if (ismax(s->stacka))
	{
		rotate(&s->stacka, 1);
		if (s->stacka->content > s->stacka->next->content)
			swap(&s->stacka, 1);
	}
	else if (ismin(s->stacka))
	{
		push(&s->stacka, &s->stackb, 0);
		swap(&s->stacka, 1);
		push(&s->stackb, &s->stacka, 0);
	}
	else
	{
		swap(&s->stacka, 1);
		if (!ismin(s->stacka))
		{
			rotate(&s->stacka, 1);
			swap(&s->stacka, 1);
		}
	}
}

void	fillstackb(t_swap *s, int start, int end)
{
	while (s->stacka)
	{
		if (found(s->stacka->content, s->nums, start, end))
		{
			push(&s->stacka, &s->stackb, 0);
			correctorder(&s->stackb);
			if (end + 1 < s->counter)
				end++;
			if (s->nums[end + 1])
				start++;
		}
		else if (start && s->stacka->content < s->nums[start])
		{
			push(&s->stacka, &s->stackb, 0);
			rotate(&s->stackb, 0);
			if (end + 1 < s->counter)
				end++;
			if (s->nums[end + 1])
				start++;
		}
		else
			rotate(&s->stacka, 1);
	}
}
