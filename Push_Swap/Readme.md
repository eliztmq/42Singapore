-PROGRAM-
argument: stack a formatted as list of integers, first argument top of stack

result: 
smallest list of instructions to sort stack a, 
print instructions separated by \n

error-handling: 
1. no parameters - program not display anything and give prompt back
2. errors - display "Error" followed by \n on standard error

-ERRORS-
1. argument aren't integers
2. arguments bigger than an integer
3. duplicates

-PROBLEM-
There are 2 stacks named a and b

Stack A: random amount of negative and/or positive numbers which cannot be duplicated
Stack B: empty

Goal: Sort in ascending order numbers into stack a

Available operations:
1. sa (swap a) - swap first two elements at top of stack a
2. sb (swap b) - swap first two elements at top of stack b
3. ss - sa and sb at the same time
4. pa (push a) - first element at top b to top of a
5. pb - take first element at top a to top b
6. ra (rotate a) - shift up all elements of a by 1 
7. rb (rotate b) - shift up all elements of b by 1
8. rr - ra and rb at the same time
9. rra (reverse rotate a) - shift down all elements of a by 1
10. rrb (reverse rotate b) - shift down all elements of b by 1
11. rrr - rra and rrb at the same time

-TO PASS- 
Minimalist validation = sort 100 random numbers < 700 operations
Maximal validation = sort 500 random numbers < 5500 operations