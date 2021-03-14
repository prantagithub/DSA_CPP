//Doubly Linked List
#include <iostream>
using namespace std;
//-----------------------Node-------------------
struct Node{
	int value;
	Node* next;
	Node* prev;
	Node(){
		this->next = NULL;
		this->prev=NULL;
	}
	Node(int val){
		this->value = val;
		this->next=NULL;
		this->prev=NULL;
	}
};
//-----------------SLL class--------------------
struct DLL{
private:
	Node* head;
	Node* tail;
public:
	int size;
	//------------Constructor-------------------
	DLL(){
		this->head=NULL;
		this->tail=NULL;
		size=0;
	}
	DLL(int val){
		head=new Node(val);
		tail=head;
		size++;
	}
	//----------------Insert---------------------
	void insert(int val){
		if(this->head==NULL){
			head=new Node(val);
		}
		else{
			Node* temp=new Node(val);
			Node* t=this->head;
			this->head=temp;
			this->head->next=t;
			t->prev=this->head;
		}
		size++;
	}
	void insert(int val,int pos){
		if(pos>=size){
			Node* t=new Node(val);
			this->tail->next=t;
		}
		else if(pos==0){
			this->insert(val);
			return;			
		}
		else{
			Node* t=this->head;
			while(pos>1){
				t=t->next;
				pos--;
			}
			Node* n=new Node(val);
			n->next=t->next;
			n->prev=t;
			n->next->prev=n;
			t->next=n;
		}
		size++;
	}
	//-----------------Deletion------------------
	void deleteNode(){
		if(this->size==0) return;
		else{
			Node* t=this->head;
			this->head=t->next;
			this->head->prev=NULL;
			delete t;
			size--;
		}
	}
	//deletion of the first occurance of a particualr value
	void deleteNode(int val){
		if(size==0) return;
		else if(this->head->value==val) this->deleteNode();
		else{
			Node* t=this->head;
			Node* pre=NULL;
			while(t->next){
				pre=t;
				t=t->next;
				if(t->value==val) break;
			}
			pre->next=t->next;
			t->next->prev=pre;
			delete t;
			size--;
		}
	}
	//------------------Search------------------
	int search(int pos){
		if(pos>=this->size){
			return -1;
		}
		else{
			Node* t=this->head;
			while(pos--){
				t=t->next;
			}
			return t->value;
		}
		
	}
	//------------------print-------------------
	void print(){
		Node* t=head;
		while(t!=NULL){
			cout<<t->value<<"<-->";
			t=t->next;
		}
		cout<<"NULL"<<endl;
	}

};
//----------------------------------------------
int main(){
	DLL* list2=new DLL(5);
	list2->insert(2);
	list2->insert(3);
	list2->print();
	//-----------code--------------------------
	return 0;
}