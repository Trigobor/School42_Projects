/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:07:03 by eosfryd           #+#    #+#             */
/*   Updated: 2021/08/22 17:21:19 by eosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_Item
{
	struct s_Item	*trueprev;
	struct s_Item	*prev;
	int				digit;
	int				order;
	int				index;
	int				shift;
	struct s_Item	*next;
	struct s_Item	*truenext;
}					t_Item;

typedef struct s_Tack
{
	t_Item			*head;
	t_Item			*truehead;
	int				lnght;
}					t_Tack;

typedef struct s_commands
{
	char		*sa;
	char		*sb;
	char		*ss;
	char		*pa;
	char		*pb;
	char		*ra;
	char		*rb;
	char		*rr;
	char		*rra;
	char		*rrb;
	char		*rrr;
}				t_commands;

typedef struct s_Main
{
	t_Tack			*stk_a;
	t_Tack			*stk_b;
	t_list			*comma;
	t_commands		*commands;
	int				next;
	int				flag;
	int				min;
	int				max;
	int				mid;
	char			**args;
	int				narg;
}					t_Main;

void	my_sasb(t_Main *main, char *comma, int i);
void	my_ss(t_Main *main);
void	my_papb(t_Main *main, char *comma);
void	my_papb_sequel(t_Tack *s, t_Tack *d);
void	my_rarb(t_Main *main, char *comma, int i);
void	my_rr(t_Main *main);
void	my_rrarrb(t_Main *main, char *comma, int i);
void	my_rrr(t_Main *main);
void	push_swap_free_stack(t_Tack *stack);
void	push_swap_free_comma(t_list *comma);
void	push_swap_free(t_Main *main);
void	push_swap_exit(t_Main *main, int code);
t_Item	*create_item(int i);
void	add_item(t_Item *itemnew, t_Tack *stack);
void	parce_args(t_Tack *stack, t_Main *main);
char	**argcreator(int ac, char **av, int *num);
void	free_commands(t_Main *main);
void	commands_init(t_Main *main);
t_Tack	*stack_init(t_Main *main);
t_Tack	*stack_a_init(t_Main *main);
t_Main	*push_swap_init(int argc, char **argv);

void	make_things_right(t_Tack *stack);
t_Item	*itemi(t_Item *lst, int index);
void	the_function_of_truth(t_Tack *stack, int a, int b, int p);

void	sort_three(t_Main *main, int i);
void	push_item_into_stack(t_Main *main, t_Tack *src, t_Tack *dst, int index);
void	push_item_into_stack_sequel(t_Main *main, char *cmd, int i);
void	sort_five(t_Main *main);
int		check_sort(t_Main *main);

int		find_median(t_Main *main, int first);
void	split_stack_a(t_Main *main, int first, t_Item *tmp, int i);
void	split_stack_b(t_Main *main, t_Item *tmp, int i);
void	finish_this(t_Main *main, t_Item *tmp, int i);
void	sort_many(t_Main *main);
#endif
