/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:39:24 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/13 16:01:16 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(nums);
	return (head);
}

t_list	*emptystack(int count)
{
	int		i;
	t_list	*head;
	t_list	*node;

	i = 0;
	head = NULL;
	while (i < count)
	{
		node = ft_lstnew(0);
		if (!node)
			return (NULL);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

int	ft_getnbr(int *nums, char **split, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < counter)
	{
		nums[i] = ft_atoi(split[i]);
		if (!nums[i] && !lookzero(split[i]))
		{
			printf("A non integer value found\n");
			return (free(nums), 0);
		}
		i++;
	}
	i = 0;
	while (i < counter)
	{
		j = i + 1;
		while (j < counter - 1)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				return (printf("A value has been repeated\n"), 0);
			}
			j++;
		}
		i++;
	}
	ft_free((void **)split, counter);
	return (1);
}

void	printlist(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	printf(" stack a:    stackb:\n");
	while (a && b)
	{
		printf("----------  ---------\n");
		printf("|   %i   |  |   %i   |\n",a->content, b->content);
		a = a->next;
		b = b->next;
	}
	printf("----------  ---------\n");
}

int	main(int ac, char **av)
{
	int 	i;
	int		*nums;
	char	*join;
	int		counter;
	char	**split;
	t_list	*stackb;
	t_list	*stacka;

	if (ac < 2)
		return (printf("There is no arguments to be sorted\n"), 1);
	i = 1;
	join = NULL;
	while (i < ac)
		join = ft_strjoin(join, av[i++]);
	counter = count_words(join, ' ');
	if (counter <= 1)
	{
		printf("Not enough numbers to be sorted\n");
		return (free(join), 1);
	}
	split = (char **)malloc(sizeof(char *) * (counter + 1));
	if (split == NULL)
		return (free(join), 1);
	ft_split(join, ' ', split, counter);
	free(join);
	if (!split)
		return (printf("Allocation error"));
	if (ft_checknums(split, counter))
		return (ft_free((void **)split, counter), 1);
	nums = (int *)malloc(sizeof(int) * counter);
	if (!nums)
		return (0);
	if (!ft_getnbr(nums, split, counter))
		return (ft_free((void **)split, counter), 1);
	stacka = createstack(nums, counter);
	stackb = emptystack(counter);
	printlist(stacka, stackb);
}
