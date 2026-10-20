#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

char menuChar;
int menuOpt = 1;

struct Veiculo{
	int numeroTicket;
	string placa;
	string modelo;

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
				cout << "Insira o ID do veiculo que esta procurando: ";
				cin >> SearchID;
				cout << BuscadorVeiculos(VectorVeiculos, VectorVeiculos.size(), SearchID);
				SearchID = 0;
				break;
			case 4:
				cout << "Editar Cadastro" << endl;
				break;
			case 5:
				cout << "Remover Cadastro" << endl;
				break;
			case 6:
				
				getline(cin, FileName);
				ImportarArquivo(FileName);
				break;
			case 7:
				ExportarVeiculos();
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}	string dono;
	string tipo;
	string horarioEntrada;
	string horarioSaida;
	float valorPago = 0.0;
};

vector <Veiculo> VectorVeiculos;

int GeradorID() {
    static int contador = 0;
    return ++contador;
}

void ImportarArquivo(string nome) {
    ifstream entrada(nome);

    if (!entrada.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    Veiculo veiculo;

    while (entrada >> veiculo.numeroTicket
                   >> veiculo.placa
                   >> veiculo.modelo
                   >> veiculo.dono
                   >> veiculo.tipo
                   >> veiculo.horarioEntrada
                   >> veiculo.horarioSaida
                   >> veiculo.valorPago) {

        VectorVeiculos.push_back(veiculo);
    }

    entrada.close();
}

void ExportarVeiculos(){
	system("clear");
	ofstream saida ("ListaDeVeiculos.txt");
	for(int i = 0; i < int(VectorVeiculos.size()); i++){
		saida << VectorVeiculos[i].numeroTicket << '\n';
		saida << VectorVeiculos[i].placa << '\n';
		saida << VectorVeiculos[i].modelo << '\n';
		saida << VectorVeiculos[i].dono << '\n';
		saida << VectorVeiculos[i].tipo << '\n';
		saida << VectorVeiculos[i].horarioEntrada << '\n';
		//saida << VectorVeiculos[i].horarioSaida << '\n';
		//saida << VectorVeiculos[i].valorPago << '\n';
	}
	cout << "Arquivo ListaDeVeiculos.txt criado!" << endl;

}


int BuscadorVeiculos(vector <Veiculo> vetor, int tamanho, int valor){
	int inicio = 0;
	int fim = tamanho - 1;
	int resultado = 0;
	
	for(int i = 0; i < tamanho; tamanho++){
		int meio 
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
				cout << "Insira o ID do veiculo que esta procurando: ";
				cin >> SearchID;
				cout << BuscadorVeiculos(VectorVeiculos, VectorVeiculos.size(), SearchID);
				SearchID = 0;
				break;
			case 4:
				cout << "Editar Cadastro" << endl;
				break;
			case 5:
				cout << "Remover Cadastro" << endl;
				break;
			case 6:
				
				getline(cin, FileName);
				ImportarArquivo(FileName);
				break;
			case 7:
				ExportarVeiculos();
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}= (inicio + fim) / 2;
		if(vetor[meio].numeroTicket == valor){
			resultado = meio;
			break;
		}
		else if(vetor[meio].numeroTicket < valor){
			inicio = meio + 1;
		}
		else{
			fim = meio - 1;
		}
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
				cout << "Insira o ID do veiculo que esta procurando: ";
				cin >> SearchID;
				cout << BuscadorVeiculos(VectorVeiculos, VectorVeiculos.size(), SearchID);
				SearchID = 0;
				break;
			case 4:
				cout << "Editar Cadastro" << endl;
				break;
			case 5:
				cout << "Remover Cadastro" << endl;
				break;
			case 6:
				getline(cin, FileName);
				ImportarArquivo(FileName);
				break;
			case 7:
				ExportarVeiculos();
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}
	cout << " MENU PRINCIPAL\n";
	cout << "---------------------------------------------------------\n";
	cout << " [1] Cadastrar veiculo\n";
	cout << " [2] Listar veiculos\n";
	cout << " [3] Buscar veiculo\n";
	cout << " [4] Editar cadastro\n";
	cout << " [5] Remover cadastro\n";
	cout << " [6] Importar arquivo\n";
	cout << " [7] Exportar arquivo\n";
	cout << " [0] Sair\n";
	cout << "=========================================================\n";
	cout << " Opcao: ";
}

int main(){
	string FileName;
	int SearchID;
	
	while(menuOpt != 0){
		
		PrintMenu();
		
		cin >> menuOpt;
		
		switch(menuOpt){
			case 0:
				//Sair do programa
				cout << "Sair" << endl;
				break;
			case 1:
				//Cadastro de veículo
				Cadastro();
				break;
			case 2:
				//Listagem de veículo			
				ListarVeiculos();
				break;
			case 3:
				//Busca de Veículos
				cout << "Insira o ID do veiculo que esta procurando: ";
				cin >> SearchID;
				cout << BuscadorVeiculos(VectorVeiculos, VectorVeiculos.size(), SearchID);
				SearchID = 0;
				break;
			case 4:
				//Editar Cadastro
				cout << "Editar Cadastro" << endl;
				break;
			case 5:
				//Remover Cadastro
				cout << "Remover Cadastro" << endl;
				break;
			case 6:
				//Importar Arquivo
				getline(cin, FileName);
				ImportarArquivo(FileName);
				break;
			case 7:
				//Exportar Arquivo
				ExportarVeiculos();
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}
