#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix
{
public:
	Matrix();
	Matrix(int l, int r);
	Matrix(const Matrix& A);
	~Matrix();
	Matrix sum(const Matrix& A, const Matrix& B);
	Matrix sub(const Matrix& A, const  Matrix& B);
	void init();
	void show();
	Matrix& operator=(const Matrix& M);
private:
	int line, row;    
	int **mat;
};

#endif