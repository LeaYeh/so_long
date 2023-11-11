/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:27:01 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:41:53 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

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
