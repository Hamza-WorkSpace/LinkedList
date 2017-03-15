#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

class node
{
private:

	int data;
	int serialno;
	
public:
	node*link;
	void setdata(int);
	void setlink(node*);
	void setserialno(int);
	int getserialno();
	int getdata();
	node*getlink();
	node ();
};


//initialising...global variables because every time function is called it will set to the following values but i want the values to remain same
//so i took global variables.... use STATIC key word before declearing the variable in the in the respective function and decleaar all the variable
//as local variable after using static/........lolx.....ha ha ha ha
	int flaghead=0;
	int flag=0;
	int flag1=0;
	int nofnodes=0;
	int srn=1001;
	node*delhead=NULL;
	node*runner=NULL;
	node*deltail=NULL;
	node*tail=NULL;
	node* temp=NULL;
	
	//node*front=NULL;
	//node*back=NULL;
	//node*sort=NULL;
	
node::node()
{
	data=0;
	link=NULL;
}

void node::setdata(int a)
{
	data=a;
}

void node::setserialno(int a)
{
	serialno=a;
}

int node:: getserialno()
{
	return serialno;
}

void node:: setlink(node* a)
{
	link=a;
}

node* node:: getlink()
{
	return link;
}

int node:: getdata()
{
return data;
}

class list
{
public:
		node*head;
		//insert functions
		int insertnod();
		int inserathead();
		int insertattail();
		int insertatmiddle();

		//delete functions
		int deletenod();
		int deleteathead();
		int deleteattail();
		int deleteatmiddle();
		
		//function to search
		int search();//not done yet
		//function to print the whole list
		void printlist();
		int printnode(node*);
		//function to accept user choise
		int userinfo();
		list();
};

list::list()
{
	head=NULL;
}

int list::insertnod()
{
	system("cls");
	char choise;
	list obj;

	int d=0;



insertmenu:

	//obj.setsrn();

	system("cls");
	 
	cout<<"\n\n\n\n\n\t\t\t###########################################\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  1) press a to insert a node at head \t\  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  2) press b to insert a node at middle  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  3) press c to insert a node at tail \t\  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  4) press e to exit insert menu      \t\  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t############################################";

	choise=getch();
	int asd;
	
	if(choise=='a')
	{
		asd=inserathead();

		if(asd==1)
		{
			goto insertmenu;
		}
	}

	if(choise=='b')
	{
		asd=insertatmiddle();

		if(asd==1)
		{
			goto insertmenu;
		}
	}

	if(choise=='c')
	{
		asd=insertattail();
		nofnodes++;
		if(asd==1)
		{
			goto insertmenu;
		}
	}

	if(choise=='e')
	{
		return 1;
	}

  return 1;
}//end of insert node function



//function to insert the node at head;
int list::inserathead()
{
int var=0;
list objs;

enteragain:
	
	system("cls");
	//objs.printlist();
	cout<<"\n\nENTER VALUE :  ";
	cin>>var;

//	 make a new node and insert data in it and set its link part to null but it is not attaached to any node yet
// now the node is ready we now attach this node to another node which is already attached in the list....

	node*temp=NULL;

	node*newnod= new node;
	newnod->setdata(var);
	newnod->setlink(NULL);
	newnod->setserialno(srn);
	srn++;
	//newnod->setserialno(nofnodes);
	
	if(head==NULL && flaghead==0)
	{
		head=newnod;
		flaghead=1;
		//runner=head;
	}
	else
	{
		temp=head;
		head=newnod;
		newnod->link=temp;
	}
		nofnodes++;
	printlist();	
		char w;
		cout<<"\n\n  PRESS 'a' TO ENTER VALUE AGAIN\n\n  PRESS 'b' TO RETURN TO INSERT MENU ";
		w=getch();

		if(w=='a')
		{
			goto enteragain;
		}
		else if(w=='b')
		{
			return 1;
		}

	return 0;
}//end of insert at head function...


//function to insert node at tail 

