/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 13:36:54 by dmonfrin      #+#    #+#                 */
/*   Updated: 2021/12/16 14:20:34 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	fd_buffer[BUFFER_SIZE + 1];
	char		*str_line;

	if (!*fd_buffer)
	{
		if (read(fd, fd_buffer, BUFFER_SIZE) < 1)
			return (NULL);
	}
	if (ft_strchr(fd_buffer, 10))
		return (is_end(fd_buffer));
	str_line = ft_strdup(fd_buffer);
	while (1)
	{
		set_zero(fd_buffer);
		if (read (fd, fd_buffer, BUFFER_SIZE) < BUFFER_SIZE
			&& !ft_strchr(fd_buffer, 10))
			return (ft_strjoin(str_line, fd_buffer, 0));
		if (ft_strchr(fd_buffer, 10))
			return (ft_strjoin(str_line, is_end(fd_buffer), 1));
		str_line = ft_strjoin(str_line, fd_buffer, 0);
	}
	return (str_line);
}

char	*is_end(char *str)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 10)
			break ;
		i++;
	}
	string = malloc(i * sizeof(char) + 2);
	if (string == NULL)
		return (NULL);
	while (j < i + 1)
	{
		string[j] = str[j];
		j++;
	}
	string[j] = '\0';
	ft_strlcpy(str, &str[i + 1], BUFFER_SIZE);
	return (string);
}

void	set_zero(char *b)
{
	while (*b)
	{
		*b = 0;
		b++;
	}
}
