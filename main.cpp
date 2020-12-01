#include <iostream>
#include <ctime>
#include <string>
using namespace std;
// maximum number or users is 1000
time_t now =time(0);
tm *ltm = localtime(&now);
int year=1900+ltm->tm_year;
string Y= to_string(year);
int month=1+ltm->tm_mon;
string M1= to_string(month);
string M2= to_string(month+1);
int day=ltm->tm_mday;
string D= to_string(day);

const int MAX= 1000;
string get[10] ;
bool f=0,f1=0;
int index=0;
int II,J,JJ;
int I=-1;
int id[MAX];
string email[MAX];
string name[MAX];
string password[MAX];
string address[MAX];
long long line[MAX][3];
double serial_numbers[MAX][2]= {{93416593540374,10},{43276547309812,5},{88374619937456,15}};

string line_package_type[MAX][3];
double line_balance[MAX][3];
string line_start_date[MAX][3];
string line_renew_date[MAX][3];

void registr(int x)
{
cout<<"Enter your name\n";
getline(cin,get[0]);
getline(cin,name[x]);
cout<<"Enter your address\n";
getline(cin,address[x]);
cout<<"Enter your email\n";
getline(cin,email[x]);
cout<<"Enter your password\n";
getline(cin,password[x]);
cout<<"Enter how many line numbers you need    Note:the maximum number of lines is three\n";
int k;
cin>>k;
while(k> 3 || k< 1 )
{
cout <<"your choice is invalid please Enter how many lines numbers you need again\n";
cin>>k;
}
for(int i=0 ; i<k; i++)
{
cout<<"Enter your line numbers\n";
cin>> line[x][i];
line_package_type[x][i]=" super flex ";
line_balance[x][i]=10;
line_start_date[x][i]="2 / 5 /"+Y;
line_renew_date[x][i]="2 / 6 /"+Y;
}
cout<<"\n\n\nyou registered successfully\n\n\n";
id[index]=index;
index++ ;
I=0;
return;
}
void login(string mail, string pass)
{
if(I>=0)
{
while(!f)
{
while( !f)
{
for(int i=0 ; i<index ; i++)
{
if(mail == email[i])
{
I=i;
f=1;
}
}
if(!f)
{
cout<<"that email is invalid please Enter your email\n";
getline(cin,mail);
}
}
f=0;
while(!f)
{
for(int i=0 ; i<index ; i++)
{
if(pass == password[i])
{
II=i;
f=1;
}
}
if(!f)
{
cout<<"that password is invalid please Enter your password\n";
getline(cin,pass);
}
}
if(I!=II)
{
f=0;
cout<<"email or password is invalid please Enter them correct\n";

cout<<"Enter your email\n";
getline(cin,mail);
cout<<"Enter your password\n";
getline(cin,pass);
}
}
f=0;
cout<<"\n\n\nwelcome "<<name[I]<<" you are logged in successfully what do you need to do now \n\n\n";
return ;
}
else
{
cout<<"\n\nplease register first\n\n\n";
return;
}
}
void renew(int e)
{
if(I>=0)
{
int s;
while( !f)
{
for(int i=0 ; i<3 ; i++)
{
if(e == line[I][i])
{
J=i;
f=1;
}
}
if(!f)
{
cout<<"that line_number is invalid please Enter your line_number\n";
cin>>e;
}
}
f=0;
while(!f)
{
cout<<"your package_type is  "<<line_package_type[I][J]<<" and your renew date is "<<line_renew_date[I][J]<<"\n"<<"Do you want change your package_type?\n1-yes\n2-no\n";

cin>>s;
if(s==1)
{
cout<<"please send for renew request firist your line_number\n";
cin>>e;
int ss;
while(!f)
{
cout<<"second select your new package from the next \n1- super flex\n2-flex plus\n3- big deal\n";
cin>>ss;
if(ss==1)
{
line_package_type[I][J]=" super flex";
f=1;
}
else if(ss==2)
{
line_package_type[I][J]=" flex plus";
f=1;
}
else if(ss==3)
{
line_package_type[I][J]=" big deal";
f=1;
}
else
{
f=0;
cout<<"invalid choice ";
}
}
f=0;
cout<<"\n\n\nyou renew your subscription successfully your new package is "<<line_package_type[I][J]<<"and your renew day is "<<D+"/"+M2+"/"+Y<<"\n\n\n";
line_renew_date[I][J]=D+"/"+M2+"/"+Y;
f=1;
}
else if(s==2)
{
cout<<"please send for renew request your line_number\n";
cin>>e;
cout<<"\n\n\nyou renew your subscription successfully your package is"<<line_package_type[I][J]<<"and your renew day is "<<D+"/"+M2+"/"+Y<<"\n\n\n";
line_renew_date[I][J]=D+"/"+M2+"/"+Y;
f=1;
}
else
cout<<"invalid choice ";
}
f=0;
return;
}
else
{
cout<<"\n\nplease log-in first\n\n\n";
return;
}
}
void make_call_message()
{
if(I>=0)
{
cout<<"the process will done with the first line_number have enough balance\n";
for(int i=0 ; i<3; i++)
{
if(line_balance[I][i]>=(0.25))
{
J=i;
line_balance[I][J]-=(0.25);
cout<<"\n\nyour balance now is"<<line_balance[I][J]<<"\n\n\n";
break;
}
else if (i==2)
cout<<"you have not enough balance in any number\n";
}
return;
}
else
{
cout<<"\n\nplease log-in first\n\n\n";
return;
}
}
void recharge_balance (long long NO)
{
if(I>=0)
{
long long serial ;
while(!f)
{
for(int i=0 ; i<3 ; i++)
{
if(NO == line[I][i])
{
J=i;
f=1;
}
}
if(!f)
{
cout<<"that line_number is invalid please Enter your line_number\n";
cin>>NO;
}
}
f=0;
cout<<"please enter your card serial number\n";
cin >> serial;
while (!f)
{
for(int i=0; i<5; i++)
{
if(serial_numbers[i][0]==serial)
{
line_balance[I][J]+=serial_numbers[I][1];
cout<<"\n\n\nthe card value= "<<serial_numbers[I][1]<<"\nbalance recharge successfully your new balance is"<<line_balance[I][J]<<"\n\n\n";
f=1;
}
}
if(!f)
{
cout<<"that card serial number is invalid please enter a valid card serial number\n";
cin>> serial;
}
}
f=0;
return;
}
else
{
cout<<"\n\nplease log-in first\n\n\n";
return;
}
}
void transfer_balance (long long NO1,long long NO2)
{
if(I>=0)
{
while(!f)
{
for(int j=0; j<index ; j++)
{
for(int i=0 ; i<3 ; i++)
{
if(NO1 == line[j][i])
{
J=i;
I=j;
f=1;
}
}
}
if(!f)
{
cout<<"the first line_number is invalid please Enter your line_number\n";
cin>>NO1;
}
}
f=0;
while(!f)
{
for(int j=0; j<index ; j++)
{
for(int i=0 ; i<3 ; i++)
{
if(NO2 == line[j][i])
{
II=j;
JJ=i;
f=1;
}
}
}
if(!f)
{
cout<<"the second line_number is invalid please Enter your line_number\n";
cin>>NO2;
}
}
f=0;
cout<<"please enter the amount you want to transfer\n";
int cach ;
cin>>cach;
for(int i=0 ; i<3; i++)
{
if(line_balance[I][J]>=cach)
{
J=i;
line_balance[I][J]-=cach;
break;
}
else if (i==2)
{
cout<<"you have not enough balance in that number\n";
return ;
}
}
line_balance[II][JJ]+=cach;
cout<<"\n\nthe "<<line[II][JJ]<<" new balance is "<<line_balance[II][JJ]<<"\n\n\n";
return;
}
else
{
cout<<"\n\nplease log-in first\n\n\n";
return;
}
}
int main()
{
int n;
while(true)
{
cout << "welcome please choose a process Number \n 1- Renew your subscription  \n 2- transfer balance \n 3- Recharge your balance  \n 4- make a call \n 5- send a message \n 6- Exit \n 7- log-in \n 8- register" << endl;

cin>> n;
switch(n)
{
case 1:
{
long long e;
cout<<"please enter your number\n";
cin>>e;
renew(e);
}
break;
case 2:
{
long long NO1,NO2;
cout<<"please enter number you will transfer from\n";
cin>>NO1;
cout<<"please enter number you will transfer to\n";
cin>>NO2;
transfer_balance (NO1,NO2);
}
break;
case 3:
{
long long e;
cout<<"please enter your number\n";
cin>>e;
recharge_balance(e);
}
break;
case 4:
make_call_message();
break;
case 5:
make_call_message();
break;
case 6:
return 0;
break;
case 7:
{
string q,w;
cout<<"Enter your email\n";
getline(cin,get[0]);
getline(cin,q);
cout<<"Enter your password\n";
getline(cin,w);
login(q,w);
break;
}
case 8:
registr(index);
break;
default:
cout<<"please Enter valid number\n";
break;
}
}
return 0;
}
