#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



typedef struct company
{
  int no_of_warehouses;
  //typedef struct warehouse[100];//change, dynamic
  //typedef struct item[1000];
  //typedef struct supplier[100];
  //typedef struct customer[100];
  //typedef struct order[100];
} company;



void removeitem(warehouse *Warehouses,int warehouse_id, int item_id ,int count)
{
	int j=0;
	warehouse W;
	int flagw=0;
	while(j<2)
	{
		if (Warehouses[j].id== warehouse_id)
		{
			W=Warehouses[j];
			flagw=1;
			break;
		}
		
		j++;
	}
	if(!flagw)
		{
			printf("invalid warehouse\n");
			return;
		}
	
	for (int i = 0; i <W.max_capacity; ++i)
	{
		 if(W.items[i].id == item_id)
		 {
		 	if(Warehouses[j].items[i].count> count )
		 		Warehouses[j].items[i].count= Warehouses[j].items[i].count - count ;
		 	else
		 	{
		 		printf("not enough stock\n");
		 		return;
		 	}
		 	
		 }
		 else
		 {
		 	printf("item not found\n");
		 } 

	}



}


void additem(warehouse* Warehouses ,int warehouse_id,int item_id ,int count)
{
	int j=0;
	warehouse W;
	int flagw=0;
	while(j<2)
	{
		if (Warehouses[j].id== warehouse_id)
		{
			W=Warehouses[j];
			flagw=1;
			break;
		}
		
		j++;
	}
	if(!flagw)
		{
			printf("invalid warehouse\n");
			return;
		}
	
	printf("j:%d",j);
	int flag=0;
	for(int i=0;i<W.max_capacity;i++)
	{
		if(W.items[i].id == item_id)
		 {
		 	Warehouses[j].items[i].count= Warehouses[j].items[i].count + count ;
			flag=1;
			break;
		 }
		
	}
	if(!flag)
		printf("item not found\n");
	
	
	
	
	
	



}

int itemexists(supplier s, int id)
{
	int res =0 ;
	item *items= s.items;
	int i=0 ;
	int n = sizeof(s);
	while(i<n)
	{
		if(items[i].id == id)
			res= id;
		i+=1;
	}
	return res;
}


void  procure(supplier* suppliers[] ,int *item_ids)
{
	int n= sizeof(item_ids);
	for(int i=0;i<n;i++)
	{	int minprice = 10000000;  
		int minid= 0; 
		int j=0;
		int n = sizeof(*suppliers);
		while(j<n)
		{ 
			if(itemexists(*suppliers[j],item_ids[i]) )
				{
					int iid= itemexists(*suppliers[j],item_ids[i]);
					if( suppliers[j]->items[iid].price<minprice)
					{
						minprice = suppliers[j]->items[iid].price;
						minid = j; 
					}
				}
				
			j+=1;
		}			
		printf("%s %d %d \n",suppliers[minid]->name, item_ids[i], minprice );
	}	
}

void daily(record* records,int warehouse_id, int day, int month, int year)
{
	int n = sizeof(*records);
	for(int i=0;i<n;i++)
	{
		if(records[i].warehouse_id==warehouse_id)
		{
			if(records[i].day==day &&records[i].month==month)
			{
				if(records[i].year==year)
					{printf("%d %d %d", records[i].warehouse_id , records[i].order_id, records[i].customer_id);}
			}
		}
	}
}


void monthly(record *records,int warehouse_id, int month, int year)
{
	int n = sizeof(*records);
	for(int i=0;i<n;i++)
	{
		if(records[i].warehouse_id==warehouse_id)
		{
			if(records[i].month==month)
			{
				if(records[i].year==year)
					{printf("%d %d %d", records[i].warehouse_id , records[i].order_id, records[i].customer_id);}
			}
		}
	}
}







/*char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       fseek(handler, 0, SEEK_END);
       string_size = ftell(handler);
       rewind(handler);
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );
       read_size = fread(buffer, sizeof(char), string_size, handler);
       buffer[string_size] = '\0';
       if (string_size != read_size)
       {
           free(buffer);
           buffer = NULL;
       }
       fclose(handler);
    }
    return buffer;
}*/

