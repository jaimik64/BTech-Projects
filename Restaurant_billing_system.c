
/*
	Project : Restaurant Billing System
	Aim : Generate Bill, Display Bill. 
		  admin can add/delete particular customer and also add/delete particular food for that customer.
	
	Programmer : Jaimik Chauhan
	Roll no : 20BCE503
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GenerateBill();
void displayUsers();
void updateFoodDetails();
void addFoodItem();
int viewFood(int);
void deleteFoodItem();
void displayBill(int);

int billno = 0;

struct RBill
{
	int bill_no, total, totalItem, showStatus;
	char fname[100], lname[100], MobileNo[12];
	struct RBill *next;
	struct FoodDetails *foodData;
};

struct FoodDetails
{
	char food_detail[100];
	int cost, quantity, totalCost;
	struct FoodDetails *next;
};

struct RBill *first = NULL;
struct RBill *notUpdateFirst = NULL;
struct RBill *newnode = NULL;
struct RBill *temp = NULL;
struct FoodDetails *foodTemp = NULL;

/* insert data into linked list using insertion at end */
int GenerateBill()
{
	int i, totalBill = 0, iCount, bill, itemNo = 1;

	char charTemp;

	/* Create Newnode and assign size dynamically */
	newnode = (struct RBill *)malloc(sizeof(struct RBill *));
	struct FoodDetails *food = NULL;

	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("\n Enter User Details ");
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	/* Take User-name, Mobile no & no of items user ordered*/

	printf("\n\nEnter User's First Name : ");
	scanf("%s", &newnode->fname);

	printf("\n Enter User's Last Name : ");
	scanf("%s", &newnode->lname);

	printf("Enter Mobile No : ");
	scanf("%s", &newnode->MobileNo);

	printf("Enter No. Of Items User Ordered : ");
	scanf("%d", &iCount);

	/* traverse loop and insert data into food node.*/
	for (i = 0; i < iCount; i++)
	{
		char charTemp1;
		struct FoodDetails *new1 = (struct FoodDetails *)malloc(sizeof(struct FoodDetails *));

		printf("\nEnter Details For Dish - %d", (i + 1));

		printf("\nEnter Dish Name : ");
		scanf("%c", &charTemp1);
		scanf("%[^\n]", &new1->food_detail);

		printf("Enter Quantity : ");
		scanf("%d", &new1->quantity);

		printf("Enter Price Of %s : ", new1->food_detail);
		scanf("%d", &new1->cost);

		int q = new1->quantity;
		int c = new1->cost;
		int total = (q * c);

		new1->totalCost = total;
		totalBill += total;

		if (food == NULL)
		{
			food = new1;
			new1->next = food;
		}
		else
		{
			foodTemp = food;

			while (foodTemp->next != food)
			{
				foodTemp = foodTemp->next;
			}
			foodTemp->next = new1;
			new1->next = food;
		}
	}

	newnode->foodData = food;
	bill = ++billno;
	newnode->total = (totalBill + ((totalBill * 5) / 100));
	newnode->bill_no = bill;
	newnode->totalItem = iCount;

	if (first == NULL)
	{
		first = newnode;
		newnode->next = first;
		printf("\n Bill Generated");
	}
	else
	{
		temp = first;

		while (temp->next != first)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = first;
		
		printf("Bill Generated");
	}
	return iCount;
}

/* display bill of billNo*/
void displayBill(int billNo)
{

	temp = first;

	while (temp->next != first)
	{
		if (temp->bill_no == billNo)
		{
			break;
		}
		temp = temp->next;
	}

	if (temp == first && temp->bill_no != billNo)
	{
		printf("\n Bill Not Found");
	}
	else
	{

		printf("\n---------------------------------------------------------------------------------------");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n 				XYZ Restaurant(Generated Bill) ");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n---------------------------------------------------------------------------------------");
		printf("\n\nBill No : %d", temp->bill_no);
		printf("\nName : %s %s", temp->fname, temp->lname);
		printf("\nMobile No : %s", temp->MobileNo);
		printf("\n\n-------------------------------------------------------------------------------------");

		printf("\n\n			Order Details		          \n");

		printf("\n---------------------------------------------------------------------------------------");

		foodTemp = temp->foodData;

		int i, totalFoodRecords;
		totalFoodRecords = temp->totalItem;
		printf("\n No | Ordered Item			 	| Quantity | Cost | Total Cost\n");
		printf("\n---------------------------------------------------------------------------------------");

		for (i = 1; i <= totalFoodRecords; i++)
		{
			printf("\n %d |	%s		  		          	| %d	    |  %d  |  %d ", i, foodTemp->food_detail, foodTemp->quantity, foodTemp->cost, foodTemp->totalCost);
			foodTemp = foodTemp->next;
		}

		printf("\n---------------------------------------------------------------------------------------");
		printf("\n Total(Inclusive Tax) : \t %d", temp->total);

		printf("\n---------------------------------------------------------------------------------------");
		printf("\n\n		Thank You For Your Order 			\n");

		printf("\n---------------------------------------------------------------------------------------");
	}
}

