/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:20:37 by vmusaely          #+#    #+#             */
/*   Updated: 2021/02/17 17:58:55 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

struct			s_flags
{
	int			minus;
	int			zero;
	int			dot;
	int			maxwidth;
	int			minwidth;
	void		*arg;
	size_t		unsign;
	int			count;
}				flags;

int				ft_printf(const char *format, ...);
void			ft_isflag(char **c);
void			ft_iswidth(char **c, int d);
void			ft_isslice(char **c, int d);
void			ft_type(char *c);
void			ft_print_char(void);
void			ft_print_str(void);
void			ft_print_address(void);
void			ft_print_digit(void);
void			ft_print_hex(void);
void			ft_print_upperhex(void);
void			ft_print_percent(void);
char			*ft_revers_str(char *s);
char			*ft_revers_str(char *s);
char			*ft_itoa2(unsigned n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

#endif
