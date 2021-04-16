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
FILE *fp;
void add_new_cont(){
    fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName (Use identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");
            scanf("%lld",&list.phone_number);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
}
