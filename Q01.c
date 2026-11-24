#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("items.txt","wb");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }

    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);

    fclose(fp);

    int itemNo, quantity;
    float totalBill=0;
    int fileItemNo, stock;
    char name[20];
    float price, amount;

    fp = fopen("items.txt","rb+");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }

    while(1)
    {
        printf("Enter item number: ");
        scanf("%d", &itemNo);

        if(itemNo == 0)
        break;
        if(itemNo < 1 || itemNo > 5)
        {
           printf("Invalid item number\n");
           continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        fseek(fp, (itemNo - 1) * 42, SEEK_SET);

        fscanf(fp, "%d", &fileItemNo);
        fscanf(fp, "%s", name);
        fscanf(fp, "%f", &price); 
        fscanf(fp, "%d", &stock);

        if(stock >= quantity)
       {
          amount = quantity * price;
          totalBill = totalBill + amount;

          stock = stock - quantity;

          printf("%s %d x %.2f = %.2f\n", name, quantity, price, amount);

          fseek(fp, (itemNo - 1) * 42, SEEK_SET);

          fprintf(fp, "%-4d %-20s %9.2f %5d\n", fileItemNo, name, price, stock);
       }
       else
       {
         printf("Only %d %s in stock\n", stock, name);
       }
    }

    printf("Total Bill: %.2f", totalBill);

    fclose(fp);
  
    return 0;
}