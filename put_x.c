/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 15:59:41 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:45:16 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_lenght_hex(unsigned int number)
{
	int	string_lenght;

	string_lenght = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		string_lenght++;
	}
	return (string_lenght);
}

static char	*ft_itoah(unsigned int x, const char format)
{
	int		string_lenght;
	char	*string;
	char	*hex_string;	

	if (format == 'x')
		hex_string = "0123456789abcdef";
	if (format == 'X')
		hex_string = "0123456789ABCDEF";
	string_lenght = get_lenght_hex(x);
	string = malloc((string_lenght + 1) * sizeof(char));
	if (!string)
		return (0);
	string[string_lenght] = '\0';
	if (x == 0)
		string[0] = '0';
	while (x > 0)
	{
		string[string_lenght - 1] = hex_string[x % 16];
		x /= 16;
		string_lenght--;
	}
	return (string);
}

int	put_x(unsigned int x, const char format)
{
	char	*string;
	int		lenght;

	lenght = get_lenght(x);
	string = ft_itoah(x, format);
	if (lenght == 0)
		return (0);
	if (!string)
		return (-1);
	if (print_string(string) == -1)
		return (free(string), -1);
	free (string);
	return (lenght);
}
