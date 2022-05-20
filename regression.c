//C program for 2 dimensional linear regression
#include <stdio.h>
#include <stdlib.h>

//Structure to store a single data point
struct data
{
    float x;
    float y;
};
typedef struct data data;


//Function to compute mean of independant variable data points
float mean_X(data arr[], int n)
{
    float sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=arr[i].x;
    }
    return sum/n;
}

//Function to compute mean of dependant variable data points
float mean_Y(data arr[], int n)
{
    float sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=arr[i].y;
    }
    return sum/n;
}
// This function returns the slope of the line of best fit from the given data
//If Y = b0 + b1X, evaluate_slope() returns b1
float evaluate_slope(data arr[], int n)
{
    float ss=0;
    for (int i=0;i<n;i++)
    {
        ss+=arr[i].x*arr[i].x;
    }
    float s1=0;
    for (int i=0;i<n;i++)
    {
        s1+=arr[i].x*arr[i].y;
    }


    float x = (n*s1 - n*n*mean_X(arr, n)*mean_Y(arr, n))/(n*ss - n*n*mean_X(arr, n)*mean_X(arr, n));
    return x;
}

//This function returns the intercept of the line of best fit from the given data
//If Y = b0 + b1X, evaluate_inercept() returns b0
float evaluate_intercept(data arr[], int n)
{
    float m = evaluate_slope(arr, n);
    return (mean_Y(arr, n) - m*mean_X(arr, n));
}



int main(void)
{
    //Declaring array of 5 data points
    data arr[5];                
    for (int i=0;i<5;i++)
    {
        printf("Enter value %d of x : ", i+1);
        scanf("%f", &arr[i].x);
    }
    for (int i=0;i<5;i++)
    {
        printf("Enter value %d of y : ", i+1);
        scanf("%f", &arr[i].y);
    }


   //Displaying equation of the line of best fit
   printf("Line of best fit is as follows : ");
   printf("y = %f + (%f)x\n", evaluate_intercept(arr, 5), evaluate_slope(arr, 5));

    return 0;
}