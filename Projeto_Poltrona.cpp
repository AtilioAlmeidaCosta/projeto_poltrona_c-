/**
 * Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupação que ofereça as seguintes opções, através de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupação
3.	Faturamento
A opção 1 deverá solicitar a informação da fileira e da poltrona. Os dados devem ser consistidos no sentido da garantia de serem válidos. Caso o lugar esteja vago, efetuar a reserva e informar o usuário do sucesso da operação. Caso o lugar já se encontre ocupado, alertar o usuário com uma mensagem.

A opção 2 deverá gerar na tela um “mapa” de ocupação do teatro com uma legenda onde:

‘.’ representa lugar vago
‘#’ representa lugar ocupado
A opção 3 deverá apresentar na tela as seguintes informações:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

•	Fileiras 1 a 5:		R$ 50,00
•	Fileiras 6 a 10:	R$ 30,00
•	Fileiras 11 a 15:	R$ 15,00

 
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define LIN 15	
#define COL 40

void mostra_matriz(int **p)
{	
	for(int i=0; i<LIN; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			if(p[i][j]==false){
				cout << setw(2) << "*" << " |"; 
			}else{
			cout << setw(2) << "#" << " |"; 
			}
		}
		cout << endl;
	}
}
void mostra_faturamento(int **p)
{	
	double valor_poltrona=0;
	double faturamento=0;
	for(int i=0; i<LIN; ++i)
	{
		if(i<5){valor_poltrona=50;}
		if(i>=5&&i<10){valor_poltrona=30;}
		if(i>=10&&i<15){valor_poltrona=15;}

		for(int j=0; j<COL; ++j)
		{
			if(p[i][j]==true){
				faturamento += valor_poltrona;
			}
		}
		cout << endl;
	}
		cout <<"Seu faturamento foi de: "<< faturamento <<endl;
}

void mostra_poltrona(int **p, int linha, int coluna)
{
		if(p[linha][coluna]==false){
				cout << setw(2) << "Poltrona vaga"; 
				p[linha][coluna]=true;
				cout<<"Poltrona reservda com sucesso";
			}else{
			cout << setw(2) << "Poltrona ocupada"; 
			cout<<"A poltrona não pode ser reservada";
			}
		cout << endl;
}

void  caso1(int **p){
	int linha, coluna;
	bool poltronaCerta;	
	cout<<"Digite a fileira da poltrona desejada (de 0 a 14)"<< endl;
	cin >> linha;
	cout<<"Digite a poltrona desejada (de 0 a 39)"<< endl;
	cin >> coluna;
	cout<<"A poltrona desejada se encontra em ("<< linha<< " " << coluna<<") ? s = 1/n = 0"<< endl;
	cin>> poltronaCerta;
	if(poltronaCerta==true){
		mostra_poltrona(p,linha,coluna);
	}
	
}
int main(int argc, char** argv)
{
	int i,j,seletor;
	bool k;
	bool interesse;
	int **mat;
	
	mat = new int*[LIN];
	
	for(i=0; i<LIN; ++i)
	{
		mat[i] = new int[COL];
	}
	k=false;
	for(i=0; i<LIN; ++i)
	{
		for(j=0; j<COL; ++j)
		{
			mat[i][j] = k; 
		}
	}
	while(seletor != 0)
	{
		cout<<"Bem vindo" << endl;
		cout<<"Digite seu interesse:" << endl;
		cout<<"0.	Finalizar" << endl <<"1.	Reservar poltrona" << endl <<"2.	Mapa de ocupação" << endl <<"3.	Faturamento"<< endl;
		cin >> seletor;
		cout<<"Se interesse foi: "<<seletor<< endl;
		
		switch(seletor)
		{
		case 0: seletor = 0;
		break;
		case 1: caso1(mat);
		break;
		case 2: mostra_matriz(mat);
		break;
		case 3: mostra_faturamento(mat);
		break;
		default:
		break;
		}
	}
    
	cout << endl; 
	delete[] mat;
	return 0;
}