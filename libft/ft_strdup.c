/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:24:13 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 16:24:23 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strdup(const char *s1)
{
	char	*start;
	int		i;
	int		len;

	len = ft_strlen(s1);
	if (!(start = malloc(len + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		start[i] = s1[i];
		i++;
	}
	start[i] = 0;
	return (start);
}
