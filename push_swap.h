/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:39:28 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/05/20 22:02:26 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_swap
{
	t_list	*stacka;
	t_list	*stackb;
	char	**split;
	char	*join;
	int		*nums;
	int		counter;
}	t_swap;

/*------utils------*/
long	ft_atoi(char *str);
int		ft_getnbr(t_swap *s);
int		count_words(char *s, char c);
int		ft_checknums(char **split, int counter);
int		ft_checkchar(char *s);
int		fillarray(t_swap *s);
int		lookzero(char *s);
int		ismax(t_list *a);
int		ismin(t_list *a);
int		order(int *nums, int counter);
int		squareroot(int n);
int		found(int c, int *nums, int start, int end);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	getmax(t_list *a, t_list **max);
void	getmin(t_list *a, t_list **mix);
void	correctorder(t_list **b);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_free(void **split, int counter);
char	**ft_split(t_swap *s, char c);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstnew(int content);
t_list	*createstack(int *nums, int counter);
size_t	ft_strlen(const char *s);
/*------algo------*/
void	smallsort(t_swap *s);
void	sortthree(t_swap *s);
void	sortalgo(t_swap *s);
void	sortarray(t_swap *s);
void	mintoup(t_list **a, t_list *min);
void	maxtoup(t_list **a, t_list *max);
void	fillstackb(t_swap *s, int start, int end);
int		issorted(t_list *head);
/*------moves-----*/
void	swap(t_list **head, int n);
void	push(t_list **src, t_list **dst, int n);
void	rotate(t_list **head, int n);
void	revrotate(t_list **head, int n);

#endif
