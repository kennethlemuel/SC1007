#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

int cr_recursive(int *p, int n)
{
    if (n == 0) //if the length of the rod is 0, then there is no price for it
        return 0;

    int i; //loop counter
    int maxval = -1;//current max value
    for (i=1;i<=n;i++)//start length 1
    {
        int temp = p[i] + cr_recursive(p, n-i); //temporary new max value
        if (temp > maxval) //if the new max value is larger than the old max value
            maxval = temp; //replaced.
    }

    return maxval; //return max value
}

int cr_top_down_dp(int *p, int n)
{
    if (n == 0) //if length 0, then no price
        return 0;

    //check memory if the max value exists already
    if (r[n] > 0)
        return r[n];

    int i; //loop counter
    int maxval = -1; //current max value
    for (i=1;i<=n;i++) //iterate through the legnths
    {
        int temp = p[i] + cr_top_down_dp(p, n-i); //finding the next max value
        if (temp > maxval)//replace max value if larger.
            maxval = temp;
    }

    //write to the memory and return the value
    r[n] = maxval;
    return maxval;
}

int cr_bottom_up_dp(int *p, int n)
{
    int i,j; //initialize loop counters
    r[0] = 0; //base case = 0
    for (j=1;j<=n;j++) //loop through all possible lengths
        for (i=1;i<=j;i++)//loop through all possible cutting
        {
            int temp = p[i] + r[j-i]; //calculate the price
            if (temp > r[j]) //replace max value for rod length of j
                r[j] = temp;
        }
    return r[n]; //return the max value of n, the length being searched for
}

void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list

    int price_list[11] = {0,1,5,8,9,10,17,17,20,24,30}; //declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;


    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));

    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d",&function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximun value is: %d \n", cr_recursive(p,n));
        }
        else if (function == 2)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;

            printf("The maximun value is: %d \n", cr_top_down_dp(p,n));
        }
        else if (function == 3)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;

            printf("The maximun value is: %d \n", cr_bottom_up_dp(p,n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d",&function);
    }
}
