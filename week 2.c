#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;	
};

struct stack *top = NULL;

struct stack* push(struct stack *top, int val)
{
    struct stack *ptr = malloc(sizeof(struct stack));
    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr = top;
	if (top == NULL)
	{
		printf("\n STACK UNDERFLOW");
	}
	else
	{
		top = top->next;
		printf("\n THE Value being deleted is: ");
		free(ptr);
	}
	return top;
}
int peek (struct stack *top)
{
	return (top == NULL) ? -1 : top->data;
}
struct stack* display (struct stack *top)
{
	struct stack *ptr = top;
	if (top == NULL)
	{
		printf("\nSTARCK IS EMPTY");
	}
	else
	{
		while (ptr !=NULL)
		{
		printf("\n%d",ptr->data);
		ptr = ptr->next;
		}
	}
	return top;
}
int main()
{
	int val, option;
	do
	{
		printf("\n*******MAIN MENU*******");
		printf("\n1.PUSH");
		printf("\n2.pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("\n Enter the number to be pushed on stack: ");
				scanf ("%d",&val);
				top = push(top, val);
				break;
				case 2:
					top = pop(top);
					break;
					case 3:
						val = peek(top);
						if (val != -1)
						printf("\n The value at the top of stack is: %d",val);
						else
						printf("\n STACK IS EMPTY");
						break;
						case 4:
							top = display(top);
							break;
		}
	} while (option != 5);
	return 0;
}
