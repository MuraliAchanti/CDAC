#include<iostream>
using namespace std;
class Matrix {
	int m, n,**ip;
public:
	void getdata() {
		cout << "Enter the rows and columns" << endl;
		cin >> m >> n;
	}
	void createdata() {
		ip = new int*[m];
		for (int i = 0; i < m; i++)
		{
			ip[i] = new int[n];
		}
	}
	void setdata(){
		int i, j;

		cout << "Enter the ele" << endl;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				cin >> ip[i][j];
	}
	friend void multi(Matrix, Matrix);
};
void multi(Matrix m1, Matrix m2)
{
	Matrix m3;
	int i, j, k,sum;
	if (m1.m == m2.m&&m1.n == m2.n)
	{
		m3.m = m1.m;
		m3.n = m1.n;
		m3.createdata();//created a new matrix to store the result
		for (i = 0; i < m3.m; i++)
		{
			for (j = 0; j < m3.n; j++)
			{
				sum = 0;
				for (k = 0; k < m3.m; k++)
				{
					sum = sum + (m1.ip[i][k] * m2.ip[k][j]);
				}
				m3.ip[i][j] = sum;
			}
		}
		for (i = 0; i < m3.m; i++)
		{
			for (j = 0; j < m3.n; j++)
			{
				cout << m3.ip[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Not possible" << endl;
	}
}
int main()
{
	Matrix m1, m2;
	m1.getdata();
	m1.createdata();
	m1.setdata();
	m2.getdata();
	m2.createdata();
	m2.setdata();
	cout << "The muliplied result" << endl;
	multi(m1, m2);
}