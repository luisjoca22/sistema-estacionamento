#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;

char menuChar;
int menuOpt = 1;

struct Veiculo{
	string numeroTicket;
	string placa;
	string modelo;
	string dono;
	string tipo;
	string horarioEntrada;
	string horarioSaida;
	float valorPago = 0.0;
};

vector <Veiculo> VectorVeiculos;

string GeradorID(){
	const string algarismos = "0123456789abcdefghijklmnopqrstuvwxyz";
	string resultado = "";
	
	random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<size_t> distrib(0, algarismos.size() - 1);
	
	for (int i = 0; i < 6; ++i) {
        resultado += algarismos[distrib(gen)];
    }
	
	return resultado;
}


void Cadastro(){
	
	struct Veiculo aux;
	
    system("clear");
	
	aux.numeroTicket = GeradorID();
	
	cout << "INSIRA OS DADOS ABAIXO: \n";
	cout << "---------------------------------------------------------\n";
	cout << "Placa: ";
	cin >> aux.placa;
	cout << "Modelo: ";
	cin >> aux.modelo;
	cout << "Proprietario: ";
	cin >> aux.dono;
	cout << "Tipo do Veiculo: ";
	cin >> aux.tipo;
	cout << "Horario de Entrada: ";
	cin >> aux.horarioEntrada;
	
	VectorVeiculos.push_back(aux);
	
	cout << "CADASTRAR MAIS VEICULOS? (S/N): ";
	cin >> menuChar;
	if(menuChar == 'S' or menuChar == 's')
		Cadastro();
}

void ListarVeiculos(){
	system("clear");
	for(int i = 0; i < int(VectorVeiculos.size()); i++){
		cout << "=============================================\n";
		cout << "              DADOS DO VEÍCULO               \n";
		cout << "=============================================\n";
		cout << left;
		cout << setw(20) << "ID do Ticket"       << VectorVeiculos[i].numeroTicket << '\n';
		cout << setw(20) << "Placa:"             << VectorVeiculos[i].placa << '\n';
		cout << setw(20) << "Modelo:"            << VectorVeiculos[i].modelo << '\n';
		cout << setw(20) << "Dono:"              << VectorVeiculos[i].dono << '\n';
		cout << setw(20) << "Tipo:"              << VectorVeiculos[i].tipo << '\n';
		cout << setw(20) << "Entrada:"           << VectorVeiculos[i].horarioEntrada << '\n';
		cout << setw(20) << "Saída: "             << VectorVeiculos[i].horarioSaida << '\n';
		cout << setw(20) << "Valor Pago:"        << "R$ "
			 << fixed << setprecision(2) << VectorVeiculos[i].valorPago << '\n';
		cout << "=============================================\n\n";
	
	} 

}

void PrintMenu(){
	cout << " MENU PRINCIPAL\n";
	cout << "---------------------------------------------------------\n";
	cout << " [1] Cadastrar veiculo\n";
	cout << " [2] Listar veiculos\n";
	cout << " [3] Buscar veiculo\n";
	cout << " [4] Editar cadastro\n";
	cout << " [5] Remover cadastro\n";
	cout << " [0] Sair\n";
	cout << "=========================================================\n";
	cout << " Opcao: ";
}

int main(){
	
	
	while(menuOpt != 0){
		
		PrintMenu();
		
		cin >> menuOpt;
		
		switch(menuOpt){
			case 0:
				cout << "Sair" << endl;
				break;
			case 1:
				Cadastro();
				break;
			case 2:
				ListarVeiculos();
				break;
			case 3:
				cout << "Buscar veículos" << endl;
				break;
			case 4:
				cout << "Editar Cadastro" << endl;
				break;
			case 5:
				cout << "Remover Cadastro" << endl;
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}
