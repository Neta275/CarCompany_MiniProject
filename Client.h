#ifndef CLIENT_H_
#define CLIENT_H_
#include "Requirments.h"
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
typedef struct 
{
    long id,
         rentPrice;

    char *name,
         *rentDate,
         *lastName;

    char rentCarNum[7],
         rentTime[5];
}CLIENT;

typedef struct Cli
{
    CLIENT Client;
    struct Cli *left;
    struct Cli *right; 

}CLIENT_LIST;

typedef struct Cli_l
{
    CLIENT Client;
    struct Cli_l *next;

}CLIENT_LINK;
void createClientTree(CLIENT_LIST *tree);
int addNewClient(CLIENT_LIST **tree);
CLIENT_LIST* deleteClient(CLIENT_LIST *tree,long key);
bool deleteAllClients(CLIENT_LIST **tree);
void printClientCarsForGivenRentDate(CLIENT_LIST *tree);
CLIENT_LINK* findClient(CLIENT_LIST *tree,CLIENT_LINK *p,char *date,long id,int flag);
#endif