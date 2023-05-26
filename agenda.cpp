#include <iostream>
#include <string>

using namespace std;

string nomes[20];
int tam = 0;
int opcao;

void adiciona(string* nomes, int& tam) {
    if (tam >= 5) {
        cout << "Não cabe mais." << endl;
        return;
    }

    string nome;
    cout << "Digite o nome que deseja adicionar: ";
    cin >> nome;
    nomes[tam] = nome;
    tam++;
    cout << "Nome adicionado com sucesso!" << endl;
}

void remover(string* nomes, int& tam) {
    if (tam == 0) {
        cout << "Lista de nomes vazia." << endl;
        return;
    }

    string nome;
    cout << "Digite o nome que deseja remover: ";
    cin >> nome;

    int posicao = -1;
    for (int i = 0; i < tam; i++) {
        if (nomes[i] == nome) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        for (int i = posicao; i < tam - 1; i++) {
            nomes[i] = nomes[i + 1];
        }
        tam--;
        cout << "Nome removido com sucesso!" << endl;
    } else {
        cout << "Nome não encontrado na lista." << endl;
    }
}

void lista(const string* nomes, int tam) {
    if (tam == 0) {
        cout << "Vazio." << endl;
        return;
    }

    cout << "Lista de nomes:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << nomes[i] << endl;
    }
}
void menu(){
    do {
        cout<<"\n\n 1-Adicionar um nome \n 2-Remover um nome \n 3-Listar nomes \n 4-Sair do programa\n"<<endl;
        cout<<"Escolha uma opção: ";
        cin>>opcao;

        switch (opcao) {
            case 1:
                adiciona(nomes, tam);
                break;
            case 2:
                remover(nomes, tam);
                break;
            case 3:
                lista(nomes, tam);
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    } while (opcao != 4);
}

int main() {
    
    menu();

    return 0;
}
