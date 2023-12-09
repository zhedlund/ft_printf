/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:34:47 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/02 17:46:15 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_length(unsigned int x)
{
	int				len;
	unsigned int	temp;

	temp = x;
	len = 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}

int	print_hex(unsigned int x, int ascii)
{
	int		len;
	char	*hex;
	int		i;
	int		temp;

	if (x == 0)
		return (print_char('0'));
	len = hex_length(x);
	hex = malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (0);
	i = len - 1;
	while (x > 0)
	{
		temp = x % 16;
		if (temp < 10)
			hex[i--] = temp + 48;
		else
			hex[i--] = temp + ascii - 10;
		x /= 16;
	}
	hex[len] = '\0';
	ft_putstr_fd(hex, 1);
	free (hex);
	return (len);
}
