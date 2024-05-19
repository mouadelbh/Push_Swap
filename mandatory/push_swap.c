/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:39:24 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/19 00:02:03 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	printstack(t_list *a, t_list *b)
// {
// 	ft_printf(" stack a:\n");
// 	while (a)
// 	{
// 		ft_printf("----------\n");
// 		ft_printf("|   %i   |",a->content);
// 		ft_printf("\n");
// 		a = a->next;
// 	}
// 	ft_printf("----------\n");
// 	ft_printf(" stack b:\n");
// 	while (b)
// 	{
// 		ft_printf("----------\n");
// 		ft_printf("|   %i   |",b->content);
// 		ft_printf("\n");
// 		b = b->next;
// 	}
// 	ft_printf("----------\n");
// }

void	sortalgo(t_swap *s)
{
	t_list	*max;
	int		start;
	int		end;

	start = 0;
	end = squareroot(s->counter) * 2;
	fillstackb(s, start, end);
	while (s->stackb)
	{
		getmax(s->stackb, &max);
		maxtoup(&s->stackb, max);
		push(&s->stackb, &s->stacka, 1);
	}
}

void	algorithm(t_swap *s)
{
	s->stacka = createstack(s->nums, s->counter);
	s->stackb = NULL;
	sortarray(s);
	if (s->counter == 2)
		swap(&s->stacka, 1);
	else if (s->counter == 3)
		sortthree(s);
	else if (s->counter < 6)
		smallsort(s);
	else
		sortalgo(s);
	ft_lstclear(&s->stacka);
	ft_lstclear(&s->stackb);
	free(s->nums);
}

int	main(int ac, char **av)
{
	int		i;
	t_swap	s;

	if (ac < 2)
		return (1);
	i = 1;
	s.join = NULL;
	while (i < ac)
	{
		s.join = ft_strjoin(s.join, av[i]);
		if (!av[i++][0])
		{
			ft_printf("ERROR\n");
			return (free(s.join), 0);
		}
	}
	if (!ft_checkchar(s.join))
		return (free(s.join), 1);
	s.counter = count_words(s.join, ' ');
	if (s.counter <= 1)
		return (free(s.join), 1);
	s.split = ft_split(&s, ' ');
	if (!s.split)
		return (ft_printf("Error\n"));
	if (ft_checknums(s.split, s.counter))
		return (ft_free((void **)s.split, s.counter), 1);
	if (!ft_getnbr(&s) || !order(s.nums, s.counter))
		return (0);
	algorithm(&s);
}
