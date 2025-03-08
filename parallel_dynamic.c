#include <stdio.h>
#include <omp.h>
#include <stdlib.h> //library  to generate random numbers

#define SIZE 1000000 // Large array size for meaningful parallelization

//creating a function to count even and odd numbers in a given array. This function executes parallely.
void countDynamicEvenOddParallel(int arr[], int size) {
    int evenCount = 0, oddCount = 0;
    
    //using dynamic scheduling to execute for loop parallely
    //reduction is used to handle race condition and critical section
    #pragma omp parallel for schedule(dynamic) reduction(+:evenCount, oddCount)
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }


    
    printf("Parallel dynamic Execution:\nEven Count: %d, Odd Count: %d\n", evenCount, oddCount);
    
}

int main() {
    int arr[SIZE]; 
    
    


    // Initialize array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

    printf("\n=== Counting Even and Odd Numbers ===\n");
    
    
    
    countDynamicEvenOddParallel(arr, SIZE);
    

    return 0;
}