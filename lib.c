#include<stdio.h>
#include<stdlib.h>
#include "header.h"

/*void removeitem(warehouse *Warehouses[],int warehouse_id, int item_id ,int count)
{
	int j;
	warehouse W;
	while(j<50)
	{
		if (Warehouses[j]->id== warehouse_id)
		{
			W=*Warehouses[j]; 
		}
		else
		{
			printf("invalid warehouse\n");
			return;
		}
	}
	
	for (int i = 0; i <W.max_capacity; ++i)
	{
		 if(W.items[i].id == item_id)
		 {
		 	if(Warehouses[j]->items[i].count> count )
		 		Warehouses[j]->items[i].count= Warehouses[j]->items[i].count - count ;
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


void additem(warehouse *Warehouses[] ,int warehouse_id,int item_id ,int count)
{
	int j;
	warehouse W;
	while(j<50)
	{
		if (Warehouses[j]->id== warehouse_id)
		{
			W=*Warehouses[j]; 
		}
		else
		{
			printf("invalid warehouse\n");
			return;
		}
	}
	
	for (int i = 0; i <W.max_capacity; ++i)
	{
		 if(W.items[i].id == item_id)
		 {
		 	Warehouses[j]->items[i].count= Warehouses[j]->items[i].count + count ;
		 }
		 else
		 {
		 	printf("item not found\n");
		 } 

	}



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


void  procure(supplier *suppliers[] ,int *item_ids)
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

void daily(record *records[],int warehouse_id, int day, int month, int year)
{
	int n = sizeof(*records);
	for(int i=0;i<n;i++)
	{
		if(records[i]->warehouse_id==warehouse_id)
		{
			if(records[i]->day==day &&records[i]->month==month)
			{
				if(records[i]->year==year)
					{printf("%d %d %d", records[i]->warehouse_id , records[i]->order_id, records[i]->customer_id);}
			}
		}
	}
}


void monthly(record *records[],int warehouse_id, int month, int year)
{
	int n = sizeof(*records);
	for(int i=0;i<n;i++)
	{
		if(records[i]->warehouse_id==warehouse_id)
		{
			if(records[i]->month==month)
			{
				if(records[i]->year==year)
					{printf("%d %d %d", records[i]->warehouse_id , records[i]->order_id, records[i]->customer_id);}
			}
		}
	}
}*/

