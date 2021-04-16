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

void del_cont()
{
   fflush(stdin);
        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
}
