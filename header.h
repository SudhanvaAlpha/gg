//supplier, customer, order, warehouse, item, record
typedef struct item
{
	int price;
	int id ;
	int count;
}item;
typedef struct supplier
{
	int id;
	char name[30];
	long int phone;
	item *items ;
}supplier;
typedef struct customer
{
	int id;
	char name[30];
	long int phone;
	char shipping[100];
}customer;
typedef struct order
{
	int id;
	char item_ids[1000];//Variable Size, max? value
	int codt;
	int lead_time;
	double cost;
	double tax;//outgoing?
	int day;
	int month;
	int year;
}order;
typedef struct warehouse
{
	int id;
	int max_capacity;
	int current_capacity;
	item items[100];
}warehouse;
//report with time duration

typedef struct record
{
	int record_type;//-1,0,1 incomng, containing, outgoing
	int supplier_id;//-1
	int customer_id;//-1
	int order_id;//-1
	int warehouse_id;
	int day;
	int month;
	int year;
}record;
/*typedef struct company
{
	int no_of_warehouses;
	typedef struct warehouse[100];//change, dynamic
	typedef struct item[1000];
	typedef struct supplier[100];
	typedef struct customer[100];
	typedef struct order[100];
}company;*/