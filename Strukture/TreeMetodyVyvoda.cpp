#include <iostream>
#include <stack>
#include <ctime>
using namespace std;
class Tree
{
private:
	struct Mos
	{
		int key;
		Mos* left;
		Mos* right;
		Mos(int kee)
		{
			key = kee;
			left = NULL;
			
				right = NULL;
		}
		~Mos() {
			left = NULL;
			right = NULL;
			key = NULL;
		}
	};
	Mos* root;
	public:
			Tree() {
				root = NULL;
			}
			void insert(int N)
			{
				int mid =N / 2;
				for(int i = 0; i <N; i++)
				{
					root = push(root, i, mid);
				}
			}
			void insertsearch(int N)
			{
				int mid =N / 2;
				for(int i = mid; i >= 0; i--) {
					root = pushsearh(root, i);
				}
				for(int i = mid + 1; i <N; i++) {
					root = pushsearh(root, i);
				}
			}
			void vyvodpreOrder() {
				printpreOrder(root);
				cout << "preOrder" << endl;
			}
			void vyvodinOrder() {
				printinOrder(root);
				cout << "inOrder" << endl;
			}
			void vyvodpostOrder() {
				printpostOrder(root);
				cout << "postOrder" << endl;
			}
			private:
					Mos* push(Mos* root, int key, int mid)
					{
						
							if(root == NULL)
							{
								root = new Mos(key);
								return root;}
						if(root->left == NULL)
						{
							root->left = push(root->left, key, mid);
							return root;
						}
						if(root->right == NULL) {
							root->right = push(root->right, key, mid);
							return root;
						}
						if(key < mid) {
							root->left = push(root->left, key, mid);
							return root;
						}
						else
						{
							root->right = push(root->right, key, mid);
							return root;
						}
					}
					Mos* pushsearh(Mos* root, int key) {
						if(root == NULL)
						{
							root = new Mos(key);
							return root;
						}
						if(key < root->key)
						{
							root->left = pushsearh(root->left, key);
							return root;
						}
						if(key > root->key) {
							root->right = pushsearh(root->right, key);
							return root;
						}
					}
					void printpreOrder(Mos*t)
					{
						stack<Mos*> s;
						s.push(NULL);
						Mos* tt =t;
						do
						{
							if (tt != NULL) {
								s.push(tt);
								//cout « tt->key « '\n'; TLR ξαυξδ
									tt = tt->left;
							}
							
							else
							{
								if (s.top() == NULL) break;
								tt = s.top();
								s.pop();
								tt = tt->right;
							}
						} while(true);
					}
					void printinOrder(Mos*t)
					{
						stack<Mos*> s;
						s.push(NULL);
						Mos* tt =t;
						do
						{
							if (tt != NULL) {
								s.push(tt);
								tt = tt->left;
							}
							else
							{
								if (s.top() == NULL) break;
								tt = s.top();
								//std::cout « tt->key « '\n'; LTR ξαυξδ
									s.pop();
								tt = tt->right;
							}
						} while(true);
					}
					void printpostOrder(Mos*t)
					{
						stack<Mos*> s;
						stack<Mos*> out;
						s.push(NULL);
						Mos* tt =t;
						do
						{
							if (tt != NULL) {
								s.push(tt);
								out.push(tt);
								tt = tt->right;
							}
							else
							{
								if (s.top() == NULL) break;
								tt = s.top();
								s.pop();
								tt = tt->left;
							}
						} while(true);
						while(true) {
							if (out.empty()) break;
							tt = out.top();
							//cout « tt->key « '\n'; LRT ξαυξδ
								out.pop();
						}
						
					}
};
int main() {
	Tree mtree;
	Tree sertree;
	int n = 2500;
	cout << n << '\n';
	mtree.insert(2500);
	sertree.insertsearch(2500);
	unsigned int start_time = clock();
	mtree.vyvodinOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
	start_time = clock();
	sertree.vyvodpreOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
	start_time = clock();
	sertree.vyvodpostOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
	start_time = clock();
	sertree.vyvodinOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
	start_time = clock();
	sertree.vyvodpreOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
	start_time = clock();
	sertree.vyvodpostOrder();
	start_time = clock()- start_time;
	cout << "Time:" << start_time << '\n';
}