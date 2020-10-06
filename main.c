#include<function.h>

int main()
{
int choice,fibonacci_limit,factorial_input,factorial_output,prime_input,prime_output;
printf("From the below option choose the mathematical operation you need to perform\n");
printf("1.Fibonacci series\n");
printf("2.Find factorial of the number\n");
printf("3.Check whether the number is prime or not.\n");
printf("\n Enter your choice - ");
scanf("%d",&choice);
switch(choice)
    {
        case 1:
            printf("\n----------------------\n");
            printf("\nEnter fibonacci limit\n");
            scanf("%d",&fibonacci_limit);
            fibonacci_func(fibonacci_limit);
            break;

        case 2:
            printf("\n----------------------\n");
            printf("\nEnter the number to know factorial\n");
            scanf("%d",&factorial_input);
            factorial_output = factorial_func(factorial_input);
            printf("The factorial is %d",factorial_output);
            break;

        case 3:
            printf("\n----------------------\n");
            printf("\nEnter the number to know whether its prime or not.\n");
            scanf("%d",&prime_input);
            prime_output = prime_func(prime_input);
            if(prime_output==1)
            {
                printf("\nIt's a prime number\n");
            }
            else
            {
                printf("\nIt's not a prime number");
            }
            break;
        default:
            printf("\nPlease choose the correct option\n");
            break;
    }

}
