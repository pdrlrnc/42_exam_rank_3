/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:38:55 by pedde-so          #+#    #+#             */
/*   Updated: 2025/11/16 11:38:56 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/** prototypes **/
void	solve(int *pos, int col, int n);
int	valid(int *pos, int col, int row);
void	print_nb(int nb);


int	main(int argc, char**argv)
{
	int	n;
	int	*pos;

	if (argc != 2 || *(argv[1]) == '-')
		return (1);
	n = atoi(argv[1]);
	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (-1);
	solve(pos, 0, n);
	write(STDOUT_FILENO, "\n", 1);
	free(pos);
}

void	solve(int *pos, int col, int n)
{
	int	i;
	int	row;

	//base case, i have reached the end of the board, should print the 
	//solution.
	if (n == col)
	{
		i = 0;
		while (i < n)
		{
			if (i > 0)
				write(STDOUT_FILENO, " ", 1);
			print_nb(pos[i]);
			i++;
		}
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (valid(pos, col, row))
		{
			pos[col] = row;
			solve(pos, col + 1, n);
		}
		row++;
	}
}

int	valid(int *pos, int col, int row)
{
	int	aux_col;
	int	aux_row;

	aux_col = 0;
	while (aux_col < col)
	{
		aux_row = pos[aux_col];
		if (aux_row == row
      			|| aux_row - aux_col == row - col
      			|| aux_row + aux_col == row + col)
			return (0);
		aux_col++;
	}
	return (1);
}

void	print_nb(int nb)
{
	char	c;

	if (nb == 0)
	{
		write(STDOUT_FILENO, "0", 1);
		return ;
	}
	else
	{
		if (nb >= 10)
			print_nb(nb / 10);
		c = (nb % 10) + '0';
		write(STDOUT_FILENO, &c, 1);
	}
}
