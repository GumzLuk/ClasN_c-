	
#include <iostream>
#include "classNumero.h"
 using namespace std;

 int main(){

  Numero nx = Numero(0);
	bool k = true;

   nx.LineasComando();
	 cout<<"OPERACIONES : "<<endl<<" 0 : Salir"<<endl<<" 1 : setValor "<<endl<<" 2 : getValor "<<endl<<" 3 : getCantDig"<<endl<<" 4 : addDigDerecha "<<endl<<
	 " 5 : addDigIzquierda"<<endl<<" 6 : es primo "<<endl<<" 7 : Invertir valor"<<endl<<" 8 : intercambiarPos"<<endl<<" 9 : Obtener posicion"<<endl
	 <<" 10 : Modificar digito"<<endl<<" 11 : insertar digito"<<endl<<" 12 : getPosDDig"<<endl<<" 13 : Numero Ord Ingresa param y ordenar"<<endl<<" 14 : Insertar dig. Derecha"<<endl; 
	 int n,dig,posA,posB;	 
   nx.LineasComando(); 	  
  
     while(k){
			cout<<"Respuesta : ";
			cin>>n;			
        
			 switch(n){
				 case 0 :
				    k = false;
						 break;
				case 1 :
          int unsigned x;				
					cout<<" Ingrese el valor : ";
					cin>>x;
				  nx.setValor(x);	
					 break;	 

				case 2 : 
				  cout<<"El valor actual es : "<< nx.getValor();	
					break;

				case 3 : 
				  cout<<"getCantDig es : "<<(int)nx.getCantDig();	
					 break;

				case 4: 				   
					 cout<<"Ingrese el digito : ";
					 cin>>dig;
					 nx.addDigDerecha((byte)dig);
   					 break;

				case 5 :				  
					cout<<"Ingrese un digito : ";
					cin>>dig;
					 nx.addDigIzquierda((byte)dig);
				  break;		 

				case 6 :
				 if(nx.esPrimo()){
					  cout<<"Primo";
				 }else{
					cout<<"No primo";
				 }  
				  break;					

				 case 7 :
				    nx.InvertirValor();
				   break; 

				 case 8:
					 cout<<"PosA :__";				
					 cin>>posA;
					 cout<<"posB :__";
			 		 cin>>posB;
					 nx.IntercambiarPos((byte)posA,(byte)posB);
				   break;	

				 case 9:
				   cout<<"Ingrese la posicion :__";
					 cin>>posA; 
					cout<<"El digito : "<<(int)nx.getPosicion((byte)posA);
					break;

         case 10 :
				   cout<<"Posicion :__" ;
					 cin>>posA;
					 cout<<"Digito :__";
					 cin>>dig; 
					 nx.modDigit((byte)posA,(byte)dig);
					break; 

				 case 11:
				  cout<<"Posicion :__" ;
					 cin>>posA;
					 cout<<"Digito :__";
					 cin>>dig; 
				 	  nx.insertDigXPos((byte)dig,(byte)posA);
				 break;

         case 12 :
				    cout<<"Ingrese el digito :___";
						cin>>dig;
						cout<<"Esta en la posicion : "<<(int)nx.getPosDDig((byte)dig);
					break;

         case 13:
				  cout<<"Ingrese un Numero__: ";
					cin>>n;
					nx.OrdParametroXYaOrd(n);
					 break;
           
				 case 14:
           cout<<"Ingrese el digito____: ";
					 cin>>dig;
					 cout<<"Ingrese la posicion____: ";
					 cin>>posA;
					  nx.insertDigDerecha((byte)dig , (byte)posA);   				 
				     break;	 	
				default :
				  cout<<"Error operacion no existe.....";		 
			 }
			cout<<endl;
			nx.LineasComando();  
		 }

      cout<<endl;

			return 0;
		 }
     

