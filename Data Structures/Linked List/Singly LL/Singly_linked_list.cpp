//Singly linked list
#include <iostream>
#include <pair>
#include <stack>
#include <unordered_map>
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
//-------function to find length of a given array iterative-----------
long long lengthIter(Node* root){
	long long l=0;
	while(root!= NULL){
		l++;
		root=root->next;
	}
}
//-------------recursive length solution------------------------
long long lengthRec(Node* root){
	if(root==NULL) return 0;
	else{
		return 1+lengthRec(root->next);
	}
}
//-------------------Detect loop---------------
int detectLoop(Node* root){
	int len=0;
	unordered_map<Node*, pair<bool,int>> mp;
	int count=0;
	bool val=false;
	Node* temp=root;
	while(temp!=NULL){
		if(mp[temp].first==false) {
			mp[temp].first=true;
			mp[temp].second=count;
		}
		else{
			val=true;
			break;
		}
		temp=temp->next;
		count++;
	}
	if(val==false) return 0;
	else{
		return count+1-mp[temp].second;
	}
}
//-------------------ifPalindrome check--------------------------
bool isPalindrome(Node* root,int n){
	stack st;
	Node* temp=root;
	for(int i=0;i<n;i++){
		if(i<n/2) st.push_back(temp->value);
		else{
			if(n%2==0){
				if(temp->value!=st.top()) return false;
				else st.pop();
			}
			else if(i>n/2){
				if(temp->value!=st.top()) return false;
				else st.pop();
			}
		}
		temp=temp->next;
	}
	return true;
}
//-----------------find duplicates from sorted LL------------------
Node*  remoDupSorted(Node* root){
	Node* temp=root;
	while(temp->next!=NULL){
		if(temp->next->value==temp->value){
			Node* t=temp->next;
			temp->next=t->next;
		}
		if(temp->next->value!=temp->value)
		{
			temp=temp->next;
		}
	}
	return temp;
}
//---------------remove duplicate in an unsorted LL-------------------------
Node* remDupUnsort(Node* root){
	Node* temp=root->next;
	unordered_map<int, bool> mp;
	Node* prev=root;
	while(temp!=NULL){
		if(mp[temp->value]!=false){
			prev->next=temp->next;
		}
		else{
			mp[temp->value]=true;
			prev=temp;
			temp=temp->next;
		}

	}
	return temp;
}
//----------------Node swapping without value swapping----------------------
Node* swapNode(Node* root,int pos1,int pos2,int length){
	Node* temp=root;
	Node* n1,n2,p1,p2,ne1,ne2;
	for(int i=0;i<length;i++){
		if(i==pos1-1){
			p1=temp;
			n1=temp->next;
			ne1=n1->next;
		}
		if(i==pos2-1){
			p2=temp;
			n2=temp->next;
			ne2=n1->next;
		}
		temp=temp->next;
	}
	//swap
	p1->next=n2;
	n2->next=ne1;
	p2->next=n1;
	n1->next=ne2;
	return temp;
}
//-----------move last element to front-----------
Node* movToFront(Node* root,int length){
	Node* temp=root;
	Node* head=root;
	for(int i=0;i<length-1;i++){
		temp=temp->next;
	}
	Node* res=temp->next->next;
	res=head;
	temp->next=NULL;
	return res; 
}
//---------------reverse a linked list--------------
Node* reverse(Node* root){
	Node* temp=root,prev=NULL,prev2;
	while(temp!=NULL){
		prev2=temp->next;
		temp->next=prev;
		prev=temp;
		temp=prev2;
	}
	return prev;
}
//------------------END--------------------------
//----------------------------------------------
int main(){
	//-----------code--------------------------
	return 0;
}
