#include <stdio.h>
#include <omp.h>
#include <stdlib.h> //library  to generate random numbers

#define SIZE 1000000 // Large array size for meaningful parallelization

void countStaticEvenOddParallel(int arr[], int size) {
    int even = 0, odd = 0; //variables to store even and odd numbers in array
    double start = omp_get_wtime();// start is a variable to starting execution time of the function
    
  //function to count even and odd numbers in a given array parallely
    #pragma omp parallel for schedule(static) reduction(+:even, odd)
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    
    double end = omp_get_wtime();// end is a variable to starting execution time of the function
   printf("Parallel static Execution:\nEven Count: %d, Odd Count: %d\n", even, odd);
   printf("Time Taken: %.6f sec\n\n", end - start);//end-start gives the total execution time of the code
    
}

int main() {
    int arr[SIZE]; //declaring an array
    int num_threads[] = { 4, 8 ,12};    // Test different thread counts

    
    


    // Initialize array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

    //executing same code for different number of threads  and calculating execution time for each number of threads
    for (int t = 0; t < 3; t++) {
        omp_set_num_threads(num_threads[t]);
        printf("\n--- Testing with %d Threads ---\n", num_threads[t]);
    
    
    countStaticEvenOddParallel(arr, SIZE);
    }
    

    return 0;
}
