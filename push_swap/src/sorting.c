#include "../push_swap.h"
#include <stdio.h>

int check_sorted(t_node *current)
{
	while (current->next)
	{
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	return 1;
}

void sort_three(t_node **a)
{
    int num1 = (*a)->value;
    int num2 = (*a)->next->value;
    int num3 = (*a)->next->next->value;

    // Case 1: 3 2 1 (needs swap and reverse rotation)
    if (num1 > num2 && num2 > num3)
    {
		sx(a, "sa");
        rrx(a, "rra"); // Reverse rotate: 1 2 3
    }
    // Case 2: 3 1 2 (needs rotation)
    else if (num1 > num3 && num3 > num2)
        rx(a, "ra");  // Rotate: 1 2 3
    else if (num2 > num1 && num1 > num3)
        rrx(a, "rra");  // Swap top two: 3 2 1
     else if (num2 > num3 && num3 > num1)
    {
        rrx(a, "rra");
		sx(a, "sa");
    }
    // Case 5: 2 1 3 
      else if (num3 > num1 && num1 > num2)
		sx(a, "sa");
    // Case 4: 1 3 2 (already sorted, no action needed)
    // No action needed as the stack is already sorted in ascending order.
}

	void simple_sort(t_node **a, t_node **b)
	{
		int size = stack_size(*a);
		while (stack_size(*a) > 3)
		{
			int min = get_min(*a);
			int index = get_index(*a, min);
			move_to_top(a, index, size, 'a');
			px(b, a, "pb");
			size--;
		}
		sort_three(a);
		while (*b)
			px(a, b, "pa");
	}



// Main sorting function
// Sort a stack of exactly 3 elements using sort_three
void sort_stack(t_node **a, t_node **b)
{
    int size = stack_size(*a);

	if(check_sorted(*a) == 1)
		return ;

	if(size == 2){
		sx(a, "sa");
		add_operation("end");
		return add_operation("print");
	}

	if(size == 3){
		sort_three(a);
		add_operation("end");
		return add_operation("print");
	}

	if(size < 6){
		simple_sort(a, b);
		add_operation("end");
		return add_operation("print");
	}

	chunk_sort(a,b);
}