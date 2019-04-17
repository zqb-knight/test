#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix::Matrix()
{
}

//���캯��
Matrix::Matrix(int l, int r)
	:line(l), row(r)
{
	mat = new int*[line];
	for (int i = 0; i < line; i++)
	{
		mat[i] = new int[row];
	}
}

//�������캯��
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

//�ӷ�����
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

//��������
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

//�������
void Matrix::show()
{
	for(int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
		{
			if (j == row - 1)		cout << mat[i][j] << endl;
			else		cout << mat[i][j] << " ";
		}
}

//��ʼ�����뺯��
void Matrix::init()
{
	cout << "������" << line << "��" << row << "�еľ���" << endl;
	for (int i = 0; i < line; i++)
		for (int j = 0; j < row; j++)
			cin >> mat[i][j];
}

Matrix& Matrix::operator=(const Matrix& M)
{
	//�ж��Ƿ��Ը�ֵ
	if (this != &M)
	{
		//�ͷž�Ԫ��
		for (int i = 0; i < line; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
		
		//��ֵ
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
