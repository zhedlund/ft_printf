/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:34 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/06 13:58:30 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_str(char *s);
int		print_int(int d);
int		print_ptr(void *p);
int		print_hex(unsigned int x, int ascii);
int		print_unsigned(unsigned int u);

int		check_format(const char format, va_list args);
int		hex_length(unsigned int x);
int		ptr_length(uintptr_t p);
void	assign_hex(char *str, int len, uintptr_t address);
int		count_digits(unsigned int n);
char	*ft_uitoa(unsigned int n);

#endif
