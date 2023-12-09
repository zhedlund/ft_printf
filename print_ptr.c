/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:55:06 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/02 17:47:21 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_length(uintptr_t p)
{
	int			len;
	uintptr_t	temp;

	temp = p;
	if (temp == 0)
		return (1);
	len = 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}

void	assign_hex(char *str, int len, uintptr_t address)
{
	int	temp;
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		temp = address % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 87;
		address /= 16;
		i--;
	}
}

int	print_ptr(void *p)
{
	uintptr_t	address;
	int			len;
	char		*str;

	address = (uintptr_t)p;
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = ptr_length(address);
	str = malloc(sizeof(char) * (len + 3));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[len + 2] = '\0';
	assign_hex(str + 2, len, address);
	ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}
