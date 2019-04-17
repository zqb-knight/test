#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix::Matrix()
{
}

//构造函数
Matrix::Matrix(int l, int r)
	:line(l), row(r)
{
	mat = new int*[line];
	for (int i = 0; i < line; i++)
	{
		mat[i] = new int[row];
	}
}

//拷贝构造函数
Matrix::Matrix(const Matrix& A)
{
	line = A.line;
	row = A.row;
	mat = new int*[line];
	for (int i = 0; i < line; i++)
	{
		mat[i] = new int[row];
	}
	for (int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
			mat[i][j] = A.mat[i][j];
}

Matrix::~Matrix()
{
	if (mat != NULL)
	{
		for (int i = 0; i < line; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}
}

//加法函数
Matrix Matrix::sum(const Matrix& A, const Matrix& B)
{
	Matrix C(A.line, A.row);
	for(int i = 0; i< line; i++)
		for (int j = 0; j < row; j++)
		{
			C.mat[i][j] = B.mat[i][j] + A.mat[i][j];
		}
	return C;
}

//减法函数
Matrix Matrix::sub(const Matrix& A, const Matrix& B)
{
	Matrix C(A.line, A.row);
	for (int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
		{
			C.mat[i][j] = A.mat[i][j] - B.mat[i][j];
		}
	return C;
}

//输出函数
void Matrix::show()
{
	for(int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
		{
			if (j == row - 1)		cout << mat[i][j] << endl;
			else		cout << mat[i][j] << " ";
		}
}

//初始化输入函数
void Matrix::init()
{
	cout << "请输入" << line << "行" << row << "列的矩阵" << endl;
	for (int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
			cin >> mat[i][j];
}

Matrix& Matrix::operator=(const Matrix& M)
{
	//判断是否自赋值
	if (this != &M)
	{
		//释放旧元素
		for (int i = 0; i < line; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
		
		//赋值
		this->line = M.line;
		this->row = M.row;
		mat = new int*[line];
		for (int i = 0; i < line; i++)
		{
			mat[i] = new int[row];
		}
		
		for (int i = 0; i < line; i++)
			for (int j = 0; j < row; j++)
				this->mat[i][j] = M.mat[i][j];
	}
	return *this;
}
