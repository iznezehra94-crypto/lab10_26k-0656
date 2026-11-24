#include<stdio.h>

void buildScores(int change[], int score[], int i, int n, int current)
{
    if(i == n)
    {
        return;
    }
    else
    {
        current = current + change[i];
        score[i] = current;
        buildScores(change, score, i+1, n, current);
    }
}

int countLow(int score[], int n)
{
    static int count = 0;

    if(n == 0)
    {
        return count;
    }
    else
    {
        if(score[n-1] < 50)
        {
            count++;
            return countLow(score, n-1);
        }
        else
        {
            return countLow(score, n-1);
        }
    }
}

void reverse(int arr[], int left, int right)
{
    int temp;
    if(left >= right)
    {
        return;
    }
    else
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
        reverse(arr, left, right);
    }
}

int main()
{
    int start = 70;
    int change[10] = {5, -8, -10, -12, 4, 6, 3, 7, -2, 5};
    int i;
    int score[10];

    buildScores(change, score, 0, 10, start);

    printf("Daily scores: ");

    for(i=0; i<10; i++)
    {
        printf("%d ", score[i]);
    }
    printf("\n");

    printf("Days below 50: %d\n",countLow(score, 10));
    printf("Latest first: ");
    
    reverse(score, 0, 9);

    for(i=0; i<10; i++)
    {
        printf("%d ", score[i]);
    }
    return 0;
}