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
	a. done: So canh (edges), so dinh (vertices) cua do thi?
	
		DESAU: Phan biet 2 TH do thi co huong va do thi vo huong
		
	b. done: Xuat bac cua tat ca cac dinh
		Bac cua 1 dinh trong do thi vo huong la
			tong cac canh ke voi dinh do.
		Khuyen duoc tinh 2 lan.
		
	c. TODO: Cac dinh co so bac max/ min,
		dinh bac chan, dinh bac le
	d. done: Cac dinh co lap, dinh treo
		Dinh co lap: bac = 0
		Dinh treo: bac = 1
*/

//read txt file from path
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


//display the degree of each node (each row)
void displayDeg(Graph g){
	/*In a nut shell:
	Check from [i] = 0
		bool isolated = false;
		int connection = 0;
		from [j]
		if adj[i][j] == 0 && adj[j][i] == 0
			isolated = true;
		if adj[i][j] != 0 || adj[j][i] != 0
			connection += 1;
		if (isolated) cout << "Dinh co lap: " << i << "\n";
		if (connection != 1)
			cout << "Dinh " << i << " co bac: " << connection << endl;
		else cout << "Dinh treo: " << i << "\n";
	*/
	for (int i= 0; i < g.ver; i++){
		bool isolated = false;
		int connection = 0;
		for (int j= 0; j < g.ver; j++){
			if (g.adj[i][j] == 0)  isolated = true;
			else connection += 1;
		}
		cout << "Dinh " << i;
	 	if (isolated == 1 && connection == 0) cout << " la dinh co lap" << "\n";
		else if (connection == 1) cout << " la dinh treo" << "\n";
		else if (connection != 1) cout << " co so bac la: " << connection << endl;
	}

}

//check if the given graph was typed as undirected
bool undirectedGraph(Graph g){
	for (int i= 0; i < g.ver; i++){
		for (int j= 0; j < g.ver; j++){
			if ( g.adj[i][j] != g.adj[j][i] ) return 0;
		}
	}
	return 1;
}

int main(){
	Graph g;
	
	readGraph(g);

	//displayNumVnE(g);

	displayDeg(g);
	
	return 0;
}
