/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:40:02 by tblancha          #+#    #+#             */
/*   Updated: 2019/04/26 14:44:10 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	else
		n = -n;
	while (n < -9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
