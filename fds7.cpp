#include <iostream>
using namespace std;
struct node{
    char name[10];
    long prn;
    node* next;
};
node* president=new node();
node* secretary=new node();
node *current=new node();
node *currentminus1=new node();
int count=0;

void gethead(){
    count++;
	cout<<"Enter Name of President:"<<endl;
	cin>>president->name;
	cout<<"Enter PRN of President:"<<endl;
	cin>>president->prn;
	president->next=secretary;
}

void gettail(){
    count++;
	cout<<"Enter the name of the secretary:"<<endl;
	cin>>secretary->name;
	cout<<"Enter PRN of secretary:"<<endl;
	cin>>secretary->prn;
	secretary->next=NULL;
}

void addmem(){
    count++;
	node* tmp=new node;
	cout<<"Enter Member name:\n";
	cin>>tmp->name;
	cout<<"Enter PRN of Member:\n";
	cin>>tmp->prn;
	if(president->prn > tmp->prn){
		tmp->next=president;
		president=tmp;
	}
	else if(tmp->prn > secretary->prn){
		secretary->next=tmp;
		tmp->next=NULL;
		secretary=tmp;
	}
	else if(president==NULL){
		president=tmp;
		tmp->next=NULL;
	}
	else if(president->next==NULL){
		if(president->prn > tmp->prn){
			tmp->next=president;
			president->next=NULL;
			president=tmp;
		}
		else{
			president->next=tmp;
			tmp->next=NULL;
		}
	}
	else
	{
		currentminus1=president;
		current=president->next;
		while(current->prn < tmp->prn && current!=secretary){
			current=current->next;
			currentminus1=currentminus1->next;
		}
		currentminus1->next=tmp;
		tmp->next=current;
	}
	tmp=NULL;
	current=NULL;
	currentminus1=NULL;
}

void display_count(){
    cout<<"Member count: "<<count<<endl;
}

void display_list(){
    current=president;
	while(current->next != NULL){
		cout<<"Name of the Member:"<<current->name<<endl;
		cout<<"PRN of the Member:"<<current->prn<<endl;
		current=current->next;
	}
	cout<<"Name of the Member:"<<current->name<<endl;
	cout<<"PRN of the Member:"<<current->prn<<endl;
	current=NULL;
}

void remove(){
    count--;
	long pno=0;
	int bl=0;
	node *tmp=NULL;
	current=president->next;
	currentminus1=president;
	cout<<"Enter the PRN of the member to be removed:"<<endl;
	cin>>pno;
	if(pno==president->prn)
	{
		tmp=currentminus1;
		delete tmp;
		president=current;
		bl=1;
	}
	else if(pno==secretary->prn)
	{
		while(current->next!=NULL)
		{
			current=current->next;
			currentminus1=currentminus1->next;
		}
		tmp=current;
		delete tmp;
		currentminus1->next=NULL;
		secretary=currentminus1;
		bl=1;
	}
	else if(president==NULL)
	{
		cout<<"Error, Underflow!"<<endl;
		bl=1;
	}
	else
	{
		while(current->prn<=pno)
		{
			if(current->prn==pno)
			{
				currentminus1->next=current->next;
				delete current;
				bl=1;
				break;
			}
			else
			{
				current=current->next;
				currentminus1=currentminus1->next;
			}
		}
	}
	if(bl==0)
	{
		cout<<"Member Not found!"<<endl;
		count++;
	}
	current=NULL;
	currentminus1=NULL;
	tmp=NULL;
}

void display_rev(node *a,node* head){
    
}

int main() {
    gethead();
    gettail();
    int bl=1;
    int c;
    while(1>0){
        	cout<<"Enter Choice:\n1.Add Member\n2.Delete Member\n3.Display No of Members\n4.Display Members\n5.Display in Reverse\n6.Enter for another division\n";
		cin>>c;
		switch(c)
		{
		case 1:addmem();
		break;
		case 2:remove();
		break;
		case 3:display_count();
		break;
		case 4:display_list();
		break;
		case 5:
		break;
		case 6:bl=0;
		break;
		default:cout<<"Wrong choice\n";
		break;
		}
    }
    return 0;
}