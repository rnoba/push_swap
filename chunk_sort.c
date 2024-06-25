#include <push_swap.h>

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
	if (ft_chunk_get_value(psw, chunk, 0) == ft_chunk_max_value(psw, chunk))
	{
		if (chunk->loc == TOP_B || chunk->loc == BOTTOM_B || chunk->loc == BOTTOM_A)
		{
			ft_chunk_move_value(psw, chunk->loc, TOP_A);
		}
		chunk->size -= 1;
	}
}

void	ft_chunk_sort_three(t_psw *psw, t_chunk *chunk)
{
	int	max;

	max = ft_chunk_max_value(psw, chunk);
	if (chunk->loc == TOP_A)
	{
		if (ft_chunk_get_value(psw, chunk, 0) == max)
		{
			ft_sa(psw);
			ft_ra(psw);
			ft_sa(psw);
			ft_rra(psw);
		}
		else if (ft_chunk_get_value(psw, chunk, 1) == max)
		{
			ft_ra(psw);
			ft_sa(psw);
			ft_rra(psw);
		}
		chunk->loc = TOP_A;
		chunk->size -= 1;
		ft_chunk_sort_two(psw, chunk);
	}
	else if (chunk->loc == TOP_B)
	{
		ft_pa(psw);
		if (ft_chunk_get_value(psw, chunk, 0) == max)
		{
			ft_pa(psw);
			ft_sa(psw);
		}
		else if (ft_chunk_get_value(psw, chunk, 1) == max)
		{
			ft_sb(psw);
			ft_pa(psw);
			ft_sa(psw);
		}
		else
			ft_pa(psw);
		ft_pa(psw);
		chunk->loc = TOP_A;
		chunk->size -= 1;
		ft_chunk_sort_two(psw, chunk);
	}
	else if (chunk->loc == BOTTOM_A)
	{
		ft_rra(psw);
		ft_rra(psw);
		chunk->loc = TOP_A;
		if (ft_chunk_get_value(psw, chunk, 0) == max)
		{
			ft_sa(psw);
			ft_rra(psw);
		}
		else if (ft_chunk_get_value(psw, chunk, 1) == max)
		{
			ft_rra(psw);
		}
		else
		{
			ft_pb(psw);
			ft_rra(psw);
			ft_sa(psw);
			ft_pa(psw);
		}
		chunk->size -= 1;
		ft_chunk_sort_two(psw, chunk);
	}
	else
	{
		ft_rrb(psw);
		ft_rrb(psw);
		chunk->loc = TOP_B;
		if (ft_chunk_get_value(psw, chunk, 0) == max)
		{
			ft_pa(psw);
			ft_rrb(psw);
		}
		else if (ft_chunk_get_value(psw, chunk, 1) == max)
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
		chunk->size -= 1;
		ft_chunk_sort_two(psw, chunk);
	}
}