/* Display Users with total bill*/
void displayUsers()
{
	if (first == NULL)
	{
		printf("\nOops!!!, You Have Not Generated Any Bill\n");
		return;
	}
	else
	{
		printf("\n---------------------------------------------------------------------------------------");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n 			XYZ Restaurant (Generated Bills)");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n---------------------------------------------------------------------------------------");

		printf("\n---------------------------------------------------------------------------------------\n");
		printf("\n| Bill No | 	Name				  |	Total Bill(Inclusive Of Tax) ");
		printf("\n---------------------------------------------------------------------------------------\n");

		temp = first;
		while (temp->next != first)
		{
			printf("\n|    %d	| 	%s  %s		 |	%d", temp->bill_no, temp->fname, temp->lname, temp->total);
			temp = temp->next;
		}

		printf("\n|    %d	| 	%s  %s		 |	%d", temp->bill_no, temp->fname, temp->lname, temp->total);
		printf("\n---------------------------------------------------------------------------------------\n");
	}
}

/* view food of particular no and return no of food_items user ordered*/
int viewFood(int no)
{
	int i = 1, totalRecord;

	temp = first;

	while (temp->next != first)
	{
		if (temp->bill_no == no)
		{
			break;
		}
		temp = temp->next;
	}

	if (temp == first && temp->bill_no != no)
	{
		printf("\n Bill Details Not Available");
		return;
	}

	if (temp->bill_no == no)
	{

		printf("\n---------------------------------------------------------------------------------------");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n 			XYZ Restaurant ");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n---------------------------------------------------------------------------------------");

		foodTemp = temp->foodData;
		totalRecord = temp->totalItem;

		printf("\n---------------------------------------------------------------------------------------");
		printf("\n			Food Details for Bill No : %d", no);
		printf("\n---------------------------------------------------------------------------------------\n");
		printf("\nNo | Dish Name		 | 	Quantity 	|	 Cost 	 | 	Total Cost ");
		printf("\n---------------------------------------------------------------------------------------\n");

		for (i = 1; i <= totalRecord; i++)
		{
			printf("\n%d |	%s			 |	%d	|	%d	|	%d	\n", i, foodTemp->food_detail, foodTemp->quantity, foodTemp->cost, foodTemp->totalCost);
			foodTemp = foodTemp->next;
		}

		printf("\n--------------------------------------------------------------------------------------\n");
	}
	return i;
}

void updateFoodDetails()
{
	int iSwitchChoice;

	printf("\n1. Add Food Item");
	printf("\n2. Delete Food Item");
	printf("\n3. Back To Menu");
	printf("\n\n Enter Choice ");
	scanf("%d", &iSwitchChoice);

	switch (iSwitchChoice)
	{
	case 1:
		addFoodItem();
		break;
	case 2:
		deleteFoodItem();
		break;
	case 3:
		break;
	default:
		printf("Enter Correct Choice");
	}
}

void addFoodItem()
{
	int billNo, total = 0, iCount, i;

	temp = first;

	printf("Enter Bill No. : ");
	scanf("%d", &billNo);

	printf("Enter No. Of Items you want to add : ");
	scanf("%d", &iCount);

	if (first->bill_no == billNo)
	{

		/* insert iCount numbers of food details in given billno */
		for (i = 0; i < iCount; i++)
		{
			struct FoodDetails *new1 = (struct FoodDetails *)malloc(sizeof(struct FoodDetails *));

			printf("\nEnter Dish Name : ");
			scanf("%s", &new1->food_detail);

			printf("Enter Quantity : ");
			scanf("%d", &new1->quantity);

			printf("Enter Price Of %s : ", new1->food_detail);
			scanf("%d", &new1->cost);

			int q = new1->quantity;
			int c = new1->cost;
			int t = (q * c);
			new1->totalCost = t;

			foodTemp = first->foodData;

			if (foodTemp == NULL)
			{
				foodTemp = new1;
				new1->next = foodTemp;
			}
			else
			{
				struct FoodDetails *temp1;
				temp1 = first->foodData;

				while(temp1->next != foodTemp){
					temp1 = temp1->next;
				}
				temp1->next = new1;
				new1->next = foodTemp;
			}
			first->totalItem = (first->totalItem + 1);
		}
		/* update Food details*/
		foodTemp = first->foodData;

		while (foodTemp->next != first->foodData)
		{
			total += foodTemp->totalCost;
			foodTemp = foodTemp->next;
		}
		total += foodTemp->totalCost;
		first->total = (total + ((total * 5) / 100));
	}
	else
	{
		/* Search bill no */
		while (temp->next != first)
		{
			if (temp->bill_no == billNo)
			{
				break;
			}
			temp = temp->next;
		}
		/* insert iCount numbers of food details in given billno */
		for (i = 0; i < iCount; i++)
		{
			struct FoodDetails *new1 = (struct FoodDetails *)malloc(sizeof(struct FoodDetails *));

			fflush(stdin);
			printf("\nEnter Dish Name : ");
			fflush(stdin);
			gets(new1->food_detail);

			printf("Enter Quantity : ");
			scanf("%d", &new1->quantity);

			printf("Enter Price Of %s : ", new1->food_detail);
			scanf("%d", &new1->cost);

			int q = new1->quantity;
			int c = new1->cost;
			int t = (q * c);
			new1->totalCost = t;

			foodTemp = temp->foodData;

			if (foodTemp == NULL)
			{
				foodTemp = new1;
				new1->next = foodTemp;
			}
			else
			{

				struct FoodDetails *temp1;
				temp1 = foodTemp;
				
				while(temp1->next != foodTemp){
					temp1 = temp1->next;
				}
				temp1->next = new1;				
				new1->next = foodTemp;
			}
			temp->totalItem = (temp->totalItem + 1);
		}
		foodTemp = temp->foodData;

		while (foodTemp->next != temp->foodData)
		{
			total += foodTemp->totalCost;
			foodTemp = foodTemp->next;
		}
		total += foodTemp->totalCost;
		temp->total = (total + ((total * 5) / 100));
	}

	displayBill(billNo);
}

