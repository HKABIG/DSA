#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reversek(node* &head,int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr != NULL){
        head->next = reversek(nextptr,k);
    }
    return prevptr;
}

bool detectcycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void printCycleNode(node* head){
    node* slow = head;
    node* fast = head;
    f = false;
    while(fast!=NULL && fast->next!=NULL && slow!=NULL){
	fast = fast->next->next;
	slow = slow->next;
	if(slow==fast)
		f = true;
		break;
}
    if(!f) cout<<"NO cycle detected in list"<<endl;
    slow = head;
    while(slow!=head){
		slow = slow->next;
		fast = fast->next;
}
return fast->data;
}

void makecycle(node*head,int pos){
    node* temp = head;
    node* startNode;
    
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

void removecycle(node* head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;   
}

int main() {
	// your code goes here
	node* head = NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	insert(head,6);
	display(head);
	node* newhead = reversek(head,2);
	display(newhead);
	cout<<detectcycle(head)<<endl;
	makecycle(head,3);
	cout<<detectcycle(head)<<endl;
	
	return 0;
}
