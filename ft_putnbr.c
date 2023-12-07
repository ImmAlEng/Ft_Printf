/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:45:50 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 13:25:38 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	ft_printnbr_base(int32_t fd, const char *base, uint32_t b_size,
		uint64_t nb)
{
	if (nb < b_size)
		return (write(fd, &base[nb % b_size], 1));
	return (ft_printnbr_base(fd, base, b_size, nb / b_size) + write(fd, &base[nb
				% b_size], 1));
}

int32_t	ft_printnbr_base_neg(int32_t fd, const char *base, uint32_t b_size,
		int64_t nb)
{
	if (nb < 0)
		return (write(fd, "-", 1) + ft_printnbr_base(fd, base, b_size, -nb));
	return (ft_printnbr_base(fd, base, b_size, nb));
}

int32_t	ft_printbinary(void *nb, int32_t length)
{
	int32_t	size;
	int32_t	i;
	int64_t	*n;

	size = 0;
	i = (length << 3) - 1;
	n = (int64_t *)nb;
	while (i >= 0)
	{
		if (i % 8 == 7 && i + 1 != (length << 3))
			size += write(1, " ", 1);
		if (*n & (1ULL << i))
			size += write(1, "1", 1);
		else
			size += write(1, "0", 1);
		i--;
	}
	return (size);
}
