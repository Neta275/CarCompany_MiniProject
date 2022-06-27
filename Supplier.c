#include "Supplier.h"


void createSupplierTree(SUPPLIER_LIST *p)
{
    p=NULL;
}

SUPPLIER zeroSup()
{
    /* THIS FUNC INITIATE A EMPTY SUPPLIER */
   SUPPLIER s;
   s.tranNumSupplier=0;
   s.sumTranNumSupplier=0;
   s.name=(char*)malloc(1);
   s.phone=(char*)malloc(1);
   strcpy(s.allowedBusinessNum,"0000000000");
   strcpy(s.name,"0");
   strcpy(s.phone,"0");
   return s;
}

SUPPLIER newSupplier()
{
    /* THIS FUNCTION CHECK'S ALL THE REQUIERMENTS TO CONFIRM OR DECLINE IF ITS A GOOD CAR PARAMETERS FROM THE USER */
    SUPPLIER s;
    long sumTranNumSupplier;
    int tranNumSupplier;
    char supname[50],phone[20],allowedBusinessNum[50];
    printf("\nTHE NEW SUPPLIER\n");
    printf("please enter a phone :\n");
    scanf( "%s" , phone);
    s.phone=(char*)malloc(strlen(phone)+1);
     if (strlen(phone)==10&&phone[0]=='0')
    {
        strcpy(s.phone,phone);
    }
    else   
       {
        printf("bad phone %s\nthe supplier is not added",phone);
        return zeroSup();
       }    
    printf("please enter a name :\n");
    scanf( "%s" ,supname);
    s.name=(char*)malloc(strlen(supname)+1);
     if (1)
    {
        strcpy(s.name,supname);
    
    }
    else 
    {
        printf("name must to be 5 letters : %s\n",supname);
        return zeroSup();
    }
    printf("please enter a allowed Business Num : \n");
    scanf( "%s" , allowedBusinessNum );
    if (strlen(allowedBusinessNum)==10)
    {
        strcpy(s.allowedBusinessNum,allowedBusinessNum);
    }
    else   
       {
        printf("bad allowedBuisnessNum %s\nthe supplier is not added",allowedBusinessNum);
        return zeroSup();
       }
    printf("please enter a sum Tran Num Supplier : \n");
    scanf("%ld",&sumTranNumSupplier);
     if (TenDigitNum(sumTranNumSupplier)==true)
    {
        s.sumTranNumSupplier=sumTranNumSupplier;
    }
    else   
       {
        printf("bad sumTranNumSupplier %ld\nthe supplier is not added",sumTranNumSupplier);
        return zeroSup();
       }
    printf("please enter a Tran Num Supplier : \n");
    scanf("%d",&tranNumSupplier);
    if (fiveDigitNum(tranNumSupplier)==true)
    {
        s.tranNumSupplier=tranNumSupplier;
    }
    else   
       {
        printf("bad tranNumSupplier %d\nthe supplier is not added",tranNumSupplier);
        return zeroSup();
       }

       return s;
}
void insert_Supplier(SUPPLIER_LIST **tree, SUPPLIER_LIST *temp)
{
   if(temp->Suplier.sumTranNumSupplier==0)
   return;
    if(!(*tree))
    {
        *tree = temp;
        return;
    }
    if(temp->Suplier.sumTranNumSupplier< (*tree)->Suplier.sumTranNumSupplier)
    {
        insert_Supplier(&(*tree)->left, temp);
    }
    else if(temp->Suplier.sumTranNumSupplier>= (*tree)->Suplier.sumTranNumSupplier)
    {
        insert_Supplier(&(*tree)->right, temp);
    }
}

int addNewSupplier(SUPPLIER_LIST **tree)
{
    SUPPLIER_LIST *new_node=(SUPPLIER_LIST*)malloc(sizeof(SUPPLIER_LIST));
    new_node->Suplier = newSupplier();
    new_node->left = new_node->right = NULL;
   insert_Supplier(tree,new_node);
   return 1;
}


double averageOfSupplierMoney(SUPPLIER_LIST *tree , int NumOfSupp)
{

    if (tree==NULL)
    {
      return 0;
    }
    return averageOfSupplierMoney(tree->left , NumOfSupp) + averageOfSupplierMoney(tree->right , NumOfSupp) + (tree->Suplier.sumTranNumSupplier / NumOfSupp ) ;
}



