/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:11:50 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 13:21:11 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	ft_handle_16_64(const char *s, t_printf *data)
{
	if (s[data->i] == 'l')
	{
		(data->i)++;
		if (s[data->i] == 'i' || s[data->i] == 'd')
			data->count += ft_printnbr_base_neg(data->fd, "0123456789", 10,
					va_arg(data->args, int64_t));
		else if (s[data->i] == 'u')
			data->count += ft_printnbr_base(data->fd, "0123456789", 10,
					va_arg(data->args, uint64_t));
	}
	else if (s[data->i] == 'h')
	{
		(data->i)++;
		if (s[data->i] == 'i' || s[data->i] == 'd')
			data->count += ft_printnbr_base_neg(data->fd, "0123456789", 10,
					va_arg(data->args, int32_t));
		else if (s[data->i] == 'u')
			data->count += ft_printnbr_base(data->fd, "0123456789", 10,
					va_arg(data->args, uint32_t));
	}
	else if (s[data->i] == 'L' && s[data->i + 1] == 'f')
	{
		(data->i)++;
		data->count += ft_printnbr_float(data->fd, va_arg(data->args, double));
	}
	(data->i)++;
	return (0);
}

int32_t	ft_handle_int32(const char *s, t_printf *data)
{
    (void)s;
	data->count += ft_printnbr_base_neg(data->fd, "0123456789", 10,
			va_arg(data->args, int32_t));
	(data->i)++;
	return (0);
}

int32_t	ft_handle_uint32(const char *s, t_printf *data)
{
	if (s[data->i] == 'u')
		data->count += ft_printnbr_base(data->fd, "0123456789", 10,
				va_arg(data->args, uint32_t));
	else if (s[data->i] == 'x')
		data->count += ft_printnbr_base(data->fd, "0123456789abcdef", 16,
				va_arg(data->args, uint32_t));
	else if (s[data->i] == 'X')
		data->count += ft_printnbr_base(data->fd, "0123456789ABCDEF", 16,
				va_arg(data->args, uint32_t));
	else if (s[data->i] == 'o')
		data->count += ft_printnbr_base(data->fd, "01234567", 8,
				va_arg(data->args, uint32_t));
	else if (s[data->i] == 'q')
		data->count += ft_printnbr_base(data->fd, "0123", 4, va_arg(data->args,
					uint32_t));
	else if (s[data->i] == 'b')
		data->count += ft_printnbr_base(data->fd, "01", 2, va_arg(data->args,
					uint32_t));
	(data->i)++;
	return (0);
}

int32_t	ft_handle_float(const char *s, t_printf *data)
{
    (void)s;
	data->count += ft_printnbr_float(data->fd, va_arg(data->args, double));
	(data->i)++;
	return (0);
}

int32_t	ft_handle_characters(const char *s, t_printf *data)
{
	if (s[data->i] == '%')
		data->count += ft_printchar_fd('%', data->fd);
	else if (s[data->i] == 'c')
		data->count += ft_printchar_fd(va_arg(data->args, int), data->fd);
	else if (s[data->i] == 's')
		data->count += ft_printstr_fd(va_arg(data->args, char *), data->fd);
	(data->i)++;
	return (0);
}
