
#ifndef RSA_H
#define RSA_H

#include <stdio.h>
#include <string>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#include <malloc.h>
#include <iostream>
#include <ppl.h>

using namespace std;
using namespace Concurrency;
//! MAX是数组的最大个数，LEN为结构体slink的占用内存空间大小 */
#define MAX 50
#define LEN sizeof(struct slink)

class _declspec(dllexport) RSA
{
public:
	typedef struct slink
	{
		int  bignum[MAX];/*!< bignum[98]用来标记正负号，1正，0负bignum[99]来标记实际长度*/
		struct slink *next;
	}slink;

public:

	RSA();
	~RSA();

public:
	//! #RSA的大数运算函数库

	/** @大数比较函数
	@see int cmp(int, int)
	*/
	int cmp(int a1[MAX], int a2[MAX]);
	/** @大数类型转换函数
	@see void mov(int a[MAX],int *b);
	*/
	void mov(int a[MAX], int *b);
	/** @大数乘积函数
	@see void mul(int a1[MAX],int a2[MAX],int *c);
	*/
	void mul(int a1[MAX], int a2[MAX], int *c);
	/** @大数相加函数
	@see void add(int a1[MAX],int a2[MAX],int *c);
	*/
	void add(int a1[MAX], int a2[MAX], int *c);
	/** @大数大数相减函数
	@see  void sub(int a1[MAX],int a2[MAX],int *c);
	*/
	void sub(int a1[MAX], int a2[MAX], int *c);
	/*! @大数取模函数
	@see void mod(int a[MAX],int b[MAX],int  *c);
	@attention /c=a mod b//注意：经检验知道此处A和C的数组都改变了。
	*/
	void mod(int a[MAX], int b[MAX], int  *c);
	/*! @大数相除函数
	@see void divt(int t[MAX],int b[MAX],int  *c ,int *w);
	@attention //试商法//调用以后w为a mod b, C为a  div b;
	*/
	void divt(int t[MAX], int b[MAX], int  *c, int *w);
	/*! @解决 了 m=a*b mod n;
	/*!
	@see void mulmod(int a[MAX] ,int b[MAX] ,int n[MAX],int *m);
	*/
	void mulmod(int a[MAX], int b[MAX], int n[MAX], int *m);
	/*! @解决 m=a^p  mod n的函数问题
	/*!
	@see void expmod(int a[MAX] ,int p[MAX] ,int n[MAX],int *m);
	*/
	void expmod(int a[MAX], int p[MAX], int n[MAX], int *m);
	/*!  @判断是否为素数
	@see int   is_prime_san(int p[MAX] );
	*/
	int   is_prime_san(int p[MAX]);
	/*! @判断两个大数之间是否互质
	@see int coprime(int e[MAX],int s[MAX]);
	*/
	int coprime(int e[MAX], int s[MAX]);
	/*!  @随机产生素数
	@see void prime_random(int *p,int *q);
	*/
	void prime_random(int *p, int *q);
	/*! @产生素数e
	@see void erand(int e[MAX],int m[MAX]);
	*/
	void erand(int e[MAX], int m[MAX]);
	/*! @根据规则产生其他的数
	@see void rsad(int e[MAX],int g[MAX],int *d);
	*/
	void rsad(int e[MAX], int g[MAX], int *d);

	unsigned long  rsa(unsigned long p, unsigned long q, unsigned long e);
	bool RSAKey();
	string tencrypto(int e[MAX], int n[MAX], char* text);
	string tdecrypto(int d[MAX], int n[MAX], string text);

public:
	/** @brief 定义的全局变量，存储密钥 */
	//q与p：产生的大素数
	int  p[MAX], q[MAX], n[MAX], d[MAX], e[MAX], m[MAX], p1[MAX], q1[MAX];

private:
	int  i;
	char  c;
	//struct slink *head,*h1,*h2;
};

#endif