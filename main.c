#include <push_swap.h>

int main(int ac, char *av[])
{
	t_psw	psw;

	ft_assert(ac >= 2, "Error");
	ft_bzero(&psw, sizeof(t_psw));
	ft_assert(ft_check_args(&psw.stk_a, av, ac - 1), "Error");
	ft_stack_print(&psw.stk_a, &psw.stk_b);
	ft_psw_solve(&psw);
	t_list *head = psw.mv_lst;
	while (head)
	{
		if (head->content)
		{
			ft_printf("%s\n", (char *)head->content);
		}
		head = head->next;
	}
	ft_stack_print(&psw.stk_a, &psw.stk_b);
	ft_stack_destroy(&psw.stk_a);
	ft_lstclear(&psw.mv_lst, free);
}
