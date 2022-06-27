#include "Common.h"

int findCarByYear(CAR_LIST *c,char *carNum ,int carYear)
{
    if(c==NULL)
    return 0;
    return findCarByYear(c->left,carNum,carYear) + 
           findCarByYear(c->right,carNum,carYear) + 
          ( (strcmp(c->car.licenceNum,carNum)==0 && carYear==c->car.manufactureYear)  ? 1 : 0 );
        

}

int clientNumberWithGivenCarYear(CAR_LIST *c,CLIENT_LIST *p,long carYear)
{
  if(p==NULL)
  return 0;

  return clientNumberWithGivenCarYear(c,p->left,carYear) + 
         clientNumberWithGivenCarYear(c,p->right,carYear) +
         findCarByYear(c,p->Client.rentCarNum,carYear);
}