void deleteFoodItem()
{
	int billNo, deleteNo, totalOrderedItems;

	if (first == NULL)
	{
		printf("No Generated Bill");
	}
	else
	{
		printf("Enter Bill No In Which You Want To Delete Food Order : ");
		scanf("%d", &billNo);

		temp = first;

		while (temp->next != first)
		{
			if (temp->bill_no == billNo)
			{
				break;
			}
			temp = temp->next;
		}

		if (temp->next == first && temp->bill_no != billNo)
		{
			printf("\nBill Not Found");
		}
		else
		{
			int i = 1;

			totalOrderedItems = viewFood(billNo);

			/* Returned 3 Records instead of 2*/
			printf("\n Total Returned Records : %d", totalOrderedItems);
			struct FoodDetails *prev;

			foodTemp = temp->foodData;

			printf("\nNote : If User Order Only One Item then system can not Delete that Item. You have to Delete that bill. ");
			printf("\nEnter Item No. You Want To Delete : ");
			scanf("%d", &deleteNo);

			if (deleteNo == 1)
			{
			    struct FoodDetails *t1;
			    t1 = foodTemp;
			    while(t1->next != foodTemp){
			        t1 = t1->next;
			    }
				foodTemp = foodTemp->next;
				t1->next = foodTemp;
				temp->foodData = foodTemp;
			}
			else
			{
                while(foodTemp->next != foodTemp){
                    prev = foodTemp;
                    if(i == deleteNo)
                        break;
                    foodTemp = foodTemp->next;
                }
				if (i == deleteNo)
				{
					prev->next = foodTemp->next;
				}
				else
				{
					printf("\nItem To be Deleted Not Available");
				}
			}
		}

		/* Update bill Details */
		int total = 0;

		foodTemp = temp->foodData;

		while (foodTemp->next != temp->foodData)
		{
			total += foodTemp->totalCost;
			foodTemp = foodTemp->next;
		}
		total += foodTemp->totalCost;
		temp->total = (total + ((total * 5) / 100));

		displayBill(billNo);
	}
}

void deleteBill(int no)
{
	struct RBill *prev;

	if (no == first->bill_no)
	{

		struct RBill *t1;
		t1 = first;

		while (t1->next != first)
		{
			t1 = t1->next;
		}
		first = first->next;
		t1->next = first;
	}
	else
	{
	    temp = first;
		while (temp->next != first)
		{
			prev = temp;
			if (temp->bill_no == no)
			{
				break;
			}
			temp = temp->next;
		}
		prev->next = temp->next;
	}
}

void main()
{
	int iSwitchChoice, iNoData, i, iData, no;

	while (1)
	{
		printf("\n---------------------------------------------------------------------------------------");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n 			XYZ Restaurant (Home)");
		printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("\n---------------------------------------------------------------------------------------");

		printf("\n\n1. Generate Bill \n");
		printf("2. View All Bills \n");
		printf("3. View Food Details\n");
		printf("4. Update Food Details \n");
		printf("5. Delete Generated Bill\n");
		printf("6. Exit\n");

		printf("\n--------------------------------------------------------------------------------------");

		printf("\nEnter Choice ");
		scanf("%d", &iSwitchChoice);

		int bil;
		switch (iSwitchChoice)
		{
		case 1:
			bil = GenerateBill();
			displayBill(billno);
			break;
		case 2:
			displayUsers();
			break;
		case 3:
			printf("Enter Bill NO ");
			scanf("%d", &no);
			bil = viewFood(no);
			break;
		case 4:
			updateFoodDetails();
			break;
		case 5:
			printf("\nNote : If You generated Only One Bill then system can not delete that bill.");
			printf("\n Enter Bill No You Want To Delete : ");
			scanf("%d", &no);
			deleteBill(no);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Enter Correct Choice ");
		}
	}
}
