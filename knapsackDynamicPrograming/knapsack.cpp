#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define b 17  // Alt k�melerinin istenen toplam�
#define n 10  // A k�mesinin eleman say�s�
#define column b+2 //Hesap matrisinde kullan�lacak s�tun say�s� b+2 tercih edildi fakat %100 garanti i�in k�me elemanlar� toplam� kadar olabilir(en k�t� durum).
main(){
int dizi[n]={0,6,2,7,1};
int hesap[n][column];
int fark=b,tempi,tempj,tempj2;
   //Rasgele atanan de�erler
   srand(time(NULL));
   for(int i=0;i<n;i++)
   	 dizi[i]=1+rand()%b;
   printf("\n  A =");
   for(int i=0;i<n;i++)
   	  printf(" %4d",dizi[i]);
   printf("\n");

	/*
		* Hesap matrisinin olu�turulmas�
		* Hesap matrisi o anda ki b de�erinin (�rn:12) dizi elemanlar�ndan hangileriyle optimum olu�tu�unu g�sterir
		* Her sat�r dizi eleman�n� ve �ncekileri temsil eder.
		* �rn:A={6,2,7,1} i�in 2.eleman� ele al�rsak e�er sutundaki b de�erine g�re optimum de�er se�ilir.
		* bu de�er b=2 iken 2, b=6 iken 6 , b=8 iken 2 ve 6 olur.
		* 2.eleman s�z konusu oldu�undan sadece bu sat�rda bu 2 elemana bak�lmaktad�r.
	*/
	for(int i=0;i<n;i++)		
		for(int j=0;j<column;j++){
		    if(i==0 ||j==0){hesap[i][j]=0;continue;}
	        if (dizi[i]>j || dizi[i]+hesap[i-1][j-dizi[i]]==hesap[i-1][j])	   
		   		hesap[i][j]=hesap[i-1][j];
			else if(dizi[i]+hesap[i-1][j-dizi[i]] < hesap[i-1][j])			
			    hesap[i][j]=hesap[i-1][j]; 
		    else if(dizi[i]+hesap[i-1][j-dizi[i]] > hesap[i-1][j]) 			
				hesap[i][j]=dizi[i]+hesap[i-1][j-dizi[i]]; 
		}
	//Hesap matrisi i�indeki de�erleri g�zle test etmek i�in ekrana bas�ld�.		
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<column;j++)
		    printf(" %4d",hesap[i][j]);		
	}
    /*
		* Buldu�umuz de�er veya bulmak istedi�imiz de�ere en yak�n de�er tespit edildi
		* Bulmak istenilen de�erin (b.s�tunun) kendisine ve sa� k�sm�na bak�ld�.
		* �rn: b=12 i�in 12.s�tuna bak�ld� e�er 12 varsa zaten do�rudan cevap 12 olarak ele al�nmas� gerekir.
		* 12 o s�tunda yoksa elemanlar�n 12'den farklar� al�n�r (mutlak de�er i�inde) ve (12+1).s�tun i�in i�lem tekrar edilir.
		* farklar�n minumumu tespit edilir ve o noktan�n konumu (tempi=i ve tempj=j) haf�zada tutulur.
		* hesap[tempi][tempj] konumu bizim cevab�m�z olur.
	*/
	for(int i=0;i<n;i++)
		for(int j=column-2;j<=column;j++){
		    if(fark>fabs(hesap[i][j]-b)){
				tempi=i;tempj=j;
			    fark=abs(hesap[i][j]-b);
			}		    
		}
	tempj2=tempj;//tempj'nin a�a��da de�eriyle oynanaca�� i�in tekrar haf�zada tutuldu.
	printf("\n\n");
	/*
		* Hangi elemanlar�n toplanmas� sonucu son de�erin elde edildi�inin tespiti.
		* Hesap matrisi olu�tururken A k�mesinin eleman� > b oldu�u durumda o s�tuna kadar t�m de�erler �st sat�r�n ayn�s� olur.
		* Nedeni �rn: {6} i�in; b=1,2,3,4,5 kar��lamaz de�eri 0 olur.�ncesinde bir eleman olsayd� �stteki de�erler do�rudan alta aktar�l�rd�.
		* Fakat b=6 i�in kar��lan�r ve 1.sat�r b=6.s�tun de�eri 6 olur.
		* Sonraki sat�rlar hesaplan�rken (A k�mesinin eleman� < b), bir �nceki sat�r�n A k�mesinin eleman� kadar geri gidip orda bulunan eleman A k�mesinin eleman�yla toplan�r..
		* bu toplam e�er bulundu�umuz konumun bir �nceki sat�r de�erinden b�y�kse yeni sat�r de�erimiz olur.K���k veya e�itse bir �nceki sat�r de�eri yeni sat�r de�eri olur.
		* Asl�nda bizim se�ti�imiz A k�mesinin eleman�, konumun de�i�ti�i (toplanan) yani �nceki sat�r de�eri olmayan de�erlerdir.
		* Bu kod blogunda bu de�i�imin oldu�u yerler tespit edilip ekrana bas�lm��t�r. 
	*/
	for(int i=tempi;i>=0;i--)			
		for(int j=tempj;j>0;j--){
		    if(hesap[i][j]>hesap[i-1][j]){			
				printf(" %4d",dizi[i]);
				tempj-=dizi[i];
			}	
				break;			
		}		
	if(b==hesap[tempi][tempj2])printf("\n\n   Buldum: %d",hesap[tempi][tempj2]);
	else printf("\n\n    Yaklasik deger: %d",hesap[tempi][tempj2]);
	
}
