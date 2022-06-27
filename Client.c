#include "Client.h"
void createClientTree(CLIENT_LIST *p)
{
    p=NULL;
}
CLIENT zeroCos()
{
    /* THIS FUNC INITIATE A EMPTY CLIENT */
   CLIENT c;
  c.name=(char*)malloc(1);
    c.lastName=(char*)malloc(1);
   strcpy(c.rentCarNum,"0");
   c.id =0;
   c.rentPrice=0;
   strcpy(c.name,"0");
   strcpy(c.lastName,"0");
   strcpy(c.rentTime,"0");
   strcpy(c.rentDate,"0");
   return c;
}
CLIENT newClient()
{
    /* THIS FUNCTION CHECK'S ALL THE REQUIERMENTS TO CONFIRM OR DECLINE IF ITS A GOOD CAR PARAMETERS FROM THE USER */
    CLIENT c;
    long id,rentPrice;
    char name[255],lastName[255],rentDate[10],rentTime[5],rentCarNum[7];
    puts("\nTHE NEW Client\n");
    printf("please enter a name : \n ");
    scanf("%s",name );
    c.name=(char*)malloc(strlen(name)+1);
    if (strlen(name)>0)
    {
        strcpy(c.name,name);
    }
    else 
    {
        printf("Bad Name %s\n",name);
        return zeroCos();
    }
    printf("please enter a last name : \n");
    scanf( "%s" , lastName );
    c.lastName=(char*)malloc(strlen(lastName)+1);
    if (strlen(lastName)>0)
    {
        strcpy(c.lastName,lastName);
    }
    else 
    {
        printf("Bad last name: %s\n",name);
        return zeroCos();
    }
    printf("please enter a rent date with the format DD/MM/YYYY : \n");
    scanf( "%s" , rentDate );
    c.rentDate=(char*)malloc(strlen(rentDate)+1);
    if (checkDate(rentDate))
    {
        strcpy(c.rentDate,rentDate);
    }
    else 
    {
        printf("with the Costumer %s ,Bad rent Date platform: %s\nClient not added\n",name,rentDate);
        return zeroCos();
    }
    printf("please enter a rent time with the format HR:MN : \n");
    scanf( "%s" , rentTime );
    if (checkTime(rentTime))
    {
        strcpy(c.rentTime,rentTime);
    }
    else 
    {
        printf("with the Costumer %s ,Bad rent Time platform: %s\nClient not added\n",name,rentTime);
        return zeroCos();
    }   
    printf("please enter a rent car number : \n");
    scanf( "%s" , rentCarNum );
    if(strlen(rentCarNum)==7&&isNumbers(rentCarNum))
    {
        strcpy(c.rentCarNum,rentCarNum);
    }
    else
    {
    printf("bad rentCarNum %s\nthe client is not added",name);
    return zeroCos();
    }
    printf("please enter a id : \n");
    scanf("%ld",&id);
    if(isNineDigitNum(id))
    {
        c.id=id;
    }
    else
    {
    printf("bad id %s\nthe client is not added\n",name);
    return zeroCos();
    }
    printf("please enter a rent price : \n");
    scanf("%ld",&rentPrice);
    if(isThreeDigitNum(rentPrice))
    {
        c.rentPrice=rentPrice;
    }
    else
    {
    printf("bad rentPrice %s\nthe client is not added\n",name);
    return zeroCos();
    }
    
    return c;  
}

