/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:58:05 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/18 17:02:02 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted(t_list *head)
{
	int	tmp;

	tmp = head->content;
	while (head)
	{
		if (tmp > head->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sortarray(t_swap *s)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < s->counter - 1)
	{
		j = 0;
		while (j < s->counter - i - 1)
		{
			if (s->nums[j] > s->nums[j + 1])
			{
				tmp = s->nums[j];
				s->nums[j] = s->nums[j + 1];
				s->nums[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i))
			i++;
		if (*(s + i) != '\0')
		{
			count++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
	}
	return (count);
}

int	ft_getnbr(t_swap *s)
{
	int		i;
	int		j;

	if (!fillarray(s))
		return (0);
	i = 0;
	while (i < s->counter)
	{
		j = i + 1;
		while (j < s->counter)
		{
			if (s->nums[i] == s->nums[j])
			{
				free(s->nums);
				return (ft_printf("Error\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_list	*createstack(int *nums, int counter)
{
	int		i;
	t_list	*head;
	t_list	*node;

	i = 0;
	head = NULL;
	while (i < counter)
	{
		node = ft_lstnew(nums[i++]);
		if (!node)
			return (NULL);
		ft_lstadd_back(&head, node);
	}
	return (head);
}
