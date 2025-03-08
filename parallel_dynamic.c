#include <stdio.h>
#include <omp.h>
#include <stdlib.h> //library  to generate random numbers

double start,end,totaltime;// glabal variables to calculate execution time

//creating a function to count even and odd numbers in a given array. This function executes parallely.
void countDynamicEvenOddParallel(int arr[], int size) {
    int even = 0, odd = 0;
     start = omp_get_wtime();// start is a variable to starting execution time of the function

    //using dynamic scheduling to execute for loop parallely
    //reduction is used to handle race condition and critical section
    #pragma omp parallel for schedule(dynamic) reduction(+:even, odd)
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

     end = omp_get_wtime(); //end is a variable to starting execution time of the function
     totaltime=end-start;
    printf("Parallel dynamic Execution:\nEven Count: %d, Odd Count: %d\n", even, odd);
    printf("Time Taken: %.6f sec\n\n", end - start); //end-start gives the total execution time of the code
    
}

int main() {
    
    int arrsize []={200000,500000,1000000}; //defining different array sizes
    int num_threads[] = { 4, 8 ,12};    // Test different thread counts


    for (int i = 0; i < 3; i++) {
        int N = arrsize[i]; 
        printf("\nArray Size:  %d\n", N);
        int arr[N]; //initializing array with different sizes
        // Initialize array with random numbers according to array size
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;  // it will generate random numbers between0 and 999
    }

   // printf("\n=== Counting Even and Odd Numbers ===\n");
    
    //executing same code for different number of threads  and calculating execution time for each number of threads
    
    for (int t = 0; t < 3; t++) {
        omp_set_num_threads(num_threads[t]); //defining number of threads
        printf("\n--- Testing with %d Threads ---\n", num_threads[t]);
    for(int i=0;i<10;i++){ 
    countDynamicEvenOddParallel(arr, N);
    totaltime+=totaltime; //calculating total time
    }
    
    printf(" Average Time Taken: %.6f sec\n\n", totaltime/10); //end-start gives the total execution time of the code
    }
}
    

    return 0;
}