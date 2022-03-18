#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include "myInf.h"
#include "dinarray.h"
const int Ns=80;
char cmd;
int val;
char buff[Ns];
char N[40];
info inf;
int main(){
int i,j,k,m;
    setlocale(0, "");
    cout<<"Write a filename: ";
    cin>>N;
	bool r=Init(N);
	if(false){
		cout << "File does not exist." << endl;
		return 1;
	}

	while(true){
        cout << "a-add, g-get, y-get all, i-insert, r-replace, d-delete, s-save, q-quit " << endl;
		//printf(">");
		cout << ">";
		/*fgets(buff,Ns,stdin);
		sscanf(buff,"%c",&cmd);*/
		cin>>cmd;
		switch(cmd){
			case 'a':
			    cout << "";
				cin >> inf;
				Add(inf);
				break;
			case 'i':
			    cout << "Insert element: ";
			    cin >> i;
			    cout << ">";
			    cin >> inf;
				Insert(i, inf);
				break;
			case 'r':
			    cout << "Replace number: ";
			    cin >> i;
				cout << ">";  
				cin >> inf;
				Replace(i, inf);
				 //cout << val << endl;
				break;
			case 'g':
			    cout << "Information about element number ";
				cin >> i;
			    cout << ">";
				Get(i, &inf);
				cout<<inf<<endl;
				break;
			case 'y':
				cout << "Information about all elements:" << endl;
				m=GetSize();
				for(i=0; i<=m; i++){
					Get(i, &inf);
					cout << inf;
				}
				break;
			case 'd':
			    cout << "Delete number" << endl;
			    cout << ">";
			    cin >> i;
				Delete(i);
				break;
			case 's':
				Save();
				break;
			case 'q':
				return 0;
				
			default:
				cout << "Unknown command" << endl;
		}
	}
}

