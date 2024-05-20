/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:19:49 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/20 22:02:50 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	squareroot(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i - 1);
}

int	found(int c, int *nums, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (nums[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	correctorder(t_list **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	if ((*b)->content < (*b)->next->content)
		swap(b, 0);
}

int	order(int *nums, int counter)
{
	int	tmp;
	int	i;

	i = 1;
	if (!nums)
		return (0);
	tmp = nums[0];
	while (i < counter)
	{
		if (tmp > nums[i])
			return (1);
		tmp = nums[i++];
	}
	free(nums);
	return (0);
}

int	fillarray(t_swap *s)
{
	int		i;
	long	check;

	i = 0;
	s->nums = (int *)malloc(sizeof(int) * s->counter);
	if (!s->nums)
		return (0);
	while (i < s->counter)
	{
		check = ft_atoi(s->split[i]);
		s->nums[i] = ft_atoi(s->split[i]);
		if ((!s->nums[i] && !lookzero(s->split[i])) || \
		check > INT_MAX || check < INT_MIN)
		{
			ft_printf("Error\n");
			ft_free((void **)s->split, s->counter);
			return (free(s->nums), 0);
		}
		i++;
	}
	ft_free((void **)s->split, s->counter);
	return (1);
}
