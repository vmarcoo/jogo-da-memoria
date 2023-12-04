#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << " _______________________________"  << endl;
    cout << "|                               |" << endl;
    cout << "| BEM-VINDO AO JOGO DA MEMÓRIA! |" << endl;
    cout << "|_______________________________|" << endl;
    cout << "\n";
    cout << "           REGRAS:";
    cout << "\n";
    cout << "\n";
    cout << "   O jogo é composto por 8 pares de" << endl;
    cout << "cartas enumeradas de 1 a 8, onde" << endl;
    cout << "o jogador deve escolher duas cartas" << endl;
    cout << "por jogada, podendo executar no" << endl;
    cout << "máximo 24 jogadas. Vence aquele que" << endl;
    cout << "localizar todos os pares." << endl;
    cout << "\n";
    cout << "Pressione ENTER para continuar.";
    getchar();
    cout << "\n";
    cout << "   O jogo será uma matriz 4x4, cujas" << endl;
    cout << "linhas e colunas são enumeradas de" << endl;
    cout << "0 a 7. Para realizar uma jogada, o" << endl;
    cout << "usuário deverá informar as coordenadas" << endl;
    cout << "relativas à carta desejada. Por exemplo:" << endl;
    cout << "Insira o valor da linha: X" << endl;
    cout << "Insira o valor da coluna: Y" << endl;
    cout << "\n";
    cout << "           BOM JOGO!" << endl;

    int matInicial[4][4] = {1, 7, 2, 6, 4, 5, 3, 5, 8, 3, 1, 7, 2, 8, 6, 4};
    int matGabarito[4][4];
    int matJogo[4][4];

    srand(time(NULL));
    int random = 1 + rand() % 4;

    // GABARITO = INICIAL
    if (random == 1){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matGabarito[i][j] = matInicial[i][j];
            }
        }
    }

    // GABARITO = TRANSPOSTA
    if (random == 2){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matGabarito[i][j] = matInicial[j][i];
            }
        }
    }

    // GABARITO = INVERTIDA POR LINHA
    if (random == 3){
    int k = -1;

        for (int i = 3; i >= 0; i--){
            k++;
            for (int j = 0; j < 4; j++){
                matGabarito[k][j] = matInicial[i][j];
            }
        }
    }

    // GABARITO = INVERTIDA POR COLUNA
    if (random == 4){
    int k = 0;

        for (int i = 0; i < 4; i++){
            k = 0;
            for (int j = 3; j >= 0; j--){
                matGabarito[i][k] = matInicial[i][j];
                k++;
            }
        }
    }

    cout << random << endl;
    cout << "\n";


    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
           cout << matGabarito[i][j];
        }
        cout << "\n";
    }

return 0;
}




