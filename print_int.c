/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:59:20 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/06 16:24:18 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int d)
{
	char	*str;
	int		len;

	str = ft_itoa(d);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free (str);
	return (len);
}
