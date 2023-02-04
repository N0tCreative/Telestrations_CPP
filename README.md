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
element at the ith index will be removed (these would confict with the person never getting a book twice). after that the permuations will be pushed onto a stack so that
recursion isnt required to go through every possibility
