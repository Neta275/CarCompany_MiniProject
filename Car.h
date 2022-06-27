#ifndef CAR_H_
#define CAR_H_
#include "Requirments.h"
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
typedef struct
{
    long shieldNum,
        manufactureYear,
        onRoadYear,
        engine,
        supplyPrice,
        curPrice;

    char *manufactureName,
         *modelName,
         *color;

     char licenceNum[7];

}CAR;

typedef struct Car
{
    CAR car;
    struct Car *right;
    struct Car *left;

}CAR_LIST;

void createCarTree(CAR_LIST *p);
int addNewCar(CAR_LIST **p);
int carNumberWithGivenCapacity(CAR_LIST *p,long cap);
CAR_LIST* deleteCar(CAR_LIST *p,char ln[]);
bool deleteAllCars(CAR_LIST **p);

#endif