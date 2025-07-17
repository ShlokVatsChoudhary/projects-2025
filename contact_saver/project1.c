#include <stdio.h>
#include <string.h>

struct info
{

    char num[999][20];
    char name[999][45];
};

int main()
{
    // variables and pointers used
    int choice;
    int quant = 0;
    struct info contact;
    FILE *fptr;
    char read;
  //displaying welcome heading
    printf("\n       CONTACT SAVER MINI SOFTWARE\n\n");
    while (1)
    { 
        // main menu displayed repeatedly unless exited..
        printf("\n\n*MENU*\n1.Add New Contact\n2.View All Contacts\n3.EXIT\nselect option number---> ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // case 1: handles the inputs of the contact details...

            fptr = fopen("contact.txt", "a");
            {
                printf("How many contact details do you want to add? (1-999)\n---> ");
                scanf("%d", &quant);

                if (quant < 1 || quant > 999) // validates contact count input
                {
                    printf("\nYou can only add upto 999 contacts or a minimum of 1 at a time...\n");
                }

                else
                    // accepts contact details...
                    for (int i = 0; i < quant; i++)
                    {
                        printf("Enter name %d: ", i + 1);
                        getchar();//clearing newline from prior scanf input...
                        fgets(contact.name[i], 45, stdin);
                        contact.name[i][strcspn(contact.name[i], "\n")] = 0;

                        printf("Enter phone number %d: ", i + 1);
                        fgets(contact.num[i], 20, stdin);

                        fprintf(fptr, "THE name of %dst contact is: %s\nThe phone number of %dst contact is: %s \n",
                                i + 1, contact.name[i], i + 1, contact.num[i]);
                        printf("Your inputs have been recorded...");
                        printf("\n\n");
                    }
                fclose(fptr);
            }

            break;

        case 2: // case 2: displays all the contact info stored...

            if (quant < 1) // checking if any contact info exists in contact.txt...
            {
                printf("\nEnter some contacts first...");
            }

            else // if atleat 1 contact info exists...
            {
                fptr = fopen("contact.txt", "r");

                printf("\nThe recorded contacts are: \n\n");

                while ((read = fgetc(fptr)) != EOF)
                {
                    putchar(read);
                }
                fclose(fptr);
            }
            break;

        case 3: // exit line. end of program...
            printf("\nTHANK YOU FOR USING OUR SERVICES\nEXITING...");
            return 0;
            break;

        default: // handles invalid menu options...
            printf("Please select from option the above mentioned options only");
            break;
        }
    }
}
