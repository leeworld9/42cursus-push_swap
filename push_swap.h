
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct		s_node
{
    int				data;
    struct s_node	*next;
    int             distance;
}					t_node;
 
typedef struct	s_stack
{
    struct s_node	*top;
}				t_stack;

void	init_stack(t_stack *stack);
int		isEmpty(t_stack *stack);
t_node	*push(t_stack *stack, int data);
int		pop(t_stack *stack);

void	ft_swap(t_stack *stack);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);

void	ft_push(t_stack *stack1, t_stack *stack2);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	ft_rotate(t_stack *stack);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);

void	ft_reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_ab(t_stack *a, t_stack *b);

#endif