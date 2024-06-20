/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:57:13 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/22 13:56:33 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_add_prefix(char *str, char *prefix)
{
	char	*ret;

	ret = ft_strjoin(prefix, str);
	free(str);
	return (ret);
}

int	ft_del_mem(void *m, int elm, int range, int max)
{
	char	*m_pointer;
	int		idx;

	m_pointer = (char *)m;
	idx = 0;
	while (idx < max && m_pointer[idx] != elm)
		idx++;
	if (idx + range > max)
		return (0);
	ft_memmove(m_pointer + idx, m_pointer + idx + range, max - idx);
	return (1);
}

char	*ft_itoa_base(long nbr, const char *base)
{
	char	*tab;
	long	nbr_l;
	size_t	len;
	size_t	blen;

	len = 0;
	if (nbr == 0)
		len = 1;
	nbr_l = nbr;
	blen = ft_strlen(base);
	while (nbr_l)
	{
		len++;
		nbr_l /= blen;
	}
	tab = malloc(sizeof(char) * (len + 1));
	ft_bzero(tab, len + 1);
	while (len--)
	{
		tab[len] = base[nbr % blen];
		nbr /= blen;
	}
	return (tab);
}

int	ft_get_value_len(enum e_type t, char *str)
{
	int	len;

	len = 0;
	if (t == CHAR && *str == 0)
		len++;
	return (len += ft_strlen(str));
}

int	ft_pad(char c, int n)
{
	int	len;

	len = 0;
	while (--n > 0)
		len += write(1, &c, 1);
	return (len);
}
