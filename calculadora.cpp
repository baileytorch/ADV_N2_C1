#include <iostream>
using namespace std;

float suma(float num1,float num2){
    float resultado = 0;
    resultado = num1 + num2;
    return resultado;
}

float resta(float num1,float num2){
    float resultado = 0;
    resultado = num1 - num2;
    return resultado;
}

float multiplicacion(float num1,float num2){
    float resultado = 0;
    resultado = num1 * num2;
    return resultado;
}

string division(float num1,float num2){
    string resultado = "";
    float operacion = 0;
    if (num2 == 0)
    {
        resultado = "Operacion NO permitida";
    }else{
        operacion = num1/num2;
        resultado = to_string(operacion);
    }
    return resultado;
}

int main(void) {
    int resultado = 0;
    string numero1 = "";
    string numero2 = "";

    cout << "Ingrese Primer Numero: ";
    cin >> numero1;
    cout << "Ingrese Segundo Numero: ";
    cin >> numero2;

    float a = stof(numero1);
    float b = stof(numero2);

    cout << numero1 << "+" << numero2 << "=" << suma(a,b) << endl;
    cout << "5.5 - 6 = " << resta(a,b) << endl;
    cout << "5.5 x 6 = " << multiplicacion(a,b) << endl;
    cout << "5.5 / 5.5 = " << division(a,b) << endl;
}