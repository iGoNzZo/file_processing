#include <stdio.h>

void main() {
	unsigned int account, transaccount, match; // account number
	char name[30];
	double balance, saleAmount;

	FILE *fp1, *fp2, *fp3;

	fp3 = fopen("newmaster.dat", "w");

	if ((fp1 = fopen("clients.dat", "r")) == NULL) {
		puts("File could not be opened\n");
	}///end if
	else if ((fp2 = fopen("trans.dat", "r")) == NULL) {
		puts("File could not be opened");
	}
	else {
		fscanf(fp1, "%d%s%lf", &account, name, &balance);
		fscanf(fp2, "%d%lf", &transaccount, &saleAmount);

		printf("%-13s%-10s%s\n", " Account", "Name", "Balance");
		while (!feof(fp1))
		{
			while (!feof(fp2)) {// && matches == 0)	{
				if (account == transaccount)
				{
					balance += saleAmount;
				}
				fscanf(fp2, "%d%lf", &transaccount, &saleAmount);

			}
			fprintf(fp3, "%d %s %.2f\n", account, name, balance);
			printf("  %-12d%-20s%.2f\n", account, name, balance);
			fscanf(fp1, "%d%s%lf", &account, name, &balance);
			rewind(fp2);
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	} // end else
}
