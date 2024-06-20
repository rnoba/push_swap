#include <push_swap.h>

void	ft_ra(t_psw *psw)
{
	if (psw->stk_a.size >= 2)
	{
		ft_stack_rotate(&psw->stk_a);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("ra")));
	}
}

void	ft_rb(t_psw *psw)
{
	if (psw->stk_b.size >= 2)
	{
		ft_stack_rotate(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("rb")));
	}
}

void	ft_rra(t_psw *psw)
{
	if (psw->stk_a.size >= 2)
	{
		ft_stack_rotate_reverse(&psw->stk_a);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("rra")));
	}
}

void	ft_rrb(t_psw *psw)
{
	if (psw->stk_b.size >= 2)
	{
		ft_stack_rotate_reverse(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("rrb")));
	}
}

void	ft_rrr(t_psw *psw)
{
	if (psw->stk_a.size >= 2 && psw->stk_b.size >= 2)
	{
		ft_stack_rotate_reverse(&psw->stk_a);
		ft_stack_rotate_reverse(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("rrr")));
	}
}

void	ft_rr(t_psw *psw)
{
	if (psw->stk_a.size >= 2 && psw->stk_b.size >= 2)
	{
		ft_stack_rotate(&psw->stk_a);
		ft_stack_rotate(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("rr")));
	}
}

void	ft_sa(t_psw *psw)
{
	if (psw->stk_a.size >= 2)
	{
		ft_stack_swap(&psw->stk_a);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("sa")));
	}
}

void	ft_sb(t_psw *psw)
{
	if (psw->stk_b.size >= 2)
	{
		ft_stack_swap(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("sb")));
	}
}

void	ft_ss(t_psw *psw)
{
	if (psw->stk_a.size >= 2 && psw->stk_b.size >= 2)
	{
		ft_stack_swap(&psw->stk_a);
		ft_stack_swap(&psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("ss")));
	}
}

void	ft_pa(t_psw *psw)
{
	if (psw->stk_b.size > 0)
	{
		ft_stack_append(&psw->stk_b, &psw->stk_a);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("pa")));
	}
}

void	ft_pb(t_psw *psw)
{
	if (psw->stk_a.size > 0)
	{
		ft_stack_append(&psw->stk_a, &psw->stk_b);
		ft_lstadd_back(&psw->mv_lst, ft_lstnew(ft_strdup("pb")));
	}
}
