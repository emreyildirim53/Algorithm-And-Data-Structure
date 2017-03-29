//bipartiteGraph
#include <conio.h>
#include <stdio.h>
//n node number
#define n 11
//buubleSort sýralama algoritmasý
void bubbleSort(int a[][n]){
	 int i, j, temp,temp2;
	 for (i = 0; i < (n- 1); ++i)
	      for (j = 0; j < n - 1 - i; ++j )	      
	           if (a[1][j] < a[1][j+1])
	           {
	                temp = a[0][j+1];
	                temp2= a[1][j+1];
	                a[0][j+1] = a[0][j];
	                a[1][j+1] = a[1][j];
	                a[0][j] = temp;
	                a[1][j] = temp2;
	           }	 
}  
int isThere( int a[],int b){
	bool kntrl=false;
    for(int i=0;i<n;i++)
	if(a[i]==b) {kntrl=true;return 1;}
	if(kntrl==false)return 0;
}
//aitlik matrisi a ile b birbirine graph üzerinde baðlý ise a.satýr b.sutunun kesiþtiði nokta 1 olmalýdýr.
//Bu matris köþegen elemanlarýna göre simetriktir. b.satýr a.sutunda 1 olmalýdýr.
main(){         //0,1,2,3,4,5,6,7,8,9,10
				//A,B,C,D,E,F,G,I,Ý,K,L
	int rs[][n]={{0,0,0,0,0,1,1,1,1,1}, //A 0
				 {0,0,0,0,0,0,0,0,1,0}, //B 1
				 {0,0,0,0,0,0,1,0,0,0}, //C 2
				 {0,0,0,0,0,0,0,1,0,1}, //D 3
				 {0,0,0,0,0,0,0,0,0,0}, //E 4
				 {1,0,0,0,0,0,0,0,0,0}, //F 5
				 {1,0,1,0,0,0,0,0,0,0}, //G 6
				 {1,0,0,1,0,0,0,0,0,1}, //I 7
				 {1,1,0,0,0,0,0,0,0,0}, //Ý 8
				 {1,0,0,1,0,0,0,1,0,0}, //K 9
				};
	   int nodes[1][n],sumNode=0;
	   // Satýr bazýnda toplama ve indis alma.	
	   for(int i=0;i<n;i++){			
		   for(int j=0;j<n;j++)
		   	   if(rs[i][j]==1)sumNode++;
		   nodes[1][i]=sumNode;
		   nodes[0][i]=i;
		   sumNode=0;
	   }
	   //Alýnan indislerin sýralanamasý.
	   bubbleSort(nodes);
		//En büüyük deðere sahip indisten baþlayarak kümelere atama yapýlýyor.
		//1. kümeye atanan elemanýn komþularý (matriste baðlý olduklarý) karþý kümeye aktarýlýyor.	
		int count=0,count2=0;
	 	int set1[n],set2[n];
	    for(int i=0;i<n;i++)set1[i]=-1;
	    for(int i=0;i<n;i++)set2[i]=-1;
		 for(int i=0;i<n;i++)
			  if(isThere(set1,nodes[0][i])==0 && isThere(set2,nodes[0][i])==0){		  
			  	set1[i]=nodes[0][i];
			  	count++;
			  	for(int j=0;j<n;j++)
			  		if (rs[nodes[0][i]][j]==1 && isThere(set2,j)==0){
					  set2[count2]=j;
					  count2++;
					}						 	
			 }else if(isThere(set1,nodes[0][i])==0 && isThere(set2,nodes[0][i])==1){			   	
			 	for(int j=0;j<n;j++){	
				  	if (rs[nodes[0][i]][j]==1 && isThere(set1,j)==0){	  						
					  set1[count]=j;
					  count++;
					}
				}
			}else if(isThere(set1,nodes[0][i])==1 && isThere(set2,nodes[0][i])==0){			   	
			 	for(int j=0;j<n;j++){		  	
				  	if (rs[nodes[0][i]][j]==1 && isThere(set2,j)==0){	  						
					  set2[count2]=j;
					  count2++;
					}
				}			
			}				
				////** Screen **\\\\
					
				printf("1.Set\n");		
				for(int i=0;i<count-1;i++)	
					printf("\t%d\n",set1[i]);
				printf("2.Set\n");		
				for(int i=0;i<count2;i++)	
					printf("\t%d\n",set2[i]);
				// küme atamalarý sýrasýnda 2 kümedede ayný eleman varsa faul durum oluyor.			        
		    	int say=0;
		    		for(int i=0;i<count;i++)
						for(int j=0;j<count;j++){
							 if(set1[i]==set1[j])say++;
							 if(set1[i]==set2[j])say++; //Baþka for içinde yazmak daha garantili olacaktýr.
						}							   
					 if(say!=count){
					   printf("\nNot Bipartite Graph.");
					   goto son;
					}
					 say=0;
						for(int i=0;i<count2;i++)
						for(int j=0;j<count2;j++){
						 if(set2[i]==set2[j])say++;
						 if(set1[i]==set2[j])say++; //Baþka for içinde yazmak daha garantili olacaktýr.
						}							   
					 if(say!=count2){
						 printf("\nNot Bipartite Graph.");
						 goto son; 
					 } 	
					 printf("\nBipartite Graph.");	
		          son:
getch();	  		
}
