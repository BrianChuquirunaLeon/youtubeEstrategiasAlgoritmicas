#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int cont=0;

void mostrarPila(stack <char> s) { 
	stack<char> aux;
	while (!s.empty()){ 
		cout << '\t' << s.top();
		aux.push(s.top());
		s.pop(); 
	}
	while (!aux.empty()){ 
		s.push(aux.top());
		aux.pop(); 
	}
	cout << '\n'; 
}	

void back(int i,int n,stack<char> pila,queue<char> cola){
	//verificamos si ya hay tres personas sentadas
	if(i==n){
		cont++;
		cout<<cont<<". ";
		mostrarPila(pila);
		//imprimir();
	}
	else{
		//con cada for nos movemos hacia los costados
		for(int j=i;j<n;j++){
			
			//Verificamos que se cumpla las restriciones
			if(!((i==1 and cola.front()=='a') or
			   (i==0 and cola.front()=='r'))){
				
				//metemos un objeto a la pila 
				pila.push(cola.front());
				cola.pop();
				
				//con cada llamada recursiva nos movemos hacia
				//abajo del arbol osea en profundidad
				back(i+1,n,pila,cola);
				//sacamos un objeto de la pila
				cola.push(pila.top());
				pila.pop();
			}else{
				cola.push(cola.front());
				cola.pop();
			}
			
		}
	}
}
	
	int main (int argc, char *argv[]) {
		
		queue<char> cola;
		stack<char> pila;
		cola.push('a');
		cola.push('b');
		cola.push('r');
		cola.push('v');
		//cola.push('m');
		int i=0;
		
		back(i,cola.size(),pila,cola);
		
	}

