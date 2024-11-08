#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DINH = 100;

struct Graph{
	int ver;
	int adj[MAX_DINH][MAX_DINH];
};

/*
Viet chuong trinh doc ma tran ke cua do thi. Xac dinh va in ra:
	a. DONE: So canh (edges), so dinh (vertices) cua do thi?
	
		DESAU: Phan biet 2 TH do thi co huong va do thi vo huong
		
	b. TODO: Xuat bac cua tat ca cac dinh
		Bac cua 1 dinh trong do thi vo huong la
			tong cac canh ke voi dinh do.
		Khuyen duoc tinh 2 lan.
		
	c. TODO: Cac dinh co so bac max/ min,
		dinh bac chan, dinh bac le
	d. TODO: Cac dinh co lap, dinh treo
		Dinh co lap: bac = 0
		Dinh treo: bac = 1
*/

void readGraph(Graph& g){
	ifstream inFile;
	
	inFile.open("E:/Cpp_text/GraphTheory/dothi.txt");
	
	if ( inFile.is_open() ){
		inFile >> g.ver;
		
		for (int i= 0; i < g.ver; i++ ){
			for (int j= 0; j < g.ver; j++){
				inFile >> g.adj[i][j];
			}
		}
		
		inFile.close();
	}
	else{
		cout << "File khong mo duoc\n";
	}
}

void displayEV(Graph g){
	cout << "Do thi co so dinh la: " << g.ver << "\n";
	cout << "Do thi co so canh:\n";
	for (int i= 0; i<g.ver; i++){
		for (int j=0; j<g.ver; j++){
			cout << g.adj[i][j] << " ";
		}
		cout << "\n";
	}
}

void displayDeg(Graph g){
	//TODO
}

int main(){
	Graph g;
	
	readGraph(g);
	
//	if (!maTranKeHopLe(g)){
//		cout << "Ma tran ke khong hop le";
//		exit(0);
//	}
//	else{
//		//Lam bai
//	}

	displayEV(g);
	
	return 0;
}
