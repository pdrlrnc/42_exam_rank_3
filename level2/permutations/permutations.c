/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:53:06 by pedde-so          #+#    #+#             */
/*   Updated: 2025/11/26 10:53:11 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*prototypes*/
void	sort(char *s);
void	swap(char *s1, char *s2);
void	solve(char *s, int start, int n);


int	main(int argc, char **argv)
{
	char	*s;
	int	n;

	if (argc != 2)
		return (1);
	s = strdup(argv[1]);
	if (!s)
		return (1);
	n = strlen(argv[1]);
	sort(s);
	solve(s, 0, n);
	free(s);
	return (0);
}

void	solve(char *s, int start, int n)
{
	int	i;

	if (start == n)
	{
		write(STDOUT_FILENO, s, n);
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	i = start;
	while (i < n)
	{
		swap(s + start, s + i);
		solve(s, start + 1, n);
		swap(s + start, s + i);
		i++;
	}
}

void	swap(char *s1, char *s2)
{
	char	aux;

	aux = *s1;
	*s1 = *s2;
	*s2 = aux;
}

void	sort(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (*(s + i))
	{
		j = i + 1;
		while (*(s + j))
		{
			if (*(s + i) > *(s + j))
				swap(s + i, s + j);
			j++;
		}
		i++;
	}
}
