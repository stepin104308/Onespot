#include <pay.h>			

void main()
	{
	  int i,n;
	  char ch;

	  printf("\nPAYMENT SYSTEM:\n");
	  printf("\n1: ADD ACOOUNT");
	  printf("\n2: SEARCH CUSTOMER");
	  printf("\n3: EXIT");

	  do{
	       printf("\nOPTION: ");
	       ch=getchar();
	  }while(ch<='0' || ch>'3');

	  switch(ch){
		case '1':

			printf("\nNO. OF ACCOUNTS: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				input();
				if(customer.payment>0)
					customer.acct_type=(customer.payment > customer.oldbalance)? 'I': 'S';
				else
					customer.acct_type=(customer.oldbalance>0)?'S' : 'N';
				customer.newbalance=customer.oldbalance - customer.payment;
				writefile();
			}
			main();
		case '2':

			printf("\nSEARCH BY? ");
			printf("\n1: Customer number");
			printf("\n2: Customer name");
			search();
			ch=getchar();
			main();
		case '3':
			exit(1);
	  }
 }





