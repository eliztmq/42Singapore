Logic:
1. Stack A ascending order (final stack to be seen)
2. Stack B descending order (to be pushed to stack A)
3. Cost savings are in being able to do the same action for both stacks 
4. Operations are in entire shifts within stacks, except exchanged in top two numbers
5. BASE: 3,only 1/2 operations needed, pushing to next stack will be a wasted step
6. Motive is smallest no. of operations, leeway to calc operation beforehand

---

Breaking down the problem:
1. Screening argument and error handling
a. should use long to take in argument and compare with MAX and MIN int for error

2. Storing the arguments into datatype (test no seg fault)

3. Testing the operations checking if it works

4. Determine the algorithm to use

5. Come up with a calculation method of cost

6. Determine base operation of simplest form : 3 numbers

7. Determine what information needed in struct of node 

---

Decisions to make:
-PLANNING-
1. Choose data type for stack: single linked list 
(easy to handle and keeps to the essence of operations we want to do)

2. Choose algorithm to solve
Basic number: 3 numbers in a stack, where only one or two operation needed
Foundational Rule: Stack B in descending order 
Cost to calculate: operations to push and order stack B
First move: push two numbers to stack B
Tracking: Min and Max of all the numbers -- represents only one op needed

3. Decide what information is needed in the struct
Int Number
Pointer to next struct
Pointer to previous struct
Int Forward Index (rot)
Int Backward index (rrot)
String Operations (list of strings)
Int Min Cost (replaced as calc cost goes on)
Int Min of whole list
Int Max of whole list

4. Establish logic flow
a. count number of int, if <= 3, just do basic op

b. else, push two int

c. check if stack A has = 3 numbers

d. If yes, do appropriate operation to arrange stack A in asc order

e. If no, calculate cost of pushing each no. in A

f. Cost = 
(i) refresh indexes based on current position A & B (if index is not refreshed for both, then exit)
(ii) count no. of rotation needed for stack B e.g. 4 (both index)
-- count rot for stack B by compare stack A no., a < b(get rot from index of this no.) but > b - 1 --
(iii) compare with corr index of stack A, e.g. 3
(iv) compare diff moves, larger no. of rrot vs larger no. of rot vs rotA + rrot B(or vice versa)

g. Execute based on lowest cost [TO BE FILLED]
(i) shift through whole of stack a to find lowest cost -> get the node 
(ii) find the corresponding node in b where u want to insert on top of
(iii) use the same conditions to sift through and push accordingly

h. when stack A has = 3 numbers
(i) check if numbers are in order
(ii) if not, first do a swap

i. push no. back to stack A using same logic as (iii)

j. find min of stack A and using forward and backward index, see which is smaller and rotate accordingly

5. Determine what are the sub codes logic that need to be thought through
--Calc Cost--
a. MAIN: populate cost of outgoing stack numbers
b. refresh indexes
c. **output node where insertion will take place on top of, 
-compare number from outgoing stack with whole of receiving stack (insertion)-
d.  condition function to calculate costs to be filled

--least cost -- 
a. MAIN: filter based on same conditions and execute operations accordingly
b. output node with the lowest cost in the stack
c. execution when both stacks need forward rotation
d. execution when both stacks need backward rotation
e. execution stack needs separate rotation (will have to be applicable to either a or b, flag required)

--basic--
a. Basic operation for when stack = 3 numbers THEN ONTO push back
b. find int_max of stack
c. find int_min of stack

--Exec--
a. initialise function 4a and 4b
b. MAIN REPEATED: execution from 4c 
c. check if list already ordered -> free stack a

--push back-- (SHOULD HIGHLIGHT IF THERE ARE SIMILARITIES IN LOGIC AND THINK ABOUT HOW TO BRING THEM TOGETHER)
a. use calc cost (c) logic to rotate stack A accordingly for push from B
b. find min of stack A to do rotation for output

--initialise--
a. MAIN PROCESS: check error and fill and check dup
b. check if alphabet 
c. check if duplicate
d. add node to end 

--push_swap--
a. MAIN: takes in arguments + initialise the two stacks, a and b + check argv to see if its valid (linking to checker.c) + execute
b. error free stack
---

Background:
stack/container - circular OR linear doubly linked list OR array but follows FILO ***