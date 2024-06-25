#include <push_swap.h>

int	ft_chunk_get_value(t_psw *psw, t_chunk *chunk, int pos)
{
	int	size;

	t_stack *stack = ft_chunk_loc_to_stack(psw, chunk->loc);
	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		size = stack->size - 1;
	else
		size = 0;
	while (pos--)
	{
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		{
			if (size == stack->size - 1)
				size = 0;
			else
				size += 1;
		}
		else
		{
			if (size == stack->size == 0)
				size = stack->size - 1;
			else
				size -= 1;
		}
	}
	return (ft_stack_get_value(stack, size));
}

int	ft_chunk_max_value(t_psw *psw, t_chunk *chunk)
{
	int	idx;
	int	max;
	int	size;

	t_stack *stack = ft_chunk_loc_to_stack(psw, chunk->loc);
	size = chunk->size;
	if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		idx = stack->size - 1;
	else
		idx = 0;
	max = -1;
	while (size--)
	{
		if (ft_stack_get_value(stack, idx) > max)
			max = ft_stack_get_value(stack, idx);
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		{
			if (idx == stack->size - 1)
				idx = 0;
			else
				idx += 1;
		}
		else
		{
			if (idx == 0)
				idx = stack->size - 1;
			else
				idx -= 1;
		}
	}
	return (max);
}

t_stack	*ft_chunk_loc_to_stack(t_psw *psw, e_stk_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
	{
		return (&psw->stk_a);
	}
	return (&psw->stk_b);
}
