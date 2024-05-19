/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:40:33 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/18 17:01:42 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	static int	k;
	char		*join;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (join == NULL)
		return (NULL);
	while (s1 && s1[i])
		join[j++] = s1[i++];
	i = 0;
	if (k)
		join[j++] = ' ';
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	k++;
	free(s1);
	return (join);
}
