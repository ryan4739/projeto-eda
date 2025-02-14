#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

    public:
        LinkedList() : head(NULL) {}

        void insereNoInicio(int valor) {
            Node* novoNode = new Node();
            novoNode->data = valor;
            novoNode->next = head;
            head = newNode;
        }

        void insereNoIndice(int valor, int indice) {
            if (posicao < 1) {
                cout << "Índice inválido!" << endl;
                return;
            }
        }

        void insereNoFim(int valor) {
            Node* novoNode = new Node();
            novoNode->data = valor;
            novoNode->next = NULL;

            if (!head) {
                head = novoNode;
                return;
            }

            Node* nodeAtual = head;
            while (nodeAtual->next) {
                temp = temp->next;
            }

            temp->next = novoNode;
        }

        void deletaPrimeiroNode() {
            if (!head) { return; }

            Node* nodeAtual = head;
            head = head->next;
            delete nodeAtual;
        }

        void deletaPorIndice(int indice) {
            if (indice == 0) {
                deletaPrimeiroNode();
                return;
            }

            Node* nodeAtual = head;
            int posicao = 0;
            while (posicao < indice - 1 && temp) {
                temp = temp->next;
                ++posicao;
            }
            
            if (!nodeAtual || !nodeAtual->next) {
                cout << "Índice inválido!" << endl;
                return;
            }

            Node* nodeParaApagar = nodeAtual->next;
            nodeAtual->next = temp->next->next;
            delete nodeParaApagar;
        }

        void deletaUltimoNode() {
            if (!head) { return; }

            if (!head->next) {
                deletaPrimeiroNode();
                return;
            }

            Node* nodeAtual = head;
            while (nodeAtual->next->next) {
                nodeAtual = nodeAtual->next;
            }

            delete nodeAtual->next;
            nodeAtual->next = NULL;

        }

        
};