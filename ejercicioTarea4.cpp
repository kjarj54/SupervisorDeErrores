#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

bool esApertura(char c) {//Revisa los caracteres de inicio
  	return c == '(' || c == '{' || c == '[';
}


bool esCierre(char c) {//Revisa los caracteres de final
  	return c == ')' || c == '}' || c == ']';
}


bool sonPareja(char a, char b) {//Comprueba que los pares sean pareja
  	return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}



int main(int argc, char* argv[]){
	
	stack<char> pila;//Crea una pila
	int linea = 1;//Lineas del posible error
	char c;//Caracter que lee
	
  	if (argc != 2) {//revisa que se introdujera un archivo
    	cout << "Uso: " << argv[0] << " <nombre del archivo .c>" << endl;
    	return 1;
  	}
  	
  	ifstream archivo(argv[1]);//Abre el archivo que solo para leer
  	
  	if (!archivo.is_open()) {//Comprueba que si se abrio el archivo
		cout << "No se pudo abrir el archivo " << argv[1] << endl;
    	return 2;
	}
	
	 
  	while (archivo.get(c)) {
    	if (c == '\n') {
      		linea++;//Aumenta el numero por cada salto de linea     	
    	}else if (esApertura(c)) {//Condicion si es de apertura el caracte
      		pila.push(c);
    	}else if (esCierre(c)) {//Condicion si es de cierre el caracte
      		if (pila.empty()) {
        		cout << "Error de sintaxis en la línea " << linea << ": " << c << " sin pareja" << endl;	
      		}else{	
        		char a = pila.top();
        		pila.pop();
        		if (!sonPareja(a, c)) {
          			cout << "Error de sintaxis en la línea " << linea << ": " << a << " y " << c << " no son pareja" << endl;
        		}		
      		}
    	}
  	}
	
	while (!pila.empty()) {
    	char a = pila.top();
    	pila.pop();
    	cout << "Error de sintaxis en la línea " << linea << ": " << a << " sin pareja" << endl;
  	}
	
	archivo.close();//Cierra el archivo

    return 0;
}
