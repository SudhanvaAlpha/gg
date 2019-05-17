#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct warehouse
{
  int id;
  char* location;
  int max_capacity;
  int current_capacity;
  int operating_cost;
  int work_start;//time
  int work_end;
  int number_of_shifts;//?
  int meets_demand;//0 if even one item out of stock and demand there...?
  char** item_ids;
  char** item_demand;
  item items[];
} warehouse;

typedef struct company
{
  int no_of_warehouses;
  //typedef struct warehouse[100];//change, dynamic
  //typedef struct item[1000];
  //typedef struct supplier[100];
  //typedef struct customer[100];
  //typedef struct order[100];
} company;











char* ReadFile(char *filename)
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
}

void populateWfromFile(struct warehouse *w, int *c)
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
          w[i].location = array2[1];
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
          /*//Print
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
          */
          free(array2);
        }
    }
    //free(array);
    //free(string);
}






int umenu()
{
	int ch;
	printf("%s\n", "Enter 1 to buy Items");
	printf("%s\n", "Enter 2 to remove/sell Items");
	printf("%s\n", "Enter 3 to get a list of current Items");//Sorted
	//printf("%s\n", "Days Report");
	//printf("%s\n", "Monthly Report");
	//printf("%s\n", "Quarterly and Anual Report");
	scanf("%d", &ch);
	return ch;
}







void modifyW(struct warehouse *w,struct warehouse *wm)
{

}

void writeWtoFile(struct warehouse *w, int *c)
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
}

int main()
{
	int sel = umenu();
    struct company c;
    c.no_of_warehouses = 100;
    struct warehouse w[100];
    struct warehouse wm;
    //printf("%d\n", c.no_of_warehouses);
    populateWfromFile(w,&c.no_of_warehouses);
    //printf("%d\n", c.no_of_warehouses);

    int did;
    int i,j;
    if(sel == 1)
    {

    }
	if(sel == 2)
    {
    	
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
    				printf("%s\n", w[i].item_ids[j]);
    			}
    		}
    	}
    }


    modifyW(w,&w[1]);//w,&wm
    writeWtoFile(w,&c.no_of_warehouses);
    //printf("%d\n", c.no_of_warehouses);
    return 0;
}

