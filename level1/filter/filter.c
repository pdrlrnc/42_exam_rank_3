/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:31:32 by pedde-so          #+#    #+#             */
/*   Updated: 2025/11/16 12:31:33 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/** prototypes */
int	ft_strlen(char *str);
int	ft_strcmp(char *buff, char *find, int len);

int	main(int argc, char **argv)
{
	char	*buff;
	char	c;
	int	i;
	int	j;
	int	len;

	if (argc != 2)
		return (1);
	buff = malloc(1000000000);
	if (!buff)
		return (1);
	i = 0;
	while (read(STDIN_FILENO, &c, 1) > 0)
		buff[i++] = c;
	buff[i] = '\0';
	len = ft_strlen(argv[1]);
	i = 0;
	while (*(buff + i))
	{
		if (ft_strcmp(buff + i, argv[1], len))
		{
			j = 0;
			while (j < (len - 1))
			{
				write(STDOUT_FILENO, "*", 1);
				j++;
			}
			i += j;
		}
		else
		{
			write(STDOUT_FILENO, buff + i, 1);
			i++;
		}
	}
	free(buff);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i++));
	return (i);
}

int	ft_strcmp(char *buff, char *find, int len)
{
	int	i;

	if (ft_strlen(buff) < len)
		return (0);
	i = 0;
	while (*(find + i))
	{
		if (*(buff + i) != *(find + i))
			return (0);
		i++;
	}
	return (1);
}
