/*
 ============================================================================
 Name        : parentheses.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

#define max 100
#define min -1

char c_data[max];
char stack[max];
int top = min;


void push(uint8_t u8_data);
uint8_t pop();
void printStack();
int isbalanced(char stack_b[]);


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter your sentence : ");
	scanf("%s",c_data);

	//int i = 0;
	//	while(c_data[i] != '\0')
	//	{
	//		push(c_data[i]);
	//		i++;
	//	}

	if(isbalanced(c_data))
	{
		printf("Balanced");
	}
	else
	{
		printf("unBalanced");
	}

	//printStack();
	return 0;
}

void push(uint8_t u8_data)
{
	if(top != max)
	{
		top++;
		stack[top] = u8_data;
	}
	else
	{
		printf("Stack is full");
	}
}

uint8_t pop()
{
	char d;
	if(top != min)
	{
		d = stack[top];
		top--;
		return d;
	}
	else
	{
//		printf("\n stack is empty");
		return 0;
	}
}

void printStack()
{
	char data = pop();
	while(data)
	{
		printf("%c", data);
		data = pop();
	}
}

int isbalanced(char stack_b[max])
{
	char dd = ' ';
	int j = 0;
	while(stack_b[j] != '\0')
	{
		if ((stack_b[j] == '{' )|| (stack_b[j] == '(') ||(stack_b[j] == '[' )|| (stack_b[j] == '<'))
		{
			push(stack_b[j]);
			j++;
			if (stack_b[j] == '\0')
			{
				return 0;
			}
		}
		else if ((stack_b[j] == '}') || (stack_b[j] == ')') || (stack_b[j] == ']') || (stack_b[j] == '>'))
		{
			switch (stack_b[j])
			{
			case '}':
				if (top == -1)
				{
					return 0;
				}
				else if (stack[top] == '{')
				{
					dd = pop();
				}
				else
				{
					return 0;
				}
				break;
			case ']':
				if (top == -1)
				{
					return 0;
				}
				else if (stack[top] == '[')
				{
					dd = pop();
				}
				else
				{
					return 0;
				}
				break;
			case '>':
				if (top == -1)
				{
					return 0;
				}
				else if (stack[top] == '<')
				{
					dd = pop();
				}
				else
				{
					return 0;
				}
				break;
			case ')':
				if (top == -1)
				{
					return 0;
				}
				else if (stack[top] == '(')
				{
					dd = pop();
				}
				else
				{
					return 0;
				}
				break;
			}
			j++;
		}
		else
		{
			j++;
		}
	}
	if (!(top == -1))
	{
		return 0;
//		while (!(top == -1))
//		{
//			pop();
//		}
	}
	return 1;
}