int list:: insertattail()
{
	int var=0;
	list objs;
	//int initialise=0;
enteragain:

	system("cls");
	//objs.printlist();
	cout<<"\n\nenter value\n";
	cin>>var;

// make a new node and insert data in it and set its link part to null but it is not attaached to any node yet
// now the node is ready we now attach this node to another node which is already attached in the list....

	node*newnod= new node;
	newnod->setdata(var);
	newnod->setlink(NULL);
	newnod->setserialno(srn);
	srn++;
	
		if(flag==0)
		{
			runner=head;
			flag=1;
		}

	if(head==NULL && flaghead==0)
	{
		head=newnod;
		flaghead=1;
	}
	else
	{
		while(runner!=NULL)
		{
			if(runner->link==NULL)
			{
				runner->link=newnod;
				runner=newnod;
			}
			runner=runner->link;
		}
	  runner=newnod;
	}
	nofnodes++;
	printlist();
	char w;
		cout<<"\n\n  PRESS 'a' TO ENTER VALUE AGAIN\n\n  PRESS 'b' TO RETURN TO INSERT MENU ";
		w=getch();

		if(w=='a')
		{
			goto enteragain;
		}
		else if(w=='b')
		{
			return 1;
		}
	return 0;
}//end of insert at tail function






//insert at middle function
int list::insertatmiddle()
{
	int sn=0;
	int var=0;
	node *mid=new node;
	node*temp=NULL;
	mid=NULL;
		
	if(head==NULL)
	{
		system("cls");
		cout<<"\n\n\tLIST NOT CREATED TO INSERT AT MIDDLE PRESS ANY KEY TO RETURN";
		getch();
		return 1;
	}
enteragain :
			
			system("cls");
			cout<<"\n\nenter value\n";
			cin>>var;
			
			node*newnod= new node;
			newnod->setdata(var);
			newnod->setlink(NULL);
			newnod->setserialno(srn);
			srn++;

			printlist();

			cout<<"\n\nenter node serial number after which u want to enter : ";
			cin>>sn; 

			mid=head;
			while(mid!=NULL)
			{
				if(mid->getserialno()==sn)
				{
					break;
				}
				mid=mid->link;
			}

			temp=mid->link;
			mid->link=newnod;
			newnod->link=temp;
			nofnodes++;

			printlist();

			char a;

			cout<<"\n\n  PRESS 'a' TO ENTER VALUE AGAIN\n\nc  PRESS 'b' TO RETURN TO INSERT MENU ";
			a=getch();

				if(a=='a')
				{
					goto enteragain;
				}
				else if(a=='b')
				{
					return 1;
				}
			return 0;

//end of insert at middle function


//	int var;
//	//cout<<"enter value";
//	//cin>>var;
//// make a new node and insert data in it and set its link part to null but it is not attaached to any node yet
//// now the node is ready we now attach this node to another node which is already attached in the list....
//	
//
//	//node*newnod= new node;
//	//newnod->setdata(var);
//	//newnod->setlink(NULL);
//
//	//first sort the list then insert at middle...te following code is to sort the linked list
//
//	back=head;
//
//	front=back->link;
//
//while(back->link!=NULL)
//{
//	while(front!=NULL)
//	{
//		if(back->getdata() > front->getdata())
//		{
//			back->link=front->link;
//				if(head->getdata()>head->link->getdata())
//				{
//				head=front;
//				sort=front;
//				}
//			printlist();
//			sort=back->link;
//			
//		}
//			sort=front;
//			front=front->link;
//		
//		}
//
//		back=back->link;
//	}
//
//
//
//	objs.setsrn();
	//return 0;
}// insertatmiddle() pending due to confusion



//function below is used to delete the node at desired position
int list::deletenod()
{
	system("cls");
	char choise;
	list obj;
	int d;

deletemenu:

	system("cls");
	 
	cout<<"\n\n\n\n\n\t\t\t###########################################\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  1) press a to delete a node at head \t  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  2) press b to delete a node at middle  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  3) press c to delete a node at tail \t\  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t|  4) press e to exit delete menu      \t\  |\n";
	cout<<"\t\t\t|                                         |\n";
	cout<<"\t\t\t############################################";

	choise=getch();
	int asd;
	
	if(choise=='a')
	{
		char q;
		system("cls");
		printlist();
		cout<<"\n\nPRESS a TO  DELETE NODE\nPRESS ANY KEY TO RETURN TO DELETE MENU";
		q=getch();

		if(q=='a')
		{
			asd=deleteathead();
			if(asd==1)
			{
				goto deletemenu;
			}
		}
		else
		{
			goto deletemenu;
		}
	}

	if(choise=='b')
	{
		char q;
		system("cls");
		printlist();
		cout<<"\n\nPRESS a TO  DELETE NODE\nPRESS ANY KEY TO RETURN TO DELETE MENU";
		q=getch();

		if(q=='a')
		{
			asd=deleteatmiddle();
			if(asd==1)
			{
				goto deletemenu;
			}
		}
		else
		{
			goto deletemenu;
		}
		
	}

	if(choise=='c')
	{
		char q;
		system("cls");
		printlist();
		cout<<"\n\nPRESS a TO  DELETE NODE\nPRESS ANY KEY TO RETURN TO DELETE MENU";
		q=getch();

		if(q=='a')
		{
			asd=deleteattail();
			if(asd==1)
			{
				goto deletemenu;
			}
		}
		else
		{
			goto deletemenu;
		}

	}	
	
	if(choise=='e')
	{
		return 1;
	}
  return 0;
}//end of delete node function


