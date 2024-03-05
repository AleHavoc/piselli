/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:37:46 by acaracci          #+#    #+#             */
/*   Updated: 2024/03/05 15:50:36 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}
char	*ft_strdup(const char	*src)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if(!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (0);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if ((size_t) start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j++] = s[i];
		}
		i++;
	}
	str[j] = 0;
	return (str);
}