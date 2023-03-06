/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_id.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:28:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:43:37 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_lenght(int number)
{
	int	string_lenght;

	string_lenght = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		string_lenght++;
	while (number != 0)
	{
		number /= 10;
		string_lenght++;
	}
	return (string_lenght);
}

static char	*ft_itoa(int number)
{
	int			string_lenght;
	long int	long_number;
	char		*string;

	long_number = (long int)number;
	string_lenght = get_lenght(long_number);
	string = malloc((string_lenght + 1) * sizeof(char));
	if (!string)
		return (0);
	string[string_lenght] = '\0';
	if (long_number == 0)
		string[0] = '0';
	if (long_number < 0)
	{
		string[0] = '-';
		long_number *= -1;
	}
	while (long_number > 0)
	{
		string[string_lenght - 1] = (long_number % 10) + '0';
		long_number /= 10;
		string_lenght--;
	}
	return (string);
}

int	put_id(int number)
{
	char	*string;

	string = ft_itoa(number);
	if (!string)
		return (-1);
	if (print_string(string) == -1)
		return (free(string), -1);
	free (string);
	return (get_lenght(number));
}
