#include <stdio.h>

void main()	{
	unsigned int account; // account number
	char name[30];
	char lName[30];
	double balance;
	
	FILE *fp;
	
	if((fp = fopen("trans.dat", "w")) == NULL)	{
		puts("File could not be opened/created\n");
	}///end if
	else	{
		puts("Enter the account,name, and balance.");
		puts("Enter EOF to end input.");
		printf("%s", "? ");
		scanf("%d%29s%lf", &account, name, &balance);
		
		while(!feof(stdin))	{
			fprintf(fp, "%d %s %.2f\n" , account, name, balance);
			printf("%s", "? ");
			scanf("%d%29s%lf", &account, name, &balance);
		}
		fclose(fp);// close the file
	} // end else
} // end main
