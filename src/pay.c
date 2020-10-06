#include <pay.h>
#include <string.h>


int checkbalance(float old, float pay)
{
    return (old-pay);
}

int getaccounttype(float old, float pay)
 {
     int result;
     if(pay>0)
        result = (pay > old)? 0 : 1;
     else
        result = (old > 0)? 1 : -1;
    printf("\n%d",result);
    return result;
 }

   void input()
	{
	  FILE *fp=fopen("Record.txt","r");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\nCustomer no: %d",++customer.number);
	  fclose(fp);
	  printf("\nAccount number: ");
	  scanf("%d",&customer.acct_no);
	  printf("\nName: ");
	  scanf("%s",customer.name);
	  printf("\nMobile No: ");
	  scanf("%f",&customer.mobile_no);
	  printf("\nStreet: ");
	  scanf("%s",customer.street);
	  printf("\nCity: ");
	  scanf("%s",customer.city);
	  printf("\nPrevious Balance: ");
	  scanf("%f",&customer.oldbalance);
	  printf("\nCurrent Payment: ");
	  scanf("%f",&customer.payment);
	  printf("\nPayment date(mm/dd/yyyy): ");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  
	  char ch;
	  float balance;
	   do{
		printf("\nCheck Balance? ");
		ch=getchar();
	 }while(ch!='Y' && ch!='N');
	 switch(ch){
	      case 'Y':
		    balance = checkbalance(customer.oldbalance,customer.payment);
		    printf("\nCurrent Balance: %f",balance);
		    break;
          case 'N':
	        break;
	 }
	
	int result;
        do{
		printf("\nCheck Account Type? ");
		ch=getchar();
	 }while(ch!='Y' && ch!='N');
	 switch(ch){
	      case 'Y':
           	 result = getaccounttype(customer.oldbalance, customer.payment);
          	 printf("\nRESULT: %d",result);
            	 break;
              case 'N':
            	 break;
	 }
	 return;
   }


   void writefile()
   {
	  FILE *fp;
	  fp=fopen("Record.txt","a");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }

   void search()
   {
	 char ch;
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("Record.txt","r");

	 do{
		printf("\nEnter your choice: ");
		ch=getchar();
	 }while(ch!='1' && ch!='2');

	 switch(ch){
	      case '1':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    do{
			printf("\nChoose customer number: ");
			scanf("%d",&n);
			if(n<=0 || n>ts)
			printf("\nEnter valid number\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&customer,sl,1,fp);
			    output();
			}
			printf("\n\nAgain?(y/n) ");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
		    break;
	      case '2':
		    fseek(fp,0,SEEK_END);
		    tl=ftell(fp);
		    sl=sizeof(customer);
		    ts=tl/sl;
		    fseek(fp,(ts-1)*sl,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\nEnter the name: ");
			scanf("%s",nam);
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\nDoesn't exist\n");
			printf("\nAnother?(y/n) ");
			ch=getchar();
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
	 }



   void output()
	 {
	   printf("\nCustomer no  :%d\n",customer.number);
	   printf("Name 	  :%s\n",customer.name);
	   printf("Mobile no      :%f\n",customer.mobile_no);
	   printf("Account number :%d\n",customer.acct_no);
	   printf("Street         :%s\n",customer.street);
	   printf("City           :%s\n",customer.city);
	   printf("Old balance    :%f\n",customer.oldbalance);
	   printf("Current payment:%f\n",customer.payment);
	   printf("New balance    :%f\n",customer.newbalance);
	   printf("Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("Account status :");

	   switch(customer.acct_type)
	      {
	      case 'I':
		 printf("\nINSUFFICIENT BALANCE");
		 break;
	      case 'S':
		 printf("\nSUFFICIENT BALANCE");
		 break;
	      case 'N':
		 printf("\nNEGATIVE BALANCE");
		 break;
	      default:
		 printf("\nERROR");
	      }
	      return;
	   }















