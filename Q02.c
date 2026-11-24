#include<stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("attendance.txt", "wb");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }

    fprintf(fp, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fp, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fp, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fp, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fp, "%-3d %-15s %3d\n", 5, "Zainab", 16);

    fclose(fp);

    fp = fopen("attendance.txt", "rb+");

    if(fp == NULL)
    {
      printf("File could not be opened");
      return 1;
    }
    int rollNo, lecture, recordRoll, lectureAdd;
    char name[20];
    float per;

    printf("Enter roll number: ");
    scanf("%d", &rollNo);

    fseek(fp,  (rollNo - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &recordRoll, name, &lecture);

    per = (lecture/20.0) * 100;

    if(per >= 75)
    {
        printf("\n%s: %d/20  (%.1f%%)\n", name, lecture, per);
    }
    else
    {
        printf("%s: %d/20 (%.1f%%)\n Short Attendance.\n", name, lecture, per);
    }
    printf("Enter Roll Number ");
    scanf("%d", &recordRoll);
    printf("\nEnter number of lectures: ");
    scanf("%d", &lectureAdd);

    fseek(fp,  (recordRoll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &recordRoll, name, &lecture);

    lecture = lecture + lectureAdd;
    per = (lecture / 20.0) * 100;

    printf("\n%s: now %d / 20 (%.1f%%)\n", name, lecture, per);

    fseek(fp,  (recordRoll - 1) * 24, SEEK_SET);
    fprintf(fp, "%-3d %-15s %3d\n", recordRoll, name, lecture);

    fseek(fp, -24, SEEK_END);
    fscanf(fp, "%d %s %d", &recordRoll, name, &lecture);

    printf("\nLast record: %d %s %d\n", recordRoll, name, lecture);

    fclose(fp);

    return 0;
}