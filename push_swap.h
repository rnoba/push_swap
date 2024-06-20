#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <libft.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					content;
	int					pos;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack {
	t_stack_node	*head;
	int				size;
}	t_stack;

typedef struct s_psw {
	t_stack	stk_a;
	t_stack	stk_b;
	t_list	*mv_lst;
}	t_psw;

typedef enum	e_stk_loc {
	BOTTOM_A,
	TOP_A,
	BOTTOM_B,
	TOP_B,
} e_stk_loc;

typedef struct s_chunk {
	int			size;
	e_stk_loc	loc;
}	t_chunk;

void	ft_stack_push_back(t_stack *stack, t_stack_node *node);
void	ft_stack_push(t_stack *stack, t_stack_node *node);
void	ft_stack_destroy(t_stack *stack);

t_stack_node	*ft_stack_get_node(t_stack *stack, int pos);
t_stack_node	*ft_stack_init_node(int content, int pos);
t_stack_node	*ft_stack_pop_back(t_stack *stack);
t_stack_node	*ft_pick_highest(t_stack *stack);
t_stack_node	*ft_stack_pop(t_stack *stack);

void	ft_stack_append(t_stack *FROM, t_stack *TO);
void	ft_stack_print(t_stack *stack, t_stack *s2);
void	ft_stack_rotate_reverse(t_stack *stack);
void	ft_stack_update_pos(t_stack *stack);
void	ft_stack_rotate(t_stack *stack);
void	ft_stack_swap(t_stack *stack);

void	ft_ra(t_psw	*psw);
void	ft_rb(t_psw	*psw);
void	ft_rra(t_psw *psw);
void	ft_rrb(t_psw *psw);
void	ft_rrr(t_psw *psw);
void	ft_rr(t_psw	*psw);
void	ft_sa(t_psw	*psw);
void	ft_sb(t_psw	*psw);
void	ft_ss(t_psw *psw);
void	ft_pa(t_psw *psw);
void	ft_pb(t_psw *psw);

int	ft_check_args(t_stack *stack, char *av[], int args_size);
int	ft_stack_get_value(t_stack *stack, int pos);
int	ft_stack_is_sorted(t_stack *stack);

void	ft_psw_solve(t_psw *psw);
#endif
