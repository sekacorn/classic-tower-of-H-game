#include<iostream>
#include<iomanip>
//Corn

using namespace std;

struct Disk{
int size;
};

class HanoiStack{
private:
	struct DiskNode{
		Disk x;
		DiskNode* next=NULL;
		};
	DiskNode *top=NULL;
	int size =0;
	int maxSize=0;
public:
	HanoiStack(int x);
	void push(Disk);
	Disk pop();
	Disk Top();
	void print() const;
	bool empty();
	int Topsize();
	bool isfull();



};
bool HanoiStack::empty(){

	if(top==NULL){
	return true;

	}
	else{
	return false;
	}


}
bool HanoiStack::isfull(){
 if(size==maxSize)
	return false;
	else{
	return true;
	}


} 
//Prints out the stack
void HanoiStack::print() const{

DiskNode *cursor= new DiskNode;
 cursor= top;
 while(cursor!=NULL)
	{
		cout<<cursor->x.size;		
		cursor=cursor->next;

	}
	   cout<<"<- Tower"<<endl;
}
//Initialize the default values
HanoiStack::HanoiStack(int x){
	maxSize=x;
	top=NULL;
	size =0;
	



}//Adds disks to stack
void HanoiStack::push(Disk t){
DiskNode *newDisk= new DiskNode;
DiskNode *cursor = new DiskNode;
cursor=top;
newDisk->x=t;

	if(top==NULL){
	top=newDisk;
	size++;


	}
	else{

	newDisk->next=top;
	top=newDisk;
	size++;
		
	}
	
		
	

}

Disk HanoiStack::pop(){
DiskNode *newDisk;
Disk a=top->x;
Disk b;
b.size=0;



	if (top==NULL){

	cout<<"Its empty"<<endl;
	return b;// returns disk
	}
	else
	{ newDisk=top;
	  top= top->next;
	  delete newDisk;
		size--;
	return a;//returns disk popped
	}




}

Disk HanoiStack::Top(){
	//returns the top element
	return top->x;



}
int HanoiStack::Topsize(){
//shows the number of the disk
return top->x.size;



}

