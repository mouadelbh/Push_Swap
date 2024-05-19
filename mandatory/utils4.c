/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:17:21 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/18 17:02:05 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	getmax(t_list *a, t_list **max)
{
	(*max) = a;
	while (a)
	{
		if ((*max)->content < a->content)
			(*max) = a;
		a = a->next;
	}
}

void	getmin(t_list *a, t_list **min)
{
	(*min) = a;
	while (a)
	{
		if ((*min)->content > a->content)
			(*min) = a;
		a = a->next;
	}
}

int	ismax(t_list *a)
{
	int	tmp;

	tmp = a->content;
	while (a)
	{
		if (a->content > tmp)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ismin(t_list *a)
{
	int	tmp;

	tmp = a->content;
	while (a)
	{
		if (a->content < tmp)
			return (0);
		a = a->next;
	}
	return (1);
}
