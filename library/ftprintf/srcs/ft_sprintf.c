/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:27:01 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/06 17:28:36 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

void	lst_add_char(t_list **lst, char ch)
{
	t_list	*node;
	
	node = ft_lstnew(&ch);
	if (!node)
		return ;
	ft_lstadd_back(lst, node);
}

void	handle_char(t_list **ch_arr, char c)
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
		lst_add_char(ch_arr, s[i++]);
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
		lst_add_char(ch_arr, num_str[i++]);
	free(num_str);
}

static void	formatter(t_list **ch_arr, char type, va_list *args)
{
	if (type == '%')
		lst_add_char(ch_arr, '%');
	else if (type == 'c')
		handle_char(ch_arr, va_arg(*args, int));
	else if (type == 's')
		handle_string(ch_arr, va_arg(*args, char *));
	else if (type == 'd' || type == 'i')
		handle_int(ch_arr, va_arg(*args, int));
	else
	{
		lst_add_char(ch_arr, '%');
		lst_add_char(ch_arr, type);
	}
}

static char	*convert_lst2str(t_list **ch_arr)
{
	int		i;
	int		len;
	char	*str;

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
	ft_lstclear(ch_arr, free);
	return (str);
}

static char	*helper(const char *fmt, va_list *args)
{
	const char	*formatters = "udicsupxX%";
	int			i;
	t_list		*ch_arr;

	i = 0;
	while (i < (int)ft_strlen(fmt))
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!ft_has_subset(fmt + i, formatters))
			{
				lst_add_char(&ch_arr, '%');
				lst_add_char(&ch_arr, fmt[i]);
			}
			else
				formatter(&ch_arr, fmt[i], args);
		}
		else
			lst_add_char(&ch_arr, fmt[i]);
		i++;
	}
	return (convert_lst2str(&ch_arr));
}

int	ft_sprintf(char *store_str, char *format, ...)
{
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	store_str = helper(format, &args);
	if (!*store_str)
		return (-1);
	va_end(args);
	return (ft_strlen(store_str));
}
