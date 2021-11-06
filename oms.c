#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void mainmenu(void);
void administration(void);
void aboutus(void);
void login(void);
void add_item(void);
void search_item(void);
void delete_item(void);
void update_item(void);
void view_record(void);
void customer(void);
void order_item(void);
void information_customer(void);
void sort_name_A_to_Z(void);
void sort_price(void);
void top_best_selling(void);
void hint_item(void);
void number_of_products_sold(void);
void gotoxy(short x, short y);
void search_order(void);

struct order
{
	char name[20];
	int price;
	int Qnt;

} or;
struct icecream
{
	char name[20];
	char type[20];
	char origin[20];
	int price;
	char productid[8];
	int Qnt;
} st;
struct info
{
	int price;
	char name1[10];
	char name2[10];
	char number[20];
	char codeorder[30];
} info;
void mainmenu()
{
	system("cls");
	printf("                                                   WELCOME TO MARIA'S ICE CREAM SHOP\n");
	printf("                                 **************************************************************************\n");
	printf("                                                           FOOD ORDER SYSTEM\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("          1. SEARCH ICE CREAM--> \n\n          2. CUSTOMER SECTION--> \n\n          3. ADMINISTRATION SECTION--> \n\n          4. ABOUT US--> \n\n          5. Exit--> \n\n\n             Enter Your Choice --->\n");

	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		search_item();
	}
	if (choice == 2)
	{
		customer();
	}
	if (choice == 3)
	{
		login();
	}
	if (choice == 4)
	{
		aboutus();
	}
	if (choice == 5)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t******************************* THANK YOU **************************************\n");
		printf("\t\t\t**************	Feeling HOT ? Call or Walk-In MARIA'S ICE CREAM SHOP	***************\n\n\n");
		exit(0);
	}
}
int main()
{
	mainmenu();
	return 0;
}
void administration()
{
	system("cls");
	printf("\n\n\n\t************************************** WELCOME TO THE PRODUCT MANAGEMENT  SYSTEM ****************************************\n\n\n\n");
	printf("          1. ADD NEW PRODUCT\n\n          2. UPDATE PRODUCT\n\n          3. DELETE PRODUCT\n\n          4. VIEW THE RECORDS\n\n          5. VIEW PREVIOUS ORDER PLACES\n\n          6. VIEW NUMBER OF PRODUCTS SOLD\n\n          7. SEARCH ORDER BY ID\n\n          8. BACK TO MAIN MENU \n\n             Enter Your Choice --->");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		add_item();
	}
	if (choice == 2)
	{
		update_item();
	}
	if (choice == 3)
	{
		delete_item();
	}
	if (choice == 4)
	{
		view_record();
	}
	if (choice == 5)
	{
		system("cls");
		FILE *view;
		char viw;
		view = fopen("order.txt", "rt");
		while ((viw = fgetc(view)) != EOF)
		{
			printf("%c", viw);
		}
		fclose(view);
		getch();
		administration();
	}
	if (choice == 6)
	{
		number_of_products_sold();
	}
	if (choice == 7)
	{
		search_order();
	}
	if (choice == 8)
	{
		system("cls");
		mainmenu();
	}
}
void aboutus()
{
	system("cls");
	printf("\t\t\t\t**************************WELCOME TO MARIA'S ICE CREAM SHOP**************************\n\n\n\n         \t\tOur shop provides delicious quality ice cream with a variety of ingredients and origin scents.\n       \n\t\t\t\t\tLet's experience new flavors of ice cream with family and friends \n\n Contact: 12345678912 \n Address: 123 ABC street , XYZ city \n web: https://mariaicecream.com                   \n\n\t\t\t\t\t*****************************THANK YOU*****************************");
	printf("\n\n\n\n\n\n    Press Any Key To Go Back.....");
	if (getch())
		mainmenu();
}
void login()
{
	system("cls");
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "admin";
	char pass[20] = "password";

	printf("\n  ========================  LOGIN   ========================  ");
	printf(" \n                        USERNAME:-");
	fflush(stdin);
	scanf("%s", &uname);
	fflush(stdin);
	printf(" \n                        PASSWORD:-");
	while (i < 10)
	{
		pword[i] = getch();
		c = pword[i];
		if (c == 13)
			break;
		else
			printf("*");
		i++;
	}
	pword[i] = '\0';
	i = 0;
	if (strcmp(uname, "admin") == 0 && strcmp(pword, "password") == 0)
	{
		printf("  \n\n\n       WELCOME TO PRODUCT MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		getch(); 
		administration();
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch(); 
		mainmenu();
	}
}
void add_item()
{
	int index, valid;
	char c;
	int a = 0;
	FILE *fp, *rp;

	do
	{
		system("cls");
		printf("============ Enter Product Detail ============");
		char ID[10];
		fp = fopen("search.dat", "a+");
		if (fp != NULL)
		{
		I:
			printf("\nProduct Code\t :");
			fflush(stdin);
			gets(ID);
			while (fscanf(fp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
			{
				if (strcmp(ID, st.productid) == 0)
				{
					printf("\n\tTHE PRODUCT CODE ALREADY EXIST.\n");
					goto I;
				}
			}
		}

		else
		{
			printf("\nProduct Code\t :");
			fflush(stdin);
			gets(ID);
		}
		fclose(fp);

		do
		{
			fflush(stdin);
			printf("\nProduct Name\t :");
			gets(st.name);
			for (index = 0; index < strlen(st.name); ++index)
			{
				if (isalpha(st.name[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();
			}
		} while (!valid);

		do
		{
			fflush(stdin);
			printf("\nProduct Type\t :");
			gets(st.type);
			for (index = 0; index < strlen(st.type); ++index)
			{
				if (isalpha(st.type[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n Type contain invalid character. Please 'Enter' again");
				getch();
			}
		} while (!valid);

		do
		{
			char origin[10];
			fflush(stdin);
			printf("\nProduct Origin\t :");
			gets(st.origin);
			for (index = 0; index < strlen(st.origin); ++index)
			{ // check if character is valid or not
				if (isalpha(st.origin[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();
			}
		} while (!valid);

		do
		{
			printf("\nPrice [10-1000]:");
			fflush(stdin);
			scanf("%i", &st.price);
			if (st.price < 10 || st.price > 1000)
			{
				printf("\n\tYou Cannot Enter the price limit [10-1000].Re-Enter.");
			}
		} while (st.price < 10 || st.price > 1000);

		do
		{
			printf("\nQuantity [1-500]\t:");
			fflush(stdin);
			scanf("%i", &st.Qnt);
			if (st.Qnt < 1 || st.Qnt > 500)
			{
				printf("\n\tEnter Quantity[1-500] only.Re-Enter.");
			}
		} while (st.Qnt < 1 || st.Qnt > 500);

		rp = fopen("TempFile.dat", "a");
		fprintf(rp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, st.price, ID, st.Qnt);
		fp = fopen("search.dat", "r+");
		while (fscanf(fp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
		{
			fprintf(rp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, st.price, st.productid, st.Qnt);
		}
		fclose(rp);
		fclose(fp);
		remove("search.dat");
		rename("TempFile.dat", "search.dat");
		printf("\nPress 'Enter' to add more item and any other key to go back");

	} while ((c = getch()) == '\r');

	administration();
}
void search_item()
{
	system("cls");
	printf("My shop have types of ice cream : choco , vanilla , durian , coca , sevenup,....\n");
	char target[40];
	int found = 0;
	FILE *sfile;
	sfile = fopen("search.dat", "r");
	printf("\n\nEnter name, id, type, or origin you want:");
	fflush(stdin);
	gets(target);
	while (!feof(sfile) && found == 0)
	{
		fscanf(sfile, "%s %s %s %i %s %i", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt);
		if (strcmp(target, st.name) == 0)
			found = 1;
		if (strcmp(target, st.type) == 0)
			found = 1;
		if (strcmp(target, st.productid) == 0)
			found = 1;
		if (strcmp(target, st.origin) == 0)
			found = 1;
	}

	if (found)
	{
		printf("\n Record found");
		printf("\nProduct Name\t\t:%s  \nProduct type\t\t:%s \nProduct origin\t\t:%s \nProduct Price\t\t:%i \nProduct ID\t\t:%s \nProduct Quantity\t:%i", st.name, st.type, st.origin, st.price, st.productid, st.Qnt);
		fclose(sfile);
		printf("\nPress any key to go back");
		getch();
		mainmenu();
	}
	else
	{
		printf("Sorry , we don't have what you want , you can try another product");
		fclose(sfile);
		printf("\nPress any key to go back");
		getch();
		mainmenu();
	}
}
void delete_item()
{
	system("cls");
	char target[40];
	int found = 0;
	FILE *sfile, *tfile;
	sfile = fopen("search.dat", "r");
	tfile = fopen("TempFile.dat", "a");
	printf("\n Enter ID to Delete: ");
	fflush(stdin);
	scanf("%s", target);
	while (fscanf(sfile, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
	{
		if (strcmp(target, st.productid) == 0)
		{
			found = 1;
		}
		else
		{
			fprintf(tfile, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, st.price, st.productid, st.Qnt);
		}
	}
	if (!found)
	{
		printf("\n Record not Found");
		getch();
		administration();
	}
	else
	{
		printf("\n Record deleted");
	}
	fclose(sfile);
	fclose(tfile);
	remove("search.dat");
	rename("TempFile.dat", "search.dat");
	printf("\nPress any key to go to Main Menu!");
	getch();
	administration();
}
void update_item()
{
	int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a = 0;
	char ID[8];
	char update;
	long int size = sizeof(st);
	if ((fp = fopen("search.dat", "r+")) == NULL)
	{
		printf("NO RECORD ADDED.");
		administration();
	}
	else
	{
		rp = fopen("TempFile.dat", "a");
		system("cls");
		printf("Enter Product Code for edit:");
		fflush(stdin);
		gets(ID);
		while (fscanf(fp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
		{
			if (strcmp(ID, st.productid) == 0)
			{

				a = 1;
				printf("\n\t*****  Record Found  *****");
				printf("\nProduct Name\t\t: %s", st.name);
				printf("\nProduct Type\t\t: %s", st.type);
				printf("\nProduct Origin\t\t: %s", st.origin);
				printf("\nProduct Price\t\t: %i", st.price);
				printf("\nProduct Code\t\t: %s", st.productid);
				printf("\nProduct Quantity\t: %i", st.Qnt);
				printf("\n\n\t*** New Record ***");
				do
				{

					fflush(stdin);
					printf("\nNew Product Name\t\t: ");
					gets(st.name);
					for (index = 0; index < strlen(st.name); ++index)
					{
						if (isalpha(st.name[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();
					}
				} while (!valid);

				do
				{
					char origin[40];
					fflush(stdin);
					printf("\nNew Product Origin:\t\t:");
					gets(st.origin);
					for (index = 0; index < strlen(st.origin); ++index)
					{
						if (isalpha(st.origin[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();
					}
				} while (!valid);

				do
				{
					char type[10];
					fflush(stdin);
					printf("\nNew Type :");
					gets(st.type);
					for (index = 0; index < strlen(st.origin); ++index)
					{
						if (isalpha(st.origin[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();
					}
				} while (!valid);

				do
				{
					printf("\nNew Price :");
					scanf("%i", &st.price);
					if (st.price <= 0)
					{
						printf("\n\tYou Cannot Enter the price .Re-Enter.");
						getch();
					}
				} while (st.price <= 0);

				printf("\nEnter New Product Code\t\t:");
				fflush(stdin);
				gets(st.productid);

				do
				{
					printf("\nNew Quantity [0-100]\t:");
					fflush(stdin);
					scanf("%d", &st.Qnt);
					if (st.Qnt < 0 || st.Qnt > 1000)
					{
						printf("\n\tEnter New Quantity[1-1000] only.Re-Enter.");
						getch();
					}
				} while (st.Qnt < 0 || st.Qnt > 1000);

				printf("\nPress 'y' to edit the existing record or any key to cancel...");
				char edit = getche();
				if (edit == 'y' || edit == 'Y')
				{
					fprintf(rp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, st.price, st.productid, st.Qnt);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
					fflush(stdin);
				}
			}
			else
			{
				fprintf(rp, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, st.price, st.productid, st.Qnt);
				fflush(stdin);
			}
		}
		if (!a)
		{
			printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("search.dat");
		rename("TempFile.dat", "search.dat");
		getch();
	}
	administration();
}
void view_record()
{
	system("cls");
	FILE *f;
	int i, v;
	if ((f = fopen("search.dat", "r")) == NULL)
	{
		gotoxy(10, 3);
		printf("NO RECORDS");
		printf("\n\t\tPress any key to go back to Menu.");
		getch();
		mainmenu();
	}
	else
	{

		gotoxy(0, 5);
		for (i = 0; i < 120; i++)
		{
			printf("-");
		}
		gotoxy(5, 6);
		printf("Product Name");
		gotoxy(25, 6);
		printf("Product Type");
		gotoxy(40, 6);
		printf("Product Origin");
		gotoxy(60, 6);
		printf("Product Price");
		gotoxy(80, 6);
		printf("Product CODE");
		gotoxy(100, 6);
		printf("Product Quantity\n");

		for (i = 0; i < 130; i++)
		{
			printf("-");
		}
		v = 8;
		while (fscanf(f, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, &st.productid, &st.Qnt) != EOF)
		{
			gotoxy(5, v);
			printf("%s", st.name);
			gotoxy(25, v);
			printf("%s", st.type);
			gotoxy(40, v);
			printf("%i", st.price);
			gotoxy(60, v);
			printf("%s", st.origin);
			gotoxy(80, v);
			printf("%s", st.productid);
			gotoxy(100, v);
			printf("%i", st.Qnt);

			v++;
		}
		printf("\n");
		for (i = 0; i < 130; i++)
			printf("-");
	}
	fclose(f);

	printf("\nPress any key to go to Main Menu!");
	getch();
	administration();
}
void customer()
{

	system("cls");
	printf("                    ************************************************\n                                      WELCOME\n                    ************************************************\n\n");
	printf("               YOU ARE--->\n\n               1. Order\n\n               2. Search\n\n               3. Hint Items\n\n\n               4. Back To Main Menu\n\n   Enter Your Choice  -->");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		order_item();
	}
	if (choice == 2)
	{
		search_item();
	}
	if (choice == 3)
	{
		hint_item();
	}
	if (choice == 4)
	{
		mainmenu();
	}
}
void order_item()
{
	system("cls");
	char name[80];
	int price;
	int Qnt;
	int valid;
	printf("                    ****************************************\n                                  ICE CREAM MENU\n                    ****************************************\n\n");
	FILE *ic, *order, *temp, *tf;
	ic = fopen("search.dat", "r+");
	printf("\n\nEnter What You Want By Name : ");
	fflush(stdin);
	gets(name);
	printf("Qnt: ");
	scanf("%d", &Qnt);
	while (fscanf(ic, "%s %s %s %i %s %i", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
	{
		if (strcmp(name, st.name) == 0)
		{
			temp = fopen("temp.txt", "a");
			fprintf(temp, "%s %i %i\n", name, st.price, Qnt);
			fclose(temp);
			fclose(ic);

			tf = fopen("Qntfood.dat", "a");
			order = fopen("orderfood.txt", "r+");
			while (fscanf(order, "%s %i", or.name, & or.Qnt) != EOF)
			{
				if (strcmp(name, or.name) == 0)
				{
					or.Qnt += Qnt;
					fprintf(tf, "%s %i\n", or.name, or.Qnt);
				}
				else
				{
					fprintf(tf, "%s %i\n", or.name, or.Qnt);
				}
			}
			fclose(tf);
			fclose(order);
			remove("orderfood.txt");
			rename("Qntfood.dat", "orderfood.txt");
		}
	}

	int choice;
	printf("Do you want order countinuely? :\n\n\n\t1.yes\n\n  \t2.exit and no order\n\n \t3.Payment\n\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		order_item();
	}
	if (choice == 2)
	{
		mainmenu();
	}

	if (choice == 3)
	{
		int cost = 0;
		int total;
		FILE *pay;
		pay = fopen("temp.txt", "r");
		while (fscanf(pay, "%s %i %i", or.name, & or.price, & or.Qnt) != EOF)
		{
			cost += or.price * or.Qnt;
		}
		if (cost > 700 && cost < 1000)
		{
			total = cost - cost * 10 / 100;
		}
		else if (cost > 1000)
		{
			total = cost - cost * 20 / 100;
		}
		else
		{
			total = cost;
		}
		printf("Your Total Amount Is :%i\n\n", total);
		FILE *ttl, *it;
		ttl = fopen("order.txt", "a");
		it = fopen("infocustom.dat", "a");
		fprintf(it, "%i ", total);
		fprintf(ttl, "\nGrand Total : %i$\n", total);
		fclose(ttl);
		fclose(it);
		printf("Press any key to countinue");
		getch();
		fclose(pay);
		remove("temp.txt");
		information_customer();
	}
}
void information_customer()
{
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	char landmark[30];
	printf("\nPlease Give Your Contact Details \n");
	printf("First Name : ");
	scanf("%s", name1);
	printf("Last Name : ");
	scanf("%s", name2);
	printf("Phone : ");
	scanf("%lld", &phone);
	printf("Address : ");
	scanf("%s", address);
	printf("Landmark : ");
	scanf("%s", landmark);
	printf("\n\n");
	printf("Your Entered Details Are --->\n\n");
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%d%m%Y%H%M%S", info);
	printf("%s\n", buffer);
	FILE *cust, *it;
	cust = fopen("order.txt", "a");
	it = fopen("infocustom.dat", "a");
	fprintf(it, "%s %s %lld %s\n", name1, name2, phone, buffer);
	fprintf(cust, "Order Placed By : %s %s\nPhone number : %lld\nCode order : %s\n", name1, name2, phone, buffer);
	fclose(cust);
	printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n    -->Landmark  :%s \n\n", name1, name2, phone, address, landmark);
	printf("  ---->Your code's order: %s", buffer);
	printf("\n\n\n");
	printf("                       *********************************************************************************************\n");
	printf("                                             Your Order Will Be At Your Door In 15 minutes.\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       *********************************************************************************************\n");
	printf("Press Any To The MainMenu.");
	if (getch())
		mainmenu();
}
void sort_name_A_to_Z()
{
	system("cls");
	char name[100][20], tname[100][20], temp[50];
	int i, j, n;
	int count = 0;
	FILE *sort;
	sort = fopen("search.dat", "r");
	while (fscanf(sort, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
	{
		strcpy(name[count], st.name);
		count++;
	}

	for (i = 0; i < count; i++)
	{
		strcpy(tname[i], name[i]);
	}

	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
			}
		}
	}
	system("cls");
	for (i = 0; i < count; i++)
	{
		printf("\t%s\n", name[i]);
	}
	printf("------------------------------------------\n");
	printf("Press any key to go back ");
	getch();
	hint_item();
}
void sort_price()
{
	system("cls");
	int count = 0;
	FILE *sort;
	int price[100];
	sort = fopen("search.dat", "r");
	while (fscanf(sort, "%s %s %s %i %s %i\n", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt) != EOF)
	{
		price[count] = st.price;
		count++;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (price[j] < price[j + 1])
			{
				int temp = price[j];
				price[j] = price[j + 1];
				price[j + 1] = temp;
			}
		}
	}
	fclose(sort);
	int q = 3;
	for (int i = 0; i < count; i++)
	{
		sort = fopen("search.dat", "r");
		while (!feof(sort))
		{
			fscanf(sort, "%s %s %s %i %s %i", st.name, st.type, st.origin, &st.price, st.productid, &st.Qnt);
			if (price[i] == st.price)
			{
				gotoxy(5, q);
				printf("%s", st.name);
				gotoxy(25, q);
				printf("%i$", st.price);
				q += 2;
				fclose(sort);
				break;
			}
		}
	}
	printf("  \n\nPress any key to go back: ");
	getch();
	hint_item();
}
void top_best_selling()
{
	system("cls");
	int count = 0;
	int n;
	int Qnt[100];
	FILE *best;
	best = fopen("orderfood.txt", "r");
	while (fscanf(best, "%s %i", or.name, & or.Qnt) != EOF)
	{
		Qnt[count] = or.Qnt;
		count++;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (Qnt[j] < Qnt[j + 1])
			{
				int temp = Qnt[j];
				Qnt[j] = Qnt[j + 1];
				Qnt[j + 1] = temp;
			}
		}
	}
	fclose(best);
	int q = 3;
	printf("How many top-selling products do you want to see?\n");
	printf("Enter your number: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		best = fopen("orderfood.txt", "r");
		while (!feof(best))
		{
			fscanf(best, "%s %i", or.name, & or.Qnt);
			if (Qnt[i] == or.Qnt)
			{
				gotoxy(5, q);
				printf("%s", or.name);
				gotoxy(25, q);
				printf("%i", or.Qnt);
				q += 2;
				fclose(best);
				break;
			}
		}
	}
	printf("  \n\nPress any key to go back: ");
	getch();
	hint_item();
}
void hint_item()
{
	system("cls");
	printf("\t\tSo many dishes that you don't know what to order? \n\t\t Don't worry I'm monica , I'll help you choose\n\n");
	printf("You want to order by: \n");
	printf("\n\t1.price \n\n\t2.Name_A_to_Z \n\n\t3.Best-selling \n\n\t4.Go back \n\n\nEnter your's choice ");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		sort_price();
	}
	if (choice == 2)
	{
		sort_name_A_to_Z();
	}
	if (choice == 3)
	{
		top_best_selling();
	}
	if (choice == 4)
	{
		customer();
	}
	fflush(stdin);
	printf("  Press any key to go back: ");
	getch();
	customer();
}
void number_of_products_sold()
{
	system("cls");
	FILE *view;
	view = fopen("orderfood.txt", "r");
	gotoxy(5, 6);
	printf("Product Name");
	gotoxy(25, 6);
	printf("Quantity");
	int q = 8;
	while (fscanf(view, "%s %i", or.name, & or.Qnt) != EOF)
	{
		gotoxy(5, q);
		printf("%s", or.name);
		gotoxy(25, q);
		printf("%i", or.Qnt);
		q += 2;
	}
	fclose(view);
	printf("\n\nPress any key to go to Main Menu!");
	getch();
	administration();
}
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void search_order()
{
	system("cls");
	int valid = 0;
	char id[15];
	FILE *order;
	order = fopen("infocustom.txt", "r+");
	printf("Enter ID of order you want to see: ");
	fflush(stdin);
	gets(id);
	while (fscanf(order, "%i %s %s %s %s", &info.price, info.name1, info.name2, info.number, info.codeorder) != EOF)
	{
		if (strcmp(id, info.codeorder) == 0)
		{
			printf("\n\nGrand total : %i\nOrder Placed By : %s %s\nPhone number : %s\nCode order : %s\n\n", info.price, info.name1, info.name2, info.number, info.codeorder);
			valid = 1;
			break;
		}
	}
	if (!valid)
	{
		printf("\n\nSorry , I don't have information you want, You can try another ID.\n\n");
	}
	fclose(order);
	printf("Press any key to go back ");
	getch();
	administration();
}
