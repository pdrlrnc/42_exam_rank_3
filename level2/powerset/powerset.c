/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:09:31 by pedde-so          #+#    #+#             */
/*   Updated: 2025/11/25 13:09:39 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*prototypes*/
void	print(int *subset, int subsize);
void	solve(int *nums, int *subset, int size, int target, int subsize, int index);
int	calculate(int *subset, int subsize);


int	main(int argc, char **argv)
{
	int	size;
	int	*subset;
	int	*nums;
	int	target;
	int	i;

	size = argc - 2;
	subset = malloc(sizeof(int) * size);
	if (!subset)
		exit(1);
	nums = malloc(sizeof(int) * size);
	if (!nums)
	{
		free(subset);
		exit(1);
	}
	target = atoi(*(argv + 1));
	i = 0;
	while (i < size)
	{
		*(nums + i) = atoi(argv[i + 2]);
		i++;
	}
	solve(nums, subset, size, target, 0, 0);
	free(subset);
	free(nums);
	exit(0);
}

void	solve(int *nums, int *subset, int size, int target, int subsize, int index)
{
	if (index == size)
	{
		if (calculate(subset, subsize) == target)
			print(subset, subsize);
		return ;
	}
	*(subset + subsize) = *(nums + index);
	//take it
	solve(nums, subset, size, target, subsize + 1, index + 1);
	//leave it
	solve(nums, subset, size, target, subsize, index + 1);
}

int	calculate(int *subset, int subsize)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < subsize)
	{
		sum += *(subset + i);
		i++;
	}
	return (sum);
}

void	print(int *subset, int subsize)
{
	int	i;

	i = 0;
	while (i < subsize)
	{
		printf("%d", *(subset + i));
		if (i < subsize -1)
			printf(" ");
		i++;
	}
	printf("\n");
}
