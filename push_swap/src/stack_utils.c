#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../push_swap.h"


long	ft_atoi_check(const char *nptr)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}

    if(!ft_isdigit(*nptr)){
	    return (long)INT_MAX + 1;
    }

	while (ft_isdigit(*nptr))
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
    //printf("%c\n", *nptr);
    if(!*nptr){
	    return (result * sign);
    }
    // printf("Hello\n");
    return (long)INT_MAX + 1;
}



// Function to add a node at the end
t_node *add_node(t_node *last_node, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;

    new_node->value = value;
    new_node->next = NULL;
    last_node->next = new_node; // Append new node
    return new_node;            // Return new last node
}

void free_tokens(char **tokens)
{
    int i = 0;

    if (!tokens)
        return;

    while (tokens[i])
    {
        free(tokens[i]); // Free each string
        i++;
    }
    free(tokens); // Free the array itself
}

// Function to process numbers and add them to the stack
int process_numbers(char *arg, t_node **last_node)
{
    char **tokens;
    int i = 0;

    tokens = ft_split(arg, ' '); // Split argument into an array of words
    if (!tokens)
        return 0;

    while (tokens[i])
    {


        long value = ft_atoi_check(tokens[i]);
        if(value < INT_MIN || value > INT_MAX){
            // printf("VALUE IS OUT OF INT\n");
            free_tokens(tokens); // Free memory if allocation fails
            return 0;
        }
        *last_node = add_node(*last_node, value); // Append to the last node
        if (!*last_node)
        {
            free_tokens(tokens); // Free memory if allocation fails
            return 0;
        }

        i++;
    }

    free_tokens(tokens); // Free the array after processing all tokens
    return 1; // Success
}

//check if integer


int has_duplicates(t_node *head)
{
    t_node *i, *j;

    for (i = head; i; i = i->next)
    {
        for (j = i->next; j; j = j->next)
        {
            if (i->value == j->value)
            {
                // printf("HAS DUPLICATES\n");
                return 1; // Duplicate found
            }
        }
    }
    return 0;
}


// Function to initialize stack A
t_node *init_stack(int argc, char **argv)
{
    if (argc < 2)
        return NULL;

    // Create a dummy head
    t_node *dummy = malloc(sizeof(t_node));
    if (!dummy)
        return NULL;
    dummy->next = NULL; // Will be ignored later

    t_node *last_node = dummy; // Start with the dummy node
    int i = 1;

    while(i < argc)
    {
        if (!process_numbers(argv[i], &last_node))
        {
            free(dummy);
            return NULL;
        }
        i++;
    }

    t_node *head = dummy->next;
    free(dummy); 

        if (has_duplicates(head)) // Check for duplicates after allocation
    {
        free_stack(head);
        return NULL;
    }

    return head;
}

// Function to print the stack for testing
void print_stack(t_node *head)
{
    while (head)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }
    // printf("NULL\n");
}

// Function to free the stack
void free_stack(t_node *head)
{
    t_node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
