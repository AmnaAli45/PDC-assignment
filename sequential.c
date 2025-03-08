#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 1000000 // defining the size of array 

//creating a function to count even and odd numbers in a given array. This function executes sequentially.

void countEvenOddSequential(int arr[], int size) {
    int even = 0, odd = 0; // variables to store even and odd count of an array

    double start = omp_get_wtime();//function of OMP used to calculate the execution time. starting time is stored.

    //whenever an odd number comes in array it will incement even otherwise odd will be incremented.
    //this loop will execute until whole array is explored.
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) 
            even++;
        else
            odd++;
    }

    double end = omp_get_wtime(); //ending execution time is stored in end variable 
    printf("Sequential Execution:\nEven Numbers are: %d\nOdd Numbers are: %d\n", even, odd);
    printf("Time Taken: %.6f sec\n\n", end - start); //end-start gives the total execution time of the code
}

int main() {
    int arr[SIZE]; //declaring an array of definesd size
    
    // Initialize array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

    printf("\n===...... Counting Even and Odd Numbers ....===\n");
    countEvenOddSequential(arr, SIZE); 
    
    

    return 0;
}

