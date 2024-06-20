#include <push_swap.h>

static int	ft_check_duplicate(t_stack *s, int node_ctt)
{
	t_stack_node	*head;

	head = s->head;
	while (head)
	{
		if (head->content == node_ctt)
			return (1);
		head = head->next;
	}
	return (0);
}

static void	ft_stack_rank(t_stack *stack)
{
	t_stack_node	*head;
	int				*tab;
	int				rank;
	int				i;
	int				j;

	head = stack->head;
	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		exit (EXIT_FAILURE);
	j = 0;
	while (head)
	{
		rank = 0;
		i = 0;
		while (i < stack->size)
			if (head->content > ft_stack_get_value(stack, i++))
				rank++;
		tab[j++] = rank;
		head = head->next;
	}
	j = 0;
	head = stack->head;
	while (j < stack->size)
	{
		head->content = tab[j++];
		head = head->next;
	}
	free(tab);
}

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static int	ft_check_args_multiple(t_stack *stack, char **args)
{
	long	nbr;

	if (!args)
		return (0);
	while (*args)
	{
		nbr = ft_atoi(*args);
		if ((!ft_isdigit(**args) && !ft_issign(**args)) ||\
				nbr > INT_MAX ||\
				nbr < INT_MIN ||\
				ft_check_duplicate(stack, nbr))
		{
			ft_stack_destroy(stack);
			return (0);
		}
		ft_stack_push_back(stack, ft_stack_init_node(nbr, -1));
		args++;
	}
	ft_stack_rank(stack);
	return (1);
}

int	ft_check_args(t_stack *stack, char *av[], int args_size)
{
	long	nbr;

	if (args_size > 1)
		return (ft_check_args_multiple(stack, &av[1]));
	if (!av[1] || !ft_strlen(av[1]))
		return (0);
	while (*av[1])
	{
		while (ft_isspace(*av[1]))
			av[1]++;
		nbr = ft_atoi(av[1]);
		if (ft_issign(*av[1]))
			*av[1]++;
		if ((!ft_isspace(*av[1]) && !ft_isdigit(*av[1])) ||\
				nbr > INT_MAX || nbr < INT_MIN ||\
				ft_check_duplicate(stack, nbr))
		{
			ft_stack_destroy(stack);
			return (0);
		}
		ft_stack_push_back(stack, ft_stack_init_node(nbr, -1));
		while (ft_isdigit(*av[1]))
			av[1]++;
	}
	ft_stack_rank(stack);
	return (1);
}