int main(){
    
	    int move1=0;
	    int move2=0;
	    
            Disk a;
	    a.size=1;
	    int n;
	    cout<<"Enter the number of disks you want to add"<<endl;
	    cin>>n;
	    HanoiStack *c=new HanoiStack(n);//creates the first tower
	    HanoiStack *d=new HanoiStack(n);//creates the second tower
            HanoiStack *e=new HanoiStack(n);// creates the third tower
	    
	
	    a.size=n;
	

	//adds disks to the first tower
	    for (int g = n; g >= 1; g--)
	    {
		c->push(a);
	
		a.size=a.size-1;
	    }
	cout<<endl;	
	c->print();
	d->print();
	e->print();
	
	   cout<<endl;
	

	   


		
	while(e->isfull()||d->isfull()){
cout<<"Please enter the tower number (1-3) to which you want to select a disc"<<endl;
	cin>>move1;
	cout<<"Please Enter the tower number(1-3)  which you want to tranfer the disc"<<endl;
	cin>>move2;
	 if(move1==1&&move2==3)
        {	
            if(c->empty()&& e->empty())
            {
                cout<<"Invalid move"<<endl;
        
                
            }
            else if(c->empty()&& !e->empty())
            {
            cout<<"Invalid move"<<endl; 
            
            }//if its empty move the disk to tower 3
            else if(e->empty())
            {
            e->push(c->Top());
		cout<<c->Topsize()<<" has been moved to tower 3"<<endl;
            c->pop();
	    
           
            }
		//if the top disk is greater than the destination disk it should not be allowed
            else if(c->Topsize()> e->Topsize())
            {
            cout<<"Invalid move"<<endl;
            
            }
		//if its not empty move the disk to tower 3
            else if(!e->empty())
            {
            e->push(c->Top());
		cout<<c->Topsize()<<" has been moved to tower 3"<<endl;
            c->pop();
	    
            
            }
      }
        else if(move1==1 && move2==2)
        { //if the stack c and d are empty show move as invalid
        	
            if(c->empty() && d->empty())
            {
            cout<<"Invalid move"<<endl;
    
           
            }
            //if the stack c is empty and d is not empty show move as invalid
             else if(c->empty()&& !d->empty())
            {
            cout<<"Invalid move"<<endl; 
            
            }
		//if its not empty move the disk to tower 2
            else if(d->empty())
            {
            d->push(c->Top());
	    cout<<c->Topsize()<<" has been moved to tower 2"<<endl;
            
            c->pop();
	    
            }
		//if the top disk is greater than the destination disk it should not be allowed
            else if(c->Topsize()> d->Topsize())
            {
            cout<<"Invalid move"<<endl;
            
            }//if its not empty move the disk to tower 2
            else if(!d->empty())
            {
            d->push(c->Top());
		cout<<c->Topsize()<<" has been moved to tower 2"<<endl;
            c->pop();
	    
            
            }
            
        }
	 else if(move1==2 && move2==1)
        { 
        
            if(c->empty() && d->empty())
            {
            cout<<"Invalid move"<<endl;
    
           
            }
            
             else if(d->empty()&& !c->empty())
            {
            cout<<"Invaid move"<<endl; 
            
            }//if its empty move the disk to tower 1
            else if(c->empty())
            {
            c->push(d->Top());
	    cout<<d->Topsize()<<" has been moved to tower  1"<<endl;
            
            d->pop();
	    
            }//if the top disk is greater than the destination disk it should not be allowed
            else if(d->Topsize()> c->Topsize())
            {
            cout<<"Invalid move"<<endl;
            
            }
		//if its not empty move the disk to tower 1
            else if(!d->empty())
            {
            c->push(d->Top());
		cout<<d->Topsize()<<" has been moved to tower  1"<<endl;
            d->pop();
	    
            
            }
            
        }


    
    
    else if(move1==3 && move2==2)
        { 
        	//if the stack e and d are empty show move as invalid
            if(e->empty() && d->empty())
            {
            cout<<"Invalid Move"<<endl;
    
            
            }
            
		//if the stack e is empty and stack d is not empty show move as invalid
             else if(e->empty()&& !d->empty())
            {
            cout<<"Invalid Move"<<endl; 
            
            }//if its empty move the disk to tower2
            else if(d->empty())
            {
            d->push(e->Top());
	    cout<<e->Topsize()<<" has been moved to tower 2"<<endl;
            e->pop();
	    
            
            }//if the top disk is greater than the destination disk it should not be allowed
            else if(e->Topsize()> d->Topsize())
            {
            cout<<"Invalid move"<<endl;
          
            }
		//if aux tower is not empty move disk to tower2
            else if(!d->empty())
            {
            d->push(e->Top());
	    cout<<e->Topsize()<<" has been moved to tower 2"<<endl;
            e->pop();
	    
           
            }
            
        }
        
        
    
     else if(move1==3 && move2==1)
        { 
        	//if the stack e and c are empty show move as invalid
            if(e->empty() && c->empty())
            {
            cout<<"Invalid move"<<endl;
    
           
            }
            //Output Invalid if 3rd stack is empyt
             else if(e->empty()&& !c->empty())
            {
            cout<<"Invalid move"<<endl; 
            
            }//if its empty move the disk to tower1
            else if(c->empty())
            {
            c->push(e->Top());
		cout<<e->Topsize()<<" has been moved to tower 1"<<endl;
            e->pop();
           
            }
		//if the disk is greater that bottom disk show as invalid move
            else if(e->Topsize()> c->Topsize())
            {
            cout<<"Invalid move"<<endl;
            
            }  
		//if its not empty move the disk to tower 1
            else if(!c->empty())
            {
            c->push(e->Top());
	     cout<<e->Topsize()<<" has been moved to tower 1"<<endl;
            e->pop();
	   
            
            }
            
        }
 	

	 else if(move1==2 && move2==3)
        { 
        //if the stack d and e are empty show move as invalid
            if(d->empty() && e->empty())
            {
            cout<<"Invalid move"<<endl;
    
            
            }
            //if the stack e is empty and e is not empty show move as invalid
             else if(d->empty()&& !e->empty())
            {
            cout<<"Invalid move"<<endl; 
            
            }
		//if its  empty move the disk to tower 3
            else if(e->empty())
            {

            e->push(d->Top());
	    cout<<d->Topsize()<<" has been moved to tower 3"<<endl;
            d->pop();
	    
            
            }
		//if the disk is greater that bottom disk show as invalid move
            else if(e->Topsize()< d->Topsize())
            {
            cout<<"Invalid movexx"<<endl;
          
            }
		//if its not empty move the disk to tower 3
            else if(!d->empty())
            {
            e->push(d->Top());
	    cout<<d->Topsize()<<" has been moved to tower 3"<<endl;
            d->pop();
	    
           
            }
            
        }
	c->print();
	d->print();
	e->print();
	
          if(!e->isfull()||!d->isfull())
		break;
    }
		cout<<"Congrats you win"<<endl;
        return 0;
        
}
/*
Enter the number of disks you want to add
3
123<- Tower
<- Tower
<- Tower


Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower A3
23<- Tower
<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
2 has been moved to tower 2
3<- Tower
2<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
3
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
1 has been moved to tower 2
3<- Tower
12<- Tower
<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
3 has been moved to tower A3
<- Tower
12<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
1
1 has been moved to tower  1
1<- Tower
2<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
2 has been moved to tower 3
1<- Tower
<- Tower
23<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower B3
<- Tower
<- Tower
123<- Tower
Congrats you win

*/
    
/*
RUN TWO
Enter the number of disks you want to add
3

123<- Tower
<- Tower
<- Tower

Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower 3
23<- Tower
<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
2 has been moved to tower 2
3<- Tower
2<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
Invalid move
3<- Tower
2<- Tower
1<- Tower

Please enter the tower number (1-3) to which you want to select a disc
3
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
1 has been moved to tower 2
3<- Tower
12<- Tower
<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
3 has been moved to tower 3
<- Tower
12<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
1
1 has been moved to tower  1
1<- Tower
2<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
2 has been moved to tower 3
1<- Tower
<- Tower
23<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower 3
<- Tower
<- Tower
123<- Tower
Congrats you win
*/

/* RUN 3
        
Enter the number of disks you want to add
3

123<- Tower
<- Tower
<- Tower

Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower 3
23<- Tower
<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
Invalid move
23<- Tower
<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
2 has been moved to tower 2
3<- Tower
2<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
Invalid move
3<- Tower
2<- Tower
1<- Tower
Please enter the tower number (1-3) to which you want to select a disc
3
Please Enter the tower number(1-3)  which you want to tranfer the disc
2
1 has been moved to tower 2
3<- Tower
12<- Tower
<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
3 has been moved to tower A3
<- Tower
12<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
1
1 has been moved to tower  1
1<- Tower
2<- Tower
3<- Tower
Please enter the tower number (1-3) to which you want to select a disc
2
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
2 has been moved to tower 3
1<- Tower
<- Tower
23<- Tower
Please enter the tower number (1-3) to which you want to select a disc
1
Please Enter the tower number(1-3)  which you want to tranfer the disc
3
1 has been moved to tower B3
<- Tower
<- Tower
123<- Tower
Congrats you win*/
    
