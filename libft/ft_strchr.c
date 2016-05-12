/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:34:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/01/09 10:49:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cpy_c;

	cpy_c = (char)c;
	if (s)
	{
		while (*s != cpy_c && *s != '\0')
			s++;
		if (*s == cpy_c)
			return ((char*)s);
	}
	return (NULL);
}
