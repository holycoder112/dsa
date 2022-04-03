#include<iostream>
#include<stack>
using namespace std;

class BST{
	int val;
	BST *left, *right;

	public:
		BST(int v);
		BST* search(int v);
		bool insert(int v);
		void del(int v);
		void inorder();
		void postorder();
		void preorder();
};

BST :: BST(int v){
	val = v;
	left = right = 0;
}

BST* BST :: search(int v){
	BST* n = this;
	while(n != 0 && n->val != v){
		if (v< n->val) n = n->left;
		else n = n->right;
	}
	if (n==0) {cout<<"Element "<<v<<" does not exist!\n"; return 0;}
	else cout<<"Element "<<v<<" exists!\n";
	return n;
}

bool BST :: insert(int v){
	BST* n = this;
	while(1){
		if (v<n->val) {
			if (n->left !=0) n = n->left;
			else {n->left = new BST(v); break;}
		}
		else if (v>n->val){
			if (n->right !=0) n = n->right;
			else {n->right = new BST(v); break;}
		}
		else if (v==n->val){
			cout<<"Element already exists\n";
			return 0;
		}
	}
	cout<<"Element "<<v<<" inserted!\n";
	return 1;
}

void BST :: del(int v){
	BST * n = this->search(v);
	if (n ==0) return;
	if (n->left == 0){
		auto temp = n;
		n = n->right;
		delete temp;
	}
	else{
		auto nn = n->left;
		if (nn->right ==0) {
			n->val = nn->val;
			n->left = nn->left;
			delete nn;
		}
		else{
			auto nn1 = nn->right;
			while(nn1->right!=0){
				nn = nn1;
				nn1 = nn1->right;
			}
			nn->right = nn1->left;
			n->val = nn1->val;
			delete nn1;
		}
	}
	cout<<"Element "<<v<<" deleted!\n";
}
// void BST :: inorder(){
// 	stack<BST*> st;
// 	auto n = this;
// 	while(n!=0 || !st.empty()){
// 		while(n!=0){
// 			st.push(n);
// 			n = n->left;
// 		}
// 		n = st.top();
// 		st.pop();
// 		cout<< n->val<<" ";
// 		n = n->right;
// 	}
// 	cout<<endl;
// }

void BST :: preorder(){
	cout<<"preorder-> ";
	stack<BST*> st;
	st.push(this);
	while (!st.empty()){
		auto t = st.top(); st.pop();
		cout<<t->val<<' ';
		if (t->right !=0) st.push(t->right);
		if (t->left!=0) st.push(t->left);
	}
	cout<<endl;
}

void BST :: postorder(){
	cout<<"postorder-> ";
	stack<pair<BST*,int>> st;
	st.push({this,1});
	while(!st.empty()){
		auto t = st.top(); st.pop();
		if (t.second == 2) cout<< t.first->val<<' ';
		else{
			st.push({t.first,2});
			if (t.first->right!=0) st.push({t.first->right,1});
			if (t.first->left !=0) st.push({t.first->left,1});
		}
	}
	cout<<endl;

}

void BST :: inorder(){
	cout<<"inorder-> ";
	stack<pair<BST*,int>> st;
	st.push({this,1});
	while(!st.empty()){
		auto t = st.top(); st.pop();
		if (t.second == 2) cout<< t.first->val<<' ';
		else{
			if (t.first->right!=0) st.push({t.first->right,1});
			st.push({t.first,2});
			if (t.first->left !=0) st.push({t.first->left,1});
		}
	}
	cout<<endl;
}
int main(){
	int n; cin>>n;
	int x; cin>>x;
	BST* root = new BST(x);

	for (int i=1; i<n; i++){
		int x; cin>>x;
		if (root->insert(x) == 0) i--;
	}
	// BST* root = new BST(5);
	// root->insert(3);
	// root->insert(4);
	// root->insert(10);
	// root->insert(6);
	// root->insert(8);
	// root->insert(7);
	// root->insert(2);
	// root->search(4);
	// root->search(3);
	// root->del(10);
	root->inorder();
	root->preorder();
	root->postorder();

}