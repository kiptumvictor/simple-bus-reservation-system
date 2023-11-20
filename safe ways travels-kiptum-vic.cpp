#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char ch[10][130]={"BUS A","BUS B","BUS C","BUS E","BUS F"};
char name[10][5]={"\0"};
char number[20][2]={"\0"};
char sch[50][100] ={"BUS A-\ttown a to town b\n\t\t\t\t\t\t\tdeparture time:0900hrs\n\t\t\t\t\t\t\tarrival time10:00hrs","BUS B-town c to town d\n\t\t\t\t\t\t\tdeparture time:0900hrs\n\t\t\t\t\t\t\tarrival time10:00hrs","BUS C-town d to town e\n\t\t\t\t\t\t\tdeparture time:0900hrs\n\t\t\t\t\t\t\tarrival time10:00hrs","BUS D-town a to town b\n\t\t\t\t\t\t\tdeparture time:0900hrs\n\t\t\t\t\t\t\tarrival time10:00hrs","BUS E-town a to town b\n\t\t\t\t\t\t\tdeparture time:0900hrs\n\t\t\t\t\t\t\tarrival time10:00hrs"};
int num1[32]={0};
int busno;
void registerUser();
void login();
void bus();//for list of buses
void schedules();//for checking bus schedules
void name_number(int booking,char* numstr);
void booking();//for booking the tickets
int read_number(int busno);//for reading the number from the file
void read_name(int busno);//for reading name from the file
void status();//for printing the status by the user input
void status_1(int busno);//for printing the status while booking ticket
void cancle();

int main()
{
	registerUser();
    login();
    
    int num;
	do{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t=========== welcome to safe travels ===========\n\n");
	printf("\t\t\t\t\t[1]=> Bus Management\n");
	printf("\n");
	printf("\t\t\t\t\t[2]=> Booking tickets\n");
	printf("\n");
	printf("\t\t\t\t\t[3]=> Cancle booking\n");
	printf("\n");
	printf("\t\t\t\t\t[4]=> bus status board\n");
	printf("\n");
	printf("\t\t\t\t\t[5]=> bus schedules\n");
	printf("\n");
	printf("\t\t\t\t\t[6]=> Exit\n\n");
	printf("========================================================\n");
	printf("\t\t\t\t\tEnter your choice: ");
	scanf("%d",&num);
	switch(num)
	{
	case 1:
		bus();
		break;
	case 2:
		booking();
		break;
	case 3:
		cancle();
		break;
	case 4:
		status();
		break;
	case 5:
        schedules();
        break;
	}
getch() ;
    }while (num!=6);
    system ("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tThank you for using this system.\n\n\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}

void bus() 
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t==========================================safe travels===========================================\n\n\n");
printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void schedules()
{
	system ("CLS");
	printf("\t==========================================safe travels===========================================\n\n\n");
   printf("\t\t\t\t\t[1] =>  %s\n",sch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2] =>  %s\n",sch[1]);
    printf("\n");
    printf("\t\t\t\t\t[3] =>  %s\n",sch[2]);
    printf("\n");
    printf("\t\t\t\t\t[4] =>  %s\n",sch[3]);
    printf("\n");
    printf("\t\t\t\t\t[5] =>  %s\n",sch[4]);
    printf("\n");
}

void booking()
{
	
	
	char numstr[100];
system("cls");
printf("\n\n\n");
printf("\t===========================================safe travels===========================================\n\n\n");
bus();//for bus 
printf("Enter bus :");
scanf("%d",&busno);
system("cls");
printf("\t===========================================safe travels===========================================\n\n\n");
printf("Your bus is %d",busno);
status_1(busno);
 FILE *f1;//for reading the seats from the user
  char str1[80]="32";
  int seat1,booking=0;
if (busno==1)
 {
 f1 = fopen("busno1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(busno == 2)
{
 f1 = fopen("busno2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(busno == 3)
{
 f1 = fopen("busno3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("busno4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(busno,numstr,10);
 name_number(booking,numstr);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(busno == 1)
{
 f1 = fopen("busno1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(busno == 2)
{
 f1 = fopen("busno2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(busno == 3)
{
 f1 = fopen("busno3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("busno4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
}
}


void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
	printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
	printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:--->");
      scanf("%s",name[number-1]);
       printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}


int read_number(int busno)//for putting the numeric value in the array
{
char tempstr2[12]="number";
FILE *a;
char numstr[100];
int i=0,j=0,k;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int busno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,busno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&busno);
    j=read_number(busno);
    read_name(busno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",busno,ch[busno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int busno)
{
    printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(busno);
    read_name(busno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&busno);
 itoa(busno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(busno);
 read_name(busno);
 status_1(busno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 ksh has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}



typedef struct {
    char username[50];
    char password[50];
} User;

User newUser;  // make newUser global so it can be accessed in both functions

// Function to register a new user
void registerUser() {
    printf("\n  =========================  REGISTRATION FORM  =========================\n\n ");
    printf("\t\t[1]Enter username: ");
    scanf("%s", newUser.username);
    printf("\t\t[2]Enter password: ");
    scanf("%s", newUser.password);
}


void login()
{
	int a=0,i=0;
    char username[10],c=' '; 
    char password[10];
   
    
    do
{
	system("cls");
	
    printf("\n  =========================  LOGIN FORM  =========================  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", username); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';
	//char code=newUser.password;
	i=0;
	//scanf("%s",&newUser.password); 
		if(strcmp(username, newUser.username)==0 && strcmp(password, newUser.password)==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");
}
