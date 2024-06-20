#include <push_swap.h>

void	ft_stack_push_back(t_stack *stack, t_stack_node *node)
{
	t_stack_node	*last_node;

	if (node)
	{
		if (stack->head == NULL)
			stack->head = node;
		else
		{
			last_node = ft_stack_get_node(stack, stack->size - 1);
			if (last_node)
				last_node->next = node;
		}
		stack->size += 1;
		ft_stack_update_pos(stack);
	}
}

void	ft_stack_push(t_stack *stack, t_stack_node *node)
{
	if (node)
	{
		if (stack->head == NULL)
			stack->head = node;
		else
		{
			node->next = stack->head;
			stack->head = node;
		}
		stack->size += 1;
		ft_stack_update_pos(stack);
	}
}

t_stack_node	*ft_stack_pop_back(t_stack *stack)
{
	t_stack_node	*last_node;
	t_stack_node	*new_last_node;

	last_node = ft_stack_get_node(stack, stack->size - 1);
	if (last_node)
	{
		new_last_node = ft_stack_get_node(stack, stack->size - 2);
		if (new_last_node)
			new_last_node->next = NULL;
		else
			stack->head = NULL;
		stack->size -= 1;
		last_node->next = NULL;
		ft_stack_update_pos(stack);
	}
	return (last_node);
}

t_stack_node	*ft_stack_pop(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->head;
	if (node)
	{
		stack->head = stack->head->next;
		stack->size -= 1;
		node->next = NULL;
		ft_stack_update_pos(stack);
	}
	return (node);
}

void	ft_stack_destroy(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*next;

	head = stack->head;
	next = NULL;
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
