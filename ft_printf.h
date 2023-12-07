/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:46:36 by iengels           #+#    #+#             */
/*   Updated: 2023/10/23 13:21:25 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_printf
{
	int32_t	i;
	int32_t	count;
	int32_t	fd;
	bool	error;
	va_list	args;
}			t_printf;

// ft_putnbr.c
int32_t		ft_printnbr_base_neg(int32_t fd, const char *base, uint32_t b_size,
				int64_t nb);
int32_t		ft_printnbr_base(int32_t fd, const char *base, uint32_t b_size,
				uint64_t nb);
int32_t		ft_printbinary(void *nb, int32_t length);

// ft_putfloat.c
int32_t		ft_printnbr_float(int32_t fd, double nb);
int32_t		ft_float_rec(int32_t fd, char *base, double nb, int32_t prec);

// ft_printf_utils.c
int32_t		ft_strlen_pf(const char *s);
int32_t		ft_printchar_fd(char c, int32_t fd);
int32_t		ft_printstr_fd(const char *s, int32_t fd);
int32_t		ft_handle_pointer(uint64_t p, t_printf *data);

// ft_handler.c
int32_t		ft_handle_16_64(const char *s, t_printf *data);
int32_t		ft_handle_int32(const char *s, t_printf *data);
int32_t		ft_handle_uint32(const char *s, t_printf *data);
int32_t		ft_handle_float(const char *s, t_printf *data);
int32_t		ft_handle_characters(const char *s, t_printf *data);

// ft_printf.c
int32_t		ft_identifier(t_printf *data, const char *s);
int32_t		ft_printf_fd(int fd, const char *s, ...);
int32_t		ft_printf(const char *s, ...);
int32_t		ft_printerror(const char *s, ...);

#endif
