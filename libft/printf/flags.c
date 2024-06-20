/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:02:16 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/11 00:16:31 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_type	ft_format_type(char c)
{
	if (c == 'd' || c == 'i')
		return (DEC);
	else if (c == 's')
		return (STRING);
	else if (c == 'u')
		return (U_DEC);
	else if (c == 'x')
		return (HEX);
	else if (c == 'X')
		return (U_HEX);
	else if (c == 'c')
		return (CHAR);
	else if (c == 'p')
		return (POINTER);
	else if (c == '%')
		return (PER);
	return (NONE);
}

int	ft_handle_flags(t_format *f)
{
	int		len;
	int		pad;
	int		pad_dir;
	int		rhs_pad;

	len = 0;
	rhs_pad = 0;
	pad_dir = (f->lhs > 0 && !f->flag_count);
	pad = 1 + f->lhs - f->len;
	while (f->flag_count > 0 && f->flags[--(f->flag_count)])
	{
		ft_loop(f, &pad_dir, &rhs_pad, &pad);
		ft_update(f, &pad, &rhs_pad);
	}
	len += ft_print(f, pad, rhs_pad, pad_dir);
	free(f->value);
	return (len);
}

void	ft_fix_flags(t_format *f)
{
	int		idx;
	char	flag;

	idx = -1;
	while (f->flags[++idx])
	{
		flag = f->flags[idx];
		if (flag == '#' && (f->type != HEX && f->type != U_HEX))
			ft_del_mem(f->flags, '#', 1, ft_strlen(f->flags));
		else if (flag == ' ' && ft_strchr(f->flags, '+'))
			ft_del_mem(f->flags, ' ', 1, ft_strlen(f->flags));
		else if (flag == '0' && ft_strchr(f->flags, '-'))
			ft_del_mem(f->flags, '0', 1, ft_strlen(f->flags));
		else if (flag == '0' && ft_strchr(f->flags, '.'))
			ft_del_mem(f->flags, '0', 1, ft_strlen(f->flags));
	}
	f->flag_count = ft_strlen(f->flags);
}

void	ft_collect_lhs(const char *str, t_format *f, int *idx, int *flag)
{
	if (ft_strchr(FLAGS, str[*idx]))
	{
		while (ft_strchr(FLAGS, str[*idx]))
		{
			if (str[*idx] == '.')
				f->lhs = 0;
			if (!ft_strchr(f->flags, str[*idx]))
			{
				f->flags[*flag] = str[*idx];
				(*flag)++;
			}
			(*idx)++;
		}
		if (f->lhs < 0)
		{
			f->lhs = ft_atoi(&str[*idx]);
			while (ft_isdigit(str[*idx]))
				(*idx)++;
		}
		return ;
	}
	f->lhs = ft_atoi(&str[*idx]);
	while (ft_isdigit(str[*idx]))
		(*idx)++;
}

void	ft_collect_rhs(const char *str, t_format *f, int *idx, int *flag)
{
	if (ft_strchr(FLAGS, str[*idx]))
	{
		while (ft_strchr(FLAGS, str[*idx]))
		{
			if (str[*idx] == '.')
				f->rhs = 0;
			if (!ft_strchr(f->flags, str[*idx]))
			{
				f->flags[*flag] = str[*idx];
				(*flag)++;
			}
			(*idx)++;
		}
		f->rhs = ft_atoi(&str[*idx]);
		while (ft_isdigit(str[*idx]))
			(*idx)++;
		return ;
	}
	f->rhs = ft_atoi(&str[*idx]);
	while (ft_isdigit(str[*idx]))
		(*idx)++;
}
