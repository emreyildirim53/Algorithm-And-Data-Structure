#include <stdio.h>
#include <conio.h>
struct liste{
 char veri;
 struct liste *sonraki;
};
struct liste *bas=NULL;
void goster(){
 if(bas==NULL) printf("\nListe Bos.. ");
 else{
   struct liste *dugum=bas;
   printf("\n");
   while(dugum!=NULL){
   printf("%d,",dugum->veri);
   dugum=dugum->sonraki;
   }
   printf("\n");
 }
}
void ekle(char gelen){
 struct liste *baslangic=NULL;
 if (bas==NULL){
      bas=(struct liste *) malloc(sizeof (struct liste));
      bas->veri=gelen;
      bas->sonraki=NULL;
 }else{
      struct liste *dugum=bas;
      while(dugum->sonraki!=NULL){
         if (baslangic==NULL)baslangic=dugum;
        dugum=dugum->sonraki; 
      }
      struct liste *yeni;
      yeni= malloc(sizeof (struct liste));
      yeni->veri=gelen;
      yeni->sonraki=NULL;
      dugum->sonraki=yeni;
 }
}
 void sil(int sayi)
 {
      struct liste *dugum=bas,*onceki=NULL;
      while(dugum!=NULL && dugum->veri!=sayi){
         onceki=dugum;
         dugum=dugum->sonraki;
      }
      if(dugum==bas)//silinecek ba�taysa
      {
        bas=bas->sonraki;
      }  
      else if (dugum->sonraki==NULL)//silinecek sondaysa
      {
           onceki->sonraki=NULL;
      }
      else if(dugum==NULL)//silinecek yoksa
      {
           printf("Bulamad�m..");
      }    
      else//silinecek ortadaysa
      {
          onceki->sonraki=dugum->sonraki;   
      }
 }
main(){ 
      int i=0,psayi,vsayi,sayac=0,onceki;     
      printf("Padisahin Buyrugu:");scanf("%d",&psayi);
      printf("Vezirin Soyledigi:");scanf("%d",&vsayi);
       for(i=1;i<=psayi;i++){
           ekle(i);   
       }
       onceki=vsayi;
       goster(); 
       while(bas->sonraki!=NULL){//sonda tek bir elemana kadar i�lemleri tekrarla
           struct liste *dugum=bas;
           while(dugum!=NULL){//sonu g�rene kadar ilerle
            sayac++;
            if (sayac==vsayi){//vsayi kadar ilerlemi�sen o veriyi sil ve sayac� s�f�rla
             sil(dugum->veri);
             sayac=0;
             printf("\n%d numara hakki rahmetine kavustu.\n",dugum->veri);
             goster();
             //sayac de�erini vsayi'dan ��karm��t�k basta vsayi-sayac kadar ilerledi(�rn:5 e 3 i�in basta 2 ilerledi)
             //sonras�nda tekrar vsayi kadar ilerlemesi i�in vsayi'yi koruduk
             if(vsayi!=onceki)vsayi=onceki;
            } 
            if (bas->sonraki==NULL)break;// 5 e 1 olarak girilince k�r�l�yordu ��nk� son kalan elemana sonraki atan�yordu.                    
            dugum=dugum->sonraki; 
          }      
          vsayi-=sayac;//listenin sonuna geldik ama vsayi kadar ilerleyemedim vsayi-sayac kadar bastan ilerle o zaman.
          sayac=0;        
       }         
getch();
}
