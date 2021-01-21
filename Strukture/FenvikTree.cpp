/*Реализовать алгоритмы дерева отрезков и дерева Фенвика для нахождения суммы на отрезке.*/
#include <iostream> 
#include <stack>
#include <algorithm>
#include <ctime>
#include <vector> 
#include <cmath>
#define N 1000000
using namespace std;
vector<int> a;
vector<int> fen;
vector<int> treeotr;
int iter=0;
void insert() {
	for (int i = 0;i < N;i++)
	{
		a.push_back(rand() % 9 + 1);
	}
	cout << a.size();
}

void F(int k, int d) { // k- с какого индекса изменять массив, d- на какую величину
	
	while (k < N)
	{
		fen[k] += d;    
		k = (k | (k + 1));
	}
}
void create(vector<int> b) {
	 fen.assign(b.size(),0);
	for (int i = 0; i < fen.size(); i++)
	{
		F(i, a[i]); //функция для обновления элементов массива Фенвика, функции подаем индекс с которого нужно обновить данные и на какую величину 
	}
}
int prsumm(int count) {          // для нахождения суммы  count элементов
	int res = 0;
	while ((count-1) >= 0) {
		res += fen[count - 1];
		count = (count - 1)&count;
	}
	return res;
}
int summotr(int l, int r) {
	int res = 0;
	res = prsumm(r) - prsumm((l - 1));
	return res;
}
void zamenaelementa(int nomer, int val) {        // производит замену элемента номер nomer, на новое значение.
	a[nomer - 1] = val;
	val=val-summotr(nomer, nomer - 1);
	F(nomer - 1, val);
}
void cre(int top,int L, int R)
{
	
	
	if (L == R) {
if (iter >= a.size()) {
		return;
	}
		treeotr[top] = a[iter];
		iter++;
		return;
		
	}
	
	
	int mid = 0;
	mid = (L+R) / 2;
	cre(top*2, L,mid );
	cre(top * 2 + 1, mid + 1, R);
		treeotr[top] = treeotr[top*2] + treeotr[top*2+1];
	
}
void createtreeotr(vector<int> b) {
	int n = 0;
	iter = 0;
	n = log(b.size()-1) / log(2) + 1;  
	n = pow(2,n);    // исходный массив будет записан в treeotr с индекса, который начинается с n
	treeotr.assign(2*n, 0); // инициализируем дерево отрекзков 0
		cre(1, n,treeotr.size()-1);   // (n + (b.size() - 1)

	
	
}


int summin(int L, int R,int l, int r, int res,int top) {
	if (l > r) {
		return 0;
	}
	if (L == l && R == r) {
		return treeotr[top];
	}
	int mid = (L + R) / 2;

	 return summin(L, mid, l, (min(r, mid)), res,top*2) + summin(mid + 1, R, (max(l, mid+1)), r, res,(top*2+1));
	
}
int summotrO(int L, int R) //трезок с какого числа нужна сумма и до какого
{
	int n = 0;
	n = log(a.size() - 1) / log(2) + 1;
	n = pow(2, n);
	int l = L + n;
	int r = R + n;
	if (L == (n+1)&&R==(n+a.size())) {
	return treeotr[1];
	}
	int summa = 0;
	L = n;
	R =treeotr.size();
	summa=summin(L,R,l,r,summa,1);
	return summa;


}


int main() {
	
	
	
	cout <<"count elementsN"<< N << '\n';

	insert();// генерация массива
	unsigned int start_time = clock();
	create(a); // инициализация дерева фенвика
	start_time = clock() - start_time;
	cout << '\n' << "Time_create_fenvik:" << start_time << '\n';
	start_time = clock();
	createtreeotr(a); // создание дерева отрезков
	start_time = clock() - start_time;
	cout << "Time_create_otrezki:" << start_time << '\n';
	cout << endl;
	
		
		
	
		start_time = clock();
		
		cout<<"Summ count fenvik "<<summotr(4, 8)<< '\n';;
		start_time = clock() - start_time;
		cout << "Timesummfenvik: " << start_time << '\n';
		
		start_time = clock();
		cout << "Summ count otrezki " << summotrO(4, 8)<< '\n';
		start_time = clock() - start_time;
		cout << "TimeOtrezki: " << start_time << '\n';
	
	
	

		
	
	cout << "Hello World!\n";
}