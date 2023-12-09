/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:53:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/06 16:26:38 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_uitoa(unsigned int n)
{
	int				digits;
	char			*str;
	int				i;

	digits = count_digits(n);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	i = digits - 1;
	while (n != 0)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

int	print_unsigned(unsigned int u)
{
	char	*str;
	int		len;

	if (u == 0)
		return (print_char('0'));
	str = ft_uitoa(u);
	len = ft_strlen(str);
	if (str != NULL)
	{
		str[len] = '\0';
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (len);
}
