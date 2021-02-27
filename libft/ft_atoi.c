/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:27:33 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/05 15:27:36 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	int sign;
	int result;
	int i;

	i = -1;
	sign = 1;
	result = 0;
	while (str[++i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		;
	if (str[i] == '-' && ++i)
		sign *= -1;
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i++] - '0');
		else
			return (result * sign);
	}
	return (result * sign);
}
