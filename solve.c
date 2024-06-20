#include <push_swap.h>

void	ft_sort_three(t_psw *psw)
{
	int	n[3];

	if (psw->stk_a.size == 3)
	{
		n[0] = ft_stack_get_value(&psw->stk_a, 0);
		n[1] = ft_stack_get_value(&psw->stk_a, 1);
		n[2] = ft_stack_get_value(&psw->stk_a, 2);
		if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
		{
			ft_sa(psw);
			ft_ra(psw);
		}
		if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
			ft_sa(psw);
		if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
			ft_rra(psw);
		if (n[0] > n[1] && n[1] > n[2])
		{
			ft_sa(psw);
			ft_rra(psw);
		}
		if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
			ft_ra(psw);
	}
}

void	ft_chunk_move_from_top_a(t_psw *psw, e_stk_loc to)
{
	if (to == BOTTOM_A)
		ft_ra(psw);
	else if (to == TOP_B)
		ft_pb(psw);
	else if (to == BOTTOM_B)
	{
		ft_pb(psw);
		ft_rb(psw);
	}
}

void	ft_chunk_move_from_bottom_a(t_psw *psw, e_stk_loc to)
{
	if (to == TOP_A)
		ft_rra(psw);
	else if (to == TOP_B)
	{
		ft_rra(psw);
		ft_pb(psw);
	}
	else if (to == BOTTOM_B)
	{
		ft_rra(psw);
		ft_pb(psw);
		ft_rb(psw);
	}
}

void	ft_chunk_move_from_top_b(t_psw *psw, e_stk_loc to)
{
	if (to == TOP_A)
		ft_pa(psw);
	else if (to == BOTTOM_B)
	{
		ft_ra(psw);
	}
	else if (to == BOTTOM_A)
	{
		ft_pa(psw);
		ft_ra(psw);
	}
}

void	ft_chunk_move_from_bottom_b(t_psw *psw, e_stk_loc to)
{
	if (to == TOP_B)
		ft_rrb(psw);
	else if (to == TOP_A)
	{
		ft_rrb(psw);
		ft_pa(psw);
	}
	else if (to == BOTTOM_A)
	{
		ft_rrb(psw);
		ft_pa(psw);
		ft_ra(psw);
	}
}

void	ft_chunk_move_value(t_psw *psw, e_stk_loc from, e_stk_loc to)
{
	if (from == TOP_A)
		ft_chunk_move_from_top_a(psw, to);
	else if (from == BOTTOM_A)
		ft_chunk_move_from_bottom_a(psw, to);
	else if (from == BOTTOM_B)
		ft_chunk_move_from_bottom_b(psw, to);
	else
		ft_chunk_move_from_top_b(psw, to);
}

void	ft_chunk_sort_two(t_psw *psw, t_chunk *chunk)
{
	if (chunk->loc == TOP_B || chunk->loc == BOTTOM_B || chunk->loc == BOTTOM_A)
	{
		ft_chunk_move_value(psw, chunk->loc, TOP_A);
		ft_chunk_move_value(psw, chunk->loc, TOP_A);
	}
	if (ft_stack_get_value(&psw->stk_a, 0) > ft_stack_get_value(&psw->stk_a, 1))
		ft_sa(psw);
	chunk->size -= 2;
}

void	ft_chunk_sort_single(t_psw *psw, t_chunk *chunk)
{
	if (chunk->loc == TOP_B || chunk->loc == BOTTOM_B || chunk->loc == BOTTOM_A)
	{
		ft_chunk_move_value(psw, chunk->loc, TOP_A);
	}
	chunk->size -= 1;
}

int	ft_chunk_get_value(t_stack *stack, t_chunk *chunk, int pos)
{
	t_stack_node	*node;
	int	p = pos + 1;
	int	size;

	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		size = chunk->size - 1;
	else
		size = 0;
	node = ft_stack_get_node(stack, size);
	while (--p)
	{
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		{
			node = ft_stack_get_node(stack, size++);
		}
		else
		{
			node = ft_stack_get_node(stack, size--);
		}
	}
	return (node->content);
}

int	ft_chunk_node_pos(int pos, t_chunk *chunk, int stk_size)
{
	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
	{
		return ((stk_size) - chunk->size + pos);
	}
	return (pos);
}

int	ft_chunk_max_value(t_stack *stack, t_chunk *chunk)
{
	t_stack_node	*node;
	int	max;
	int	size;

	max = ft_chunk_get_value(stack, chunk, 0);
	size = chunk->size + 1;
	while (--size)
	{
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		{
			node = ft_stack_get_node(stack, chunk->size - size);
		}
		else
		{
			node = ft_stack_get_node(stack, (stack->size - 1) - (chunk->size - size));
		}
		if (node && node->content > max)
			max = node->content;
	}
	return (max);
}

t_stack	*ft_chunk_loc_to_stack(t_psw *psw, e_stk_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
	{
		return (&psw->stk_a);
	}
	return (&psw->stk_b);
}