int list::deleteathead()
{
	char e;
	//list objs;
		system("cls");
	cout<<"\n\n\tLIST BEFORE DELETING FROM HEAD IS AS FOLLOW";
	printlist();


again:

	system("cls");
	if(nofnodes>0)
	{
	//cout<<"\n\n\tLIST BEFORE DELETING FROM HEAD IS AS FOLLOW";
	//printlist();
	
	delhead=head;
	head=delhead->link;
	delhead->link=NULL;

	delete delhead;

	nofnodes--;
	
	cout<<"\n\n\tLIST AFTER DELEATING IS";
	printlist();

  if(nofnodes!=0)
  { 	   
	cout<<"\n\n\tPRESS a TO DELETE AGAIN FROM HEAD\n\n\tPRESS B TO EXIT DELETE AT HEAD";
	e=getch();  

	if(e=='a')
	{
		goto again;
	}
	else if(e=='b')
	{
	return 1;
	}
  }
}

	else
		cout<<"\n\n\tNO NODES LEFT TO BE DELEATED";
		getch();
	return 1;
}//end of delete at head function


//start of delete at middle function
int list::deleteatmiddle()
{
int serialn;
node * delmid=NULL;
node*temp= NULL;



		system("cls");
		cout<<"\n\n\tLIST BEFORE DELETING FROM HEAD IS AS FOLLOW";
		printlist();
	again :
			if(nofnodes>0)
			{
				cout<<"\n\nENTER SERIAL NUMBER OF NODE YOU WANT TO DELETE";
				cin>>serialn;

			
				delmid=head;
				while(delmid!=NULL)
				{
					if(delmid->getserialno()==serialn)
					{
						break;
					}
					if(delmid->link->getserialno()==serialn)
					{
						temp=delmid->link;
						break;
					}
					delmid=delmid->link;
				}

				delmid->link=temp->link;
				temp->link=NULL;
				delete temp;

				nofnodes--;
	
	cout<<"\n\n\tLIST AFTER DELEATING IS";
	printlist();
	char e;
  if(nofnodes!=0)
  { 	   
	cout<<"\n\n\tPRESS a TO DELETE AGAIN FROM MIDDLE\n\n\tPRESS b TO EXIT DELETE AT MIDDLE";
	e=getch();  

	if(e=='a')
	{
		goto again;
	}
	else if(e=='b')
	{
	return 1;
	}
  }
}


	else
		cout<<"\n\n\tNO NODES LEFT TO BE DELEATED";
		getch(); 
	return 1;
}

//end of delete at middle function


//start of delete at tail function

int list::deleteattail()
{
	again:
		system("cls");
		if(nofnodes>0)
		{
		
			tail=head;
			deltail=head;
			while(deltail!=NULL)
			{

				if(nofnodes==1 && deltail==head && tail==head)
				{
					head=NULL;
					break;
				}

				if(deltail->link!=NULL)
				{
					tail=deltail;
				}

				deltail=deltail->link;
				
				if(deltail==NULL)
				{
					break;
				}
				
		   }

			tail->link=NULL;
			delete deltail;
			nofnodes--;
			printlist();


if(nofnodes!=0)
{
	char e;
	cout<<"\n\n\tPRESS a TO DELETE AGAIN FROM TAIL\n\n\tPRESS B TO EXIT DELETE AT TAIL";
	e=getch();  

	if(e=='a')
	{
		goto again;
	}
	if(e=='b')
	{
	return 1;
	}
}
}

		getch();

	return 1;
}

