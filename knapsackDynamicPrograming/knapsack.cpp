#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define b 17  // Alt kümelerinin istenen toplamý
#define n 10  // A kümesinin eleman sayýsý
#define column b+2 //Hesap matrisinde kullanýlacak sütun sayýsý b+2 tercih edildi fakat %100 garanti için küme elemanlarý toplamý kadar olabilir(en kötü durum).
main(){
int dizi[n]={0,6,2,7,1};
int hesap[n][column];
int fark=b,tempi,tempj,tempj2;
   //Rasgele atanan deðerler
   srand(time(NULL));
   for(int i=0;i<n;i++)
   	 dizi[i]=1+rand()%b;
   printf("\n  A =");
   for(int i=0;i<n;i++)
   	  printf(" %4d",dizi[i]);
   printf("\n");

	/*
		* Hesap matrisinin oluþturulmasý
		* Hesap matrisi o anda ki b deðerinin (örn:12) dizi elemanlarýndan hangileriyle optimum oluþtuðunu gösterir
		* Her satýr dizi elemanýný ve öncekileri temsil eder.
		* örn:A={6,2,7,1} için 2.elemaný ele alýrsak eðer sutundaki b deðerine göre optimum deðer seçilir.
		* bu deðer b=2 iken 2, b=6 iken 6 , b=8 iken 2 ve 6 olur.
		* 2.eleman söz konusu olduðundan sadece bu satýrda bu 2 elemana bakýlmaktadýr.
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
	//Hesap matrisi içindeki deðerleri gözle test etmek için ekrana basýldý.		
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<column;j++)
		    printf(" %4d",hesap[i][j]);		
	}
    /*
		* Bulduðumuz deðer veya bulmak istediðimiz deðere en yakýn deðer tespit edildi
		* Bulmak istenilen deðerin (b.sütunun) kendisine ve sað kýsmýna bakýldý.
		* örn: b=12 için 12.sütuna bakýldý eðer 12 varsa zaten doðrudan cevap 12 olarak ele alýnmasý gerekir.
		* 12 o sütunda yoksa elemanlarýn 12'den farklarý alýnýr (mutlak deðer içinde) ve (12+1).sütun için iþlem tekrar edilir.
		* farklarýn minumumu tespit edilir ve o noktanýn konumu (tempi=i ve tempj=j) hafýzada tutulur.
		* hesap[tempi][tempj] konumu bizim cevabýmýz olur.
	*/
	for(int i=0;i<n;i++)
		for(int j=column-2;j<=column;j++){
		    if(fark>fabs(hesap[i][j]-b)){
				tempi=i;tempj=j;
			    fark=abs(hesap[i][j]-b);
			}		    
		}
	tempj2=tempj;//tempj'nin aþaðýda deðeriyle oynanacaðý için tekrar hafýzada tutuldu.
	printf("\n\n");
	/*
		* Hangi elemanlarýn toplanmasý sonucu son deðerin elde edildiðinin tespiti.
		* Hesap matrisi oluþtururken A kümesinin elemaný > b olduðu durumda o sütuna kadar tüm deðerler üst satýrýn aynýsý olur.
		* Nedeni örn: {6} için; b=1,2,3,4,5 karþýlamaz deðeri 0 olur.Öncesinde bir eleman olsaydý üstteki deðerler doðrudan alta aktarýlýrdý.
		* Fakat b=6 için karþýlanýr ve 1.satýr b=6.sütun deðeri 6 olur.
		* Sonraki satýrlar hesaplanýrken (A kümesinin elemaný < b), bir önceki satýrýn A kümesinin elemaný kadar geri gidip orda bulunan eleman A kümesinin elemanýyla toplanýr..
		* bu toplam eðer bulunduðumuz konumun bir önceki satýr deðerinden büyükse yeni satýr deðerimiz olur.Küçük veya eþitse bir önceki satýr deðeri yeni satýr deðeri olur.
		* Aslýnda bizim seçtiðimiz A kümesinin elemaný, konumun deðiþtiði (toplanan) yani önceki satýr deðeri olmayan deðerlerdir.
		* Bu kod blogunda bu deðiþimin olduðu yerler tespit edilip ekrana basýlmýþtýr. 
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
