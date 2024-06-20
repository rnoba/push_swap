/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:03:39 by rnogueir          #+#    #+#             */
/*   Updated: 2023/12/14 13:14:22 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_init_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	*format = (t_format){
		.offset = 0,
		.flag_count = 0,
		.lhs = -1,
		.rhs = -1,
		.type = NONE,
		.pad_char = ' '
	};
	return (format);
}

char	*ft_get_initial_value(enum e_type t, va_list *ptr)
{
	if (t == STRING)
		return (ft_string_initial_value(va_arg(*ptr, char *)));
	else if (t == CHAR)
		return (ft_sfromc(va_arg(*ptr, int)));
	else if (t == POINTER)
		return (ft_pointer_initial_value(va_arg(*ptr, void *)));
	else if (t == DEC)
		return (ft_itoa(va_arg(*ptr, int)));
	else if (t == U_DEC)
		return (ft_itoa_base(va_arg(*ptr, unsigned int), "0123456789"));
	else if (t == HEX)
		return (ft_itoa_base(va_arg(*ptr, unsigned int), HEX_BASE));
	else if (t == U_HEX)
		return (ft_itoa_base(va_arg(*ptr, unsigned int), U_HEX_BASE));
	else if (t == PER)
		return (ft_strdup("%"));
	return (NULL);
}

t_format	*ft_parse_format(const char *str, va_list *ptr)
{
	t_format	*f;
	int			idx;
	int			flag;

	idx = 0;
	flag = 0;
	f = ft_init_format();
	ft_collect_lhs(str, f, &idx, &flag);
	ft_collect_rhs(str, f, &idx, &flag);
	f->type = ft_format_type(str[idx]);
	if (f->type == NONE)
		f->value = ft_substr(str - 1, 0, 2);
	else
		f->value = ft_get_initial_value(f->type, ptr);
	f->len = ft_get_value_len(f->type, f->value);
	ft_fix_flags(f);
	f->offset = idx;
	return (f);
}

void	ft_handle_hex(t_format *f)
{
	if (f->type == HEX)
		f->value = ft_add_prefix(f->value, HEX_PREFIX);
	else
		f->value = ft_add_prefix(f->value, U_HEX_PREFIX);
}

void	ft_handle_zero(t_format *f, int *rhs_pad, int *pad)
{
	if (f->value[0] == '-')
		*rhs_pad = *pad - 1;
	else
		*rhs_pad = *pad;
	*pad = 0;
}
