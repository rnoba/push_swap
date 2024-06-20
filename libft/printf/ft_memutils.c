/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:47:25 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/10 23:53:41 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_recycle(char *str, const char *new)
{
	free(str);
	return (ft_strdup(new));
}

char	*ft_recycle_stack(char *stack, char *ret)
{
	free(stack);
	return (ret);
}

char	*ft_sfromc(char c)
{
	char	*str;

	str = ft_strdup(" ");
	str[0] = c;
	return (str);
}

char	*ft_string_initial_value(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*ft_pointer_initial_value(void *v)
{
	if (!(long)v)
		return (ft_strdup("(nil)"));
	return (ft_add_prefix(ft_itoa_base((long)v, HEX_BASE), HEX_PREFIX));
}
