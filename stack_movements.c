#include <push_swap.h>

void	ft_stack_rotate(t_stack *stack)
{
	t_stack_node	*head;

	if (stack->size >= 2)
	{
		head = ft_stack_pop(stack);
		ft_stack_push_back(stack, head);
	}
}

void	ft_stack_rotate_reverse(t_stack *stack)
{
	t_stack_node	*last_node;

	if (stack->size >= 2)
	{
		last_node = ft_stack_pop_back(stack);
		ft_stack_push(stack, last_node);
	}
}

void	ft_stack_swap(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*new_head;

	if (stack->size >= 2)
	{
		head = ft_stack_pop(stack);
		new_head = ft_stack_pop(stack);
		ft_stack_push(stack, head);
		ft_stack_push(stack, new_head);
	}
}

void	ft_stack_append(t_stack *FROM, t_stack *TO)
{
	t_stack_node	*head;

	if (FROM->size > 0)
	{
		head = ft_stack_pop(FROM); 
		ft_stack_push(TO, head);
	}
}
