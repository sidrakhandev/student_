#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>  //-->library for malloc & realloc...
using namespace std;
bool register_student(struct student *stud,struct list *ls);
double calculate_aggregiate(struct student *);
void addToList(struct student *stud, struct list *l);
void addToListt( struct list *l, struct subject *subj);
void showList(struct student *stud, struct list *l, struct subject *subj);
bool register_subject(struct list *ls,struct subject *sub1);
struct student
{
    char name[20];
    int metric_marks, fsc_marks, entryTest_marks;
    student *next;
    //--> 10 % weightage to metric, 50% to fsc, 40% to entry test...
};

struct subject
{
	string subj1[];
	subject *next;
};
struct list
{
    char name[20];
    double aggr;
    list *next;
};
int main()
{   
    student *s;     //--> creates an object of student...
    s = (struct student *) malloc(sizeof(struct student));
    struct list *ls;
    ls = (struct list *) malloc(sizeof(struct list));
    subject *s1;
    s1= (struct subject *) malloc(sizeof(struct subject));
    strcpy(ls->name, "");
    ls->aggr = 0;
    ls->next= NULL;
    do
    {
    cout<<"Write 1 to register a new student\n";
    cout<<"Write 2 to display lists of students registered\n";
    cout<<"Write 3 to register in subject\n";
    cout<<"Write 4 to quit\n";
    int input;
    cin>>input;
    if (input == 1)
    {
        register_student(s, ls);
    }
    else if (input == 2)
    {
        showList(s, ls,s1);
    }
    else if(input== 3)
    {    register_subject(ls,s1);
   // cout<< endl;
    //	cout<<" you are registered in subject ";
	}
    else if (input == 4)
        exit(0);
    cout<<"\n";
    } while(1);
    getch();
}
bool register_student(struct student *stud,struct list *ls)
{   
    student *s = stud;
    cout<<"Write name of student\n";
    cin>>s->name;
    cout<<"Enter metric percentage\n";
    cin>>s->metric_marks;
    cout<<"Enter fsc percentage\n";
    cin>>s->fsc_marks;
    cout<<"Enter entry test percentage\n";
    cin>>s->entryTest_marks;
    double aggregiate;
    aggregiate = calculate_aggregiate(s);   //-->call to function below...
    cout<<"aggregiate percentage is "<< aggregiate<<"\n";
    if (aggregiate >= 70)
    {
        cout<<"Student registered in Electrical\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >= 60)
    {
        cout<<"Student registered in Mechanical\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >=50)
    {
        cout<<"Student registered in CSE\n";
        addToList(s,ls);
        return true;
    }
    else
    {
        cout<<"Sorry, the student can't be registered in engineering\n";
        return false;
    }
}


bool register_subject(struct list *ls,struct subject *sub1)
{
//	cout<<"1. Object Oriented Programming\n";
//	cout<<"2. Data Structure and Alogrithm \n";
//	cout<<"3. Digital logic Design\n";
//	cout<<"4. Computer Organization and Assembly Language \n";
//	cout<<"5. Technical Writting \n";
string subjects[5]={"1. Object Oriented Programming\n","2. Data Structure and Alogrithm \n","3. Digital logic Design\n"
    "4. Computer Organization and Assembly Language \n","5. Technical Writting \n"};
    for(int i=0;i<5;i++)
    { 
    cout<< subjects[i]<< endl;
	}
	int num;
		int num2;
	cout<<"Enter the subject number you want to register \n";
	cin>> num;
	switch(num)
	{
	
	case 1:
	
			cout<<"Have you already studied programming fundamental  \n"; 
			cout<<"Enter 1 if YES \n";
			cout<<"Enter 0 if NO \n";
			cin>> num2;
			subject *s1 = sub1;
			 //strcpy(pointer->name , subject[0]);
			strcpy(s1,"programming fundamental");
		//	s1=subjects[0];
		//	strcpy(pointer->name , stud->name);
			if(num2==1)
			{
			
			addToListt(ls,s1);
			cout<<"You can registered in Object Oriented Programming Successfully!!!!  \n";
	     	}
			else 
			cout<<"SORRY!!! /n You cannot registered in Object Oriented Programming  \n";
			break;
			
			case 2:
				
			cout<<"Have you already studied Object Oriented Programming  \n"; 
			cout<<"Enter 1 if YES \n";
			cout<<"Enter 0 if NO \n";
			cin>> num2;
			if(num2==1)
			cout<<"You can registered in Data Structure and Alogrithm Successfully!!!!  \n";
			else 
			cout<<"SORRY!!! /n You cannot registered in Data Structure and Alogrithm  \n";
			break;
			case 3:
					
			cout<<"Have you already studied INTRODUCTION TO COMPUTING \n"; 
			cout<<"Enter 1 if YES \n";
			cout<<"Enter 0 if NO \n";
			cin>> num2;
			if(num2==1)
			cout<<"You can registered in Digital logic Design Successfully!!!!  \n";
			else 
			cout<<"SORRY!!! /n You cannot registered in Digital logic Design  \n";
			break;
			case 4:
					
			cout<<"Have you already studied Digital logic Design \n"; 
			cout<<"Enter 1 if YES \n";
			cout<<"Enter 0 if NO \n";
			cin>> num2;
			if(num2==1)
			cout<<"You can registered in  Computer Organization and Assembly Language Successfully!!!!  \n";
			else 
			cout<<"SORRY!!! /n You cannot registered in  Computer Organization and Assembly Language  \n";
			break;
			case 5:
				
			cout<<"Have you already studied Communication Skills \n"; 
			cout<<"Enter 1 if YES \n";
			cout<<"Enter 0 if NO \n";
			cin>> num2;
			if(num2==1)
			cout<<"You can registered in  Technical Writing Successfully!!!!  \n";
			else 
			cout<<"SORRY!!! /n You cannot registered in  Technical Writing  \n";
			break;
			default:
				cout<<"SORRY!!! /n You are not eligible for this post \n";	
}
	
	
	
}







double calculate_aggregiate(struct student *stud)
{   
    student *s = stud;
    double aggr;
    aggr = s->metric_marks * 10/100  + s->fsc_marks * 50/100 + 
        s->entryTest_marks * 40/100;
    return aggr;
}
void addToList(struct student *stud, struct list *l)
{   
    list *pointer = l;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    } 
    pointer->next = (struct list *) malloc(sizeof(struct list));
    pointer = pointer->next;
    strcpy(pointer->name , stud->name);
    pointer->aggr = calculate_aggregiate(stud);
    pointer->next = NULL;
}
void addToListt( struct list *l, struct subject *subj)
{   
    list *pointer = l;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    } 
    pointer->next = (struct list *) malloc(sizeof(struct list));
   // pointer = pointer->next;
  //  strcpy(pointer->name , stud->name);
    pointer = pointer->next;
    strcpy(pointer->name , subj->name);
    pointer->next = NULL;
}
void showList(struct student *stud, struct list *l, struct subject *subj)
{
    list *pointer = l;
    if (pointer->next == NULL)
        cout<<"No student registered yet!\n";
    else
    {
        cout<<"Students statistics are: \n";
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
            cout<<"Name of student is: "<<pointer->name<<"\n";
            cout<<"Aggregiate of student is: "<<pointer->aggr<<"\n";
             cout<<"Subjects of student is: "<<pointer->subj1<<"\n";
            if (pointer->aggr >= 70)
                cout<<"Student registered in Electrical\n";
            else if(pointer->aggr >=60)
                cout<<"Student registered in Mechanical\n";
            else
                cout<<"Student registered in CSE\n";
                cout<<"\n";
            }
        }
    }

