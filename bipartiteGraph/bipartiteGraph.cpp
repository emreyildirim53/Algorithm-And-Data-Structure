//bipartiteGraph
#include <conio.h>
#include <stdio.h>
//n node number
#define n 11
//buubleSort s�ralama algoritmas�
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
//aitlik matrisi a ile b birbirine graph �zerinde ba�l� ise a.sat�r b.sutunun kesi�ti�i nokta 1 olmal�d�r.
//Bu matris k��egen elemanlar�na g�re simetriktir. b.sat�r a.sutunda 1 olmal�d�r.
main(){         //0,1,2,3,4,5,6,7,8,9,10
				//A,B,C,D,E,F,G,I,�,K,L
	int rs[][n]={{0,0,0,0,0,1,1,1,1,1}, //A 0
				 {0,0,0,0,0,0,0,0,1,0}, //B 1
				 {0,0,0,0,0,0,1,0,0,0}, //C 2
				 {0,0,0,0,0,0,0,1,0,1}, //D 3
				 {0,0,0,0,0,0,0,0,0,0}, //E 4
				 {1,0,0,0,0,0,0,0,0,0}, //F 5
				 {1,0,1,0,0,0,0,0,0,0}, //G 6
				 {1,0,0,1,0,0,0,0,0,1}, //I 7
				 {1,1,0,0,0,0,0,0,0,0}, //� 8
				 {1,0,0,1,0,0,0,1,0,0}, //K 9
				};
	   int nodes[1][n],sumNode=0;
	   // Sat�r baz�nda toplama ve indis alma.	
	   for(int i=0;i<n;i++){			
		   for(int j=0;j<n;j++)
		   	   if(rs[i][j]==1)sumNode++;
		   nodes[1][i]=sumNode;
		   nodes[0][i]=i;
		   sumNode=0;
	   }
	   //Al�nan indislerin s�ralanamas�.
	   bubbleSort(nodes);
		//En b��y�k de�ere sahip indisten ba�layarak k�melere atama yap�l�yor.
		//1. k�meye atanan eleman�n kom�ular� (matriste ba�l� olduklar�) kar�� k�meye aktar�l�yor.	
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
				// k�me atamalar� s�ras�nda 2 k�medede ayn� eleman varsa faul durum oluyor.			        
		    	int say=0;
		    		for(int i=0;i<count;i++)
						for(int j=0;j<count;j++){
							 if(set1[i]==set1[j])say++;
							 if(set1[i]==set2[j])say++; //Ba�ka for i�inde yazmak daha garantili olacakt�r.
						}							   
					 if(say!=count){
					   printf("\nNot Bipartite Graph.");
					   goto son;
					}
					 say=0;
						for(int i=0;i<count2;i++)
						for(int j=0;j<count2;j++){
						 if(set2[i]==set2[j])say++;
						 if(set1[i]==set2[j])say++; //Ba�ka for i�inde yazmak daha garantili olacakt�r.
						}							   
					 if(say!=count2){
						 printf("\nNot Bipartite Graph.");
						 goto son; 
					 } 	
					 printf("\nBipartite Graph.");	
		          son:
getch();	  		
}
