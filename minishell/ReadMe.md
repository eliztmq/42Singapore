-PROGRAM-
Arguments: NA

Frame of reference: Bash

-ERRORS-
Memory Leaks: Can arise from readline() function. BUT own code should not have leaks

-TO PASS- 
1. display prompt when waiting for new command
2. has working history
3. search and launch right executable based on PATH
4. DO NOT use more than 1 global variable to indicate received signal
5. do not interpret unclosed quotes or special characters which are not required such as \ or ;
6. handle ' 
7. handle " except for $
8. implement redirections 
9. implement pipes
10. handle environment variables ($)
11. handle $? -> expand to exit status of most recently executed foreground pipeline
12. Handle ctrl-c, ctrl-D, ctrl-\
13. in interactive mode, the above should have a differnt function?
14. implement builtins: echo -n, cd, pwd, export, unset, env, exit