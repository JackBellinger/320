# 320_Matrix

SU COSC 320 - Lab 3: Matrix Operations + timing
Jackson Bellinger 9/25/2018


a)
    In this lab we implemented a matrix class, and made the matrix opertions.
I made a class for the matrix, which had all of the functions and operator overloads needed.
The matrix class also had a function for filling the array in various different patterns.
All of the operations are called from the matrix that you want the result to be put into.
Both operands are passed by reference to the operator function, and then the result is put
into a temporary matrix that gets returned (and the data is put into the calling matrix)

b)
    
    Multiplication Timing
    
    fill        ratio of    ratio of
    type        elements    time taken
    ------------------------------------
    diagonal    2->4=2      9.42e-05 / 5.41e-05 = 1.741
    diagonal    2->8=4      9.42e-05/9.5214e-05 = 0.989
    
    filled      4->8=2      0.000756851 / 9.42e-05 = 8.0345
    
    up_triangle 2->4=2      0.0002827/4.4149e-05 = 6.403
    up_triangle 2->8=4      0.000623284/4.4149e-05 = 14.117
    
    down_triang 2->4=2      0.000110544/3.9278e-05 = 2.814
    down_triang 2->8=4      0.000618734/3.9278e-05 = 15.752
    
c) The arithmetic time complexity of Matrix multiplication is O(n^3). It may not take that long all the time, but since there are 3 for loops, have to do a sum for each element in the output matrix, and to do that you need one sum for each row and each column, so that’s n^3.

d) I would really like to implements strassen’s quick matrix multiplication, and finding fast Fibonacci. I could have done more error checking, but I think I have enough for normal use.
Also, I want to make it so that the timing stuff automatically calculates the O().

    