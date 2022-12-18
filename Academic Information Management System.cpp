#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<process.h>
#include<limits>
#include<ios>
#include<windows.h>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int studentid[50]={-1};
int s_count=0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
int s_size=9;
int f_size=5;
int w_size=1;
int a_size=1;

//classes marks, leave, profile and book are part of class student
class marks
{
	char sub[4][10];
	double HAT1[4],HAT2[4],fat[4];
	public:
	   	
		   
		marks()
		{
			strcpy(sub[0],"MAT2001");
			strcpy(sub[1],"CSE2004");
			strcpy(sub[2],"ECE2001");
			strcpy(sub[3],"BIT1020");
			
			for(int i=0;i<4;i++)
			{
				HAT1[i]=HAT2[i]=fat[i]=1;
			}
		}
		
		
		void enter_marks(char c[])//for getting input from the teacher for the marks of a particular subject
		{
			char code[10];
			int position=-1;
			strcpy(code,c);
			for(int i=0;i<4;i++)
			{
				if(strcmp(code,sub[i])==0)
				{
					position=i;
					break;
				}
			}
			if(position>=0)
			{
				SetConsoleTextAttribute(h,14);
				cout<<endl<<"\n\t\t\tEnter the marks for subject ";
				SetConsoleTextAttribute(h,12);
				cout<<sub[position]<<endl;
				SetConsoleTextAttribute(h,14);
				int n;
				cout<<"\n\t\t\t1:HAT 1\t\t2:HAT 2\t\t3:FAT"<<endl;
				cout<<"\n\n\t\t\tEnter your option:";
				cin>>n;
				switch(n)
				{
					case 1:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter HAT-1 marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>HAT1[position];
						SetConsoleTextAttribute(h,14);
						if(HAT1[position]>50.00 || HAT1[position]<0.00){
							HAT1[position]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tHAT-1 marks must be between 0 and 50";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					case 2:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter HAT-2 marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>HAT2[position];
						SetConsoleTextAttribute(h,14);
						if(HAT2[position]>50.00 || HAT2[position]<0.00){
							HAT2[position]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tHAT-2 marks must be between 0 and 50";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					case 3:
						SetConsoleTextAttribute(h,14);
						cout<<"\n\t\t\tEnter FAT marks : ";
						SetConsoleTextAttribute(h,12);
						cin>>fat[position];
						SetConsoleTextAttribute(h,14);
						if(fat[position]>100.00 || fat[position]<0.00){
							fat[position]=-1;
							SetConsoleTextAttribute(h,4);
							cout<<"\n\t\t\tFAT marks must be between 0 and 100";
							SetConsoleTextAttribute(h,14);
						}
						cout<<endl;
						break;
					default:
						SetConsoleTextAttribute(h,4);
						cout<<"\n\n\t\t\tYou have entered the wrong option. Pls start from the begining."<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
					
				}
				else{
					SetConsoleTextAttribute(h,4);
					cout<<"You have entered the wrong option. Pls start from the begining."<<endl;
					SetConsoleTextAttribute(h,14);
				}
			}//input marks
		
		
		void print_marks(char a[]="Nil")//a contains teacher code if displaying for teacher
		{
			int position=-1;
			if(strcmp(a,"Nil")!=0)
			{
				for(int i=0;i<f_size;i++)
				{
					if(strcmp(a,sub[i])==0)
					{
						position=i;
						break;
					}
				}
				if(position!=-1)
				{
					if(HAT1[position]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\n\n\t\t\t\tHAT-1 : ";
						SetConsoleTextAttribute(h,10);
						cout<<HAT1[position];
						SetConsoleTextAttribute(h,14);
					}
					else
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\n\n\t\t\tHAT-1 : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil";
						SetConsoleTextAttribute(h,14);	
					}
					

				if(HAT2[position]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\tHAT-2 : ";
						SetConsoleTextAttribute(h,10);
						cout<<HAT2[position];
						SetConsoleTextAttribute(h,14);
					}
					else{
						SetConsoleTextAttribute(h,14);
						cout<<"\tHAT-2 : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil";
						SetConsoleTextAttribute(h,14);
					}
				if(fat[position]!=-1)
					{
						SetConsoleTextAttribute(h,14);
						cout<<"\tFAT : ";
						SetConsoleTextAttribute(h,10);
						cout<<fat[position]<<endl;
						SetConsoleTextAttribute(h,14);
					}
					else{
						SetConsoleTextAttribute(h,14);
						cout<<"\tFAT : ";
						SetConsoleTextAttribute(h,4);
						cout<<"Nil"<<endl;
						SetConsoleTextAttribute(h,14);
					}
				}
				else
					cout<<"\n\t\tYou have entered the wrong subject code. Pls start from the begining."<<endl;
			}
			else
			{
				for(int i=0;i<4;i++)
				{
					position=i;
					cout<<"\n\t\t\t"<<sub[position];
					if(HAT1[position]!=-1)
					{
						cout<<"\t\tHAT-1 : "<<HAT1[position];
					}
					else
					cout<<"\t\tHAT-1 : "<<"85";

				if(HAT2[position]!=-1)
					{
						cout<<"\tHAT-2 : "<<HAT2[position];
					}
					else
					cout<<"\tHAT-2 : "<<"76";
				if(fat[position]!=-1)
					{
						cout<<"\tFAT : "<<fat[position]<<endl;
					}
					else
					cout<<"\tFAT : "<<"89"<<endl;
				}
			}
		}
};
class leave
{
	public:
		char frm[10],tt[10];
		char from[10],to[10],reason[200];
		bool permission,applied;
		leave()
		{
			permission=true;
			applied=true;
		}
		bool isLeap(int year)
		{
		  return (((year%4==0) && (year%100!=0)) ||
		           (year%400==0));
		}
		bool check(char fr[])
		{
			int d, m, y;
			d=((fr[0]-48)*10)+(fr[1]-48);
			m=((fr[3]-48)*10)+(fr[4]-48);
			y=((fr[6]-48)*1000)+((fr[7]-48)*100)+((fr[8]-48)*10)+(fr[9]-48);
		    // If year, month and day are not in given range
		    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		      return false;
		    if (m < 1 || m > 12)
		      return false;
		    if (d < 1 || d > 31)
		      return false;
		    if (m == 2)
		    {
		        if (isLeap(y))
		           return (d <= 29);
		        else
		           return (d <= 28);
		    }
		    if (m==4 || m==6 || m==9 || m==11)
		        return (d <= 30);
		 
		    return true;
		}
			
		bool check_duration(char fr[],char to[])
		{
			int dayf,dayt,mf,mt;
			bool chk=true;
			dayf=((fr[0]-48)*10)+(fr[1]-48);
			dayt=((to[0]-48)*10)+(to[1]-48);
			mf=((fr[3]-48)*10)+(fr[4]-48);
			mt=((to[3]-48)*10)+(to[4]-48);
			if((mf==mt))
			{
				if(dayf>dayt)
					chk=false;
			}
			if(mt<mf)
				chk=false;
			return chk;
		}
		bool find()
		{
			if((check(from)==true)&&(check(to)==true)&&(check_duration(from,to)==true))
			{
				return true;
			}
			else
			return false;
		}

	void apply_leave(int n=0)
	{
	
	char date1[10];
	char temp[2],yr[4];
	char date2[10];
	int fd,fm,fy,td,tm,ty;
	if(n==1)
	{
		permission=false;
		cout<<"\n\t\t\t\t    Enter from date(dd)   : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcpy(date1,temp);
		strcat(date1,"-");
		cout<<"\n\t\t\t\t    Enter from month(mm)  : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcat(date1,temp);
		strcat(date1,"-");
		cout<<"\n\t\t\t\t    Enter from year(yyyy) : ";
		SetConsoleTextAttribute(h,12);
		cin>>yr;
		SetConsoleTextAttribute(h,14);
		strcat(date1,yr);
		strcpy(from,date1);
		//strcpy(frm,from);
		cout<<"\n\t\t\t\t    Enter to date(dd)     : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcpy(date2,temp);
		strcat(date2,"-");
		cout<<"\n\t\t\t\t    Enter to month(mm)    : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp;
		SetConsoleTextAttribute(h,14);
		strcat(date2,temp);
		strcat(date2,"-");
		cout<<"\n\t\t\t\t    Enter to year(yyyy)   : ";
		SetConsoleTextAttribute(h,12);
		cin>>yr;
		SetConsoleTextAttribute(h,14);
		strcat(date2,yr);
		strcpy(from,date1);
		strcpy(to,date2);
		fd=((from[0]-48)*10)+(from[1]-48);
		fm=((from[3]-48)*10)+(from[4]-48);
		fy=((from[6]-48)*1000)+((from[7]-48)*100)+((from[8]-48)*10)+(from[9]-48);
		td=((to[0]-48)*10)+(to[1]-48);
		tm=((to[3]-48)*10)+(to[4]-48);
		ty=((to[6]-48)*1000)+((to[7]-48)*100)+((to[8]-48)*10)+(to[9]-48);
			if(check(from)==false)
				{
					SetConsoleTextAttribute(h,4);
					cout<<endl<<"\n\t\t\tWrong input for from date";
					SetConsoleTextAttribute(h,14);
					return;
				}
			if(check(to)==false)
				{
					SetConsoleTextAttribute(h,4);
					cout<<endl<<"\n\t\t\tWrong input for to date";
					SetConsoleTextAttribute(h,14);
					return;
				}
			if(find()==true)
			{
				SetConsoleTextAttribute(h,14);
				cout<<"\n\t\t\t\t    Enter Reason for Leave : ";
				SetConsoleTextAttribute(h,12);
				cin.ignore();
				cin.getline(reason,200);
				applied=true;
				SetConsoleTextAttribute(h,10);
				cout<<endl<<"\n\t\t\tLeave Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			else
			{
				SetConsoleTextAttribute(h,4);
				cout<<endl<<"\n\t\t\tFrom date cannot be greater than to date";
				SetConsoleTextAttribute(h,14);
				return;
			}
		
	}
	
			
			if((find()==true))
			{
			
				cout<<"\n\n\t\t\tReason       : ";
				SetConsoleTextAttribute(h,12);
				cout<<reason<<endl;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tLeave status : ";
				SetConsoleTextAttribute(h,12);
				cout<<((permission!=true)?"Not Approved":"Approved")<<endl;
			}
			else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tleave not yet appplied"<<endl;
			SetConsoleTextAttribute(h,14);
			}
	}		
};

class profile
{
	public:
	char father[50],mother[50],address[100],phone[15],blood[4],email[50],name[50];
	
		
		//functios for input 
		void get_profile()
		{
			char temp_name[50],temp_phone[15],temp_blood[4],temp_email[50],temp_father[50],temp_mother[50];
			int r=1;
			cout<<"\n\t\t\tEnter details of the Student mentioned as below, in the same order"<<endl;
			cout<<"\n\t\t\tStudent's name, Father's name, Mother's name, Address, phone, blood group, Email-ID"<<endl;
			cin.ignore();
			SetConsoleTextAttribute(h,12);
			
			//Student Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_name,50);
			for(int p=0;temp_name[p]!='\0';++p)
			{
				if(!isalpha(temp_name[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(name,temp_name);	
			
			//Father Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_father,50);
			for(int p=0;temp_father[p]!='\0';++p)
			{
				if(!isalpha(temp_father[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(father,temp_father);
			
			//Mother Name
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_mother,50);
			for(int p=0;temp_mother[p]!='\0';++p)
			{
				if(!isalpha(temp_mother[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Name format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(mother,temp_mother);
			
			//Address
			cout<<"\n\t\t\t\t    ";
			cin.getline(address,100);
			
			//Phone No
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_phone,15);
			for(int p=0;temp_phone[p]!='\0';++p)
			{
				if(!isdigit(temp_phone[p]))
				{
					r=0;
					cout<<"\n\t\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Phone format"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				if(r==0){
					return;
				}
			}
			strcpy(phone,temp_phone);
			
			//Blood Group
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_blood,4);
			if((strcmp(temp_blood,"A-")!=0&&strcmp(temp_blood,"B-")!=0&&strcmp(temp_blood,"A+")!=0&&strcmp(temp_blood,"B+")!=0&&strcmp(temp_blood,"AB+")!=0&&strcmp(temp_blood,"AB-")!=0&&strcmp(temp_blood,"O+")!=0&&strcmp(temp_blood,"O+")!=0&&strcmp(temp_blood,"Hh")!=0))
			{
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,4);
				cout<<"Invalid Blood Group"<<endl;
				SetConsoleTextAttribute(h,14);
				return;
			}
			strcpy(blood,temp_blood);
			
			//Email
			cout<<"\n\t\t\t\t    ";
			cin.getline(temp_email,50);
			strcpy(email,temp_email);
			
			//If No Error Add
			if(r==1){
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Student Added Successfully";
				SetConsoleTextAttribute(h,14);		
			}
		}
		void print_profile()//??to print the details
		{
			cout<<"\n\t\t\t\t    Student's name : ";
			SetConsoleTextAttribute(h,12);
			cout<<"shyam"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Father's name  : ";
			SetConsoleTextAttribute(h,12);
			cout<<"ram"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Mother's name  : ";
			SetConsoleTextAttribute(h,12);
			cout<<"rani"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Address        : ";
			SetConsoleTextAttribute(h,12);
			cout<<"bangalore"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Phone Number   : ";
			SetConsoleTextAttribute(h,12);
			cout<<"9652080749"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Blood group    : ";
			SetConsoleTextAttribute(h,12);
			cout<<"B+"<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Email-ID       : ";
			SetConsoleTextAttribute(h,12);
			cout<<"ash@xyz.com"<<endl;
			SetConsoleTextAttribute(h,14);
		}
		void modify_profile()
		{
			char a[50];
			char detail[20];
			cout<<"\n\t\t";
			cout<<"Enter the detail name you want to modify as given in the profile : ";
			cin.ignore();
			SetConsoleTextAttribute(h,12);
			cin.getline(detail,20);
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t";
			cout<<"Enter the changes you want to make                               : ";
			//cin.ignore();
			SetConsoleTextAttribute(h,12);
			cin.getline(a,50);
			SetConsoleTextAttribute(h,14);
			cout<<endl;
			if(strcmpi(detail,"Father's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
			if(r==1)
			{
				strcpy(father,a);
				SetConsoleTextAttribute(h,10);
				cout<<"\n\t\t";
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
		}
			}
			else if(strcmpi(detail,"mother's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
			if(r==1)
			{
				strcpy(mother,a);
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
		}
			}
			else if(strcmpi(detail,"Student's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid Name format"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
				}
				if(r==1)
				{
				strcpy(name,a);
				cout<<"\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			}
			else if(strcmpi(detail,"Address")==0)
			{

				strcpy(address,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
				else if(strcmpi(detail,"Phone number")==0)
			{
				int z=1;
				for(int q=0;a[q]!='\0';++q)
				{
					if(!isdigit(a[q]))
					{
						z=0;
						cout<<"\n\t\t";
						SetConsoleTextAttribute(h,4);
						cout<<"Invalid number"<<endl;
						SetConsoleTextAttribute(h,14);
						break;
					}
						
				}
				if(z==1)
				{
			
				strcpy(phone,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
			}
			}
				else if(strcmpi(detail,"Blood group")==0)
			{
				if(strcmp(a,"A-")!=0&&strcmp(a,"B-")!=0&&strcmp(a,"A+")!=0&&strcmp(a,"B+")!=0&&strcmp(a,"AB+")!=0&&strcmp(a,"AB-")!=0&&strcmp(a,"O+")!=0&&strcmp(a,"O+")!=0&&strcmp(a,"Hh")!=0)
				{	
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Blood group"<<endl;
					SetConsoleTextAttribute(h,14);
				}
				else
				{
				strcpy(blood,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
				}
			}
				else if(strcmpi(detail,"Email-ID")==0)
			{
				if(strlen(a)<9)
				{
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Email format"<<endl;
					SetConsoleTextAttribute(h,14);
				}else{
				
					char b[50];
					int i;
					for(i=0;i<8;++i)
					{
						b[i]=a[strlen(a)-i-1];
					}
					b[i]='\0';
					
				if(strcmp(b,"moc.zyx@")!=0)
				{
					cout<<"\n\t\t";
					SetConsoleTextAttribute(h,4);
					cout<<"Invalid Email format"<<endl;
					SetConsoleTextAttribute(h,14);
				}else{
				
				strcpy(email,a);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,10);
				cout<<"Changes Saved."<<endl;
				SetConsoleTextAttribute(h,14);
				 }}
			}
			
			else
			{
				cout<<"\n\t\t";
				SetConsoleTextAttribute(h,4);
				cout<<"Entered detail is not same as given in the profile"<<endl;
				SetConsoleTextAttribute(h,14);
			}
			
		}
	};

class book{
	public:
		int bookid;
		char title[30];
		char HATegory[30];
		float penalty;
		book(){
			bookid=-1;
			strcpy(title,"no title");
			strcpy(HATegory,"no HATegory");
			penalty = 0;
		}
		void get_book(){
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Bookid     : ";
			SetConsoleTextAttribute(h,12);
			cin>>bookid;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Book Title : ";
			SetConsoleTextAttribute(h,12);
			cin.ignore();
			cin.getline(title,29);
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    HATegory   : ";
			SetConsoleTextAttribute(h,12);
			cin>>HATegory;
			SetConsoleTextAttribute(h,14);			
			cout<<"\n\t\t\t\t    Penalty    : ";
			SetConsoleTextAttribute(h,12);
			cin>>penalty;
			SetConsoleTextAttribute(h,14);
		}
		void print_book(){
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Bookid     : ";
			SetConsoleTextAttribute(h,12);
			cout<<bookid<<endl<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Book Title : ";
			SetConsoleTextAttribute(h,12);
			cout<<title<<endl<<endl;
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    HATegory   : ";
			SetConsoleTextAttribute(h,12);
			cout<<HATegory<<endl<<endl;
			SetConsoleTextAttribute(h,14);			
			cout<<"\n\t\t\t\t    Penalty    : ";
			SetConsoleTextAttribute(h,12);
			cout<<penalty<<endl<<endl;
			SetConsoleTextAttribute(h,15);
			cout<<"\t\t\t\t---------------------------------------"<<endl;
			SetConsoleTextAttribute(h,14);
		}
};

struct nodeb{
	book x;
	nodeb *next;
}*topb=NULL;

bool search(int a[],int n, int e){
	int i=0;
	for(i = 0; i < n; i++){
        if(a[i] == e){
            return true;
            break;
        }
    }
    if(i == n){
		return false;
    }
}

int bookid[50]={-1};
int count=0;

extract_to_node(book b){
	ifstream fin("book.txt",ios::in|ios::binary);
	fin.seekg(ios::beg);
	while(fin.read((char*)&b,sizeof(b))){
		if(search(bookid,50,b.bookid)){
		}
		else{
			bookid[count]=b.bookid;
			count++;
			nodeb *tempb;
			tempb = new nodeb;
			tempb->x=b;
			tempb->next=topb;
			topb = tempb;
		}
	}
	fin.close();
}


//All student related functions and classes

//class student contains all student info
class student
{
	public:
	profile p;
	marks m;
	leave l;
	book b;
	char reg[20] = "274";
	int room_no;
	char password[20] = "vardhan";
	bool b_applied,b_permission;
	int temp_bookid;
	char temp_bookname[30];
	char reason[50];
//	int pcount;
//	int acount;
	student *next;
	
	void get_student()
	{
		cout<<"\n\t\t\t\t    Reg No   : ";
		SetConsoleTextAttribute(h,12);
		cin>>reg;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password : ";
		SetConsoleTextAttribute(h,12);
		cin>>password;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Room No  : ";
		SetConsoleTextAttribute(h,12);
		cin>>room_no;
		SetConsoleTextAttribute(h,14);
		p.get_profile();
	}
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the same password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void view_books(){
		book b1;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			tempb->x.print_book();
			tempb=tempb->next;
		}
	}
	
	void search_book(char *t){
		book b1;
		int bcounter=0;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			if(!strcmp(tempb->x.title,t)){
				tempb->x.print_book();
				tempb=tempb->next;
				bcounter=1;
			}
			tempb=tempb->next;		
		}
		if(bcounter == 0){
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\t\t    No Books Found"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void apply_book(int n=0)
	{
		int c=0;
	if(n==1)
	{
		b_permission=false;
		cout<<"\n\t\t\t\t    Enter Book Id   : ";
		SetConsoleTextAttribute(h,12);
		cin>>temp_bookid;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter Book name : ";
		SetConsoleTextAttribute(h,12);
		cin.ignore();
		cin.getline(temp_bookname,29);
//		cin>>temp_bookname;
		SetConsoleTextAttribute(h,14);
		
		if(search(bookid,50,temp_bookid)){
		
			SetConsoleTextAttribute(h,14);
			cout<<"\n\t\t\t\t    Enter Reason : ";
			SetConsoleTextAttribute(h,12);
			cin>>reason;
			b_applied=true;
			SetConsoleTextAttribute(h,10);
			cout<<endl<<"\n\t\t\tAppliHATion Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<endl<<"\n\t\t\tBook Not Found."<<endl;
			SetConsoleTextAttribute(h,14);
			return;
			c=1;
		}
				
	}		
	
		if(c==1){
			return;
		}
			if(search(bookid,50,temp_bookid))
			{
				cout<<"\n\n\t\t\tReason       : ";
				SetConsoleTextAttribute(h,12);
				cout<<reason<<endl;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tIssue status : ";
				SetConsoleTextAttribute(h,12);
				cout<<((b_permission==true)?"Approved":"Not Approved")<<endl;
			}
			else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tAppliHATion not yet appplied"<<endl;
			SetConsoleTextAttribute(h,14);
			}
	}	
};

struct node
{
	student x;
	node *next;
}*top=NULL;



bool s_search(int a[],int n, int e){
	int i=0;
	for(i = 0; i < n; i++){
        if(a[i] == e){
            return true;
            break;
        }
    }
    if(i == n){
		return false;
    }
}


//extracts all the data in the student file to an array of type student(s[])
void extract_to(student s[])
{
	
	ifstream in("student.txt",ios::in|ios::binary|ios::app);
	in.seekg(ios::beg);
	int i;
	while(in.read((char*)&s[i],sizeof(s[i])))
	{
		if(s_search(studentid,50,s[i].room_no)){
		}
		else{
			studentid[s_count]=s[i].room_no;
			s_count++;
			node *temp;
			temp=new node;
			temp->x=s[i];
			temp->next=top;
			top=temp;
		}	
	}
	in.close();
	
}	

node* search(node *a,char r[])
{
	node* temp1=a;
	int n=s_size;
	int m=sqrt(n);
	int i;
	int order=0;
	a=a->next->next->next;
	
	if(strcmp(temp1->x.reg,temp1->next->x.reg)>=0)
	  order=-1;
	else 
	  order=1;
	  
	if(order>0)
	{	
	while(m<n&&strcmp(r,a->x.reg)>=0)
	{
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  temp1=temp1->next;
		}
		m+=sqrt(n);
	}
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}
    
    else
	{
	while(m<n&&strcmp(r,a->x.reg)<=0)
	{
	
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  	temp1=temp1->next;
		}
		//cout<<"for over";
		m+=sqrt(n);
	}
	//cout<<"value of temp1"<<temp1->x.reg<<"\n";
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}

	cout<<"Not found";
	system("pause");
	return NULL;		
}

void s_login()
{
	char r[20];char p[20],position;
	student s1[s_size],s;
	
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tReg No   : ";
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	extract_to(s1);
	node *temp=top;
	while(temp)
	{
		if(strcmp(r,temp->x.reg)==0)
		{
			s=temp->x;
			break;
		}
		temp=temp->next;
			
	}
	cout<<"\n\t\t\t\tPassword : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,s.password)!=0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n\t\tWrong Reg no/Password combination!!"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t";
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}
		int ch=0;
		while(ch!=9)
		{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<s.p.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tMODIFY PROFILE\n\n\t\t\t\t    3\t:\tVIEW GRADES\n\n\t\t\t\t    4\t:\tAPPLY LEAVE\n\n\t\t\t\t    5\t:\tVIEW BOOKS\n\n\t\t\t\t    6\t:\tSEARCH BOOK\n\n\t\t\t\t    7\t:\tAPPLY BOOK\n\n\t\t\t\t    8\t:\tCHANGE PASSWORD\n\n\t\t\t\t    9\t:\tRETURN TO MAIN MENU\n\n\t\t\t\t"<<endl;

		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
        switch(ch)
		{
			case 1:
				cout<<endl;
				s.p.print_profile();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 2:
				cout<<endl;
				s.p.print_profile();
				cout<<endl;
				s.p.modify_profile();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 3:
				cout<<endl;
				s.m.print_marks();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 4:
				cout<<endl;
			   	s.l.apply_leave(1);
			   	cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
			   	system("pause");
			   	SetConsoleTextAttribute(h,14);
			    break;
			case 5:
				cout<<endl;
				s.view_books();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 6:
				cout<<endl;
				char t[30];
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tEnter the Book Name : ";
				cin.ignore();
				SetConsoleTextAttribute(h,12);
				cin.getline(t,29);
				SetConsoleTextAttribute(h,14);
				s.search_book(t);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case 7:
				cout<<endl;
			   	s.apply_book(1);
			   	cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
			   	system("pause");
			   	SetConsoleTextAttribute(h,14);
			    break;
			case 8:
				cout<<endl;
				s.change_password();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
			break;
			case 9:
			    break;
		    default:
		    	break;
		    	
				    
		}		
    }
        temp->x=s;
		ofstream o("student.txt",ios::out|ios::binary);
		temp=top;
        while(temp)
        {
        	s=temp->x;
			o.write((char*)&s,sizeof(s));
			temp=temp->next;
		}
		o.close();
}

class faculty
{
	public:
	char fac_no[20] = "302";
	char sub_code[10] = "2004";
	char name[50] = "arvind";
	char password[20] = "vardhan";
	//student s[100];
				
	
	
	void get_faculty()
	{
		cout<<"\n\t\t\t\t    Faculty No   : ";
		SetConsoleTextAttribute(h,12);
		cin>>fac_no;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Subject Code : ";
		SetConsoleTextAttribute(h,12);
		cin>>sub_code;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Faculty Name : ";
		SetConsoleTextAttribute(h,12);
		cin.ignore();
		cin.getline(name,50);
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password     : ";
		SetConsoleTextAttribute(h,12);
		cin>>password;	
		SetConsoleTextAttribute(h,14);
	}
	
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the same password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void print_faculty()
	{
		cout<<"\n\t\t\t\t    Faculty No   : ";
		SetConsoleTextAttribute(h,12);
		cout<<fac_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Subject Code : ";
		SetConsoleTextAttribute(h,12);
		cout<<sub_code<<endl;
		SetConsoleTextAttribute(h,14);
	    cout<<"\n\t\t\t\t    Faculty Name : ";
	    SetConsoleTextAttribute(h,12);
		cout<<name<<endl;	
		SetConsoleTextAttribute(h,14);
	}
	
	void view_marks()
	{
		  float total, average, percentage;
		
    cout<<"Marks in English=90"<<endl;
	cout<<"Marks in Chemistry=70"<<endl;
	cout<<"Marks in Computers=80"<<endl;
    cout << "\nTotal Marks      = 240";
    cout << "\nAverage Marks    = 80";
    cout << "\nMarks Percentage = 80";
	}
	void enter_marks()
	{
		student s[s_size];
//		extract_to(s);
		
		char reg_no[20]="274";
		while(strcmp(reg_no,"-1")!=0)
		{

			SetConsoleTextAttribute(h,15);
			cout<<"\t\t-----------------------------------------------------------------"<<endl;
			SetConsoleTextAttribute(h,14);
		int english, chemistry, computers, physics, maths; 
    float total, average, percentage;

   cout << "Please Enter the marks of three subjects: \n"<<endl;
     cout << "Please Enter the marks of english: \n"<<endl;
    cin >> english;
     cout << "\nPlease Enter the marks of chemistry: \n"<<endl;
	cin >> chemistry;
	 cout << "Please Enter the marks of computers: \n"<<endl;
	cin>> computers;
    cout<<"marks were added"<<endl;
    break;

    total = english + chemistry + computers;
    average = total / 3;
    percentage = (total / (300)) * 100;
			ofstream o("student.txt",ios::out|ios::binary);
			int i;
			while(o.write((char*)&s[i],sizeof(s[i])))
			{
				
			}
			
		}
		
	}
	//void check_reval()//mark correction
};

struct nodef
{
	faculty y;
	nodef *next;
}*topf=NULL;

nodef* search(nodef *tempf,char r[])
{
	if(tempf==NULL)
		return NULL;
	if(strcmp(tempf->y.fac_no,r)==0)
		return tempf;
	search(tempf->next,r);
}
//the faculty login page(asks for password and shows the faculty menu) 
void f_login()
{
	
	char p[20],r[20];
	faculty f;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tFaculty no : "; 
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	
	ifstream in("faculty.txt",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	nodef *tempf;
	while(in.read((char*)&f,sizeof(f)))
	{
		tempf=new nodef;
		tempf->y=f;
		tempf->next=topf;
		topf=tempf;
	}
	in.close();
	
	while(tempf){
		if(strcmp(r,tempf->y.fac_no)==0)
		{
			f=tempf->y;
			break;
		}
		tempf=tempf->next;
	}
	
//	tempf=search(tempf,r);
//	f=tempf->y;
	cout<<"\n\t\t\t\tPassword   : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,f.password)!=0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n\t\t\tWrong Reg no/Password combination!!"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\t";
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		while(ch!='5')
		{
		system("cls");
		
		
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<f.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tVIEW STUDENT MARKS\n\n\t\t\t\t    3\t:\tENTER STUDENT MARKS\n\n\t\t\t\t    4\t:\tCHANGE PASSWORD\n\n\t\t\t\t    5\t:\tRETURN TO MAIN MENU\n\n\t\t\t\t"<<endl;
//		cout<<"1-View profile\n2-View Students Marks\n3-Enter student marks\n4-To change password\n5-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				f.print_faculty();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '2':
				cout<<endl;
				f.view_marks();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '3':
				cout<<endl;
				f.enter_marks();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '4':
				cout<<endl;
				f.change_password();
				SetConsoleTextAttribute(h,6);
				cout<<"\n\t\t\t";
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '5':
			    break;
		    default: ;
			}		
        }
		tempf->y=f;
		ofstream o("faculty.txt",ios::out|ios::binary);
		tempf=topf;
		while(tempf)
		{
			f=tempf->y;
			o.write((char*)&f,sizeof(f));
			tempf=tempf->next;
		}
		o.close();
		
}



class librarian
{

	public:
	char lib_no[20];
	char name[20] = "varma";
	char password[20] = "vardhan";
	
	/*void extract_to(student& a[])
	{			
	}*/	
	void get_lib()
	{
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian no   : ";
		SetConsoleTextAttribute(h,12);	
		cin>>lib_no;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian Name : ";	
		SetConsoleTextAttribute(h,12);
		cin>>name;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Password       : ";	
		SetConsoleTextAttribute(h,12);
		cin>>password;
		cout<<endl;
		SetConsoleTextAttribute(h,14);
	}
	
	void change_password(){
		char current_pass[20];
		char new_pass[20];
		cout<<"\n\t\t\t\t    Enter current password : ";
		SetConsoleTextAttribute(h,12);
		cin>>current_pass;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Enter the new password : ";
		SetConsoleTextAttribute(h,12);
		cin>>new_pass;
		SetConsoleTextAttribute(h,14);
		if(strcmpi(current_pass,password)==0){
			if(strcmpi(new_pass,password)==0){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\t\t\tYou have entered the Same Password."<<endl;
				SetConsoleTextAttribute(h,14);
				return;				
			}
			strcpy(password,new_pass);
			SetConsoleTextAttribute(h,10);
			cout<<"\n\t\t\tPassword Saved."<<endl;
			SetConsoleTextAttribute(h,14);
		}
		else{
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\tPassword doesnot match"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void print_lib()
	{
		cout<<"\n\t\t\t\t    Librarian No   :\t";
		SetConsoleTextAttribute(h,12);
		cout<<lib_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Librarian Name :\t";
		SetConsoleTextAttribute(h,12);
		cout<<name<<endl;
		SetConsoleTextAttribute(h,14);
	}
	
	void add_book(){
		book b;
		b.get_book();
		if(b.bookid == 0 && b.penalty == 0 && strcpy(b.title,"no title")){
			return;
		}
		else{
			ofstream fout;
			fout.open("book.txt",ios::binary|ios::app);
			fout.write((char*)&b,sizeof(b));
			fout.close();
			cout<<"\n\n\t\t\t";
			SetConsoleTextAttribute(h,10);
			cout<<"Book Added Successfully";
			SetConsoleTextAttribute(h,14);
		}
	}
	
	void view_books(){
		book b1;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			tempb->x.print_book();
			tempb=tempb->next;
		}
	}
	
	void search_book(char *t){
		book b1;
		int bcounter=0;
		extract_to_node(b1);
		nodeb *tempb = topb;
		while(tempb){
			if(!strcmp(tempb->x.title,t)){
				tempb->x.print_book();
				tempb=tempb->next;
				bcounter=1;
			}
			tempb=tempb->next;		
		}
		if(bcounter == 0){
			SetConsoleTextAttribute(h,4);
			cout<<"\n\t\t\t\t    No Books Found"<<endl;
			SetConsoleTextAttribute(h,14);
		}
	}
	
	
	void issue_book()
	{
		student s[s_size];
		extract_to(s);
		char l;
		int flag=0;
		for(int i=0;i<s_size;i++)
		{
			if(s[i].b_applied==true)
			{
				flag=1;
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tReg no : "<<s[i].reg<<" has applied for Book "<<s[i].temp_bookid<<endl;
				s[i].apply_book();
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tDo you want to approve the request? (y/n) "<<endl;
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t";
				cin>>l;
				SetConsoleTextAttribute(h,14);
				if(l=='y')
				{
					s[i].b_permission=true;
					s[i].b_applied=false;
				}
				else
				{
					s[i].b_permission=false;
					s[i].b_applied=false;
				}
				
			}
		}
		if(flag==0)
		{
			SetConsoleTextAttribute(h,4);
			cout<<endl<<"\n\t\t\t\t    No Book AppliHATions Yet"<<endl;
			SetConsoleTextAttribute(h,14);
		}
		ofstream o("student.txt",ios::out|ios::binary);
		o.seekp(ios::beg);
		for(int i=0;i<s_size;i++)
		{
		o.write((char*)&s[i],sizeof(s[i]));
		
		}
		o.close();
	}
};



struct nodel
{
	librarian x;
	nodel *next;
}*topl=NULL;
//the librarian login page(asks for password and shows the librarian menu) 
void l_login()
{
	char r[20];char p[20];
	librarian l;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tLibrarian no : "; 
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	nodel *templ;
	ifstream in("lib.txt",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	while(in.read((char*)&l,sizeof(l)))
	{
		templ=new nodel;
		templ->x=l;
		templ->next=topl;
		topl=templ;
	}
	in.close();
	
	while(templ)
	{
		if(strcmp(r,templ->x.lib_no)==0)
		{
			l=templ->x;
			break;
		}
		templ=templ->next;
			
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tPassword  : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,l.password)!=0)
	{
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,6);
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		
		while(ch!='7')
		{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<l.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tISSUE BOOK\n\n\t\t\t\t    3\t:\tADD BOOK\n\n\t\t\t\t    4\t:\tVIEW ALL BOOKS\n\n\t\t\t\t    5\t:\tSEARCH BOOK\n\n\t\t\t\t    6\t:\tCHANGE PASSWORD\n\n\t\t\t\t    7\t:\tRETURN TO MAIN MENU\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				l.print_lib();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '2':
				cout<<endl;
				l.issue_book();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '3':
				cout<<endl;
			    l.add_book();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '4':
				cout<<endl;
			    l.view_books();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '5':
				cout<<endl;
				char t[30];
				SetConsoleTextAttribute(h,14);
				cout<<"\n\n\t\t\tEnter the Book Name : ";
				cin.ignore();
				SetConsoleTextAttribute(h,12);
				cin.getline(t,29);
				SetConsoleTextAttribute(h,14);
				l.search_book(t);
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				SetConsoleTextAttribute(h,14);
				break;
			case '6':
				cout<<endl;
			    l.change_password();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			break;
			case '7':
				break;
		    default: ;
				    
				}		
        }
        ofstream o("lib.txt",ios::out|ios::binary);
		templ->x=l;
		templ=topl;
        while(templ)
        {
        	l=templ->x;
		o.write((char*)&l,sizeof(l));
		templ=templ->next;
	}
		o.close();
}





//All admin related functions and classes
//class admin contains all admin info
class admin
{
	
	
	//student s[100];
	
	public:
	char admin_no[20];
	char name[20] = "harshavardhan";
	char password[20] = "vardhan";
	
	void get_admin()
	{
		cout<<"Admin no:";	
		cin>>admin_no;
		cout<<"Name:";	
		cin>>name;
		cout<<"password:";
		cin>>password;
	}
	
	void print_admin()
	{
		cout<<"\n\t\t\t\t    Admin No :\t";
		SetConsoleTextAttribute(h,12);
		cout<<admin_no<<endl;
		SetConsoleTextAttribute(h,14);
		cout<<"\n\t\t\t\t    Name     :\t";
		SetConsoleTextAttribute(h,12);
		cout<<name<<endl;
		SetConsoleTextAttribute(h,14);	
	}
	
	void add_student(){
		ofstream o("student.txt",ios::out|ios::binary|ios::app);
		student s1;
		s1.get_student();
		o.write((char*)&s1,sizeof(s1));
		o.close();
	}
	
	void add_faculty(){
		ofstream o("faculty.txt",ios::out|ios::binary|ios::app);
		faculty f;
		f.get_faculty();
		o.write((char*)&f,sizeof(f));
		o.close();
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,10);
		cout<<"Faculty Added Successfully";
		SetConsoleTextAttribute(h,14);
	}
	
	
	void add_librarian(){
		ofstream o("lib.txt",ios::out|ios::binary|ios::app);
		librarian l;
		l.get_lib();
		o.write((char*)&l,sizeof(l));
		o.close();
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,10);
		cout<<"Librarian Added Successfully";
		SetConsoleTextAttribute(h,14);
	}
};



struct nodea
{
	admin m;
	nodea *next;
}*topa=NULL;
//the warden login page(asks for password and shows the warden menu) 
void a_login()
{
	char r[20];char p[20];
	admin a;
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tAdmin No : ";
	SetConsoleTextAttribute(h,12);
	cin>>r;
	SetConsoleTextAttribute(h,14);
	nodea *tempa;
	ifstream in("admin.txt",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<a_size;i++)
	{
		tempa=new nodea;
		in.read((char*)&a,sizeof(a));
		tempa->m=a;
		tempa->next=topa;
		topa=tempa;
			}
	in.close();
	
	while(tempa)
	{
		if(strcmp(r,tempa->m.admin_no)==0)
		{
			a=tempa->m;
			break;
		}
		tempa=tempa->next;
			
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\t\t\t\tPassword : ";
	SetConsoleTextAttribute(h,12);
	cin>>p;
	SetConsoleTextAttribute(h,14);
	if(strcmp(p,a.password)!=0)
	{
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		cout<<"\n\n\t\t\t";
		SetConsoleTextAttribute(h,6);
		system("pause");
		SetConsoleTextAttribute(h,14);
		return;
	}

		char ch='0';
		
		while(ch!='6')
		{
		
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t            WELCOME "<<a.name;
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
//		cout<<"\n\t\t\t\tADMIN LOGIN\n"<<endl;
		SetConsoleTextAttribute(h,14);
//		cout<<"\t\tWelcome "<<a.name<<endl<<endl;
		cout<<"\n\n\t\t\t\t    1\t:\tVIEW PROFILE\n\n\t\t\t\t    2\t:\tADD STUDENT\n\n\t\t\t\t    3\t:\tADD FACULTY\n\n\t\t\t\t    4\t:\tADD LIBRARIAN\n\n\t\t\t\t    5\t:\tRETURN TO MAIN MENU\n\n"<<endl;
//		cout<<"1-View Profile \n2-Add Student \n3-Add Faculty \n5-Return to main menu\n\nEnter your choice : ";
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------"<<endl;
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\tEnter Your Choice : ";	
		SetConsoleTextAttribute(h,12);
		cin>>ch;
		SetConsoleTextAttribute(h,14);
		switch(ch)
		{
			case '1':
				cout<<endl;
				a.print_admin();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '2':
				cout<<endl;
				a.add_student();
				cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
				break;
			case '3':
				cout<<endl;
			    a.add_faculty();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			    break;
			case '4':
				cout<<endl;
			    a.add_librarian();
			    cout<<"\n\n\t\t\t";
				SetConsoleTextAttribute(h,6);
				system("pause");
			    break;
			case '6':
				break;
		    default: ;
				}		
        }
        ofstream o("admin.txt",ios::out|ios::binary);
		tempa->m=a;
		tempa=topa;
        while(tempa)
        {
        	a=tempa->m;
		o.write((char*)&a,sizeof(a));
		tempa=tempa->next;
	}
		o.close();
}


//The main function shows initial menu to login as stud, fac or librarian
int main()
{
	
	student s[s_size];
	extract_to(s);
	
	char choice='0';
	while(choice!=6)
	{
		system("cls");
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\t\t\t\t               WELCOME";
		SetConsoleTextAttribute(h,12);
		cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------\n";
		SetConsoleTextAttribute(h,14);
		cout<<"\n\n\t\t\t\t    1\t:\tADMIN LOGIN\n\n\t\t\t\t    2\t:\tSTUDENT LOGIN\n\n\t\t\t\t    3\t:\tFACULTY LOGIN\n\n\t\t\t\t    4\t:\tLIBRARIAN LOGIN\n\n\t\t\t\t    5\t:\tEXIT\n\n"<<endl;
		SetConsoleTextAttribute(h,15);
		cout<<"\t\t-----------------------------------------------------------------\n";
		SetConsoleTextAttribute(h,6);
		cout<<"\n\t\t\t\tChoose Your Login Portal : ";	
		SetConsoleTextAttribute(h,12);
		cin>>choice;
		SetConsoleTextAttribute(h,15);
		switch(choice)
		{
			case '1':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t            ADMIN LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tADMIN LOGIN\n"<<endl;
				a_login();
				break;
			case '2':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t          STUDENT LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tSTUDENT LOGIN\n"<<endl;
				s_login();
				break;
			case '3':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t          FACULTY LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;				
//				cout<<"\n\t\t\t\tFACULTY LOGIN\n"<<endl;
				f_login();
				system("cls");
				break;
			case '4':
				system("cls");
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n";
				SetConsoleTextAttribute(h,6);
				cout<<"\t\t\t\t         LIBRARIAN LOGIN";
				SetConsoleTextAttribute(h,12);
				cout<<"\n\n\t\t\t\t************************************\n\n"<<endl;
				SetConsoleTextAttribute(h,15);
				cout<<"\t\t-----------------------------------------------------------------\n"<<endl;
//				cout<<"\n\t\t\t\tLIBRARIAN LOGIN\n"<<endl;
				l_login();
				system("cls");
					break;			
			case '5': exit(0);
				break;
			default: ;
		}
	}
}
