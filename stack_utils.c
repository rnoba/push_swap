#include <push_swap.h>

t_stack_node	*ft_stack_get_node(t_stack *stack, int pos)
{
	t_stack_node	*head;

	head = stack->head;
	while (head)
	{
		if (head->pos == pos)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	ft_stack_print(t_stack *stack, t_stack *s2)
{
	t_stack_node	*head;

	head = stack->head;
	while (head)
	{
		ft_printf("[%d, %d] ", head->content, head->pos);
		head = head->next;
	}
	ft_printf(" | ");
	head = s2->head;
	while (head)
	{
		ft_printf("[%d, %d] ", head->content, head->pos);
		head = head->next;
	}
	ft_printf("\n");
}

int	ft_stack_get_value(t_stack *stack, int pos)
{
	t_stack_node	*node;

	node = ft_stack_get_node(stack, pos);
	return (node->content);
}

void	ft_stack_update_pos(t_stack *stack)
{
	t_stack_node	*head;
	int	pos;

	head = stack->head;
	pos = 0;
	while (head)
	{
		head->pos = pos++;
		head = head->next;
	}
}

t_stack_node	*ft_stack_init_node(int content, int pos)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	ft_bzero(node, sizeof(t_stack_node));
	if (node)
	{
		node->content = content;
		node->pos = pos;
	}
	return (node);
}
