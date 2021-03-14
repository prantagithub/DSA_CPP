//Singly linked list
#include <iostream>
using namespace std;
//-----------------------Node-------------------
struct Node{
	int value;
	Node* next;
	Node(){
		this->next = NULL;
	}
	Node(int val){
		this->value = val;
		this->next=NULL;
	}
};
//-----------------SLL class--------------------
struct SLL{
private:
	Node* head;
	Node* tail;
public:
	int size;
	//------------Constructor-------------------
	SLL(){
		this->head=NULL;
		this->tail=NULL;
		size=0;
	}
	SLL(int val){
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
			head=temp;
			head->next=t;
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
			Node* prev=NULL;
			while(t->next){
				prev=t;
				t=t->next;
				if(t->value==val) break;
			}
			prev->next=t->next;
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
			cout<<t->value<<"-->";
			t=t->next;
		}
		cout<<"NULL"<<endl;
	}

};
//----------------------------------------------
int main(){
	SLL* list1=new SLL(2);
	list1->insert(1);
	list1->insert(3);
	list1->insert(5,0);
	list1->deleteNode(1);
	list1->print();
	cout<<list1->search(1)<<endl;
	//-----------code--------------------------
	return 0;
}