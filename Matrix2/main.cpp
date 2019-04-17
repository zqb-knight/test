#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	int l, r;
	cout << "请输入矩阵的行数和列数" << endl;
	cin >> l >> r;
	Matrix A1(l,r),  A2(l, r);
	//初始化输入
	A1.init();
	A2.init();
	//测试拷贝构造函数
	Matrix A3(A1);
	cout << "A3拷贝A1后的值为：" << endl;
	A3.show();
	//测试加减法函数和=的重载
	A3 = A3.sum(A1, A2);
	cout << "A1 + A2的结果为:" << endl;
	A3.show();
	A3 = A3.sub(A1, A2);
	cout << "A1 - A2的结果为:" << endl;
	A3.show();
	//测试指针
	Matrix *pA1 = new Matrix(l, r), *pA2 = new Matrix(l, r), *pA3 = new Matrix(l, r);
	pA1->init();
	pA2->init();
	cout << "pA1 + pA2的结果为：" << endl;
	*pA3 = pA3->sum(*pA1, *pA2);
	pA3->show();
	cout << "pA1 - pA2的结果为：" << endl;
	*pA3 = pA3->sub(*pA1, *pA2);
	pA3->show();
	delete pA1;
	delete pA2;
	delete pA3;
	system("pause");
	return 0;
}