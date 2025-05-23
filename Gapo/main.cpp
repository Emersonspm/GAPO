#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contato {
    string nome;
    string telefone;
};

vector<Contato> agenda;

void inserirContato() {
    Contato c;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, c.nome);
    cout << "Telefone: ";
    getline(cin, c.telefone);
    agenda.push_back(c);
    cout << "Contato adicionado com sucesso.\n";
}

void buscarContato() {
    string nomeBusca;
    cout << "Digite o nome a buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    bool encontrado = false;
    for (const auto& c : agenda) {
        if (c.nome == nomeBusca) {
            cout << "Encontrado: " << c.nome << " - " << c.telefone << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Contato não encontrado.\n";
    }
}

void deletarContato() {
    string nomeDeletar;
    cout << "Digite o nome do contato a deletar: ";
    cin.ignore();
    getline(cin, nomeDeletar);

    auto it = remove_if(agenda.begin(), agenda.end(),
                        [&](const Contato& c) { return c.nome == nomeDeletar; });

    if (it != agenda.end()) {
        agenda.erase(it, agenda.end());
        cout << "Contato deletado com sucesso.\n";
    } else {
        cout << "Contato não encontrado.\n";
    }
}

void listarContatos() {
    if (agenda.empty()) {
        cout << "Agenda vazia.\n";
        return;
    }

    cout << "Contatos:\n";
    for (const auto& c : agenda) {
        cout << "- " << c.nome << " : " << c.telefone << "\n";
    }
}

int main() {
    int opcao;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Inserir contato\n";
        cout << "2. Buscar contato\n";
        cout << "3. Deletar contato\n";
        cout << "4. Listar contatos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: inserirContato(); break;
            case 2: buscarContato(); break;
            case 3: deletarContato(); break;
            case 4: listarContatos(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
