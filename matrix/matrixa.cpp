//#include "matrixa.h"
//
//Matrix::Matrix(int a, int b, int c, int d)
//{
//	//������
//	m[0][0] = a;
//	m[0][1] = b;
//	m[1][0] = c;
//	m[1][1] = d;
//	/*2���� �迭�� ��Ļ���(2by2)*/
//}
//
//void Matrix::Transpose()
//{
//	//����� ��ġ
//	int tmp = m[0][1];
//	m[0][1] = m[1][0];
//	m[1][0] = tmp;
//
//}
//
//Matrix Matrix::operator+(const Matrix& a)
//{
//	//����� ����
//	Matrix c;
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			c.m[i][j] = this->m[i][j] + a.m[i][j];
//		}
//	}
//	return c;
//}
//
//Matrix Matrix::operator-(const Matrix& a)
//{
//	//����� ����
//
//	Matrix c;
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			c.m[i][j] = this->m[i][j] - a.m[i][j];
//		}
//	}
//	return c;
//}
//
//Matrix Matrix::operator*(const Matrix& a)
//{
//	//����� ����
//	Matrix c;
//	int sum = 0;
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			sum = 0;
//			for (int k = 0;k < 2;k++)
//			{
//				sum += (m[i][k] * a.m[i][k]);
//			}
//			c.m[i][j] = sum;
//		}
//	}
//	return c;
//}
//
//void Matrix::operator=(const Matrix& a)
//{
//	//����� �̵�
//
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			this->m[i][j] = a.m[i][j];
//		}
//	}
//}
//
//void Matrix::ShowMatrix()
//{
//	for (int i = 0;i < 2;i++)
//	{
//		for (int j = 0;j < 2;j++)
//		{
//			cout << m[i][j];
//		}
//		cout << endl;
//	}
//	//����� ���ҵ��� ������
//}
//
//int Matrix::GetDet()
//{
//	int det = 0;
//	det = (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
//	return det;
//	//����� ��Ľ��� ��ȯ 
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
