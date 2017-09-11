#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

void run();
void display(char A[9]);
int check(char A[9],char ch,int count);
struct mydatatype input(char A[9],int count);

struct mydatatype
{
	int i;
	char ch;
};

mydatatype input(char A[9],int count)
{
	char value;
	struct mydatatype info;
	inputagain:
	if(count%2 == 0)
		cout<<"\n Enter your choice X: \n";
	else
		cout<<"\n Enter your choice O: \n";
	cin>>value;
	int i;
	for(i=0;i<9;i++)
	{
	if(value==A[i])
	{
	 info.i=i;
	if(count%2 == 0)
	  info.ch='X';	
	else
  	info.ch='O';
	break;
	}
	else
	{
	info.i=-1;
	}
	}
	if(info.i==-1)
	{
	cout<<"\nERROR: Input is invalid. Please Enter your choice again\t";
	goto inputagain;
	}
	return info;
}






int main()
{
	cout<<" W E L C O M E\tT O\tT I C\tT A C\tT O E\tG A M E \n\n\t\t HOPE THE BEST PLAYER WINS\n\n";
	cout<<"     PLAYER 1's SYMBOL: X\n";
	cout<<"     PLAYER 2's SYMBOL: O\n";
	again:
	run();	
	char restart;
	cout<<"\nIf you want to play again then press 1:\n else press any key: ";
	cin>>restart;
	if(restart=='1')
	goto again;
	else
	{
	    cout<<"\n\n\n\t\t\tGOOD\tBYE\n\n";
	    exit(0);
	}
	return 0;
	}
void run()
{
	int count;
	struct mydatatype info;
	char A[9]={'1','2','3','4','5','6','7','8','9'};
	display(A);
	again:
	info= input(A,count);
	A[info.i]=info.ch;
	system("clear");
	display(A);
	int chk;
	chk=check(A,info.ch,count);
	if(chk != 1)
	{
	    count++;
	}
	else if( chk==1)
	{
		exit(0);
	}
	goto again;
}
int check(char A[9],char ch,int count)
{
 	   int i;
	for(i=0;i<3;i++) //for  row
	{
		if(A[i]==ch&&A[i+1]==ch&&A[i+2]==ch)
			{
			   cout<<"The winner is: "<<ch;
	 			return 1;
			}
	}
	for(i=0;i<3;i++) //for  column
	{
		if(A[i]==ch&&A[i+3]==ch&&A[i+6]==ch)
		{
			cout<<"The winner is: "<<ch;
			return 1;
		}
	}
	if(A[0]==ch&&A[4]==ch&&A[8]==ch)
	{
		cout<<"The winner is: "<<ch;
		return 1;
	}
	else if(A[2]==ch&&A[4]==ch&&A[6]==ch)
	{
		cout<<"The winner is: "<<ch;
		return 1;
	}
	else if(count==8)
	{
		cout<<"THE GAME IS DRAW";
		return 1;
	}
	else
	return 0;
}



void display(char A[9])
{
	cout<<"\n\n\t\t\tT I C\tT A C\tT O E\tG A M E \n";
	cout<<"\n\t\t\t        |        |        ";
	cout<<"\n\t\t\t   "<<A[0]<<"    |   "<<A[1]<<"    |    "<<A[2];
	cout<<"\n\t\t\t--------|--------|--------";
	cout<<"\n\t\t\t   "<<A[3]<<"    |   "<<A[4]<<"    |    "<<A[5];
	cout<<"\n\t\t\t--------|--------|--------";
	cout<<"\n\t\t\t   "<<A[6]<<"    |   "<<A[7]<<"    |    "<<A[8];
	cout<<"\n\t\t\t        |        |        \n";
}
