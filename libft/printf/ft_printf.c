/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:27 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/14 18:00:50 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_handle_dot(int *pad, int *rhs_pad, int *pad_dir, t_format *f)
{
	*pad_dir = 1;
	*rhs_pad = 1 + f->rhs - ft_strlen(f->value);
	if (*rhs_pad < 0)
		*rhs_pad = 0;
	if (*pad > *rhs_pad && f->type != STRING)
		*pad = 1 + *pad - *rhs_pad;
	if ((f->rhs == f->lhs) || (f->lhs < f->rhs))
		*pad = 0;
	if (f->type == STRING)
	{
		*rhs_pad = 0;
		if (0 == ft_strncmp(f->value, "(null)", f->len) && \
				(int)ft_strlen("(null)") > f->rhs)
			f->value = ft_recycle(f->value, "");
		else
			f->value = ft_recycle_stack(f->value, \
					ft_substr(f->value, 0, f->rhs));
	}
	else if (f->value[0] == '-')
		(*pad)--;
}

static void	ft_handle_prefix(t_format *f, int *pad_dir)
{
	*pad_dir = 1;
	if (f->type != STRING && f->value[0] != '-')
		f->value = ft_add_prefix(f->value, &f->flags[f->flag_count]);
}

void	ft_update(t_format *f, int *pad, int *rhs_pad)
{
	if (f->type != CHAR)
		f->len = ft_strlen(f->value);
	if (*rhs_pad == 0)
		*pad = 1 + f->lhs - f->len;
}

void	ft_loop(t_format *f, int *pad_dir, int *rhs_pad, int *pad)
{
	if (f->flags[f->flag_count] == '0')
		ft_handle_zero(f, rhs_pad, pad);
	else if (f->flags[f->flag_count] == '+' || f->flags[f->flag_count] == ' ')
		ft_handle_prefix(f, pad_dir);
	else if (f->value[0] != '0' && f->flags[f->flag_count] == '#')
		ft_handle_hex(f);
	else if (f->flags[f->flag_count] == '.')
		ft_handle_dot(pad, rhs_pad, pad_dir, f);
	else if (f->flags[f->flag_count] == '-')
		*pad_dir = 0;
}

int	ft_printf(const char *str, ...)
{
	int			len;
	int			idx;
	va_list		ptr;
	t_format	*format;

	len = 0;
	idx = -1;
	va_start(ptr, str);
	while (str && str[++idx])
	{
		if (str[idx] == '%')
		{
			format = ft_parse_format(&str[++idx], &ptr);
			if (format)
			{
				len += ft_handle_flags(format);
				idx += format->offset;
				free(format);
			}
		}
		else
			len += write(1, &str[idx], 1);
	}
	va_end(ptr);
	return (len);
}
