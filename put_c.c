/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:31:26 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:02:21 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(int character)
{
	return (write(1, &character, 1));
}
