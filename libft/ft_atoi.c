/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:06:26 by yarutiun          #+#    #+#             */
/*   Updated: 2023/05/03 10:02:10 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				ifminus;

	ifminus = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || \
		str[i] == '\v' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			ifminus = -1;
	}
	if (!ft_isdigit(str[i]))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(ifminus * num));
}
