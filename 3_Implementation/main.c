/**
 * @file contact_management.c
 * @author Raghavendra A M
 * @brief The aim of the project is to store contacts with name,phone number,address and e-mail ID.
 *        The main functionalities are to add a new contact, list all contacts, search a contact, edit a contact and 
 *        delete a contact.
 * @version 0.1
 * @date 2021-04-12
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include "fun.h"
struct contact
{
    long long int phone_number;
    char name[20],add[20],email[30];
} list;

char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;

int main()
{
main:
    system("cls");    /* ************Main menu ***********************  */
    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);

    switch(ch)
    {
    case 0:
        printf("\n\n\t\tAre you sure you want to exit?");
        break;
        /* *********************Add new contacts************  */
    
    case 1:
        system("cls");
        add_new_cont();
        break;
        /* *********************list of contacts*************************  */

    case 2:
        system("cls");
        list_all_contact();
        break;
        /* *******************search contacts**********************  */

    case 3:
        system("cls");
        search_cont();
        break;
        /* *********************edit contacts************************/

    case 4:
        system("cls");
        edit_cont();
        break;
        /* ********************delete contacts**********************/

    case 5:
        system("cls");
        del_cont();
        break;

    default:
        printf("Invalid choice");
        break;
    }
    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {

    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}
