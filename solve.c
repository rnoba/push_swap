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

void	ft_init_partition(t_partition *p, e_stk_loc loc)
{
	if (loc == TOP_A)
	{
		p->min.loc = BOTTOM_B;
		p->mid.loc = TOP_B;
		p->max.loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		p->min.loc = BOTTOM_B;
		p->mid.loc = TOP_B;
		p->max.loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		p->min.loc = BOTTOM_B;
		p->mid.loc = BOTTOM_A;
		p->max.loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		p->min.loc = TOP_B;
		p->mid.loc = BOTTOM_A;
		p->max.loc = TOP_A;
	}
}

void	ft_chunk_partition(t_psw *psw, t_chunk *chunk, t_partition *partition)
{
	int	m_pivot;
	int	h_pivot;
	int	curr;
	int	max;

	ft_init_partition(partition, chunk->loc);
	partition->mid.size = 0;
	partition->min.size = 0;
	partition->max.size = 0;
	h_pivot = chunk->size / 3;
	m_pivot = h_pivot * 2;
	max = ft_chunk_max_value(psw, chunk);
	while (chunk->size--)
	{
		curr = ft_chunk_get_value(psw, chunk, 0);
		if (curr > max - h_pivot)
		{
			ft_chunk_move_value(psw, chunk->loc, partition->max.loc);
			partition->max.size += 1;
		}
		else if (curr > max - m_pivot)
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

	if (chunk->loc == BOTTOM_A && psw->stk_a.size == chunk->size)
		chunk->loc = TOP_A;
	if (chunk->loc == BOTTOM_B && psw->stk_b.size == chunk->size)
		chunk->loc = TOP_B;
	if (chunk->size <= 3)
	{
		if (chunk->size == 3)
		{
			ft_chunk_sort_three(psw, chunk);
		}
		else if (chunk->size == 2)
		{
			ft_chunk_sort_two(psw, chunk);
		}
		else
		{
			ft_chunk_sort_single(psw, chunk);
		}
	}
	else
	{
		ft_chunk_partition(psw, chunk, &partition);
		ft_psw_solve_rec(psw, &partition.max);
		ft_psw_solve_rec(psw, &partition.mid);
		ft_psw_solve_rec(psw, &partition.min);
	}
}

void	ft_test(t_psw *psw, t_chunk *chunk)
{
	ft_chunk_sort_three(psw, chunk);
}

void	ft_psw_solve(t_psw *psw)
{
	t_chunk	chunk;

	chunk.size = psw->stk_a.size;
	chunk.loc = TOP_A;
	if (psw->stk_a.size <= 5)
	{
		if (psw->stk_a.size == 3)
			ft_sort_three(psw);
	}
	else
	{
		ft_psw_solve_rec(psw, &chunk);
	}
}
