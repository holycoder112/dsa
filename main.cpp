#include <bits/stdc++.h>
using namespace std;

class Node{
	string data;
	Node *next;
	friend class linkedlist;
	public:
		Node(string d){
			this->data = d;
			this->next=NULL;
		}
};

class linkedlist{
	Node *head;
	friend class hashTable;
	public:
		linkedlist(){
			head=NULL;
		}

		void insertion(string data){
			Node *ptr = new Node(data);
			Node *temp = head;
			Node *prev=temp;
			if(temp == NULL){
				head=ptr;
			}
			else{
				while(temp != NULL){
					prev=temp;
					temp = temp->next;
				}
				prev->next=ptr;
			}
		}

		int searching(string data){
			if(head != NULL){
				Node *temp = head;
				while((temp != NULL)&&(temp->data != data)){
					temp=temp->next;
				}
				if(temp != NULL){
					return 1;
				}
				return -1;
			}
			return -1;
		}

		int deletion(string data){
			if(head != NULL){
				Node *temp = head;
				if(temp->data == data){
					head=temp->next;
					delete temp;
					return 1;
				}
				else{

				Node *prev=temp;
				while((temp != NULL)&&(temp->data != data)){
					prev=temp;
					temp = temp->next;
				}
				if(temp != NULL){
					prev->next = temp->next;
					delete temp;
					return 1;
				}
				else{
					return -1;
				}
				}
			}else{
				return -1;
			}
		}

		void print(){
			Node *temp=head;
			while(temp != NULL){
				cout<<temp->data<<"  ";
				temp=temp->next;
			}cout<<endl;
		}
};

class hashTable{
	linkedlist arr[14];
	public:
	hashTable(){
		for(int i=0;i<14;i++){
			arr[i].insertion("-1");
		}
	}

	int hash_(string str){
		int length=str.size();
		int sum = 0;
		int val;
		for(int i=0;i<length;i++){
			val=str[i];
			sum += (val)*(i+1);
		}
		return (sum % 14);
	}

	void insertion(string s){
		int rem = hash_(s);
		arr[rem].deletion("-1");
		arr[rem].insertion(s);
	}

	void search(string s){
		int rem = hash_(s);
		int val = arr[rem].searching(s);
		if(val == -1){
			cout<<s<<" not found in the table "<<endl;
		}
		else{
			cout<<s<<" found in the table at index "<<rem<<endl;
		}

	}

	void printTable(){
		cout<<"Index   "<<"Words  "<<endl;
		for(int i=0;i<14;i++){
			cout<<i<<"  ";
			arr[i].print();
		}
	}
};

int main(){
	hashTable h;
	// string arr[20] ={"consider", "minute", "accord", "evident",
    //                  "practice", "intended", "concern", "commit",
    //                  "issue", "approach", "establish", "utter",
    //                  "conduct", "engage", "obtain", "scarce",
    //                  "policy", "straight", "stock", "apparent"};
	// for(int i=0;i<20;i++){
	// 	h.insertion(arr[i]);
	// }
	// h.printTable();
	
	string word;
	ifstream infile;
    infile.open("Dictionary.txt");

    if(infile.fail()){
        cout<<"ERROR-The file was not found"<<endl;
        return 0;
    }

	while(infile >> word){
        h.insertion(word);
	}

	infile.close();
    
	char ch;
	do{
        string input;
        cout<<"Enter word : ";
        cin>>input;

        h.search(input);

        cout<<"Do you want to continue?(y/n)"<<endl;
        cin>>ch;
	}while(ch == 'Y' || ch == 'y');
}