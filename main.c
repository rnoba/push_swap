#include <push_swap.h>

void	ft_moves_optimize(t_list *mv_list, int size)
{
	t_list	*head;
	t_list	*next;

	(void)size;
	head = mv_list;
	next = NULL; 
	while (head && head->next)
	{
		next = head->next;
		int curr_is_rb = ft_strncmp((char *)head->content, "rb", 2) == 0;
		int next_is_rb = ft_strncmp((char *)next->content, "rb", 2) == 0;

		int curr_is_ra = ft_strncmp((char *)head->content, "ra", 2) == 0;
		int next_is_ra = ft_strncmp((char *)next->content, "ra", 2) == 0;

		int curr_is_rrb = ft_strncmp((char *)head->content, "rrb", 3) == 0;
		int next_is_rrb = ft_strncmp((char *)next->content, "rrb", 3) == 0;

		int curr_is_rra = ft_strncmp((char *)head->content, "rra", 3) == 0;
		int next_is_rra = ft_strncmp((char *)next->content, "rra", 3) == 0;

		if ((curr_is_rb && next_is_ra) || (curr_is_ra && next_is_rb))
		{
			printf("rr\n");
		}
		else if ((curr_is_rrb && next_is_rra) || (curr_is_rra && next_is_rrb))
		{
			printf("rrr\n");
		}
		else
		{
			printf("%s\n", (char *)head->content);
			printf("%s\n", (char *)next->content);
		}
		head = next->next;
	}
	if (head)
		printf("%s\n", (char *)head->content);
}

int main(int ac, char *av[])
{
	t_psw	psw;

	ft_assert(ac >= 2, "Error");
	ft_bzero(&psw, sizeof(t_psw));
	ft_assert(ft_check_args(&psw.stk_a, av, ac - 1), "Error");
	ft_psw_solve(&psw);
	ft_moves_optimize(psw.mv_lst, psw.stk_a.size);
//	t_list *head = psw.mv_lst;
//	while (head)
//	{
//		if (head->content)
//		{
//			ft_printf("%s\n", (char *)head->content);
//		}
//		head = head->next;
//	}
	//ft_stack_print(&psw.stk_a, &psw.stk_b);
	ft_stack_destroy(&psw.stk_a);
	ft_lstclear(&psw.mv_lst, free);
}
