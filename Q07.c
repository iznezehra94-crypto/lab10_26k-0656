#include<stdio.h>

int finalBalance(int trans[], int n, int balance)
{
    if(n == 0)
    {
        return balance;
    }
    else
    {
    balance = balance + trans[n-1];
    return finalBalance(trans, n-1, balance);
    }
}

int totalDeposit(int trans[], int n)
{
    static int sum = 0;
    if(n == 0)
    {
        return 0;
    }
    else
    {
        if(trans[n-1] > 0)
        {
        totalDeposit(trans, n-1);
        return sum = sum + trans[n-1];;
        }
        else
        {
            return totalDeposit(trans, n-1);
        }
    }
}

int copyLarge(int trans[], int i, int n, int large[], int k)
{
    if(n == 0)
    {
        return k;
    }
    else
    {
        if(trans[n-1] <= -10000)
        {
            large[i] = trans[n-1];
            i++;
            k++;
            return copyLarge(trans, i, n-1, large, k);
            
        }
        else return copyLarge(trans, i, n-1, large, k);
    }
}

int main()
{
    int trans[7] =  {20000, -5000, -12000, 8000, -25000, -2500, 15000};
    int balance = 20000;
    int large[7];
    int count, j;

    count = copyLarge(trans, 0, 7, large, 0);
    printf("Finsl balance: %d\n", finalBalance(trans, 7, balance));
    printf("Total deposits: %d\n", totalDeposit(trans, 7));
    printf("Large withdrawls (%d):", count);

    for(j=0; j<count; j++)
    {
        printf("%d ", large[j]);
    }
    return 0;
}