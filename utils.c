#include <push_swap.h>

static t_stack_node	*ft_pick_smallest(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*sm;

	if (!stack->size)
		return (NULL);
	sm = stack->head;
	head = stack->head->next;
	while (head)
	{
		if (head->content < sm->content)
			sm = head;
		head = head->next;
	}
	return (sm);
}

t_stack_node	*ft_pick_highest(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*hi;

	if (!stack->size)
		return (NULL);
	hi = stack->head;
	head = stack->head->next;
	while (head)
	{
		if (head->content > hi->content)
			hi = head;
		head = head->next;
	}
	return (hi);
}

int	ft_stack_is_sorted(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*sm;
	int				prev;
	int				i;

	sm = ft_pick_smallest(stack);
	prev = sm->content;
	i = (sm->pos + 1) % stack->size;
	while (i != sm->pos)
	{
		node = ft_stack_get_node(stack, i);
		if (node->content < prev)
			return (0);
		prev = node->content;
		i = (i + 1) % stack->size;
	}
	return (1);
}
