#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;
/*
Aim: To read the input file from path: E:\Cpp_text\GraphTheory\dothi.txt
	which consists of first line as the matrix's degree
	and the following lines as the actual matrix
	
	And print the given matrix out of the console
*/

struct GRAPH{
	int degree; //Number of the graph's degree
	int matrix[MAX][MAX]; //Adjacency matrix
};

void readGraphFromPath(GRAPH& g){
	//define in file
	ifstream fileIn;
	
	//open in-file from the following path
	fileIn.open("E:/Cpp_text/GraphTheory/dothi.txt");
	/*
The file path "E:\Cpp_text\GraphTheory\dothi.txt" should be written
with a single forward slash (/) because \ is treated as an escape character in C++.
	*/
	
	//working with in file
	if ( fileIn.is_open() ){
		fileIn >> g.degree;
		
		for (int i= 0; i < g.degree; i++){
			for (int j= 0; j < g.degree; j++){
				fileIn >> g.matrix[i][j];
			}
		}
		
		//close after working
		fileIn.close();
	}
	else {
		cerr << "File can't be opened, check the path and try again";
	//It’s good practice to include error messages in cerr instead of cout when reporting errors.
	}
}

void printGraph(GRAPH g){
	cout << "So dinh la: " << g.degree << "\nMa tran ke:\n";
	
	for (int i= 0; i < g.degree; i++){
		for (int j= 0; j < g.degree; j++){
			cout <<  g.matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	
	GRAPH graph;
	
	readGraphFromPath(graph);
	
	printGraph(graph);
	
	return 0;
}
