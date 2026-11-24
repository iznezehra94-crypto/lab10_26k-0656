#include<stdio.h>

void grow(int heights[], int n)
{
    if(n == 0)
    {
        return;
    }
    else
    {
       heights[n-1] = heights[n-1] + (int)(heights[n-1] * 0.10);
       grow(heights, n-1);
    }
}

int tallest(int heights[], int n)
{
    int pos;

    if(n == 1)
    {
        return 0;
    }
    else
    {
        pos = tallest(heights, n-1);
        if(heights[n-1] > heights[pos])
        {
            return n-1;
        }
        else
        {
            return pos;
        }
  
    }
}

int search(int heights[], int n, int target)
{

    if(n == 0)
    {
        return -1;
    }
    else
    {
        if(heights[n-1] == target)
        {
            return n-1;
        }
        return search(heights, n-1, target);
    }
}
int main()
{
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};
    int i, tall, target, height;

    grow(heights, 6);

    printf("New Height: ");

    for(i=0; i<6; i++)
    {
        printf("%d ", heights[i]);
    }
    tall = tallest(heights, 6);

    printf("\nTallest: tower %d (%d m).\n", ids[tall], heights[tall]);

    printf("Enter height wich you want to find: ");
    scanf("%d", &height);
    printf("\n");

    target = search(heights, 6, height);

    if(target == -1)
    {
        printf("Tower not found.\n");
    }
    else
    {
        printf("Tower %d is %d m.", ids[target], heights[target]);
    }
    return 0;
}