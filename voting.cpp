#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>

ifstream in;
ofstream out;

struct block
{
    int id;
    char voted[10];
    int adhar;
 block *nxt;
};


int main()
{
    block *p=NULL,*q=NULL;
    char name[100],ch;
    int voted;
    int id=0,n=3;


block *head=(block*)malloc(sizeof(block));
head->nxt=NULL;
p=head;

int result[4],k=0;
while(k<5)
result[k++]=0;

char pass[15],pass1[15];
in.open("pass.txt");
in>>pass;
retry:
cout<<" TO start Voting verify you Are ADMIN by entering password: ";
cin>>pass1;


if(strcmp(pass,pass1)==0)
{


do
{

p->id=++id;
cout<<endl<<"choose:\n1.BJP\n2.CONG\n3.MNS\n4.NOTA\n*Any other number key to exit"<<endl;
cin>>voted;
if(voted==1)
{
strcpy(p->voted,"BJP");
result[0]++;
}
if(voted==2)
{
strcpy(p->voted,"CONG");
result[1]++;
}
if(voted==3)
{
strcpy(p->voted,"MNS");
result[2]++;
}
if(voted==4)
{
strcpy(p->voted,"NOTA");
result[3]++;
}
p->nxt=NULL;
    
    
    if(voted<5 && voted>0)
    {
        p->nxt=(block*)malloc(sizeof(block));
        p=p->nxt;
    }
}while(voted<5 && voted>0);







int j,win=0;
int max=result[0];

if((result[0]==result[1] && result[1]==result[2] && result[1]==result[3]) && id>2)
cout<<"same votes to all parties! It's a draw!!"<<endl;
else if(id>2)
{
    j=0;
while(j<4)
{
    if(max<result[j])
    {
    max=result[j];
    win=j;
    }
    j++;
}
cout<<endl<<endl<<"RESULT: ";
if(win==0)
cout<<"***BJP wins with max votes="<<max<<"/"<<id-1<<"***"<<endl;
if(win==1)
cout<<"***CONG wins with max votes="<<max<<"/"<<id-1<<"***"<<endl;
if(win==2)
cout<<"***MNS wins with max votes="<<max<<"/"<<id-1<<"***"<<endl;
if(win==3)
cout<<"***No one wins(NOTA)***"<<endl;
}

    




}
else
{
    n--;
    if(n>0)
    {
cout<<"Incorrect Password! only "<<n<<" attempts left!"<<endl;
goto retry;
    }

}
if(id>2)
{
    cout<<endl<<endl<<"show voting details?(Y/N):";
    cin>>ch;
    
    if (ch=='Y')
    {
    
    cout<<endl<<"*VOTING DETAILS:-\n";
 q=head;
    while(q->nxt!=NULL)
    {
        cout<<"person "<<q->id<<" voted to="<<q->voted<<endl;
        q=q->nxt;
    }
   
    }
}


cout<<endl<<"Thanx for Voting with us!"<<endl<<endl;

}