#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>

ifstream in;
ofstream out;

int check(char pass[15])
{
int i=0,j=0,n,sym=0,num=0,upr=0,lwr=0;
n=strlen(pass);

if(n>=6 && n<=15)
{
while (i<n)
{     
    if(sym==0)
    if((int(pass[i])>32 && int(pass[i])<=47) || (int(pass[i])>57 && int(pass[i])<=64) )
    {
        sym=1;
    }
    if(num==0)
    if (int(pass[i])>47 && int(pass[i])<=57)
    {
        num=1;
    }
    if(upr==0)
    if (int(pass[i])>64 && int(pass[i])<=90)
    {
        upr=1;
    }
    if(lwr==0)
    if (int(pass[i])>96 && int(pass[i])<=122)
    {
        lwr=1;
    }

    


    i++;
}
}
else
{
    cout<<" password length must be equal or greater than 6 & less than 15\npassword must contain:\n at least 1 uppercase , 1 lowercase, 1 special symbol & 1 numerical value! ";
     return 0;
}
if (sym==1 && num==1 && upr==1 && lwr==1)
{
    return 1;
}
else 
{
cout<<"password length must be equal or greater than 6 & less than 15\npassword must contain:\n at least 1 uppercase , 1 lowercase, 1 special symbol & 1 numerical value! "<<endl;
return 0;
}


}

int main()
{

    out.open("pass.txt");



char pass[15],pass1[15];
    retry:
    cout<<"Set password: ";
    cin>>pass;

if(check(pass)==0)
goto retry;
else
{
cout<<"comfirm password:";
cin>>pass1;
if(strcmp(pass,pass1)==0)
{
    cout<<"password set!";
    out<<pass;
}
else
{
    cout<<"passwords don't match!\nplease retry!\n";
    goto retry;
}

}


    
}