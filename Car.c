#include "Car.h"

void createCarTree(CAR_LIST *p)
{
    p=NULL;

}
CAR zeroCar()
{ /* THIS FUNC INITIATE A EMPTY CAR */
    CAR c;
    c.color=(char*)malloc(1);
    c.modelName=(char*)malloc(1);
    c.manufactureName=(char*)malloc(1);
    c.engine=0;
   c.manufactureYear=0;
   c.onRoadYear=0;
   c.shieldNum=0;
   c.supplyPrice=0;
   strcpy(c.licenceNum,"0");
   strcpy(c.manufactureName,"0");
   strcpy(c.color,"0");
   strcpy(c.modelName,"0");
   return c;
}
CAR newCar()

{
    /* THIS FUNCTION CHECK'S ALL THE REQUIERMENTS TO CONFIRM OR DECLINE IF ITS A GOOD CAR PARAMETERS FROM THE USER */
    long shieldNum,manufactureYear,onRoadYear,engine,supplyPrice,curPrice;
    char manufactureName[255],modelName[255],color[255],licenceNum[255];
    CAR a;
    printf("\nTHE NEW CAR\n");
    printf("please enter a licence number : \n");
    scanf( "%s" , licenceNum );
    
    if(strlen(licenceNum)==7&&isNumbers(licenceNum))
    {
        strcpy(a.licenceNum,licenceNum);
    }
    else
    {
        printf("bad licenceNum %s\nthe car is not added\n",licenceNum);
        return zeroCar();
    }
    printf("please enter a color : \n");
    scanf( "%s" , color );
    a.color=(char*)malloc(strlen(color)+1);
     if (strlen(color)>1)
    {
        strcpy(a.color,color);
    }
    else 
    {
        printf("Bad Color, Car is not added: %s\n",color);
        return zeroCar();
    }
    printf("please enter a model name : \n");
    scanf( "%s" , modelName );
    a.modelName=(char*)malloc(strlen(modelName)+1);
      if (strlen(modelName)>1)
    {
        strcpy(a.modelName,modelName);
    }
    else
    {
        printf("Bad model name , Car is not added: %s\n",modelName);
        return zeroCar();
    }
    printf("please enter a manufacturer name : \n");
    scanf( "%s" , manufactureName );
    a.manufactureName=(char*)malloc(strlen(manufactureName)+1);
     if (strlen(manufactureName)>1)
    {
         strcpy(a.manufactureName,manufactureName);
    }
    else
    {
        printf("Bad manufacture name, Car is not added : %s\n",manufactureName);
        return zeroCar();
    }
    printf("please enter a engine capacity : \n");
    scanf("%ld",&engine);
    if(fourDigitNum(engine))
    {
        a.engine=engine;
    }
    else
    {
        printf("bad engine capacity , Car is not added %ld\n",engine);
        return zeroCar();
    }
    printf("please enter a shield number : \n");
    scanf("%ld",&shieldNum);
     if(fiveDigitNum(shieldNum))
    {
        a.shieldNum=shieldNum;
    }
    else
    {
        printf("bad shieldNum %ld\nthe car is not added\n",shieldNum);
        return zeroCar();
    }
    printf("please enter a manufacture year : \n");
    scanf("%ld" , &manufactureYear);
      if(fourDigitNum(manufactureYear))
    {
        a.manufactureYear=manufactureYear;
    }
    else
    {
        printf("bad manufactureYear %ld\nthe car is not added\n",manufactureYear);
        return zeroCar();
    }
    printf("please enter a on road year : \n");
    scanf("%ld",&onRoadYear);
      if(fourDigitNum(onRoadYear))
    {
        a.onRoadYear=onRoadYear;
    }
    else
    {
        printf("bad onRoadYear %ld\nthe car is not added\n",onRoadYear);
        return zeroCar();
    }
    printf("please enter a supply price : \n");
    scanf("%ld",&supplyPrice);
     if(sevenDigitNum(supplyPrice))
    {
        a.supplyPrice=supplyPrice;
    }
    else
    {
        printf("bad supplyPrice %ld\nthe car is not added\n",supplyPrice);
        return zeroCar();
    }
    printf("please enter a cur price : \n");
    scanf("%ld",&curPrice);
     if(sevenDigitNum(curPrice))
    {
        a.curPrice=curPrice;
    }
    else
    {
        printf("bad curPrice %ld\nthe car is not added\n",curPrice);
        return zeroCar();
    }
    return a;
}
void insert(CAR_LIST **tree, CAR_LIST *temp)
{
   if(strlen(temp->car.licenceNum)!=7)
   return;
    if(!(*tree))
    {
        *tree = temp;
        return;
    }

    if(temp->car.manufactureYear < (*tree)->car.manufactureYear)
    {
        insert(&(*tree)->left, temp);
    }
    else if(temp->car.manufactureYear >= (*tree)->car.manufactureYear)
    {
        insert(&(*tree)->right, temp);
    }


}
int addNewCar(CAR_LIST **tree)
{
    CAR_LIST *new_node=(CAR_LIST*)malloc(sizeof(CAR_LIST));
    new_node->car = newCar();
    new_node->left = new_node->right = NULL;
   insert(tree,new_node);
   return 1;
}

int carNumberWithGivenCapacity(CAR_LIST *tree,long cap)
{
    if(!tree)
    return 0;
   if(tree->car.engine==cap)
       return 1+carNumberWithGivenCapacity(tree->right,cap)+carNumberWithGivenCapacity(tree->left,cap);
   else
       return 0+carNumberWithGivenCapacity(tree->right,cap)+carNumberWithGivenCapacity(tree->left,cap);
}
CAR_LIST* minValueNode(CAR_LIST* node)
{
    CAR_LIST* current = node;
 
    
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
CAR_LIST* deleteCar(CAR_LIST *root, char key[])
{
   
    if (root == NULL)
        return root;
 
    
    if (strcmp(key , root->car.licenceNum)<0)
        root->left = deleteCar(root->left, key);
 
    else if (strcmp(key,root->car.licenceNum)>0)
        root->right = deleteCar(root->right, key);
 

    else {
       
        if (root->left == NULL) {
            CAR_LIST *temp = root->right;
            printf("Deleting node: %s\n", root->car.licenceNum);
            free(root);
            return temp;
        }
        else if (root->right == NULL) { 
            CAR_LIST *temp = root->left;
            printf("Deleting node: %s\n", root->car.licenceNum);
            free(root);
            return temp;
        }
    else
    {
        CAR_LIST* temp = minValueNode(root->right);
    
        strcpy(root->car.licenceNum,temp->car.licenceNum);
        strcpy(root->car.color,temp->car.color);
        strcpy(root->car.modelName,temp->car.modelName);
        strcpy(root->car.manufactureName,temp->car.manufactureName);
        root->car.shieldNum=temp->car.shieldNum;
        root->car.manufactureYear=temp->car.manufactureYear;
        root->car.onRoadYear=temp->car.onRoadYear;
        root->car.engine= temp->car.engine;
        root->car.supplyPrice= temp->car.supplyPrice;
        root->car.curPrice= temp->car.curPrice;
        
        root->right = deleteCar(root->right, temp->car.licenceNum);
    }
    }
    return root;
}

void delete_rec(CAR_LIST *tree)
{
    if (tree == NULL) 
     return;
    delete_rec(tree->left);
    delete_rec(tree->right);
    printf("Deleting node: %s\n", tree->car.licenceNum);
    free(tree);
}
bool deleteAllCars(CAR_LIST **tree)
{
     delete_rec(*tree);
     *tree=NULL;
     printf("Deleting done\n");
     return true;
}
