#include<stdio.h>

int main()
{
	int roll_no;
	char name[50];
	int marks[5],total=0;
	int i;
	 
	 printf("enter roll number: ");
	 scanf("%d",&roll_no);
	 
	 printf("enter name: ");
	 scanf("%s",&name);
	 
	 for(i = 0; i < 5; i++) {
	 	printf("enter marks for subject %d: ", i+1);
	 	scanf("%d",&marks[i]);
	 	total += marks[i];
	 }
	 printf("n--- student details ()using Arrays) ---\n");
	 printf("Roll number: %d\n", roll_no);
	 printf("marks:");
	 for(i = 0; i < 5; i++)
	 {
	 	printf("%d ",marks[i]);
	 }
	 printf("\nTotal: %d\n", total);
	 return 0;
	 
}
