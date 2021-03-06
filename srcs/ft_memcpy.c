/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:57:43 by obouykou          #+#    #+#             */
/*   Updated: 2020/10/16 17:10:53 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp0;
	char		*tmp1;

	tmp0 = (char *)src;
	tmp1 = dst;
	if (!tmp0 && !tmp1)
		return (NULL);
	if (tmp0 == tmp1)
		return (dst);
	i = 0;
	while (i < n)
	{
		tmp1[i] = tmp0[i];
		i++;
	}
	return (dst);
}
