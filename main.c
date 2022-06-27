#include "Car.h"
#include "Client.h"
#include "Supplier.h"
#include "Requirments.h"
#include "Common.h"

void print_postorder(CAR_LIST * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);       
        printf("number licence : %s\n",tree->car.licenceNum);
    }
    
}

void print_postorder_client(CLIENT_LIST * tree)
{
    if (tree)
    {
        print_postorder_client(tree->left);
        print_postorder_client(tree->right);       
        printf("ID : %ld\n",tree->Client.id);
    }
    
}
void print_postorder_supplier(SUPPLIER_LIST * tree)
{
    if (tree)
    {
        print_postorder_supplier(tree->left);
        print_postorder_supplier(tree->right);       
        printf("allowed Buisness Num : %s\n",tree->Suplier.allowedBusinessNum);
    }
    
}
int numOfSupplier(SUPPLIER_LIST * tree)
{
    if (tree)
    {
      return 1+numOfSupplier(tree->left)+numOfSupplier(tree->right);       
        
    }
    return 0;
    
}
void printGreatest(Greatest three)
{
    int i,j;
     for(i=0;i<three.size;i++)
   {printf("Greatest %d : ",i+1);
    for(j=0;j<10;j++)
    {
        printf("%c",three.greatest[i][j]);
    }
    printf("\n");
   }
}
bool deleteAllClientsLink(CLIENT_LINK **p)
{
     CLIENT_LINK *prev;
    while((*p)!=NULL)
    {
        prev = (*p);
        (*p) = (*p)->next;
        free(prev); /* free old head*/
}
p=NULL;
return true;
}
void printClientLink(CLIENT_LINK *c)
{
    while(c)
    {
    printf("id : %ld\n",c->Client.id);
    printf("name : %s\n",c->Client.name);
    printf("rent car num : %s\n\n",c->Client.rentCarNum);
    c=c->next;
    }
}
int main()
{
    char delcar[7]=" ";
    char delsup[10]=" ";
    char date[10]=" ";
    int findchoose,chose,NumOfSupp,capacity,carYear,flag;
    long id,delClient;
    SUPPLIER_LIST *s=NULL;
    CAR_LIST  *p=NULL;
    CLIENT_LIST *c=NULL;
    CLIENT_LINK *clientlink=NULL;
    Greatest threeSup={{" "}};
    createCarTree(p);
    createSupplierTree(s);
    createClientTree(c);
    
        while(true)
    {
        puts("\n[----MENU----]\n");
        puts("1 - add newcar\n");
        puts("2 - add new supplier\n");
        puts("3 - add new costumer\n");
        puts("4 - three greater suppliers\n");
        puts("5 - get num of costumers by year of the car\n");
        puts("6 - get num of cars with common engine capacity\n");
        puts("7 - delete car\n");
        puts("8 - delete client\n");
        puts("9 - delete supplier\n"); 
        puts("10 - Find Clients\n"); 
        puts("11 - Get the average of suppliers money\n");
        puts("12 - print Client Cars For Given Rent Date\n");
        puts("13 - print all suppliers\n");
        puts("14 - delete all cars\n");
        puts("15 - delete all supplier\n");
        puts("16 - delete all clients\n");
        puts("17 - exit");
        scanf("%d",&chose);
        switch (chose)
        {
        case 1:addNewCar(&p);
            break;
        case 2:addNewSupplier(&s);
            break;
        case 3:addNewClient(&c);
            break;
        case 4:threeSup = threeGreatestSuppliers(s,threeSup);
                printGreatest(threeSup);
            break;
        case 5:puts("Enter the year you want to check: \n");
               scanf("%d" , &carYear);
            printf("sum of costumers with same year of car : %d\n",clientNumberWithGivenCarYear(p,c,carYear)); 
            break;
        case 6:puts("Please enter the capacity you want to check");
            scanf("%d",&capacity);
            printf("sum of cars with same engine capacity of car : %d\n", carNumberWithGivenCapacity(p,capacity));
            break;
        case 7:puts("Enter the license number of the car you want to delete");
               scanf("%s",delcar);
               p=deleteCar(p,delcar);
            break;
         case 8:puts("Enter the id of the client you want to delete");
               scanf("%ld",&delClient);
               c=deleteClient(c,delClient);
            break;
            
        case 9:puts("Enter the buisness number of the supplier you want to delete");
               scanf("%s",delsup);
                s=deleteSupplier(s,delsup);
            break;
        case 10: puts("1.Find by id\n2.Find Date\n");
                 scanf("%d",&findchoose);
                 if(findchoose==1)
                 {
                     flag=1;
                     puts("Enter a id\n");
                     scanf("%ld",&id);
                     clientlink=findClient(c,clientlink,date,id,flag);
                     printClientLink(clientlink);
                     deleteAllClientsLink(&clientlink);
                 }
                 else if(findchoose==2)
                 {
                     flag=0;
                     puts("Enter a date by this format DD/MM/YYYY\n");
                     scanf("%s",date);
                     clientlink=findClient(c,clientlink,date,id,flag);
                     printClientLink(clientlink);
                     deleteAllClientsLink(&clientlink);
                 }
                 else
                 {
                     puts("Bad Choose Return to Main Menu\n");
                 }
            break;
        case 11:
            NumOfSupp=numOfSupplier(s);
            printf("%f",averageOfSupplierMoney(s,NumOfSupp));
            break;
        case 12:printClientCarsForGivenRentDate(c);
            break;
        case 13:
                printSuppliers(s);
            break;
        case 14:puts("Starting deleting all the cars:");
            deleteAllCars(&p);
            printf("\nAll Cars were deleted\n");
            break;
        case 15:puts("Starting deleting all Suppliers");
            deleteAllSupplier(&s);
            printf("\nAll suppliers have been deleted\n");
            break;
        case 16:puts("Starting deleting all the Clients:");
            deleteAllClients(&c);
            printf("\nAll Clients have been deleted\n");
            break;
        case 17:puts("EXIT_THE_PROGREM!");
                exit(1);
            break;
        default:
        puts("bad chose please try again\n");
            break;
        }
       
    } 
    return 0;

}