void fillList(SUPPLIER_LIST *tree)
{
    int i;
   for(i=0;i<3;i++)
   sup.sup[i]=zeroSup();
   sup.size=3;
 
}
void b_sort()

{
   int i, j;
   SUPPLIER temp;
   for (i = 0; i < 2; i++)       
       for (j = 0; j < 2-i; j++)
           if (sup.sup[j].sumTranNumSupplier > sup.sup[j+1].sumTranNumSupplier)
              {
                    temp = sup.sup[j];
                    sup.sup[j] = sup.sup[j+1];
                    sup.sup[j+1] = temp;
              }
}
void addtomax(SUPPLIER p)
{
            if(p.sumTranNumSupplier>sup.sup[0].sumTranNumSupplier)
            {
            sup.sup[0]=p;
            b_sort();
            }
        
   
}
void find_max(SUPPLIER_LIST *tree)
{
    if(tree)
    {
    addtomax(tree->Suplier);
    find_max(tree->left);
    find_max(tree->right);
    }
    return ;
}
Greatest threeGreatestSuppliers(SUPPLIER_LIST *tree,Greatest threeSup)
{
    int i,j;
    
    fillList(tree);
    find_max(tree);

    for(i=0;i<3;i++)
    {
        for(j=0;j<10;j++)
        {
            threeSup.greatest[i][j]=sup.sup[i].allowedBusinessNum[j];
          
        }
        
        threeSup.greatest[i][j]='\0';
    }
    threeSup.size=sup.size;
    
    return threeSup;
}

void printSuppliers(SUPPLIER_LIST *tree)
{
     if (tree)
    {
        printSuppliers(tree->left);
        printSuppliers(tree->right);       
        printf("allowed Buisness Num : %s\n",tree->Suplier.allowedBusinessNum);
        printf("Name : %s\n",tree->Suplier.name);
        printf("Phone : %s\n",tree->Suplier.phone);
        printf("Sum Tran Num Supplier : %ld\n",tree->Suplier.sumTranNumSupplier);
        printf("Tran Num Supplier : %ld\n",tree->Suplier.tranNumSupplier);
      

    }
}

SUPPLIER_LIST* minValueNode_Supplier(SUPPLIER_LIST* node)
{
    SUPPLIER_LIST* current = node;
 
    
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
SUPPLIER_LIST* deleteSupplier(SUPPLIER_LIST *root, char *key)
{
   
    if (root == NULL)
    {
          
        return root;
    }
 
    
    if (strcmp(key,root->Suplier.allowedBusinessNum)<0)
    {
        
        root->left = deleteSupplier(root->left, key);
    }
    
 
    else if (strcmp(key,root->Suplier.allowedBusinessNum)>0)
    {
          
        root->right = deleteSupplier(root->right, key);
    }
 

    else {
     
        if (root->left == NULL) {
           
            SUPPLIER_LIST *temp = root->right;
            printf("Deleting node: %s\n", root->Suplier.allowedBusinessNum);
            free(root);
            return temp;
        }
        else if (root->right == NULL) { 
            
            SUPPLIER_LIST *temp = root->left;
            printf("Deleting node: %s\n", root->Suplier.allowedBusinessNum);
            free(root);
            return temp;
        }
    else
    {
        
        SUPPLIER_LIST* temp = minValueNode_Supplier(root->right);
    
        strcpy(root->Suplier.name,temp->Suplier.name);
        strcpy(root->Suplier.allowedBusinessNum,temp->Suplier.allowedBusinessNum);
        strcpy(root->Suplier.phone,temp->Suplier.phone);
        root->Suplier.sumTranNumSupplier=temp->Suplier.sumTranNumSupplier;
        root->Suplier.tranNumSupplier=temp->Suplier.tranNumSupplier;
        
        root->right = deleteSupplier(root->right, temp->Suplier.allowedBusinessNum);
    }
    }
    return root;
}
void delete_rec_Supplier(SUPPLIER_LIST *tree)
{
    if (tree == NULL) 
     return;
    delete_rec_Supplier(tree->left);
    delete_rec_Supplier(tree->right);
    printf("Deleting node: %s\n", tree->Suplier.allowedBusinessNum);
    free(tree);
}
bool deleteAllSupplier(SUPPLIER_LIST **tree)
{
     delete_rec_Supplier(*tree);
     *tree=NULL;
     printf("Deleting done\n");
     return true;
}
