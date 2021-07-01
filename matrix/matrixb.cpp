#include "matrixb.h"

Matrix::Matrix(int a, int b, int c, int d,int e,int f,int g,int h,int i)
{
	//생성자

	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[1][0] = d;
	m[1][1] = e;
	m[1][2] = f;
	m[2][0] = g;
	m[2][1] = h;
	m[2][2] = i;

	/*2차원 배열로 행렬생성(3by3)*/
}

void Matrix::Transpose()
{
	//행렬의 전치
	int tmp[3] = {m[0][1],m[1][2],m[0][2]};

	m[0][1] = m[1][0];
	m[1][2] = m[2][1];
	m[0][2] = m[2][0];

	m[1][0] = tmp[0];
	m[2][1] = tmp[1];
	m[2][0] = tmp[2];
}

Matrix Matrix::operator+(const Matrix& a)
{
	//행렬의 덧셈
	Matrix c;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			c.m[i][j] = this->m[i][j] + a.m[i][j];
		}
	}
	return c;
}

Matrix Matrix::operator-(const Matrix& a)
{
	//행렬의 뺄셈

	Matrix c;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			c.m[i][j] = this->m[i][j] - a.m[i][j];
		}
	}
	return c;
}

Matrix Matrix::operator*(const Matrix& a)
{
	//행렬의 곱셈
	Matrix c;
	int sum = 0;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sum = 0;
			for (int k = 0;k < 3;k++)
			{
				sum += (m[i][k] * a.m[i][k]);
			}
			c.m[i][j] = sum;
		}
	}
	return c;
}

void Matrix::operator=(const Matrix& a)
{
	//행렬의 이동

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			this->m[i][j] = a.m[i][j];
		}
	}
}

void Matrix::ShowMatrix()
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << m[i][j]<<" ";
		}
		cout << endl;
	}
	//행렬의 원소들을 보여줌
}

int Matrix::GetDet()
{

	int det = 0;
	int tmp[3] = { m[0][0],m[0][1],m[0][2] };
	
	det += tmp[0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
	det -= tmp[1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	det += tmp[2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

	return det;

	//행렬의 행렬식을 반환 

}

























