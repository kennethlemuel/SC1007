#include <stdio.h>
#include <stdlib.h>

int waysToScore(int n, int* score){ // n is the score we want to find out, given an array 'score'
    int* arr; //array to store the dynamic programming table
    arr = (int*) malloc((n+1)*sizeof(int)); //allocate the memory for a total of n integers
    int i; //initialize loop counter
    for(i=0;i<=n;i++){
        arr[i]=0; //fill up with zeros
    }  //iterate through all the possible positions


    arr[0] = 1; //base case, do nothing and receive 0 points.

    for(i=1;i<=n;i++) //iterate through the array
    {
        if(i-score[0]>=0) //check if the index 0 (value of 3), minus the scores we want (n)
            arr[i] += arr[i-score[0]];
        if(i-score[1]>=0) //check if the index 1 (value of 5), minus the scores we want (n)
            arr[i] += arr[i-score[1]];
        if(i-score[2]>=0) //check if the index 2 (value of 10), minus the scores we want (n)
            arr[i] += arr[i-score[2]];
    }
    int result = arr[n];
    free(arr);
    return result; //return value of last index which corresponds to the total number of unique  ways to reach score of n
}


void main ()
{
    int n;

    int score[3] = {3,5,10};

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
