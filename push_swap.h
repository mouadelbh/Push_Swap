/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:39:28 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/13 15:44:37 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(char *str);
int		count_words(char *s, char c);
int		ft_checknums(char **split, int counter);
int		lookzero(char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_free(void **split, int counter);
char	**ft_split(char *s, char c, char **split, int counter);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(int content);

#endif
