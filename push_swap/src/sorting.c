#include "../push_swap.h"
#include <stdio.h>

int stack_size(t_node *current)
{
    int size = 0;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

int check_sorted(t_node *current)
{
	while (current->next)
	{
		// printf("current value: %d\n", current->value);
		if (current->value > current->next->value)
			return 0;
		current = current->next;
	}
	// printf("is sorted\n");
	return 1;
}



#include "../push_swap.h"
#include <stdio.h>

// Sort a stack of size 3 with fewer moves
void sort_three(t_node **a)
{
    int num1 = (*a)->value;
    int num2 = (*a)->next->value;
    int num3 = (*a)->next->next->value;

    // Case 1: 3 2 1 (needs swap and reverse rotation)
    if (num1 > num2 && num2 > num3)
    {
        sa(a);  // Swap top two: 2 3 1
        rra(a); // Reverse rotate: 1 2 3
    }
    // Case 2: 3 1 2 (needs rotation)
    else if (num1 > num3 && num3 > num2)
    {
        ra(a);  // Rotate: 1 2 3
    }
    // Case 3: 2 3 1 (needs swap and rotate)
    else if (num2 > num1 && num1 > num3)
    {
        rra(a);  // Swap top two: 3 2 1
    }
    // Case 4: 1 3 2 (needs swap and rotate)
     else if (num2 > num3 && num3 > num1)
    {
        rra(a);
        sa(a);
    }
    // Case 5: 2 1 3 
      else if (num3 > num1 && num1 > num2)
    {
        sa(a);
    }
    // Case 4: 1 3 2 (already sorted, no action needed)
    // No action needed as the stack is already sorted in ascending order.
}




// Main sorting function
// Sort a stack of exactly 3 elements using sort_three
void sort_stack(t_node **a, t_node **b)
{
    int size = stack_size(*a);

	/* printf("\nStack A: \n");
	print_stack(*a);
	printf("\nStack B: \n");
	print_stack(*b);
	printf("\n"); */

	if(check_sorted(*a) == 1){
		printf("is sorted\n");
		return ;
	}

	if(size == 2){
		sa(a);
		return ;
	}

	if(size == 3){
		sort_three(a);
		return ;
	}

	chunk_sort(a,b);
	

}