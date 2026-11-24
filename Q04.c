#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp;

    fp = fopen("hotel.txt", "wb+");

    if(fp == NULL)
    {
        printf("File could not be opened");
        return 1;
    }

    int i, j, roomNo, nights, oldRoom, oldNights;
    int rooms[10], found = 0;

    char status, name[21], oldName[21];
    char guests[10][21], searchName[21];

    float rate, bill;

    for(i = 0; i < 10; i++)
    {
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                101 + i, 'F', "-", 0, 8000.00);
    }

    fflush(fp);

    printf("Check-in room: ");
    scanf("%d", &roomNo);

    printf("Name: ");
    scanf("%20s", name);

    printf("Nights: ");
    scanf("%d", &nights);

    if(roomNo >= 101 && roomNo <= 110)
    {
        fseek(fp, (roomNo - 101) * 39, SEEK_SET);

        fscanf(fp, "%d %c %20s %d %f",
               &oldRoom, &status, oldName, &oldNights, &rate);

        if(status == 'F')
        {
            fseek(fp, (roomNo - 101) * 39, SEEK_SET);

            fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                    roomNo, 'B', name, nights, 8000.00);

            fflush(fp);
        }
        else
        {
            printf("Room already booked.\n");
        }
    }
    else
    {
        printf("Invalid room number.\n");
    }

    rewind(fp);

    j = 0;

    for(i = 0; i < 10; i++)
    {
        fscanf(fp, "%d %c %20s %d %f",
               &roomNo, &status, name, &nights, &rate);

        if(status == 'B')
        {
            rooms[j] = roomNo;
            strcpy(guests[j], name);
            j++;
        }
    }

    printf("Search name: ");
    scanf("%20s", searchName);

    found = 0;

    for(i = 0; i < j; i++)
    {
        if(strcmp(searchName, guests[i]) == 0)
        {
            printf("%s is in room %d\n", searchName, rooms[i]);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Guest not found.\n");
    }

    printf("Check-out room: ");
    scanf("%d", &roomNo);

    if(roomNo >= 101 && roomNo <= 110)
    {
        fseek(fp, (roomNo - 101) * 39, SEEK_SET);

        fscanf(fp, "%d %c %20s %d %f",
               &oldRoom, &status, oldName, &oldNights, &rate);

        if(status == 'B')
        {
            bill = oldNights * rate;

            printf("Bill: %d x %.2f = %.2f\n",
                   oldNights, rate, bill);

            fseek(fp, (roomNo - 101) * 39, SEEK_SET);

            fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                    roomNo, 'F', "-", 0, 8000.00);

            fflush(fp);
        }
        else
        {
            printf("Room is already free.\n");
        }
    }
    else
    {
        printf("Invalid room number.\n");
    }

    fclose(fp);

    return 0;
}