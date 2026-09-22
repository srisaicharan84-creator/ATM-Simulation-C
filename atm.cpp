#include <stdio.h>
#include <stdbool.h>
int main()
{
    double BALANCE =
    1000000;
    int PASSCODE, CHOICE;
    double AMOUNT;
    int count = 0;

    char r = '$';
    bool isAuthenticated = false;
    while (!isAuthenticated)
    {
        printf("WELCOME USER!\n\n");
        printf("PLEASE ENTER YOUR SECURITY PIN--->");
        scanf("%d", &PASSCODE);
        if (PASSCODE < 100000 || PASSCODE > 999999)
        {
            printf("ERROR! THE PASSCODE MUST BE 6 DIGITED \n");
            count++;
            if (count >= 3)
            {
                printf("\nTOO MANY ATTEMPTS.\n");
                printf("YOUR CARD IS BLOCKED FOR 24 HOURS.\n");
                printf("YOU SHOULD ATTEND ENQUIRY IN YOUR HOME BRANCH AND UNBLOCK IT.\n");
                printf("OTHERWISE YOUR CARD WILL BE BLOCKED PERMANENTLY");
                return 0;
            }

            continue;
        }

        if (PASSCODE != 814315)
        {
            printf("INCORRECT PASSCODE \n");
            count++;
            printf("SESSION ENDED !\n ");
            printf("TRY AGAIN \n");

            if (count >= 3)
            {
                printf("\nTOO MANY ATTEMPTS.\n");
                printf("YOUR CARD IS BLOCKED FOR 24 HOURS.\n");
                printf("YOU SHOULD ATTEND ENQUIRY IN YOUR HOME BRANCH AND UNBLOCK IT.\n");
                printf("OTHERWISE YOUR CARD WILL BE BLOCKED PERMANENTLY");
                return 0;
            }
        }
        else
        {
            printf("LOGIN SUCCESSFUL!\n");
            isAuthenticated = true;
        }
    }

    while (true)
    {
        printf("\n\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. EXIT\nYour choice: ");
        scanf("%d", &CHOICE);

        if (CHOICE == 1)
        {
            printf("ENTER YOUR AMOUNT TO DEPOSIT--->");
            scanf("%lf", &AMOUNT);
            if (AMOUNT > 0)
            {
                BALANCE = BALANCE + AMOUNT;
                printf("YOUR CURRENT BALANCE IS--->  %lf%c\n", BALANCE, r);
                printf("THANKYOU FOR VISITING");
            }
            else
            {
                printf("PLEASE ENTER MEANINGFUL AMOUNT");
            }
        }
        else if (CHOICE == 2)
        {
            printf("ENTER AMOUNT TO BE WITHDRAW--->");
            scanf("%lf", &AMOUNT);
            if (AMOUNT > 0)
            {
                if (AMOUNT > BALANCE)
                {
                    printf("INSUFFICENT FUND");
                    printf("THANKYOU! VISIT AGAIN");
                }
                else
                {
                    printf("amount entered---> %lf\n", AMOUNT);
                    printf("COLLECT YOUR CASH\n");
                    BALANCE = BALANCE - AMOUNT;
                    printf("YOUR CURRENT BALANCE IN YOUR ACCOUNT AFTER WITHDRAWL IS---> %lf%c", BALANCE, r);
                }
            }
            else
            {
                printf("PLEASE ENTER MEANINGFUL AMOUNT");
            }
        }
        else if (CHOICE == 3)
        {
            printf("YOUR CURRENT BALANCE IS %lf%c", BALANCE, r);
        }
        else if (CHOICE == 4)
        {
            printf("THANKYOU");
            break;
        }
        else
        {
            printf("INVALID CHOICE !\n");
        }
    }

    printf("\n SESSION ENDED\n ");
    printf("HAVE A GREAT DAY\n");
    printf("THANKYOU");
}