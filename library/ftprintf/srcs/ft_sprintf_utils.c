/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:40:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:49:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*copy_char(char c)
{
	char	*new;

	new = (char *)malloc(sizeof(char));
	if (!new)
		return (NULL);
	*new = c;
	return (new);
}

void	lst_add_char(t_list **lst, char *ch)
{
	t_list	*node;

	node = ft_lstnew(ch);
	if (!node)
		return ;
	ft_lstadd_back(lst, node);
}

void	handle_char(t_list **ch_arr, char *c)
{
	lst_add_char(ch_arr, c);
}

void	handle_string(t_list **ch_arr, char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		lst_add_char(ch_arr, copy_char(s[i++]));
}

void	handle_int(t_list **ch_arr, int n)
{
	char	*num_str;
	int		i;

	num_str = ft_itoa(n);
	if (!num_str)
		return ;
	i = 0;
	while (num_str[i])
		lst_add_char(ch_arr, copy_char(num_str[i++]));
	free(num_str);
}
