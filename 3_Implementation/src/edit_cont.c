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
void edit_cont()
{
 fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%lld",&list.phone_number);
        fflush(stdin);
        printf("..::address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
}
        
