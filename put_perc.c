/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_%.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:25:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:02:35 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_perc(void)
{
	return (write(1, "%", 1));
}
