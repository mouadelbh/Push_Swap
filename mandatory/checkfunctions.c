/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:11 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/20 22:05:37 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lookzero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i] && s[i] == '0')
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	ft_checkchar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != 32 \
		&& s[i] != '-' && s[i] != '+')
		{
			ft_printf("Error\n");
			return (0);
		}
		if ((s[i] == '-' || s[i] == '+') && \
		!(s[i + 1] >= '0' && s[i + 1] <= '9'))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checkint(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	while (s[i++])
		j++;
	if (j > 10)
		return (0);
	return (1);
}

int	ft_checknums(char **split, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (!ft_checkchar(split[i++]))
			return (ft_printf("Error\n"));
	}
	i = 0;
	while (i < counter)
	{
		if (!ft_checkint(split[i++]))
			return (ft_printf("Error\n"));
	}
	return (0);
}
