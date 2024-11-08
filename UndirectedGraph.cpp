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
	a. TODO: So canh (edges), so dinh (vertices) cua do thi?
	
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

void displayNumVnE(Graph g){
	int edgeNum = 0;
	cout << "Do thi co so dinh la: " << g.ver << "\n";
	cout << "Do thi co so canh: ";
	for (int i= 0; i<g.ver; i++){
		for (int j=0; j<g.ver; j++){
			if ( g.adj[i][j] != 0 || g.adj[i][j] != 0 ){
				edgeNum += 1;
			}
		}
	}
	cout << edgeNum << "\n";
}

void displayDeg(Graph g){
	//TODO
}

bool undirectedGraph(Graph g){
	for (int i= 0; i < g.ver; i++){
		for (int j= 0; j < g.ver; j++){
			if ( g.adj[i][j] != g.adj[j][i] ) return 0;
		}
	}
	return 1;
}
/*
void displaySpecialVertices(Graph g){
	for (int i= 0; i < g.ver; i++){
			for (int j= 0; j < g.ver; j++){
				if ( (g.adj[i][j] == 0) && (g.adj[j][i]==0) ){
					cout << "Dinh co lap:\n"
					cout << g.adj[i] << " ";
				}
				cout << "\n"
				if ( (g.adj[i][j] == 1) && (g.adj[j][i]==1) ){
					cout << "Dinh treo:\n"
					cout << g.adj[i] << " ";
				}
				cout << "\n";
			}
		}
	}
}
*/
int main(){
	Graph g;
	
	readGraph(g);

	displayNumVnE(g);

	
	
	return 0;
}
