/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhedlund <zhedlund@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:02:01 by zhedlund          #+#    #+#             */
/*   Updated: 2023/06/07 13:47:20 by zhedlund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char format, va_list args)
{
	int	type;

	type = 0;
	if (format == 'c')
		type += print_char(va_arg(args, int));
	else if (format == 's')
		type += print_str(va_arg(args, char *));
	else if (format == 'p')
		type += print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		type += print_int(va_arg(args, int));
	else if (format == 'u')
		type += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		type += print_hex(va_arg(args, unsigned int), 97);
	else if (format == 'X')
		type += print_hex(va_arg(args, unsigned int), 65);
	return (type);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	res;

	if (!format)
		return (-1);
	va_start(args, format);
	res = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				res += check_format(*format, args);
			else if (*format == '%')
				res += print_char('%');
		}
		else
			res += print_char(*format);
		format++;
	}
	va_end(args);
	return (res);
}

/*#include <stdio.h>

int main(void) 
{
    char c = '@';
    char *str = "This is a string";
    int num = -2369854;
    unsigned int uNum = 3214569874;
    void *ptr = &num;

    ft_printf("Character: %c\n", c);
	printf("Character: %c\n", c);
    ft_printf("String: %s\n", str);
	printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", ptr);
	printf("Pointer: %p\n", ptr);
    ft_printf("Decimal: %d\n", num);
	printf("Decimal: %d\n", num);
    ft_printf("Integer: %i\n", num);
	printf("Integer: %i\n", num);
    ft_printf("Unsigned: %u\n", uNum);
	printf("Unsigned: %u\n", uNum);
    ft_printf("Lowercase Hexadec: %x\n", uNum);
	printf("Lowercase Hexadec: %x\n", uNum);
    ft_printf("Uppercase Hexadec: %X\n", uNum);
	printf("Uppercase Hexadec: %X\n", uNum);
    ft_printf("Percent Sign: %%\n");
	printf("Percent Sign: %%\n");

    return (0);
}*/
