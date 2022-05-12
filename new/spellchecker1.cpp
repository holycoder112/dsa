#include <bits/stdc++.h>
using namespace std;
#define max 10
struct dic{
	char cWord[20];
	char cMeaning[20];
};	

class hashtable{
	public:
		dic ht[max];
		hashtable(){
			for(int i=0;i<max;i++){
				strcpy(ht[i].cWord,"");
				strcpy(ht[i].cMeaning,"");
			}
		}
		int hash(char ckey[10]){
			int i,s=0;
			for(i=0;ckey[i]!='\0';i++){
				s=s+ckey[i];
			}
			return(s%max);
		}
		void insert_word(dic d);
		void display();
		int search_word(char cW[]);
		void del_word(char cW[]);
};
void hashtable::insert_word(dic d){
	int iIndex=10;
	for(int i=0;i%max!=iIndex;i=(i+1)%max){
		iIndex=(hash(d.cWord)+i*i)%max;
		cout<<"\n\n Position :"<<i<<" "<<iIndex;
		if(i>0)
		cout<<"\n Collision at "<<iIndex; 
		if(strcmp(ht[iIndex].cWord,"")==0){
			ht[iIndex]=d;
			break;
		}
	}		
}
void hashtable::display(){
	cout<<"index\t\tWord\t\tmeaning";
	for(int i=0;i<max;i++){
		cout<<"\n"<<i<<"\t\t"<<ht[i].cWord<<"\t\t"<<ht[i].cMeaning<<"\n";
	}
}
int hashtable::search_word(char cW[10]){
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max){
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0){
			cout<<"\nWord Found and Meaning is :"<<ht[iIndex].cMeaning;
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\nWord Not Found";
}
void hashtable::del_word(char cW[10]){
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max){
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0){
			cout<<"\nWord Found and deleted :"<<ht[iIndex].cMeaning;
			strcpy(ht[iIndex].cWord,"");
			strcpy(ht[iIndex].cMeaning,"");
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\n Word Not Found";
}	
int main(){
	char cW[10];
	int iCh,iFlag=0;
	hashtable h;
	dic d;
	do{
		cout<<"\n1.INSERT WORD"<<endl<<"2.DISPLAY"<<endl<<"3.SEARCH MEANING"<<endl<<"4.DELETE"<<endl<<"5.EXIT"<<endl;
		cout<<"Enter your choice:";
		cin>>iCh;
		switch(iCh){
			case 1:
				cout<<"\n Enter word to insert:";
				cin>>d.cWord;
				cout<<"\n Enter Meaning:";
				cin>>d.cMeaning;
				h.insert_word(d);
				break;
			case 2:
				h.display();
				break;
			case 3:
				cout<<"\n Enter word to be searched:";
				cin>>cW;
				h.search_word(cW);
				break;
			case 4:
				cout<<"\n Enter the word to be deleted:";
				cin>>cW;
				h.del_word(cW);
				break;
			case 5:
				break;
		}
	}while(iCh!=5);
}