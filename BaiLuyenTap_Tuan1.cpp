#include <iostream>
using namespace std;

const int MAX_DINH = 100;

struct GRAPH{
	int sodinh;
	int adMatrix[MAX_DINH][MAX_DINH];
};

/*
Viet chuong trinh doc ma tran ke cua do thi. Xac dinh va in ra:
	a. So canh, so dinh cua do thi?
		Phan biet 2 TH do thi co huong va do thi vo huong
	b. Xuat bac cua tat ca cac dinh
		Bac cua 1 dinh trong do thi vo huong la
		tong cac canh ke voi dinh do.
		Khuyen duoc tinh 2 lan.
	c. Cac dinh co so bac max/ min,
		dinh bac chan, dinh bac le
	d. Cac dinh co lap, dinh treo
		Dinh co lap: bac = 0
		Dinh treo: bac = 1
*/

int main(){
	GRAPH g;
	
	readGRAPH(g);
	
	if (!maTranKeHopLe(g)){
		cout << "Ma tran ke khong hop le";
		exit(0);
	}
	else{
		//Lam bai
	}
	
	return 0;
}
