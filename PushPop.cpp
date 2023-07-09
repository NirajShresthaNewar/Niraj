#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool isEmpty(const Stack *stack) { return stack->top == -1; }

bool isFull(const Stack *stack) { return stack->top == MAX_SIZE - 1; }

void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Stack overflow!\n");
    return;
  }

  stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow!\n");
    return -1;
  }

  return stack->data[stack->top--];
  printf("pushed");
}

void listStack(const Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty!\n");
    return;
  }

  printf("Stack elements: ");
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}

int main() {
  Stack stack;
  initialize(&stack);

  int choice, value;
  while (true) {
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. List\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the value to push: ");
      scanf("%d", &value);
      push(&stack, value);
      break;
    case 2:
      value = pop(&stack);
      if (value != -1) {
        printf("Popped element: %d\n", value);
      }
      break;
    case 3:
      listStack(&stack);
      break;
    case 4:
      printf("Exiting the program.\n");
      return 0;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
}
