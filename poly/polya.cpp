#include <iostream>
#include "polya.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p)
/* 다항식의 항들을 읽어나감. */
{
    // #terms and (coefficoent, exponent)의 pair들을 읽어들인다.
    // 높은차수의 항부터 저장되었다고 가정한다.
    int noofterms; float coef; int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // 계수와 지수 pair를 읽어들인다.
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
                    os << "x^"<<p.termArray[i].exp;
                }
                else if (p.termArray[i].coef == -1)
                {
                    os << "-"<<"x^" << p.termArray[i].exp;
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
                //계수출력

                if (p.termArray[i].exp != 0)
                {
                    os << "x^" << p.termArray[i].exp;
                }
                //x^(지수) 출력
            }
    }

    os << endl; //다항식하나 출력할 떄마다 개행

    return os;

}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // 다항식 뒤에 새로운 항을 추가하는 함수
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
/* 다항식의 덧셈을 구현하는 연산자 + 오버로딩*/
{    
    Polynomial c;	
    // 더한 결과를 저장할 다항식 c
    
    if (terms == 0)return b;
    //항이 존재하지 않는 경우

    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)) 
    {
        if (termArray[aPos].exp == b.termArray[bPos].exp)
        /*지수가 같은 경우*/
        {	
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) { c.NewTerm(t, termArray[aPos].exp); }	
            // 계수를 더해서 0이 아닐경우 c에추가
            
            aPos++;
            bPos++; // 다음 항으로 넘어가자!
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp) 
        /*a의 지수 < b의 지수*/
        {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++; 
        }
        else 
         /*a의 지수 > b의 지수*/
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    } 

    // 나머지 a, b중에 남은항들 넣어주기
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












