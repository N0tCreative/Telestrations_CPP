# Telestrations_CPP
organizes a telestration game where no person gives their book to the same person twice

with n number of people telestrations involves each person getting a book, writting something in it, 
the next person that gets the book must draw what was written, the person after that must write what was drawn etc 
until there have been n rounds (each person has contributed once to each book). 
The first thing this should find is all sets of paths that would result in each person getting each book exactly once. 
the second thing this sould find is if its possible for each person to hand their current book to a different person each time.

essentially (1)generates every possible permutation of an array such that no number is in the same position in the array
then (2)checks that the permutations dont move any numbers from one position to another more than once
(ie the number in position 1 in round 1 is in position 2 in round 2 and the number in position 1 in round 3 is in position 2 in round 4)

the original progam was the telestrations orgainzer written in rust and was highly unoptimized hopefully this refactored version will be more able to accommodate a
larger number of players. to reduce complexity first, all possible permutations will be generated based on heaps algorithm, then any permutations that have the ith
element at the ith index will be removed (these would confict with the person never getting a book twice and the permuation where everyone starts with their book). 
after that the permuations will be pushed onto a stack so that recursion isnt required (randomize the order to make finding the solution faster). create a filter 
(number only shows in each index once) that is updated every time a permutation is added to current order to weed out perms that confilct with it from the stack 
(using tree pruning algorithm). once you have a valid set of permutations then reorder them until you have covered every possible ordering or you reach one that 
satisfies both (1) and (2). 

Optimization research:
Condition (2) checking:
-look into using a table for who can send to who instead. this might be faster to prove that it would be impossible to never send to the same person twice.
-this type of issue seems similar to an euler/hamiltonian path problem (since odd numbered players never gets an optimal solution in testing thus far) but ive been unable
to simplify to a euler/hamiltonian path problem that results in a confirmation that its impossible for odd numbers

Permutation Generation:
-did more reasearch into (1)generating the list of permutations since this seemed like a general problem that would have already been solved and it turns out i was right
these type of permutations are called latin squares, and one can be used to create several others that are isotopic to it. unfortunately being able to swap columns and rows, 
symbols (book numbers), and that you can flip the order completely is something i already knew about and decided against due to the large amount of repitition (repeatedly checking
the same permutation set) that would be involved. also just creating one isotopic class would not cover all possible solutions, also as far as i can tell (2) still has to be 
checked after the latin square generation is done regardless of method, so it seems that generating the permutations cannot be further optimized using known algorithms.
