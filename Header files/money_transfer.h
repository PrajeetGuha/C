#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct customer
{
    char name[50];
    int acc_no;
    char acctyp[10];
    int password;
    float balance;
}; 

void atm()
{
    int ac;
    const int access = 2020;
    printf("------------No data found------------");
    printf("\n--------------Initiating setup-----------\n");
    printf("Enter access key:");
    scanf("%d",&ac);
    if (ac ==access)
    {
        system("cls");
        int i,j,n,c; 
        printf("Enter The Total Number Of customers : ");
        scanf("%d",&n);
        struct customer s[n];
        printf("\nEnter Information of customers:\n");
        for(i=0;i<n;i++)
        {
            printf("\naccno. : ");
            scanf("%d",&(s[i].acc_no));
            printf("Name : ");
            scanf(" ");
            gets((s[i].name));
            printf("\naccount type : ");
            scanf("%s",&(s[i].acctyp));
            printf("\nbalance : ");
            scanf("%f",&(s[i].balance));
            printf("Password:");
            scanf("%d",&(s[i].password));
        }
        printf("\n\nAgain give access code:");
        scanf("%d",&ac);
        if (ac != access)
        exit(0);
        system("cls");
        for (i=0;i<10;i++)
        {
            printf("\n\n--------------Loading up all the data-------------------\n\nSystem ready in:%d s",(10-i));
            printf("\a");
            for (j=0;j<=1000000000;j++);
            system("cls");

        }
        printf("\n\n");
        printf("---------ATM-----------\n");
        do
        {
            printf("Choose the option:\n\n1.Search by account number.\n2.Search by customer name.\n3.List all account details depending on account-type.\n4.Show all accounts.\n5.Deposit amount\n6.Bank Transfer\n7.Exit\n");
            scanf("%d",&c);
            printf("\n");
            switch (c)
            {
            case 1:
            {
                system("cls");
                int r;
                printf("Enter account number to search:");
                scanf("%d",&r);
                printf("\n");
                for (i=0;i<n;i++)
                {
                    if ((s[i].acc_no) == r)
                    {
                        printf("Account holder name:%s\nAccount Type:%s\nAmount in the Account:%f\n\n\n",(s[i].name),(s[i].acctyp),(s[i].balance));
                            break;
                    }
                }
                break;
            }
            
            case 2:
            {
                system("cls");
                char r[50];
                printf("Enter Account holder name to search:");
                scanf(" ");
                gets(r);
                printf("\n");
                for (i=0;i<n;i++)
                {
                    if ((strcmp(r,(s[i].name))==0))
                    {
                        printf("Account Number:%d\nAccount Type:%s\nAmount in the Account:%f\n\n\n",(s[i].acc_no),(s[i].acctyp),(s[i].balance));
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                printf("Enter access code:");
                scanf("%d",&ac);
                if (ac!=access)
                exit(0);
                system("cls");
                char r[10];
                printf("Enter Account-type:");
                scanf(" ");
                gets(r);
                printf("\n");
                for (i=0;i<n;i++)
                {
                    if ((strcmp(r,(s[i].acctyp))==0))
                    {
                        printf("Account holder name:%s\nAccount Number:%d\nAmount in the Account:%f\n\n",(s[i].name),(s[i].acc_no),(s[i].balance)); 
                    }
                }
            printf("\n");
            break;
            }

            case 4:
            {
                printf("Enter access code:");
                scanf("%d",&ac);
                if (ac!=access)
                exit(0);
                system("cls");
                for (i=0;i<n;i++)
                {
                    printf("Account holder name:%s\nAccount Number:%d\nAccount-Type:%s\nAmount in the Account:%f\n\n",(s[i].name),(s[i].acc_no),(s[i].acctyp),(s[i].balance)); 
                }
            printf("\n");
            break;
            }

            case 5:
            {
                int r;
                char c[50];
                system("cls");
                printf("Enter account number:");
                scanf("%d",&r);
                printf("Enter account holder name:");
                scanf(" ");
                gets(c);
                for (i=0;i<n;i++)
                {
                    if ((strcmp(c,(s[i].name))==0) && r==(s[i].acc_no))
                    {
                        printf("--------Match found----------\n\n");
                        int cash;
                        char sub[20];
                        printf("Ammount to deposit:");
                        scanf("%d",&cash);
                        printf("Enter subject line:");
                        scanf(" ");
                        gets(sub);
                        time_t t;
                        time(&t);
                        (s[i].balance) += cash;
                        FILE *fptr = fopen("invoice.txt","a");
                        fprintf(fptr,"\n\nDEPOSIT DETAILS:\n--------------------------------------\nAccount holder name: %s\nAccount Number: %d\nCredited: %d\nDeposited On: %s\nSubject: %s\nAccount Type: %s\nBalance: %f\n--------------------------------------",(s[i].name),(s[i].acc_no),cash,ctime(&t),sub,(s[i].acctyp),(s[i].balance));
                        fclose(fptr);
                        printf("-----Deposit Successful-----\n-------Invoice created-------\n\n");
                        break;
                    }
                    else
                    printf("------------No match found-------------");
                }
                break;

            }

            case 6:
            {
                system("cls");
                int a,c,j;
                printf("From:\n\nAccount Number:");
                scanf("%d",&a);
                for (i=0;i<n;i++)
                {
                    if (a == (s[i].acc_no))
                    {
                        printf("--------Match found----------\n\n");
                        int cash;
                        char sub[20];
                        printf("Ammount:");
                        scanf("%d",&cash);
                        if (cash > (s[i].balance))
                        {
                            printf("Ammount is more than balance in account.\n\n");
                            break;
                        }
                        else
                        {
                            system("cls");
                            printf("------------------Balance is sufficient for transaction---------------\n\n");
                            printf("Enter account number to which %d has to be transferred:",cash);
                            scanf("%d",&c);
                            for (j=0;j<n;j++)
                            {
                                if ((c == (s[j].acc_no)) && ((s[i].acc_no) != (s[j].acc_no)))
                                {
                                    printf("\n\n-------------Match found------------\n\n");
                                    char sub[20];
                                    int pass;
                                    printf("enter subject line:");
                                    scanf(" ");
                                    gets(sub);
                                    printf("Enter password:");
                                    scanf("%d",&pass);
                                    if (pass != s[i].password)
                                    exit(0);
                                    FILE *fptr = fopen("invoice.txt","a");
                                    time_t t;
                                    time(&t);
                                    (s[i].balance) -= cash;
                                    (s[j].balance) += cash;
                                    fprintf(fptr,"\n\nBANK TRANSFER DETAILS:\n--------------------------------------\nAccount holder name: %s\nAccount Number: %d\nDebited: %d\nTransfer to: %s (Acc No.: %d)\nTransfer On: %s\nSubject: %s\nAccount Type: %s\nBalance: %f\n--------------------------------------",(s[i].name),(s[i].acc_no),cash,(s[j].name),(s[j].acc_no),ctime(&t),sub,(s[i].acctyp),(s[i].balance));
                                    fclose(fptr);
                                    printf("-----Bank Transfer Successful-----\n-------Invoice created-------\n\n");
                                    break;
                                }
                                
                                
                            }
                        }
                    }
                }
                break;
            }

            case 7:
            {
                printf("GoodBye");
                break;
            }
            
            default:
            {
                printf("Wrong Choice. Try Again.\n\n");
            }
        }
        }
        while(c != 7); 

    }
    else
    {
        printf("Failed setup.");
    }
}
