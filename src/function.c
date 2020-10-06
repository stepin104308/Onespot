#include<function.h>

void fibonacci_func(int fibonacci_limit)
{
    int init_term=0, second_term=1, nextTerm, fibonacci_iterator;
    printf("Fibonacci Series: ");

    for (fibonacci_iterator = 1; fibonacci_iterator <= fibonacci_limit; ++fibonacci_iterator) {
        printf("%d, ", init_term);
        nextTerm = init_term + second_term;
        init_term = second_term;
        second_term = nextTerm;
    }
}

int factorial_func(int factorial_input)
{
    int factorial_value=1,factorial_iterator;
    if (factorial_input < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (factorial_iterator = 1; factorial_iterator <= factorial_input; ++factorial_iterator) {
            factorial_value *= factorial_iterator;
        }
    }
    return factorial_value;
}

int prime_func(int prime_input)
{
    int prime_iterator,flag=0;
    for (prime_iterator = 2; prime_iterator <= prime_input / 2; ++prime_iterator) {

        // condition for non-prime
        if (prime_input % prime_iterator == 0) {
            flag = 1;
            break;
        }
    }

    if (prime_input == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (flag == 0)
            return 1;
        else
            return 0;
    }

}