void	ft_chunk_sort_three(t_psw *psw, t_chunk *chunk)
{
	t_stack	*stack;
	int		max;

	stack = ft_chunk_loc_to_stack(psw, chunk->loc);
	max = ft_chunk_max_value(stack, chunk);
	if (chunk->loc == TOP_A)
	{
		if (ft_chunk_get_value(stack, chunk, 0) == max)
		{
			ft_sa(psw);
			ft_ra(psw);
			ft_sa(psw);
			ft_rra(psw);
		} 
		else if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_ra(psw);
			ft_sa(psw);
			ft_rra(psw);
		}
	}
	else if (chunk->loc == TOP_B)
	{
		ft_pa(psw);
		if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_pa(psw);
			ft_sa(psw);
		}
		else if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_sb(psw);
			ft_pa(psw);
			ft_sa(psw);
		}
		ft_pa(psw);
	}
	else if (chunk->loc == BOTTOM_B)
	{
		ft_rrb(psw);
		ft_rrb(psw);
		if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_pa(psw);
			ft_rrb(psw);
		}
		else if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_sb(psw);
			ft_pa(psw);
			ft_rrb(psw);
		}
		else
		{
			ft_rrb(psw);
			ft_pa(psw);
		}
	}
	else
	{
		ft_rra(psw);
		ft_rra(psw);
		if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_sa(psw);
			ft_rra(psw);
		}
		else if (ft_chunk_get_value(stack, chunk, 0))
		{
			ft_rra(psw);
			ft_sa(psw);
		}
		else
		{
			ft_pb(psw);
			ft_rra(psw);
			ft_sa(psw);
			ft_pa(psw);
		}
	}
	chunk->size -= 1;
	chunk->loc = TOP_A;
	ft_chunk_sort_two(psw, chunk);
}

typedef struct s_partition {
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_partition;

void	ft_init_partition(e_stk_loc loc, t_partition *partition)
{
	if (loc == TOP_A)
	{
		partition->min.loc = BOTTOM_A;
		partition->mid.loc = TOP_B;
		partition->max.loc = BOTTOM_B;
	}
	else if (loc = TOP_B)
	{
		partition->min.loc = BOTTOM_B;
		partition->mid.loc = TOP_A;
		partition->max.loc = BOTTOM_A;
	}
	else if (loc = BOTTOM_B)
	{
		partition->min.loc = TOP_B;
		partition->mid.loc = TOP_A;
		partition->max.loc = BOTTOM_A;
	}
	else if (loc = BOTTOM_A)
	{
		partition->min.loc = TOP_A;
		partition->mid.loc = TOP_B;
		partition->max.loc = BOTTOM_B;
	}
}

void	ft_chunk_partition(t_psw *psw, t_chunk *chunk, t_partition *partition)
{
	t_stack *stack = ft_chunk_loc_to_stack(psw, chunk->loc);
	partition->mid.size = 0;
	partition->min.size = 0;
	partition->max.size = 0;
	ft_init_partition(chunk->loc, partition);
	int	h_pivot = stack->size/3;
	int	m_pivot = 2 * (stack->size) / 3;
	int max = ft_chunk_max_value(stack, chunk);
	while (chunk->size--)
	{
		int	head = ft_chunk_get_value(stack, chunk, 0);
		if (head > max - h_pivot)
		{
			ft_chunk_move_value(psw, chunk->loc, partition->max.loc);
			partition->max.size += 1;
		}
		else if (head > max - m_pivot)
		{
			ft_chunk_move_value(psw, chunk->loc, partition->mid.loc);
			partition->mid.size += 1;
		}
		else
		{
			ft_chunk_move_value(psw, chunk->loc, partition->min.loc);
			partition->min.size += 1;
		}
	}
}

void	ft_psw_solve_rec(t_psw *psw, t_chunk *chunk)
{
	t_partition	partition;

	if (chunk->loc == BOTTOM_B && psw->stk_b.size == chunk->size)
		chunk->loc = TOP_B;
	if (chunk->loc == BOTTOM_A && psw->stk_a.size == chunk->size)
		chunk->loc = TOP_A;
	if (chunk->size <= 3)
	{
		if (chunk->size == 2)
		{
			ft_chunk_sort_two(psw, chunk);
		}
		else if (chunk->size == 1)
		{
			ft_chunk_sort_single(psw, chunk);
		}
		else
		{
			ft_chunk_sort_three(psw, chunk);
		}
		return ;
	}
	ft_chunk_partition(psw, chunk, &partition);
	ft_psw_solve_rec(psw, &partition.min);
	ft_psw_solve_rec(psw, &partition.mid);
	ft_psw_solve_rec(psw, &partition.max);
}

void	ft_psw_solve(t_psw *psw)
{
	t_chunk	chunk;

	chunk.size = psw->stk_a.size;
	chunk.loc = TOP_A;
	ft_psw_solve_rec(psw, &chunk);
}
