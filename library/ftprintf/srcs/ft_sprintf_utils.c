/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:40:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:41:58 by lyeh             ###   ########.fr       */
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

char	*convert_lst2str(t_list **ch_arr)
{
	int		i;
	int		len;
	char	*str;
	t_list	*root;

	root = *ch_arr;
	len = ft_lstsize(*ch_arr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *((char *)((*ch_arr)->content));
		(*ch_arr) = (*ch_arr)->next;
		i++;
	}
	str[len] = '\0';
	*ch_arr = root;
	ft_lstclear(ch_arr, free);
	return (str);
}
