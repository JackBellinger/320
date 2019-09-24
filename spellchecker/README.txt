Cosc 320 Project 2: HashTable Spell Checker
Jackson Bellinger 11/14/2018

In this project, we implemented a hashtable to be used for checking the spelling of strings against a dictionary, read in from a text file.
We timed how long it takes to load, and how well distributed the elements across the hashtable.
I made the hashtable store an abstract type, Hashable, and made a string wrapper, Word, that inherits from Hashable. I did this so that whenever I need to use a hashtable agian I just need to write another wrapper class, rather than alter the HashTable class.
I also used reb-black trees for chaining / to store the collisions, which doesn't reduce the time to load significantly, but it makes checking words O(logx), where x is the size of the biggest bucket, rather than O(x) ~ O(n) if the hash function was really bad.

I used the bitshifting hash function, and converted the strings to doubles block-wise. The bitshifting multiplication hash just multiplies the key by a large number and gets the decimal portion of that. The bitshifting multiplication hash function The strToNum function sums each digit into the digit%4 th place, + any remainder. Also, I tried a few prime numbers around the s value that me and Steph used, but it didn't make much of a difference.
