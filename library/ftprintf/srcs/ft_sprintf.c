/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:27:01 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/06 18:45:33 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

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

void	formatter(t_list **ch_arr, char *type, va_list *args)
{
	if (*type == '%')
		lst_add_char(ch_arr, copy_char('%'));
	else if (*type == 'c')
		handle_char(ch_arr, va_arg(*args, char *));
	else if (*type == 's')
		handle_string(ch_arr, va_arg(*args, char *));
	else if (*type == 'd' || *type == 'i')
		handle_int(ch_arr, va_arg(*args, int));
	else
	{
		lst_add_char(ch_arr, copy_char('%'));
		lst_add_char(ch_arr, type);
	}
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

char	*helper(char *fmt, va_list *args)
{
	const char	*formatters = "udicsupxX%";
	int			i;
	t_list		*head;

	head = NULL;
	i = 0;
	while (i < (int)ft_strlen(fmt))
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!ft_has_subset(fmt + i, formatters))
			{
				lst_add_char(&head, copy_char('%'));
				lst_add_char(&head, copy_char(fmt[i]));
			}
			else
				formatter(&head, &fmt[i], args);
		}
		else
			lst_add_char(&head, copy_char(fmt[i]));
		i++;
	}
	return (convert_lst2str(&head));
}

int	ft_sprintf(char **store_str, char *format, ...)
{
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	*store_str = helper(format, &args);
	if (!*store_str)
		return (-1);
	va_end(args);
	return (ft_strlen(*store_str));
}
