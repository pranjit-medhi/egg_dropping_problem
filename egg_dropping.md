Egg Dropping Problem 

A program that determines the minimum number of trials that  is guaranteed to work in all cases

 We make a few assumptions:

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If an egg breaks when dropped, then it would break if dropped from a higher floor.
If an egg survives a fall then it would survive a shorter fall.
It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?


The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.

Brute Force logic:
Start from ground floor and keep going up until the egg breaks at floor X. 

Solution is very inefficient, in case the egg doesn't break till the nth floor.

Best solution:
We need to minimize this worst-case number of drops. For that, we need to generalize the problem to have n floors. What would be the step value, for the first egg? Would it still be 10? Suppose we have 200 floors. Would the step value be still 10? 

The point to note here is that we are trying to minimize the worst-case # of drops which happens if the threshold is at the highest floors. So, our steps should be of some value which reduces the #of drops of the first egg.

Let's assume we take some step value m initially. If every subsequent step is m-1,
then, 
m+m−1+m−2+.....+1=n

This is m∗(m+1)2=n

If n =100, then m would be \ceil13.65 which is actually 14.

So, the worst case scenario is now when the threshold is in the first 14 floors with #of drops being 14



Optimal Substructure:
When we drop an egg from a floor x, there can be two cases:
 1. The egg breaks 
 2. The egg doesn’t break.

1) If the egg breaks after dropping from xth floor, then we only need to check for floors lower than x with remaining eggs; so the problem reduces to x-1 floors and n-1 eggs
2) If the egg doesn’t break after dropping from the xth floor, then we only need to check for floors higher than x; so the problem reduces to k-x floors and n eggs.

