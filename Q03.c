#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    
    fp = fopen("temperature.txt", "wb");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }

    fprintf(fp, "%-10s %5.1f\n", "Karachi", 32.5);
    fprintf(fp, "%-10s %5.1f\n", "Lahore", 30.1);
    fprintf(fp, "%-10s %5.1f\n", "Islamabad", 24.3);
    fprintf(fp, "%-10s %5.1f\n", "Quetta", 18.7);
    fprintf(fp, "%-10s %5.1f\n", "Peshawar", 28.9);

    fclose(fp);

    fp = fopen("temperature.txt", "rb+");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }
    int cityNo, i;
    char city[20], ncity[20];
    float temp, correctTemp, highest=0;

    printf("Enter city number: ");
    scanf("%d", &cityNo);

    fseek(fp, (cityNo - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f\n", city, &temp);
    printf("%s %.1f", city, temp);

    printf("\nEnter city number and correct temperature: ");
    scanf("%d %f", &cityNo, &correctTemp);
    fseek(fp, (cityNo - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", city, &temp);
    printf("%s updated to %.1f", city, correctTemp);

    fseek(fp, (cityNo - 1) * 17, SEEK_SET);
    
    fprintf(fp, "%-10s %5.1f\n", city, correctTemp);

    rewind(fp);

    for(i=0; i<5; i++)
    {
        fscanf(fp, "%s %f\n", city, &temp);
        if(highest < temp)
        {
            highest = temp;
            strcpy(ncity, city);
        }
    }
    printf("\nThe city with highest temperature is %-10s.", ncity);

    fclose(fp);

    return 0;
}