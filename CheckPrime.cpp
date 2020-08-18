#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct _node{     
    //資料型態 變數名稱;
    int data;
    struct _node *next;
};  
typedef struct _node node;
void printreverseorder(int value){
	 	
  int i;
  node *head=NULL, *ptr;
  

for(i = 1 ; i <=value ; i++)
{
	if (value % i ==0)
	{
		 if(head==NULL){
            head = (node *)malloc(sizeof(node));
            
            ptr = head; 
            ptr->data = i;
            ptr->next = NULL;           
        }
        else{
          
 
        ptr->next = (node *)malloc(sizeof(node));
        ptr = ptr->next; 
		   ptr->data = i;  
		   ptr->next = NULL;                    
        }
        
	}
}
 
 
 ptr = head;
int factor;

    while(ptr !=NULL){
       printf("%d ", ptr->data);
        factor = ptr->data;
        bool isPrime = true;
        for (i = 2; i < factor ;i ++){
        	if(factor % i == 0) {
        		isPrime = false;
			}
		}
		if (factor == 1)
		{
			isPrime = false;
		}
		if (isPrime)
		{
			printf("P");
		}
		else{
			printf("N");
		}
		
		puts("");
		
        ptr = ptr->next;
    }
}
void printinorder(int value){
	
  int i;
  node *head=NULL, *ptr;
  

for(i = 1 ; i <=value ; i++)
{
	if (value % i ==0)
	{
		 if(head==NULL){
            head = (node *)malloc(sizeof(node));
            //printf("head => %d\n", head);
            ptr = head; 
            ptr->data = i;
            //printf("i = %d\n", i);
           // printf("head = %d\n",  ptr->data );
            ptr->next = NULL;           
        }
        else{
            head = (node *)malloc(sizeof(node));
            //printf("head => %d\n", head);
            head->data = i;
            head->next = ptr;
            ptr = head;                       
        }
        
	}
}
ptr = head;
int factor;

    while(ptr !=NULL){
        printf("%d ", ptr->data);
        factor = ptr->data;
        bool isPrime = true;
        for (i = 2; i < factor ;i ++){
        	if(factor % i == 0) {
        		isPrime = false;
			}
		}
		if (factor == 1)
		{
			isPrime = false;
		}
		if (isPrime)
		{
			printf("P");
		}
		else{
			printf("N");
		}
		
		puts("");
		
        ptr = ptr->next;
    }
    
}

int main()
{
	int value,op;
	while (1)
{
	scanf("%d", &value);
scanf("%d", &op);



switch (op){
	case 1:
		
		printreverseorder(value);
		break;
	case 2:
		printinorder(value);
		break;
	case 3:
		return 0;
		break;
}
}
return 0;
}

