SU COSC 320 - Lab 1: Sorting Algorithms Runtime analysis
Jackson Bellinger 9/10/2018

In this project, Bubble Sort, Insertion Sort, and Selection Sort were implemented in C++. I used a Sort class to contain all of the algorithms and a few functions for generating test arrays. I decided to use a seperate class so that these sorting algorithms, and any added later, can be included with minimal modification in any project for which they're needed.
I noticed that bubble sort and insertion sort took significantly more time and swap operations to sort a decending ordered array than selection sort did.
For insertion sort this could perhaps be helped by checking the current element to be inserted against the index where the last element ended up. I would have to do more testing to see how that affects O(insertion sort).
From the runtime of the sorting algorithms (data is in output.txt) it's clear that all of the sorting algorithms are O(n^2) as expected. However, selection sort seems to run

#note sortRands only outputs the sortinf for random arrays
Questions
1)What is the theoretical run time (best and worst case) in terms of the number of elements n
            best case       worst case
selection   O(n/2)~O(n)     O(n^2)	
insertion   O(n)            O(n^2)
bubble      O(n)            O(n^2)

2) the runtime of the algorithms doesn't seem to take 
quite as high as T(n^2) to run, but it's definitely 
higher than T(n) on average. 

For selection sort, from
100k to 1mil it took about 30 times as long, 3x longer
per element.

3) The best case for all of the sorting algorithms was if the array was already sorted. All 3 of them had 0 swaps for any array pre-sorted in ascending order.
With the descending order, selection sort took somewhere between O(n) and O(n/2), while insertion and bubble sort took O(n^2). When the arrays were randomly sorted, the average is around O(n^2) for all of them.

For some reason my insertion sort and bubble sort took O(n^4) only for 100000 elements, so I'm not 
sure what to make of that.

4)  Making the input arrays templated would help with code reusability. I would also like to use a comparable interface so that I could sort arrays of non-numeric types.

