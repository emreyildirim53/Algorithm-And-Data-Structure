#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define b 17  // Alt kümelerinin istenen toplamı
#define n 10  // A kümesinin eleman sayısı
#define column b+2 //Hesap matrisinde kullanılacak sütun sayısı b+2 tercih edildi fakat %100 garanti için küme elemanları toplamı kadar olabilir(en kötü durum).
main(){
int dizi[n]={0,6,2,7,1};
int hesap[n][column];
int fark=b,tempi,tempj,tempj2;
   //Rasgele atanan değerler
   srand(time(NULL));
   for(int i=0;i<n;i++)
   	 dizi[i]=1+rand()%b;
   printf("\n  A =");
   for(int i=0;i<n;i++)
   	  printf(" %4d",dizi[i]);
   printf("\n");
	/*
		* Hesap matrisinin oluşturulması
		* Hesap matrisi o anda ki b değerinin (örn:12) dizi elemanlarından hangileriyle optimum oluştuğunu gösterir
		* Her satır dizi elemanını ve öncekileri temsil eder.
		* örn:A={6,2,7,1} için 2.elemanı ele alırsak eğer sutundaki b değerine göre optimum değer seçilir.
		* bu değer b=2 iken 2, b=6 iken 6 , b=8 iken 2 ve 6 olur.
		* 2.eleman söz konusu olduğundan sadece bu satırda bu 2 elemana bakılmaktadır.
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
	//Hesap matrisi içindeki değerleri gözle test etmek için ekrana basıldı.		
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<column;j++)
		    printf(" %4d",hesap[i][j]);		
	}
         /*
		* Bulduğumuz değer veya bulmak istediğimiz değere en yakın değer tespit edildi
		* Bulmak istenilen değerin (b.sütunun) kendisine ve sağ kısmına bakıldı.
		* örn: b=12 için 12.sütuna bakıldı eğer 12 varsa zaten doğrudan cevap 12 olarak ele alınması gerekir.
		* 12 o sütunda yoksa elemanların 12'den farkları alınır (mutlak değer içinde) ve (12+1).sütun için işlem tekrar edilir.
		* farkların minumumu tespit edilir ve o noktanın konumu (tempi=i ve tempj=j) hafızada tutulur.
		* hesap[tempi][tempj] konumu bizim cevabımız olur.
	*/
	for(int i=0;i<n;i++)
		for(int j=column-2;j<=column;j++){
		    if(fark>fabs(hesap[i][j]-b)){
				tempi=i;tempj=j;
			    fark=abs(hesap[i][j]-b);
			}		    
		}
	tempj2=tempj;//tempj'nin aşağıda değeriyle oynanacağı için tekrar hafızada tutuldu.
	printf("\n\n");
	/*
		* Hangi elemanların toplanması sonucu son değerin elde edildiğinin tespiti.
		* Hesap matrisi oluştururken A kümesinin elemanı > b olduğu durumda o sütuna kadar tüm değerler üst satırın aynısı olur.
		* Nedeni örn: {6} için; b=1,2,3,4,5 karşılamaz değeri 0 olur.Öncesinde bir eleman olsaydı üstteki değerler doğrudan alta aktarılırdı.
		* Fakat b=6 için karşılanır ve 1.satır b=6.sütun değeri 6 olur.
		* Sonraki satırlar hesaplanırken (A kümesinin elemanı < b), bir önceki satırın A kümesinin elemanı kadar geri gidip orda bulunan eleman A kümesinin elemanıyla toplanır..
		* bu toplam eğer bulunduğumuz konumun bir önceki satır değerinden büyükse yeni satır değerimiz olur.Küçük veya eşitse bir önceki satır değeri yeni satır değeri olur.
		* Aslında bizim seçtiğimiz A kümesinin elemanı, konumun değiştiği (toplanan) yani önceki satır değeri olmayan değerlerdir.
		* Bu kod blogunda bu değişimin olduğu yerler tespit edilip ekrana basılmıştır. 
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
