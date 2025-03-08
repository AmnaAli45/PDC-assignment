#include <stdio.h>
#include <omp.h>
#include <stdlib.h> //library  to generate random numbers

#define SIZE 1000000 // Large array size for meaningful parallelization

//creating a function to count even and odd numbers in a given array. This function executes parallely.
void countDynamicEvenOddParallel(int arr[], int size) {
    int evenCount = 0, oddCount = 0;
    double start = omp_get_wtime();// start is a variable to starting execution time of the function

    //using dynamic scheduling to execute for loop parallely
    //reduction is used to handle race condition and critical section
    #pragma omp parallel for schedule(dynamic) reduction(+:evenCount, oddCount)
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    double end = omp_get_wtime(); //end is a variable to starting execution time of the function
    printf("Parallel dynamic Execution:\nEven Count: %d, Odd Count: %d\n", evenCount, oddCount);
    printf("Time Taken: %.6f sec\n\n", end - start); //end-start gives the total execution time of the code
    
}

int main() {
    int arr[SIZE]; 
    
    int num_threads[] = {1, 4, 8 ,12};    // Test different thread counts


    // Initialize array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

    printf("\n=== Counting Even and Odd Numbers ===\n");
    
    //executing same code for different number of threads  and calculating execution time for each number of threads
    
    for (int t = 0; t < 4; t++) {
        omp_set_num_threads(num_threads[t]); //defining number of threads
        printf("\n--- Testing with %d Threads ---\n", num_threads[t]);
    
    countDynamicEvenOddParallel(arr, SIZE);
    
    }
    

    return 0;
}