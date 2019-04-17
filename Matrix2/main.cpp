#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	int l, r;
	cout << "��������������������" << endl;
	cin >> l >> r;
	Matrix A1(l,r),  A2(l, r);
	//��ʼ������
	A1.init();
	A2.init();
	//���Կ������캯��
	Matrix A3(A1);
	cout << "A3����A1���ֵΪ��" << endl;
	A3.show();
	//���ԼӼ���������=������
	A3 = A3.sum(A1, A2);
	cout << "A1 + A2�Ľ��Ϊ:" << endl;
	A3.show();
	A3 = A3.sub(A1, A2);
	cout << "A1 - A2�Ľ��Ϊ:" << endl;
	A3.show();
	//����ָ��
	Matrix *pA1 = new Matrix(l, r), *pA2 = new Matrix(l, r), *pA3 = new Matrix(l, r);
	pA1->init();
	pA2->init();
	cout << "pA1 + pA2�Ľ��Ϊ��" << endl;
	*pA3 = pA3->sum(*pA1, *pA2);
	pA3->show();
	cout << "pA1 - pA2�Ľ��Ϊ��" << endl;
	*pA3 = pA3->sub(*pA1, *pA2);
	pA3->show();
	delete pA1;
	delete pA2;
	delete pA3;
	system("pause");
	return 0;
}