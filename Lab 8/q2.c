#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

void print_pos(int rlength, int first_cut[]){
    if (rlength==0) //if there is no length,
        return;
    int pos = first_cut[rlength]; //get the position of the first cut for the current rod length
    printf("%d ", pos); //print this position
    print_pos(rlength-pos,first_cut); //recursive call to print the remaining rod length
}

int cr_bottom_up_dp_print(int *p, int n)
{

    int i,j; //initiate the counters
    r[0] = 0;//base case

    int first_cut[n+1]; //making an array with size n+1
    for (i=0;i<=n;i++)
        first_cut[i] = 0; //array populated with zeros

    for (j=1;j<=n;j++) //iterate through all possible rod length
    {
        int pos_temp = 0; //currently the position of max value cut, which is 0 cause no cuts has been done
        for (i=1;i<=j;i++)//iterate through all possible cuts
        {
            int temp = p[i] + r[j-i]; //calculate the length
            if (temp > r[j]){ //replace the maxvalue
                pos_temp = i; //replace the best cut that would give maxvalue
                r[j] = temp; //store the maxvalue into the current value
            }
        }
        first_cut[j] = pos_temp; // stores into t he array the position of the first cut that result in max revenue for current rod length
    }

    printf("Length of each piece is:\n");
    print_pos(n,first_cut); //call the function prtin_pos
    printf("\n");
    return r[n];
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


    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