/*void populateWfromFile(struct warehouse *w, int *c)
{
    int N = *c;//100 warehouses
    char **array = (char**) malloc((N+1)*sizeof(char*));
    char *string = ReadFile("warehouse.txt");
    //printf("%s\n", string);
    int i=0;

    if (string)
    {
        char * pch;
        pch = strtok (string,"--");
        while (pch != NULL)
        {
          //printf ("%s",pch);
          array[i]=pch;
          pch = strtok (NULL, "--");
          i++;
        }
        i--;
        //printf("%s\n", array[1]);
        int count = i;
        *c = count;
        int j =0;
        for(i = 0; i < count; i++)
        {
          char * pch;
          char **array2 = (char**) malloc((N+1)*sizeof(char*));
          //printf("%s\n", array[i]);
          pch = strtok(array[i],"\n");
          j = 0;
          while (pch != NULL)
          {
            array2[j]=pch;
            pch = strtok (NULL, "\n");
            j++;
          }
          int k = j;
          j = 0;
          while(j<k)
          {
            //printf("%s\n", array2[j]);
            j++;
          }
          j=0;

          w[i].id = atoi(array2[0]);
          w[i].location = atoi(array2[1]);
          w[i].max_capacity = atoi(array2[2]);
          w[i].current_capacity = atoi(array2[3]);
          w[i].operating_cost = atoi(array2[4]);
          w[i].work_start = atoi(array2[5]);
          w[i].work_end = atoi(array2[6]);
          w[i].number_of_shifts = atoi(array2[7]);
          w[i].meets_demand = atoi(array2[8]);
          pch = strtok(array2[9],",");
          j = 0;
          w[i].item_ids = (char**)malloc((w[i].max_capacity+2)*sizeof(char*));
          while (pch != NULL)
          {
            w[i].item_ids[j]=pch;
            pch = strtok (NULL, ",");
            j++;
          }
          w[i].current_capacity = j;
          pch = strtok(array2[10],",");
          j = 0;
          w[i].item_demand = (char**)malloc((w[i].max_capacity+2)*sizeof(char*));
          while (pch != NULL)
          {
            w[i].item_demand[j]=pch;
            pch = strtok (NULL, ",");
            j++;
          }
          j=0;
          //Print
          printf("%d\n", w[i].id);
          printf("%s\n", w[i].location);
          printf("%d\n", w[i].max_capacity);
          printf("%d\n", w[i].current_capacity);
          printf("%d\n", w[i].operating_cost);
          printf("%d\n", w[i].work_start);
          printf("%d\n", w[i].work_end);
          printf("%d\n", w[i].number_of_shifts);
          printf("%d\n", w[i].meets_demand);
          for(j=0;j<w[i].current_capacity;j++)
          {
            printf("%.*s,", (int)strlen(w[i].item_ids[j]), w[i].item_ids[j]);
          }
          printf("\n");
          for(j=0;j<w[i].current_capacity;j++)
          {
            printf("%.*s,", (int)strlen(w[i].item_demand[j]), w[i].item_demand[j]);
          }
          printf("\n");
          
          free(array2);
        }
    }
    //free(array);
    //free(string);
}*/






int umenu()
{
	int ch;
	printf("Enter 1 to buy Items\n");
	printf("%s\n", "Enter 2 to remove/sell Items");
	printf("%s\n", "Enter 3 to get a list of current Items");//Sorted
	//printf("%s\n", "Days Report");
	//printf("%s\n", "Monthly Report");
	//printf("%s\n", "Quarterly and Anual Report");
	scanf("%d", &ch);
	return ch;
}







/*void modifyW(struct warehouse *w,struct warehouse *wm)
{
	

}*/

/*void writeWtoFile(struct warehouse *w, int *c)
{
   FILE * fp;
   int i,j;
   fp = fopen ("warehouse.txt","w");
   int N = *c;
   fprintf (fp, "--\n");
   for(i=0;i<N;i++)
   {
     fprintf (fp, "%d\n",w[i].id);
     fprintf (fp, "%s\n",w[i].location);
     fprintf (fp, "%d\n",w[i].max_capacity);
     fprintf (fp, "%d\n",w[i].current_capacity);
     fprintf (fp, "%d\n",w[i].operating_cost);
     fprintf (fp, "%d\n",w[i].work_start);
     fprintf (fp, "%d\n",w[i].work_end);
     fprintf (fp, "%d\n",w[i].number_of_shifts);
     fprintf (fp, "%d\n",w[i].meets_demand);
     for(j=0;j<w[i].current_capacity;j++)
     {
      fprintf (fp, "%s,",w[i].item_ids[j]);
     }
     fprintf (fp, "\n");
     for(j=0;j<w[i].current_capacity;j++)
     {
      fprintf (fp, "%s,",w[i].item_demand[j]);
     }
     fprintf (fp, "\n");
     fprintf (fp, "--\n");
   }
   fclose (fp);
}*/

