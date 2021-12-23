/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:56:59 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/21 20:21:38 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_check(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (!ft_strcmp(args[i], args[j]))
			{
				write(1, "Error\n", ft_strlen("Error\n"));
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	ready_steady_go(int ac, char **av, char ***args)
{
	int		num;

	if (ac == 1 || ac == 0)
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		exit(0);
	}
	*args = argcreator(ac, av, &num);
	if (num == 1)
	{
		write(1, "\n", ft_strlen("\n"));
		exit(0);
	}
	ready_check(*args);
	return (num);
}

void	print_rezult(t_Main *main)
{
	t_list	*tmp;

	tmp = main->comma;
	while (tmp)
	{
		write(1, tmp->content, ft_strlen(tmp->content));
		write(1, "\n", ft_strlen("\n"));
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_Main	*main;
	char	**args;
	int		num;

	num = ready_steady_go(ac, av, &args);
	main = push_swap_init(num, args);
	make_things_right(main->stk_a);
	if (check_sort(main))
	{
		push_swap_free(main);
		return (0);
	}
	else if (num <= 3)
		sort_three(main, num);
	else if (num <= 5)
		sort_five(main);
	else
		sort_many(main);
	print_rezult(main);
	push_swap_free(main);
	return (0);
}
