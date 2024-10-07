#include<iostream>
#include<string.h>
using namespace std;
void nhap(char A[],char B[]);
void chuanHoa(char A[],char B[]);
void chen(char A[],int lA,int k);
void tinh_tong(char A[],char B[],char C[]);
void tinh_hieu(char A[],char B[],char D[]);
void tinhHieu(char A[],char B[],char D[]);
int ss(char A[],char B[]);
void xoa(char A[],int x);
void xuat(char C[],char D[]);
int main ()
{
	char A[10000],B[10000],C[10000],D[10000];
	nhap(A,B);
	chuanHoa(A,B);
	tinh_tong(A,B,C);
	tinh_hieu(A,B,D);
	xuat(C,D);
 	return 0;
}
void chuanHoa(char A[],char B[]){
	int lA=strlen(A);
	int lB=strlen(B);
	if(lA>lB){
		chen(B,lB,lA-lB);
	}else{
		chen(A,lA,lB-lA);
	}
}
void chen(char A[],int lA,int k){
	strrev(A);
	for(int i=0;i<k;i++){
		A[lA+i]='0';
	}
	A[lA+k]='\0';
	strrev(A);
}
void xuat(char C[],char D[]){
	puts(C);
	puts(D);
}
void tinhHieu(char A[],char B[],char D[]){
	int l=strlen(A);
	int nho=0;
	int i=0;
	for(int i=0;i<l;i++){
		int s=(A[i]-'0')-(B[i]-'0')-nho;
		if(s<0)
		{
			D[i]=s+10+'0';
			nho=1;
		}
		else
			{
				D[i]=s+'0';
				nho=0;
			}
	}
	D[l]='\0';
}
int ss(char A[],char B[]){
	strrev(A);
	strrev(B);
	for(int i=0;i<strlen(A);i++){
		if((A[i]-'0')>(B[i]-'0'))
		{
			strrev(A);
			strrev(B);
			return 1;
		}
		if((A[i]-'0')<(B[i]-'0'))
		{
			strrev(A);
			strrev(B);
			return 0;
		}
	}
	strrev(A);
	strrev(B);
	return 2;
}
void xoa(char A[],int x){
	int t=strlen(A);
	for(int i=x;i<t;i++)
		A[i]=A[i+1];
	A[t-1]='\0';
}
void tinh_hieu(char A[],char B[],char D[]){
	if(ss(A,B)==1){
		tinhHieu(A,B,D);
		strrev(D);
		while(D[0]=='0')
			xoa(D,0);
	}
	else
		if(ss(A,B)==0||ss(A,B)==2)
		{
			tinhHieu(B,A,D);
			strrev(D);
			while(D[0]=='0'&&strlen(D)>1)
				xoa(D,0);
			strrev(D);
			int l=strlen(D);
			if(ss(A,B)==0)
				{
					D[l++]='-';
					D[l]='\0';	
				}
			strrev(D);			
		}
}
void tinh_tong(char A[],char B[],char C[]){
	strrev(A);
	strrev(B);
	int l=strlen(A);
	int nho=0;
	int i=0;
	for(int i=0;i<l;i++){
		int s=(A[i]-'0')+(B[i]-'0')+nho;
		nho=s/10;
		s=s%10;
		C[i]=s+'0';
	}
	if(nho==1)
		C[l++]=nho+'0';
	C[l]='\0';
	strrev(C);
}
void nhap(char A[],char B[]){
	gets(A);
	gets(B);
}
