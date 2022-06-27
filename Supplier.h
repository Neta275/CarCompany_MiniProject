#ifndef SUPPLIER_H_
#define SUPPLIER_H_
#include "Requirments.h"
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
typedef struct 
{
    long sumTranNumSupplier,
         tranNumSupplier;

    char *name,
         *phone;
    char 
         allowedBusinessNum[10];
}SUPPLIER;

typedef struct SUPP 
{
    SUPPLIER Suplier;
    struct SUPP *left;
    struct SUPP *right; 

}SUPPLIER_LIST;

typedef struct 
{
     char greatest[3][11];
     int size;
     
}Greatest;

typedef struct 
{
     SUPPLIER sup[3];
     int size;
}SUPPLIER_ARR;
SUPPLIER_ARR sup;
double averageOfSupplierMoney(SUPPLIER_LIST *tree , int NumOfSupp);
void createSupplierTree(SUPPLIER_LIST *tree);
int addNewSupplier(SUPPLIER_LIST **tree);
SUPPLIER_LIST* deleteSupplier(SUPPLIER_LIST *tree,char *key);
bool deleteAllSupplier(SUPPLIER_LIST **tree);
void printSuppliers(SUPPLIER_LIST *tree);
Greatest threeGreatestSuppliers(SUPPLIER_LIST *tree,Greatest threeSup);
#endif