#include <iostream>
#include "polyb.h"
using namespace std;

Polynomial Polynomial::operator/(Polynomial& b)
/* ���׽��� ������ ������ / �� �����ε� �����Լ� */
/* *this�� b�� ���� */
{
    Polynomial c;//����������� ��ȯ�� ���׽İ�ü
   
    int tmp = this->termArray[0].coef;
    int val = -(b.termArray[1].coef);
    //������ ���� 0���� ����� ��

    c.NewTerm(tmp, (termArray[0].exp - 1));

    for (int i = 1;i < (terms - 1);i++)
    {
        tmp = termArray[i].coef + (val * tmp);
        c.NewTerm(tmp, (termArray[i].exp - 1));
    }

    return c;
}

istream& operator>> (istream& is, Polynomial& p)
/* ���׽��� �׵��� �о��. */
{
    // #terms and (coefficoent, exponent)�� pair���� �о���δ�.
    // ���������� �׺��� ����Ǿ��ٰ� �����Ѵ�.
    int noofterms; float coef; int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // ����� ���� pair�� �о���δ�.
        p.NewTerm(coef, exp);
    }
    return is;
}
ostream& operator<<(ostream& os, Polynomial& p)

{
    for (int i = 0;i < p.terms;i++)
    {
        if (i == 0)
        {
            if (p.termArray[i].coef == 1)
            {
                os << "x^" << p.termArray[i].exp;
            }
            else if (p.termArray[i].coef == -1)
            {
                os << "-" << "x^" << p.termArray[i].exp;
            }
            else
            {
                os << p.termArray[i].coef << "x^" << p.termArray[i].exp;
            }
        }
        else
        {
            if (p.termArray[i].coef == 1)
            {
                os << "+";
            }
            else if (p.termArray[i].coef == -1)
            {
                os << "-";
            }
            else
            {
                if (p.termArray[i].coef > 0)
                {
                    os << "+" << p.termArray[i].coef;
                }
                else if (p.termArray[i].coef < 0)
                {
                    os << "-" << -(p.termArray[i].coef);
                }
            }
            //������

            if (p.termArray[i].exp != 0)
            {
                os << "x^" << p.termArray[i].exp;
            }
            //x^(����) ���
        }
    }

    os << endl; //���׽��ϳ� ����� ������ ����

    return os;

}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // ���׽� �ڿ� ���ο� ���� �߰��ϴ� �Լ�
    if (terms == capacity)
    {
        capacity *= 2;
        Term* tmp = new Term[capacity];
        copy(termArray, termArray + terms, tmp);
        delete[] termArray;
        termArray = tmp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator+(Polynomial& b)
/* ���׽��� ������ �����ϴ� ������ + �����ε�*/
{
    Polynomial c;
    // ���� ����� ������ ���׽� c

    if (terms == 0)return b;
    //���� �������� �ʴ� ���

    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms))
    {
        if (termArray[aPos].exp == b.termArray[bPos].exp)
            /*������ ���� ���*/
        {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) { c.NewTerm(t, termArray[aPos].exp); }
            // ����� ���ؼ� 0�� �ƴҰ�� c���߰�

            aPos++;
            bPos++; // ���� ������ �Ѿ��!
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp)
            /*a�� ���� < b�� ����*/
        {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else
            /*a�� ���� > b�� ����*/
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }

    // ������ a, b�߿� �����׵� �־��ֱ�
    for (; aPos < terms; aPos++)
    {
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    }
    for (; bPos < b.terms; bPos++)
    {
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    }
    return c;
}











