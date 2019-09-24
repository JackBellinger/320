Cosc 320 Lab 4: Heap and Heapsort
Jackson Bellinger 10/9/2018

In this project, we implemented a heap class, and used it to time the runtime of heapsort. We also timed the sorting to validate the theoretical time complexity of heapsort.
I pretty much used all the standard implementations of the heap functions. I did use templates, so that's kind of interesting (also a bit of a pain but also fun).

Theoretically, the time should be Big Theta(nlogn). The best and worst case should be the same. Since a heap is always complete, because we used an array to store the elements, it will never be unbalanced like a BST can be. Therefore heapsort will always be able to take advantage of the logn properties of trees.

The absolute timing was found to be about the same as the theoretical time complexity of Thete(nlogn). I saw that the arrays sorted in ascending order took marginally longer to sort than descending and random order, however this is likely a coincidence. If I tested it again I would add more tests to try to get a better average.

(I didn't actually write the delta times / delta elements because it's 11:55)
Part of the reason I'm not doing more testing is because it takes me some time to take the numbers from the output and do the math to see what the time difference between test array sizes is, so I would like to change my timing function to output the timing in a more useful way. 

Array with 10 elements is in Ascending Order and will be sorted by HeapSort
finished at Tue Oct  9 11:47:22 2018
elapsed time: 0.0115984 s
Array is Sorted Correctly

Array with 10 elements is in Descending order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 5.9076e-05 s
Array is Sorted Correctly

Array with 10 elements is in Random order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 6.0802e-05 s
Array is Sorted Correctly

Array with 100 elements is in Ascending Order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.000476307 s
Array is Sorted Correctly

Array with 100 elements is in Descending order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.00045438 s
Array is Sorted Correctly

Array with 100 elements is in Random order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.000459817 s
Array is Sorted Correctly

Array with 1000 elements is in Ascending Order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.013087 s
Array is Sorted Correctly

Array with 1000 elements is in Descending order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.00534623 s
Array is Sorted Correctly

Array with 1000 elements is in Random order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.00588564 s
Array is Sorted Correctly

Array with 10000 elements is in Ascending Order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.124974 s
Array is Sorted Correctly

Array with 10000 elements is in Descending order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.116668 s
Array is Sorted Correctly

Array with 10000 elements is in Random order and will be sorted by HeapSort

finished at Tue Oct  9 11:47:23 2018
elapsed time: 0.11105 s
Array is Sorted Correctly

