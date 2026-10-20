#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

static int contador = 0;


struct Veiculo{
	int numeroTicket;
	string placa;
	string modelo;
	string dono;
	string tipo;
	string horarioEntrada;
	string horarioSaida;
	float valorPago = 0.0;
};

vector <Veiculo> VectorVeiculos;

int GeradorID() {
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
        contador++;
    }
	
	cout << "\n" << "Arquivo Importado" << "\n";
	
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
	system("clear");
	int inicio = 0;
	int fim = tamanho - 1;
	int resultado = 0;
	
	for(int i = 0; i < tamanho; tamanho++){
		int meio = (inicio + fim) / 2;
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
	
	char menuChar;
	
	struct Veiculo aux;
	
    system("clear");
	
	aux.numeroTicket = GeradorID();
	
	cout << "INSIRA OS DADOS ABAIXO: \n";
	cout << "---------------------------------------------------------\n";
	cout << "Placa: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, aux.placa);
	cout << "Modelo: ";
	getline(cin, aux.modelo);
	cout << "Proprietario: ";
	getline(cin, aux.dono);
	cout << "Tipo do Veiculo: ";
	getline(cin, aux.tipo);
	cout << "Horario de Entrada: ";
	getline(cin, aux.horarioEntrada);
	
	VectorVeiculos.push_back(aux);
	
	cout << "CADASTRAR MAIS VEICULOS? (S/N): ";
	cin >> menuChar;
	if(menuChar == 'S' or menuChar == 's')
		Cadastro();
}

void ListarVeiculos(){
	
	string espera;
	
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Pressione ENTER para continuar..." << endl;
	getline(cin,espera);
}

void PrintMenu(){
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
	
	int menuOpt = 1;
	
	while(menuOpt != 0){
		
		PrintMenu();
		
		cin >> menuOpt;
		
		switch(menuOpt){
			case 0:
				cout << "Sair" << endl;
				break;
			case 1:
				//Cadastrar Veículos
				Cadastro();
				break;
			case 2:
				//Listar Veículos Cadastrados
				ListarVeiculos();
				break;
			case 3:
				//Buscar Cadastro
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
				//Importar Arquivos
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Escreva o nome do arquivo a ser lido: ";
				getline(cin, FileName);
				ImportarArquivo(FileName);
				break;
			case 7:
				//Exportar Arquivos
				ExportarVeiculos();
				break;
			default:
				cout << "Opcao Invalida" << endl;
		}
	}
}
