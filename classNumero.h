#include <iostream>
#include <math.h>

using namespace std;

 class Numero{
   //Atributos
     private:
       int unsigned valor;

   //Metodos
	  public :
      //Constructor
        Numero(int unsigned v);

       //SETTERS
  			 void LineasComando();
	       void setValor(int unsigned n);
	       void addDigDerecha( byte dig);
         void addDigIzquierda( byte dig);
         void elimDigit(byte pos);
	       void modDigit(byte pos , byte dig);
				 void insertDigXPos(byte dig,byte pos);
				 void insertDigDerecha(byte dig,byte pos);
				 void InvertirValor();
				 void IntercambiarPos(byte posA, byte posB);
				 void OrdParametroXYaOrd(int unsigned nu);

	  //GETTERS
          int unsigned getValor();
	        byte getPosicion(byte pos);
					byte getPosN(int unsigned nu , byte pos);
	        byte getCantDig();
					byte getCantDig(int unsigned n);
					bool esPrimo();
					bool esDigPrimo(byte digit);
					bool esDigit(byte digit);
					int unsigned PoT10(byte k);
					byte getPosDDig(byte pos);
					byte frecMayDig();
					byte frecDDig(byte dig);					
					
 };	

//CONSTRUCTOR
   Numero::Numero(int unsigned v){
        	 this->valor = v;
    }

 //SETTERS____________________________________________________________________________________________________

  void Numero::LineasComando(){

		std::cout<<"_______________________________"<<std::endl;
	}


   void Numero::setValor(int unsigned n){
       this->valor = n;
   }

  void Numero::addDigDerecha( byte dig){
      this->valor = getValor()* 10 + (int unsigned)dig;
  }

   void Numero::addDigIzquierda(byte dig){

      this->valor = (int unsigned)dig * PoT10(this->getCantDig()) + this->valor;
  }

  void Numero::elimDigit(byte pos){

		int unsigned nr = this->valor / PoT10(pos);
    this->valor = (int unsigned)nr * PoT10((byte)((int)pos-1)) + this->valor % PoT10((byte)((int)pos-1));
   }

  void Numero::modDigit(byte pos , byte dig){

      int  nr = (this->valor / PoT10(pos)) * 10 + (int unsigned)dig;
			this->valor = nr * PoT10((byte)((int)pos - 1)) + this->valor % PoT10((byte)((int)pos-1));
   }

	 void Numero::insertDigXPos(byte dig , byte pos){
		  int unsigned nr = (this->valor / PoT10(pos)) * 10 + (int unsigned)dig;					
      this->valor = nr * PoT10(pos) + (this->valor % PoT10(pos));
	 }

   void Numero::insertDigDerecha(byte dig , byte pos){
     int unsigned nr = (this->valor / PoT10((byte)((int)pos-1))) * 10 + (int)dig;  
		 this->valor = nr * PoT10((byte)((int)pos-1)) + this->valor % PoT10((byte)((int)pos-1));
	 }

	 void Numero::InvertirValor(){
     short nrov = (short)getCantDig() / (short)2;
		 short i = 1;
		 short f = (short)getCantDig();
		   while(i<=nrov){
		      IntercambiarPos((byte)i,(byte)f);
					i++;
					f--;
			 }
 	 }

   void Numero::IntercambiarPos(byte posA, byte posB){
		if(((int)posA > 0 && (int)posB > 0) && ((int)posA <= (int)getCantDig() && (int)posB <= (int)getCantDig())){
		   byte recop = getPosicion(posB);
   	   modDigit(posB,getPosicion(posA));
 	  	 modDigit(posA,recop)	;
		}else{
			cout<<"\n________Error posiciones invalidas________"<<endl;
			
		}
	 }

  void Numero::OrdParametroXYaOrd(int unsigned nu){
     byte i = (byte)1;
		 byte j;
		 bool k;
		  while(i <= this->getCantDig(nu)){
				 j = (byte)1;
				 k = true;
				   while(j <= this->getCantDig() && k){
								if(this->getPosN(nu,i) <= this->getPosicion(j) && k) {
                  this->insertDigDerecha(this->getPosN(nu,i),j);   									
									k = false;									
								}
							 j = (byte)((int)j + 1);	
							}							
							if(k){
								this->addDigIzquierda(this->getPosN(nu,i));
					 }
					i = (byte)((int)i + (int)1); 
			}
	}
 //GETTERS____________________________________________________________________________________________________

  int unsigned Numero::getValor(){

    	return valor;
  }

  bool Numero::esDigit(byte Digit){

    if((int)getCantDig((int unsigned)Digit) == 1){
      return true;
		}else{
			return false;
		}

  } 

  byte Numero::getPosicion(byte pos){

     return (byte)(this->valor / PoT10((byte)((int)pos-1))  % 10);
  }

	byte Numero::getPosN(int unsigned nu , byte pos){
		 int unsigned k = PoT10((byte)((int)pos-1));
		 int unsigned nx = nu / k;
		 return (byte)(nx % 10);
	}
    
	byte	Numero::getCantDig(){
    int n = (unsigned int )(log10(this->valor)+1);
       return (byte)n;
  }

	byte Numero::getCantDig(int unsigned n){

		return (byte)(log10(n)+1);
	}

	bool Numero::esPrimo(){

		short cont = 0;
		short n = 1;
  		 for (short i = 1; i <= getValor(); i++)
	  	 {
	       if(getValor() % i ==0 ){
					 cont++;
				 }
		   }
		 if(cont == 2){
		    	return true;
		 }else{
			   return false;
		 }
	}
 bool Numero::esDigPrimo(byte digit){
    byte c = (byte)0;
    byte i = (byte)2;
		bool k = false;
		 while(i < digit){
        if (((int) digit % (int)i) == 0) c = (byte)((int)c + (int)1);         			 
			i = (byte)((int)i + (int)1); 
		 }
		   if((int)c == 0) k = true;
		return k;
	}

	int unsigned Numero::PoT10(byte k){

    int unsigned pow = 1;
		 for(int i=1;i<=(int)k;i++){
			 pow = pow * 10;
		 }
		return pow;
	}

	byte Numero::getPosDDig(byte dig){
		int i = 1;
		bool k = false;
    byte posDig = (byte)0;
		 while((i <= (int)this->getCantDig()) && !(k)){
         if(this->getPosicion((byte)i) == dig){
						k = true;
						posDig = (byte)i;
				 }
		  	i++;
		 }		 
   return posDig;
	}
  
	byte Numero::frecMayDig(){
	  byte frecM = this->frecDDig(this->getPosicion((byte)1));
		byte digM = this->getPosicion((byte)1);
		byte i = (byte)1;
		short k ; 
      while(i <= this->getCantDig()){
          if((int)this->frecDDig(this->getPosicion(i)) > (int)frecM ){
               frecM = this->frecDDig(this->getPosicion(i));
							 digM = this->getPosicion(i);	
					}
			  i = (byte)((int)i + 1);		
			}			
		return digM;	
	}

  byte Numero::frecDDig(byte dig){
	  byte i = (byte)1;
		byte frec = (byte)0;	  
		  while(i <= this->getCantDig()){
          if((int)this->getPosDDig(i) == (int)dig) frec = (byte)((int)frec + (int)1);
			 i = (byte)((int)i + (int)1);	 
		  }
		return frec;			
	}
	