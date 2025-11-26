/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:13:40 by pedde-so          #+#    #+#             */
/*   Updated: 2025/11/26 12:13:40 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*prototypes*/
void	solve(char *s, int should_fix, int fixed, int pos);
int	invalid(char *s);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	solve(argv[1], invalid(argv[1]), 0, 0);
	return (0);
}

int	invalid(char *s)
{
	int	closed;
	int	opened;
	int	i;

	closed = 0;
	opened = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '(')
			opened++;
		else if (*(s + i) == ')')
		{
			if (opened > 0)
				opened--;
			else
				closed++;
		}
		i++;
	}
	return (closed + opened);
}

void	solve(char *s, int should_fix, int fixed, int pos)
{
	int	i;
	char	c;

	if (should_fix == fixed)
	{
		if (!invalid(s))
			puts(s);
		return ;
	}
	i = pos;
	while(*(s + i))
	{
		if (*(s + i) == '(' || *(s + i) == ')')
		{
			c = *(s + i);
			*(s + i) = ' ';
			solve(s, should_fix, fixed + 1, i + 1);
			*(s + i) = c;
		}
		i++;
	}
}
