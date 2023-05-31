#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>


void add_details();
void list_of_details();
void delete_details();
void search_details();
void edit_details();

struct CustomerDetails   
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[20];
	char nationality[10];	
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;



void login();
int main()
{
  int i;
  char choice;
  time_t CurrentTime;
  time(&CurrentTime);
  system("color A");

  printf(" ------------------------------------------------------------------------------------ \n");
	printf("|                                                                                    |\n");      
	printf("|                                                                                    |\n");
	printf("|  O O O O       O O O     O       O   O O O O O     O O O     O       O   O O O O   |\n");
	printf("|  O       O   O       O   O O     O       O       O       O   O       O   O      O  |\n");
	printf("|  O       O   O       O   O  O    O       O       O       O   O       O   O      O  |\n");
	printf("|  O O O O     O       O   O   O   O       O       O       O   O       O   O O O O   |\n");
	printf("|  O       O   O       O   O    O  O  o    O       O       O   O       O   O O       |\n");
	printf("|  O       O   O       O   O     O O    o  O       O       O   O       O   O   O     |\n");     
    printf("|  O O O O       O O O     O       O      o          O O O       O O O     O     O   |\n");   
    printf(" ------------------------------------------------------------------------------------ \n");
 	printf("\t\t****************************************************\n");
	printf("\t\t*                                                  *\n");
	printf("\t\t*         -----------------------------            *\n");
	printf("\t\t*          WELCOME TO HOTEL TAJ PLAZA              *\n");
	printf("\t\t*         -----------------------------            *\n");
	printf("\t\t*                                                  *\n");
	printf("\t\t*                                                  *\n");
	printf("\t\t****************************************************\n");
   
  for(i=0;i<80;i++)
 {
  printf("-");
 }
  printf("\nCurrent date and time : %s",ctime(&CurrentTime));
  for(i=0;i<80;i++)
 {
  printf("-");
 }
 printf(" \n press any key to continue");

 getch();
 system("cls");
 login();
system("cls");
 while(1)
 {
  system("cls");
 for(i=0;i<80;i++)
 {
		printf("-");
 }
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		{
      printf("-");
    }
	    system("color B");
		printf("\n");
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&CurrentTime));
	    for(i=0;i<80;i++)
		printf("-");

    choice = getch();
    switch(choice)
    {
      case'1' :
      add_details();
      break;
      case '2' :
      list_of_details();
      break;
      case '3' :
      delete_details();
      break;
      case '4' :
      search_details();
      break;
      case '5' :
      edit_details();
      break;
      case '6' :
      system("cls");
      printf("\n\n\t*THANK YOU*");
      printf("\n\tFOR TRUSTING OUR SERVICE ");
      exit(0);
      break;
      default:
      system("cls");
      printf("Incorrect Input ");
      printf("\n Press any key to continue ");
      getch();
    }

 }  

  

}
void login()
{
  char k;
  int i,g;
  char username[20];
  char password[20];
  char user[10]="user";
  char pass[10]="pass";

for(int i=0;i<10;i++){
	printf("\u2588");
	usleep(150000);
  }

  printf("      LOGIN FORM      ");

for(int i=0;i<10;i++){
	printf("\u2588");
	usleep(150000);
  }

    printf(" \n\n                       ENTER USERNAME:-"); 
	scanf("%s", &username); 
	printf(" \n                       ENTER PASSWORD:-");
  for(i=0;i<10;i++)
  {
    password[i]=getch();
    k=password[i];
    if(k==13)
    break;
    
    else
    printf("*");
  }
 password[i]='\0';
	i=0;
		if(strcmp(username,user)==0 && strcmp(password,pass)==0)
	{
	printf("\n    WELCOME !!!! LOGIN IS SUCCESSFUL");
	}
	else
	{
	printf("\n    SORRY !!!!  LOGIN IS UNSUCCESSFUL");
	printf("Please try to login again \n");
	usleep(1000000000);
	system("cls");
	login();
	
	}
	printf("\npress any key to continue");
    getch();
    system("cls");
	

}


  void add_details()
{
  FILE *f;
	char test;
	f=fopen("add.txt","a+");
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getch();
		if(test==27)
			break;
			
	}
	fclose(f);
}
 
 void list_of_details()

 {
  FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");
	
	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s \n",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}
 void delete_details()


{
  FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\n Records of Customer in this  Room number is not found!!");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}
void search_details()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}
void edit_details()
{
FILE *f;
	int p=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			p=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(p==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}
