#include <push_swap.h>

void	ft_chunk_move_from_top_a(t_psw *psw, e_stk_loc to)
{
	if (to == BOTTOM_A)
		ft_ra(psw);
	else if (to == TOP_B)
	{
		ft_pb(psw);
	}
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
		ft_rb(psw);
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
	else if (from == TOP_B)
		ft_chunk_move_from_top_b(psw, to);
}
