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
a. count number of int, if = 3, just do basic op, if = 4 just push one

b. else, push two int

c. check if stack A has = 3 numbers

d. If yes, do appropriate operation to arrange stack A in asc order

e. If no, calculate cost of pushing each no. in A

f. Cost = 
(i) check if no. is min or max, rot of stack b =  0/1 (after push), exit
(ii) if not, refresh indexes based on current position A & B
(iii) count no. of rotation needed for stack B e.g. 4 (both index)
-- count rot for stack B by compare stack A no., a < b(get rot from index of this no.) but > b - 1 --
(iv) compare with corr index of stack A, e.g. 3
(v) compare diff moves, larger no. of rrot vs larger no. of rot vs rotA + rrot B(or vice versa)
(vi) populate the string list of operations needed
(vii)take the larger no. of rotation + 1 (push)
(viii) keep track of lowest cost

g. Execute based on lowest cost
(i) if length of list = int min cost
(ii) execute each operation in list of string operations by order
(iii) after executing reroute to 4c and repeat

h. when stack A has = 3 numbers
(i) check if numbers are in order
(ii) if not, first do a swap

i. push no. back to stack A using same logic as (iii)

j. find min of stack A and using forward and backward index, see which is smaller and rotate accordingly

5. Determine what are the sub codes logic that need to be thought through
--Calc Cost--
a. MAIN: populate cost of outgoing stack numbers and find abs min cost
b. refresh indexes
c. **output node where insertion will take place on top of, 
-compare number from outgoing stack with whole of receiving stack (insertion)-
d. output list string, compare outgoing node in consideration vs receiving stack (to do 4f(v))
e. count list items 

--Exec--
a. initialise function
b. MAIN REPEATED: execution from 4c 
c. AFTER CALC COST: execute based on list of operation
d. Basic operation for when stack = 3 numbers

--push back--
a. use calc cost (c) logic to rotate stack A accordingly for push from B
b. find min of stack A to do rotation for output

--checker--
a. check if input list already ordered
b. check for error on inputs

---

Background:
stack/container - circular OR linear doubly linked list OR array but follows FILO ***