int main()
{
	int sel = umenu();
    struct company c;
    c.no_of_warehouses = 100;
    struct warehouse* w=malloc(sizeof(warehouse)*100);
    struct warehouse wm;
    //printf("%d\n", c.no_of_warehouses);
    //populateWfromFile(w,&c.no_of_warehouses);
    //printf("%d\n", c.no_of_warehouses);
	int i=0;
	w[i].id = 1;
    w[i].max_capacity = 100;
    w[i].current_capacity =2;
	//w[i].items=
	w[i].items[0].price=456;
	w[i].items[0].id=44;
	w[i].items[0].count=4;
	w[i].items[1].price=456;
	w[i].items[1].id=45;
	w[i].items[1].count=4;
	i=1;
	w[i].id = 2;
    w[i].max_capacity = 100;
    w[i].current_capacity =2;
	w[i].items[0].price=345;
	w[i].items[0].id=46;
	w[i].items[0].count=6;
	w[i].items[1].price=3443;
	w[i].items[1].id=47;
	w[i].items[1].count=7;
	//struct warehouse** ware=&w;
	
	
	
	
	
	
	record *Records=malloc(sizeof(record)*100);
	
	
	Records[0].record_type=45;//-1,0,1 incomng, containing, outgoing
	Records[0].supplier_id=54;//-1
	Records[0].customer_id=46;//-1
	Records[0].order_id=43;
	Records[0].warehouse_id=454;
	Records[0].day=30;
	Records[0].month=5;
	Records[0].year=2019;
	Records[1].record_type=32;//-1,0,1 incomng, containing, outgoing
	Records[1].supplier_id=53;//-1
	Records[1].customer_id=23;//-1
	Records[1].order_id=32;
	Records[1].warehouse_id=324;
	Records[1].day=23;
	Records[1].month=5;
	Records[1].year=2019;
	//record** Rec=&Records;

    int did;
    int j,k;
    if(sel == 1)
    {
		printf("Enter WAREHOUSE ID\n");
		scanf("%d",&did);
		printf("Enter ITEM ID\n");
		scanf("%d",&i);
		printf("Enter COUNT\n");
		scanf("%d",&j);
		additem(w,did,i,j);
	}
	if(sel == 2)
    {
    	printf("Enter WAREHOUSE ID\n");
		scanf("%d",&did);
		printf("Enter ITEM ID\n");
		scanf("%d",&i);
		printf("Enter COUNT\n");
		scanf("%d",&j);
		removeitem(w,did,i,j);
    }
    if(sel == 3)
    {
    	printf("%s\n", "Enter Department ID:");
    	scanf("%d", &did);
    	for(i == 0; i < c.no_of_warehouses; i++)
    	{
    		if(did == w[i].id)
    		{
    			printf("%s\n", "Item IDs:");
    			for(j == 0; j < w[i].current_capacity; j++)
    			{
    				printf("%s\n", w[i].items[j].id);
    			}
    		}
    	}
    }
	
	if(sel==4)
	{
		printf("Enter WAREHOUSE ID\n");
		scanf("%d",&did);
		printf("Enter the DAY\n");
		scanf("%d",&i);
		printf("Enter the MONTH\n");
		scanf("%d",&j);
		printf("Enter the YEAR\n");
		scanf("%d",&k);
		daily(Records,did,i,j,k);
	}
	if(sel==5)
	{
		printf("Enter WAREHOUSE ID\n");
		scanf("%d",&did);
		printf("Enter the MONTH\n");
		scanf("%d",&j);
		printf("Enter the YEAR\n");
		scanf("%d",&k);
		monthly(Records,did,j,k);
	}


    //modifyW(w,&w[1]);//w,&wm
    //writeWtoFile(w,&c.no_of_warehouses);
    //printf("%d\n", c.no_of_warehouses);
    return 0;
}