void list::printlist()
{
	if(head!=NULL)
	{
		int sn=0;
		list obj;
		node*n;
		n=head;

	cout<<endl<<endl<<"";
	cout<<"\tDATA IN NODES\t\t"<<"NODE SERIALNUMBER\n";
	cout<<"\t~~~~~~~~~~~~~\t\t"<<"~~~~~~~~~~~~~~~~~\n\n";
		do 
		{
			cout<<"\t     "<<n->getdata()<<"\t\t\t      "<<n->getserialno()<<"\n\n";
			n=n->link;
		
		}while(n!=NULL);

	cout<<endl<<"";
	cout<<"\n\ntotal number of nodes="<<nofnodes;
    }
	else
		cout<<"\n\n\tLIST IS DESTROYED OR NOT CREATED YET";
}
//function below is used to take information from the user
int list::userinfo()
{
	list obj;
	int s=0;
	char d=' ';
	obj.head=NULL;
mainmenu:

	system("cls");

	cout<<"\n\n\n\n\t\t\t      MY FIRST LINKED LIST YAHOOOO!\n\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	cout<<"\n\n\n\n\t\t\t      MADE BY HAMZA!\n\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";


	cout<<"\n\n\n\n\n\t\t\t#########################################\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t|  1) press a to insert a node \t\t|\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t|  2) press b to delete a node \t\t|\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t|  3) press c to search a node \t\t|\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t|  4) press d to print list\t\t|\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t|  5) press e to exit\t\t\t|\n";
	cout<<"\t\t\t|                                       |\n";
	cout<<"\t\t\t#########################################";
	d=getch();
	int q;
	if(d=='a')
	{
		q=obj.insertnod();
		if(q==1)
		{
			goto mainmenu;
		}
	}

	if(d=='b')
	{
		if(nofnodes!=0)
		{
				q=obj.deletenod();
		
				if(q==1)
				{
					goto mainmenu;
				}
		}

		else
		{
			system("cls");
			cout<<"\n\n\t NO NODES LEFT TO BE DELEATED-----PRESS ANY KEY TO COUNTINUE";
			getch();
		}
	}

	if(d=='c')
	{
		
		if(nofnodes!=0)
		{
			q=obj.search();

			if(q==1)
			{
				goto mainmenu;
			}
		}
		else
		{
			system("cls");
			cout<<"LIST DESTROYED OR NOT CREATED YET";
		}
		
	}

	if(d=='d')
	{
		system("cls");
		obj.printlist();
		getch();
		goto mainmenu;
	}
	
	if(d=='e')
	{
		return 0;
	}

	return 1;
}

int list::search()
{
	char g;
	int srn;
	
	node *searchnod=NULL;
again:
	
	system("cls");
	cout<<"ENTER YOUR SEARCHING CHOICE\n\n\na)simple search\n\nb)binary search";
	g=getch();
	
	system("cls");
	printlist();
	cout<<"\n\nENTER SERIAL NUMBER YOU WANT TO SEARCH : ";
	cin>>srn;
	if(g=='b')
	{
		cout<<"not done yet";
	}

	if(g=='a')
	{
		searchnod=head;

			while(searchnod!=NULL)
			{

				if(searchnod->getserialno()==srn && nofnodes==1 && searchnod==head )
				{
					break;
				}

				if(searchnod->getserialno()==srn)
				{
					break;
				}
			  searchnod=searchnod->link;
			   
			}//end of loop


		if(searchnod->getserialno()==srn)
		{
			printnode(searchnod);
		}
		else if(searchnod->getserialno()!=srn)
		{
			cout<<"ELEMENT NOT IN LIST or YOU ENTERED WRONG CODE";
		}

		if(nofnodes!=0)
		{
			char e;
			cout<<"\n\n\tPRESS a TO SEARCH AGAIN\n\n\tPRESS B TO EXIT SEARCH MENU";
			e=getch();  

			if(e=='a')
			{
				goto again;
			}
			if(e=='b')
			{
			return 1;
			}
		}
	}

	getch();

	return 1;
}//end of print node function

int list::printnode(node *srch)
{
	system("cls");
	cout<<"\n\n\tELEMENT FOUND \n\n\n";
	if(nofnodes!=0)
	{
		cout<<endl<<endl<<"";
		cout<<"\tDATA IN NODES\t\t"<<"NODE SERIALNUMBER\n";
		cout<<"\t~~~~~~~~~~~~~\t\t"<<"~~~~~~~~~~~~~~~~~\n\n";
		cout<<"\t     "<<srch->getdata()<<"\t\t\t      "<<srch->getserialno()<<"\n\n";

		cout<<endl<<"";
		cout<<"\n\ntotal number of nodes="<<nofnodes;
	}
	else
	{
		cout<<"LIST DESTROYED OR NOT CREATED YET";
	}
	getch();
	return 1;
}

void main()
{
	list objq;
	objq.userinfo();
} 