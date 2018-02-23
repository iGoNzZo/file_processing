#include <stdio.h>

void main()	{
	unsigned int account; // account number
	char name[30];
	double balance;
	
	int transaccount;
	char date[30];
	double saleAmount;
	
	int allGood = 0;
	double temp;
	double total = 0;
	
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	
	fp3 = fopen("newMaster.dat" , "w");
	
	if((fp1 = fopen("clients.dat", "r")) == NULL)	{
		puts("File could not be opened\n");
	}///end if
	else if((fp2 = fopen("trans.dat", "r")) == NULL)	{
		puts("File could not be opened");
	}
	else	{
		fscanf(fp1, "%d%s%lf", &account, name, &balance);
		fscanf(fp2, "%d%s%lf", &transaccount, date, &saleAmount);
		
		printf("%-13s%-10s%s\n", " Account", "Name", "Balance");
		while(!feof(fp2) )	{
			while(!feof(fp1)) {// && matches == 0)	{
				if(account == transaccount)	{
					allGood = 1;
					total = 0;
					temp = balance + saleAmount;
					total = total + temp;
					balance = total;
					//lastBalance = balance;
					fprintf(fp3, "%d %s %.2f\n", account, name, total);
					printf("  %-12d%-10s%.2f\n", account, name, total);
					total = 0;
				}
				else	{
					fprintf(fp3, "%d %s %.2f\n", account, name, balance);
					printf("  %-12d%-12s%.2f\n", account, name, total);
				}
				if(allGood == 0)	{
					fprintf(fp3, "%d %s %.2f\n", transaccount, date, saleAmount);
					printf("  %-12d%-12s%.2f\n", transaccount, date, saleAmount);	
					fscanf(fp2, "%d%s%lf", &transaccount, date, &saleAmount);
				}
				else	{
					fscanf(fp2, "%d%s%lf", &transaccount, date, &saleAmount);
				}
				
				fscanf(fp1, "%d%s%lf", &account, name, &balance);
				allGood = 0;
			}
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	} // end else
}
