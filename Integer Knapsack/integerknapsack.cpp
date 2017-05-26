#include <stdio.h>
#include <conio.h>
int main(){
	int esyasayisi=4;
    int kapasite=15;
	int Canta[esyasayisi+1][kapasite+1];
	int Agirlik[esyasayisi+1]={0,3,6,2,4};
	int Hacim[esyasayisi+1]={0,7,8,3};
	int Deger[esyasayisi+1]={0,14,30,9,19};
	for(int i=0;i<=esyasayisi;i++){
		Canta[i][0]=0;
			for(int j=0;j<=kapasite;j++){
			 	if(i==0)Canta[0][j]=0; 
			 	else{
			 	 if(Agirlik[i]>j) Canta[i][j]=Canta[i-1][j];
			 	 else 
			 	 	if(Canta[i][j-Agirlik[i]]+Deger[i]>Canta[i-1][j])
			 	 		Canta[i][j]=Canta[i][j-Agirlik[i]]+Deger[i];
			 	 	else 
						Canta[i][j]=Canta[i-1][j];		 		
				}
			}		
	}
	//---------Matris Gösterimi--------
	for(int i=0;i<=esyasayisi;i++){
		printf("\n");
		for(int j=0;j<=kapasite;j++){
			printf("%3d",Canta[i][j]);
		}
	}
	int say=0;
    //backtracing
	printf("\n\nAdet, Esya , Agirlik , Deger");
	for(int i=esyasayisi;i>0;i--){
		for(int j=kapasite;j>0;j--){
			if(Canta[i][j]!=Canta[i-1][j]){				
				j-=Agirlik[i]-1;
				kapasite-=Agirlik[i]-1;	
				say++;	
			}else{if(say!=0)printf("\n%d x %5d%8d%9d",say,i,Agirlik[i],Deger[i]);say=0;break;}
										
		}
	}	
	return 1;
}
