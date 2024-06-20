/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:45:31 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/11 01:10:06 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_dot(t_format *f, int *pad_left)
{
	if (!f->rhs)
		f->value = ft_recycle(f->value, "");
	if (f->lhs)
		(*pad_left)++;
	f->len = ft_strlen(f->value);
}

static int	ft_handle_left_dir(t_format *f, int *pl, int *off, int *pr)
{
	int	len;

	len = 0;
	len += ft_pad(' ', *pl);
	if (*off)
		len += write(1, "-", 1);
	len += ft_pad('0', *pr + *off);
	len += write(1, f->value + *off, f->len - *off);
	return (len);
}

int	ft_print(t_format *f, int pl, int rpad, int dir)
{
	int	len;
	int	offset;

	len = 0;
	offset = 0;
	if (f->type != CHAR && f->value[0] == '%')
		return (write(1, f->value, f->len));
	else if ((ft_strchr(f->flags, '.') && f->value[0] == '0') \
			&& (!f->lhs || !f->rhs))
		ft_handle_dot(f, &pl);
	if (f->value[0] == '-')
		offset = 1;
	if (dir)
		len += ft_handle_left_dir(f, &pl, &offset, &rpad);
	else
	{
		if (offset)
			len += write(1, "-", 1);
		len += ft_pad('0', rpad + offset);
		len += write(1, f->value + offset, f->len - offset);
		len += ft_pad(' ', pl);
	}
	return (len);
}
