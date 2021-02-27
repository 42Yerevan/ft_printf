/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:24:08 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/19 10:59:36 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_revers_str(char *s)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s);
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	ptr[0] = '0';
	ptr[1] = 'x';
	i = 2;
	while ((len) != 0)
	{
		ptr[i] = s[len - 1];
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}

void		ft_iswidth(char **c, int d)
{
	int n;

	n = 0;
	if (**c == '*' && d)
	{
		flags.minwidth = d;
		(*c)++;
	}
	else
	{
		n = ft_atoi(*c);
		flags.minwidth = n;
		while (**c >= '0' && **c <= '9')
			(*c)++;
	}
	if (**c == '*')
		(*c)++;
}

void		ft_isslice(char **c, int d)
{
	int n;

	n = 0;
	if (**c == '.' || **c == '*')
	{
		flags.dot = 1;
		(*c)++;
		if (**c == '*')
		{
			flags.maxwidth = d;
			(*c)++;
		}
		else
		{
			n = ft_atoi(*c);
			flags.maxwidth = n;
			while (**c >= '0' && **c <= '9')
				(*c)++;
		}
	}
	if (d < 0)
		flags.dot = 0;
}

int			ft_dc(unsigned n)
{
	int i;

	i = 0;
	if (n < 0 || n == 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa2(unsigned n)
{
	int			n1;
	long	int	n2;
	int			i;
	char		*d;

	i = ft_dc(n);
	n1 = 0;
	n2 = n;
	d = malloc(i);
	d[--i] = '\0';
	if (n < 0)
	{
		n2 = n * -1;
		d[n1] = '-';
		n1++;
	}
	while (n1 < i--)
	{
		d[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (d);
}
