#include <stdio.h>
#include <stdlib.h>
#include <omp.h>



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
    int arrsize []={200000,500000,1000000}; //defining different array sizes
    
    //executing the function for different array sizes
    for (int i = 0; i < 3; i++) {
        int N = arrsize[i];
        printf("\nArray Size:  %d\n", N);
        int arr[N];
        // Initialize array with random numbers
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

    printf("\n===...... Counting Even and Odd Numbers ....===\n");
    countEvenOddSequential(arr, N); 
        
    }
    
    return 0;
}

