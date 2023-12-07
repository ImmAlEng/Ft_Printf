/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:22:56 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 16:16:27 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	ft_identifier(t_printf *data, const char *s)
{
	(data->i)++;
	if (s[data->i] == 'l' || s[data->i] == 'h' || s[data->i] == 'L')
		return (ft_handle_16_64(s, data));
	else if (s[data->i] == 'x' || s[data->i] == 'X' || s[data->i] == 'u'
		|| s[data->i] == 'o' || s[data->i] == 'q' || s[data->i] == 'b')
		return (ft_handle_uint32(s, data));
	else if (s[data->i] == 'i' || s[data->i] == 'd')
		return (ft_handle_int32(s, data));
	else if (s[data->i] == 'f')
		return (ft_handle_float(s, data));
	else if (s[data->i] == 'c' || s[data->i] == 's' || s[data->i] == '%')
		return (ft_handle_characters(s, data));
	else if (s[data->i] == 'p')
		return (ft_handle_pointer(va_arg(data->args, uint64_t), data));
	return (0);
}

int32_t	ft_printf_fd(int fd, const char *s, ...)
{
	t_printf	data;

	if (!s)
		return (-1);
	data.i = 0;
	data.count = 0;
	data.fd = fd;
	va_start(data.args, s);
	while (s[data.i] != '\0')
	{
		if (s[data.i] == '%')
		{
			if (ft_identifier(&data, s) == -1)
				return (-1);
		}
		else if (ft_printchar_fd(s[(data.i)++], data.fd))
			data.count++;
		else
			return (-1);
	}
	va_end(data.args);
	return (data.count);
}

int32_t	ft_printf(const char *s, ...)
{
	t_printf	data;

	if (!s)
		return (-1);
	data.i = 0;
	data.count = 0;
	data.fd = 1;
	va_start(data.args, s);
	while (s[data.i] != '\0')
	{
		if (s[data.i] == '%')
		{
			if (ft_identifier(&data, s) == -1)
				return (-1);
		}
		else if (ft_printchar_fd(s[(data.i)++], data.fd))
			data.count++;
		else
			return (-1);
	}
	va_end(data.args);
	return (data.count);
}

int32_t	ft_printerror(const char *s, ...)
{
	t_printf	data;

	if (!s)
		return (-1);
	data.i = 0;
	data.count = 0;
	data.fd = 2;
	va_start(data.args, s);
	while (s[data.i] != '\0')
	{
		if (s[data.i] == '%')
		{
			if (ft_identifier(&data, s) == -1)
				return (-1);
		}
		else if (ft_printchar_fd(s[(data.i)++], data.fd))
			data.count++;
		else
			return (-1);
	}
	va_end(data.args);
	return (data.count);
}
