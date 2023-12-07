/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:06:45 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 13:27:15 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	ft_float_rec(int32_t fd, char *base, double nb, int32_t prec)
{
	double	round;

	if (nb < 0.00000001f)
		return (0);
	nb *= 10;
	if (prec == 1)
	{
		round = (nb - (long long)nb);
		round *= 10;
		if (round > 4.4)
			nb += 1.0;
		return (write(fd, &base[(int)(nb)], 1));
	}
	else
	{
		return (write(fd, &base[(int)(nb)], 1) + ft_float_rec(fd, base, nb
				- (long long)nb, --prec));
	}
}

int32_t	ft_printnbr_float(int32_t fd, double nb)
{
	int32_t	size;

	size = 0;
	if (nb > LLONG_MAX)
		return (-1);
	size += ft_printnbr_base_neg(fd, "0123456789", 10, (long long)nb);
	size += write(1, ".", 1);
	nb -= (long long)nb;
	size += ft_float_rec(fd, "0123456789", nb, 8);
	return (size);
}
