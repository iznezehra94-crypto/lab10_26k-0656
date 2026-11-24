
#include<stdio.h>

int main()
{
    FILE *fp;
    char category[20];
    float amount, correctAmount;
    int entryNo;

    fp = fopen("expenses.txt", "ab");

    if(fp == NULL)
    {
        printf("File could not be opened");
        return 1;
    }

    printf("Category: ");
    scanf("%19s", category);

    printf("Amount: ");
    scanf("%f", &amount);

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    fclose(fp);

    fp = fopen("expenses.txt", "rb+");

    if(fp == NULL)
    {
        printf("File could not be opened");
        return 1;
    }
    
    int i;
    float total = 0;

    fseek(fp, -2 * 23, SEEK_END);

    for(i=0; i<2; i++)
    {
    fscanf(fp, "%s %f", category, &amount);
    printf("Category: %s and Amount: %.2f\n", category, amount);
    }

    printf("Enter entry number and correct amount: ");
    scanf("%d %f", &entryNo, &correctAmount);

    fseek(fp, (entryNo -1) * 23 + 13, SEEK_SET);
    fprintf(fp,"%9.2f", correctAmount);

    rewind(fp);

    while(fscanf(fp, "%s %f", category, &amount) != EOF)
    {
        printf("%s %.2f\n", category, amount);
        total = total + amount;
    }

    printf("Total: %.2f", total);

    fclose(fp);
    
    return 0;
}
