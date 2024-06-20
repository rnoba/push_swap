/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:34 by rnogueir          #+#    #+#             */
/*   Updated: 2023/12/14 18:19:55 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "unistd.h"
# include "stdarg.h"

enum	e_type
{
	HEX,
	U_HEX,
	DEC,
	U_DEC,
	PER,
	POINTER,
	STRING,
	CHAR,
	NONE
};

# define FLAGS           ". 0+-#"
# define HEX_BASE        "0123456789abcdef" 
# define U_HEX_BASE      "0123456789ABCDEF" 
# define HEX_PREFIX      "0x"
# define U_HEX_PREFIX    "0X"

typedef struct f_format {
	int			lhs;
	int			flag_count;
	int			rhs;
	enum e_type	type;
	int			len;
	int			offset;
	char		pad_char;
	char		flags[6];
	char		*value;
}	t_format;

void		ft_fix_flags(t_format *f);
void		ft_collect_rhs(const char *str, t_format *f, int *idx, int *flag);
void		ft_handle_hex(t_format *f);
void		ft_collect_lhs(const char *str, t_format *f, int *idx, int *flag);
void		ft_handle_zero(t_format *f, int *rhs_pad, int *pad);
void		ft_update(t_format *f, int *pad, int *rhs_pad);
void		ft_loop(t_format *f, int *pad_dir, int *rhs_pad, int *pad);

int			ft_get_value_len(enum e_type t, char *str);
int			ft_pad(char c, int n);
int			ft_handle_flags(t_format *f);
int			ft_printf(const char *str, ...);
int			ft_del_mem(void *m, int elm, int range, int max);
int			ft_print(t_format *f, int pl, int rpad, int dir);

char		*ft_add_prefix(char *str, char *prefix);
char		*ft_itoa_base(long nbr, const char *base);
char		*ft_sfromc(char c);
char		*ft_string_initial_value(char *str);
char		*ft_pointer_initial_value(void *v);
char		*ft_get_initial_value(enum e_type t, va_list *ptr);
char		*ft_recycle_stack(char *stack, char *ret);
char		*ft_recycle(char *str, const char *n);

enum e_type	ft_format_type(char c);

t_format	*ft_init_format(void);
t_format	*ft_init_format(void);
t_format	*ft_parse_format(const char *str, va_list *ptr);
#endif
