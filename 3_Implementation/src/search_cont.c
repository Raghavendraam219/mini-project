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
void search_cont()
{
    do
        {
            found=0;
            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("contact.dll","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.phone_number,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("..::Press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\n..::No match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
}
