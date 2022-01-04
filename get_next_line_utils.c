/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 13:38:05 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/13 13:38:33 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && i < src_size)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < dstsize)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (src_size);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2, int n)
{
	char	*nws;
	size_t	nwssize;
	size_t	i;
	size_t	dst_len;

	if (!*s2 || s1 == NULL)
		return (s1);
	nwssize = ft_strlen(s1) + ft_strlen(s2) + 1;
	nws = (char *)malloc(nwssize * sizeof(char));
	if (nws == NULL)
		return (NULL);
	ft_strlcpy(nws, s1, nwssize);
	i = 0;
	dst_len = ft_strlen(nws);
	while (dst_len + i < nwssize - 1)
	{
		nws[dst_len + i] = s2[i];
		i++;
	}
	free(s1);
	if (n)
		free(s2);
	else
		set_zero(s2);
	return (nws);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
