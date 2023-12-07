/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:31:48 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 16:36:56 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int32_t	ft_strlen_pf(const char *s)
{
	uint32_t	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i++])
		;
	return (i - 1);
}

int32_t	ft_printchar_fd(char c, int32_t fd)
{
	return (write(fd, &c, 1));
}

int32_t	ft_printstr_fd(const char *s, int32_t fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen_pf(s)));
}

int32_t	ft_handle_pointer(uint64_t p, t_printf *data)
{
	if (p == 0)
		data->count += write(1, "(nil)", 5);
	else
	{
		data->count += write(1, "0x", 2);
		data->count += ft_printnbr_base(data->fd, "0123456789abcdef", 16, p);
	}
	(data->i)++;
	return (0);
}