void insert_Client(CLIENT_LIST **tree, CLIENT_LIST *temp)
{
   if(temp->Client.id==0)
   return;
    if(!(*tree))
    {
        *tree = temp;
        return;
    }

    if(temp->Client.id < (*tree)->Client.id)
    {
        insert_Client(&(*tree)->left, temp);
    }
    else if(temp->Client.id >= (*tree)->Client.id)
    {
        insert_Client(&(*tree)->right, temp);
    }


}
int addNewClient(CLIENT_LIST **tree)
{
    CLIENT_LIST *new_node=(CLIENT_LIST*)malloc(sizeof(CLIENT_LIST));
    new_node->Client = newClient();
    new_node->left = new_node->right = NULL;
   insert_Client(tree,new_node);
   return 1;
}
CLIENT_LIST* minValueNode_Client(CLIENT_LIST* node)
{
    CLIENT_LIST* current = node;
 
    
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
CLIENT_LIST* deleteClient(CLIENT_LIST *root, long key)
{
   
    if (root == NULL)
    {
          
        return root;
    }
 
    
    if (key<root->Client.id)
    {
        
        root->left = deleteClient(root->left, key);
    }
    
 
    else if (key>root->Client.id)
    {
          
        root->right = deleteClient(root->right, key);
    }
 

    else {
     
        if (root->left == NULL) {
           
            CLIENT_LIST *temp = root->right;
            printf("Deleting node: %ld\n", root->Client.id);
            free(root);
            return temp;
        }
        else if (root->right == NULL) { 
            
            CLIENT_LIST *temp = root->left;
            printf("Deleting node: %ld\n", root->Client.id);
            free(root);
            return temp;
        }
    else
    {
        
        CLIENT_LIST* temp = minValueNode_Client(root->right);
    
        strcpy(root->Client.name,temp->Client.name);
        strcpy(root->Client.lastName,temp->Client.lastName);
        strcpy(root->Client.rentCarNum,temp->Client.rentCarNum);
        strcpy(root->Client.rentDate,temp->Client.rentDate);
        strcpy(root->Client.rentTime,temp->Client.rentTime);
        root->Client.id=temp->Client.id;
        root->Client.rentPrice=temp->Client.rentPrice;
        
        root->right = deleteClient(root->right, temp->Client.id);
    }
    }
    return root;
}
void delete_rec_Client(CLIENT_LIST *tree)
{
    if (tree == NULL) 
     return;
    delete_rec_Client(tree->left);
    delete_rec_Client(tree->right);
    printf("Deleting node: %ld\n", tree->Client.id);
    free(tree);
}
bool deleteAllClients(CLIENT_LIST **tree)
{
     delete_rec_Client(*tree);
     *tree=NULL;
     printf("Deleting done\n");
     return true;
}

void printClientCarsForGivenRentDate_rec(CLIENT_LIST *tree,char date[])
{
    if(!tree)
    return ;
if(tree)
{
    if(strcmp(tree->Client.rentDate,date)==0)
    {

    printf("id : %ld\n",tree->Client.id);
    printf("name : %s\n",tree->Client.name);
    printf("rent car num : %s\n\n",tree->Client.rentCarNum);
    }
    printClientCarsForGivenRentDate_rec(tree->left,date);
    printClientCarsForGivenRentDate_rec(tree->right,date);
    

}
}
void printClientCarsForGivenRentDate(CLIENT_LIST *tree)
{
 CLIENT_LIST *cur=&(*tree);
    char date[20];
    puts("enter a date by the right format dd/mm/yyyy\n");
    scanf("%s",date);
    printClientCarsForGivenRentDate_rec(cur,date);
   
}

int addNewClientLink(CLIENT_LINK **head_ref,CLIENT c)
{
    CLIENT_LINK* current;
    CLIENT_LINK *new_node=(CLIENT_LINK*)malloc(sizeof(CLIENT_LINK));
     new_node->Client.name=(char*)malloc(strlen(c.name)+1);
     new_node->Client.lastName=(char*)malloc(strlen(c.lastName)+1);
     new_node->Client.rentDate=(char*)malloc(strlen(c.rentDate)+1);
    
     new_node->next=NULL;
    strcpy(new_node->Client.name,c.name);
    strcpy(new_node->Client.rentCarNum,c.rentCarNum);
    strcpy(new_node->Client.rentDate,c.rentDate);
    strcpy(new_node->Client.lastName,c.lastName);
    strcpy(new_node->Client.rentTime,c.rentTime);
    new_node->Client.id=c.id;
    new_node->Client.rentPrice=c.rentPrice;

        current = *head_ref;
        if(current==NULL)
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        return 1;
        }
       
        while (current->next != NULL&&current->Client.id<=c.id) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        return 1;
    }

CLIENT_LINK* findClientById(CLIENT_LIST *tree,long id,CLIENT_LINK *head)
{

if(tree==NULL)
{
 return head;
}
if(tree->Client.id>id)
    {
    return findClientById(tree->left,id,head);
    }
else if(tree->Client.id<id)
    {
    return findClientById(tree->right,id,head);
    }
else
    {
    addNewClientLink(&head,tree->Client);
    return findClientById(tree->right,id,head);
    }
}
CLIENT_LINK* findClientByDate(CLIENT_LIST *tree,char date[],CLIENT_LINK *head)
{

if(tree)
{
if(strcmp(date,tree->Client.rentDate)==0)
{
 addNewClientLink(&head,tree->Client);
}
 findClientByDate(tree->left,date,head);
 findClientByDate(tree->right,date,head);
}
return head;
}
CLIENT_LINK* findClient(CLIENT_LIST *tree,CLIENT_LINK *p,char *date,long id,int flag)
{
if(flag==1)
p=findClientById(tree,id,p);
else
p=findClientByDate(tree,date,p);
return p;
}