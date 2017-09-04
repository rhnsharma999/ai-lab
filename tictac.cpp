#include <bits/stdc++.h>
using namespace std;

void printBox(char c){
	if(c != 'X' && c != 'O') cout <<" ";
	else cout <<c;
	cout <<" | ";
}
void printGrid(char arr[][3]){
	cout <<endl;
	for(int i =0; i < 13; i++) cout <<"_";
	cout <<endl;
	for(int i = 0; i < 3;i++){
		cout <<"| ";
		for(int j = 0; j < 3;j++){
			printBox(arr[i][j]);
		}
		cout <<endl;
	}
	for(int i =0; i < 13; i++) cout <<"_";
	cout <<endl;
}
void init(char arr[3][3]){
	char a = 'A';
	for(int i = 0; i < 3;i++) for(int j = 0; j < 3;j++) arr[i][j] = a++;
}

bool checkLine(char arr[3][3]){
	bool fRow = true;
	bool sRow = true;
	bool tRow = true;
	bool fCol = true;
	bool sCol = true;
	bool tCol = true;
	bool lDiag = true;
	bool tDiag = true;
	
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 3;j++){
		    if(arr[0][i] != arr[0][j]) fRow = false;
			if(arr[1][i] != arr[1][j]) sRow = false;
			if(arr[2][i] != arr[2][j]) tRow = false; 
			if(arr[i][0] != arr[j][0]) fCol = false;
			if(arr[i][1] != arr[j][1]) sCol = false;
			if(arr[i][2] != arr[j][2]) tCol = false;
			if(arr[i][i] != arr[j][j]) lDiag = false;
			if(arr[i][3 - i - 1] != arr[j][j - 3 - 1]) tDiag = false;	
		}	
	}
	
	return (fRow || sRow || tRow || fCol || sCol || tCol || lDiag || tDiag);
		
	
}
int main(){
	cout <<"TIC TAC TOE\n";
	cout <<"\n\n";
	
	int i = 0;
	//int moves = 0;
	char arr[3][3];
	int moves = 0;
	init(arr);
	int x,y;
	bool flag = 0;
	while(moves < 9){
		cout <<"Enter move\n";
		cin >>x >>y;
		if(x > 3 || x < 0 || y > 3 || y < 0){
			cout <<"Invalid Move\n";
			continue;
		}
		if(moves & 1) arr[x-1][y-1] = 'O';
		else arr[x-1][y-1] = 'X';
		if(checkLine(arr)){
			printGrid(arr);
			cout <<"Player " <<(moves & 1) <<" Wins\n";
			flag = 1;
			break;
		}
		printGrid(arr);
		moves++;
	}
	
	if(!flag) cout <<"Draw\n";
	
	

}
