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
    cout << "cartas enumeradas de 1 a 8, onde em" << endl;
    cout << "cada jogada o jogador deve escolher" << endl;
    cout << "duas cartas, podendo executar até no" << endl;
    cout << "máximo 24 jogadas. Vence aquele que" << endl;
    cout << "localizar todos os pares em tempo hábil." << endl;
    cout << "\n";
    cout << "Pressione ENTER para continuar...";
    getchar();
    cout << "\n";
    cout << "   O jogo consiste em uma matriz 4x4," << endl;
    cout << "cujas linhas e colunas são enumeradas" << endl;
    cout << "de 0 a 3. Para realizar uma jogada, o" << endl;
    cout << "usuário deverá informar as coordenadas" << endl;
    cout << "relativas à carta desejada. Por exemplo:" << endl;
    cout << "\n";
    cout << "Insira o valor da linha: 2" << endl;
    cout << "Insira o valor da coluna: 0" << endl;
    cout << "\n";
    cout << "|0|0|0|0|" << endl;
    cout << "|0|0|0|0|" << endl;
    cout << "|X|0|0|0|" << endl;
    cout << "|0|0|0|0|" << endl;
    cout << "\n";
    cout << "           BOM JOGO!" << endl;
    cout << "\n";
    cout << "Pressione ENTER para continuar...";
    getchar();
    cout << "\n";
    system("clear");

    int matInicial[4][4] = {1, 7, 2, 6, 4, 5, 3, 5, 8, 3, 1, 7, 2, 8, 6, 4};
    int matGabarito[4][4];
    int matJogo[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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

    int contPares = 0;

    for (int r = 1; r <= 24; r++){

        int coordLin, coordCol, coordLinC1, coordColC1, c1, coordLinC2, coordColC2, c2;

        if (contPares == 8){
            system("clear");
            cout << "Parabéns! Você ganhou!" << endl;
            return 0;
        }

        cout << "Jogada " << r << " de 24" << endl;
        cout << "\n";

        // ESTÉTICA DE DIVISÃO DAS CARTAS
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){

                if (j == 3) {
                cout << "|" << matJogo[i][j] << "|";
                }

                else {
                cout << "|" << matJogo[i][j];
                }
            }
            cout << "\n";
        }
        cout << "\n";

        for (int carta = 1; carta <= 2; carta++){

            do {
                cout << "Insira o valor da linha da carta " << carta << ": ";
                cin >> coordLin;

                if (coordLin < 0 || coordLin > 3){
                    cout << "ERRO: Coordenada inexistente!" << endl;
                    cout << "\n";
                }

                if (carta == 1){

                    if (matJogo[coordLin][0] != 0 && matJogo[coordLin][1] != 0 && matJogo[coordLin][2] != 0 && matJogo[coordLin][3] != 0){
                        cout << "ERRO: A linha já foi preenchida!" << endl;
                        cout << "\n";
                        coordLin = -1;
                    }

                    else{
                        coordLinC1 = coordLin;
                    }
                }

                if (carta == 2){

                    if (matJogo[coordLin][0] != 0 && matJogo[coordLin][1] != 0 && matJogo[coordLin][2] != 0 && matJogo[coordLin][3] != 0){
                        cout << "ERRO: A linha já foi preenchida!" << endl;
                        cout << "\n";
                        coordLin = -1;
                    }

                    else{
                        coordLinC2 = coordLin;
                    }
                }

            }
            while(coordLin < 0 || coordLin > 3);
            cout << "\n";

            do {
                cout << "Insira o valor da coluna da carta " << carta << ": ";
                cin >> coordCol;

                if (coordCol < 0 || coordCol > 3){
                    cout << "ERRO: Coordenada inexistente!" << endl;
                    cout << "\n";
                }

                if (matJogo[coordLin][coordCol] != 0 && coordCol >= 0 && coordCol <= 3) {
                    cout << "ERRO: A carta já foi descoberta!" << endl;
                    cout << "\n";
                    coordCol = -1;
                }

                if (carta == 1){
                    coordColC1 = coordCol;
                }

                if (carta == 2){
                    coordColC2 = coordCol;
                }
            }
            while(coordCol < 0 || coordCol > 3);
            cout << "\n";

            if (carta == 1) {
                c1 = matGabarito[coordLinC1][coordColC1];
                matJogo[coordLinC1][coordColC1] = c1;
            }

            if (carta == 2) {
                c2 = matGabarito[coordLinC2][coordColC2];
                matJogo[coordLinC2][coordColC2] = c2;
            }

            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){

                    if (j == 3) {
                        cout << "|" << matJogo[i][j] << "|";
                    }

                    else {
                        cout << "|" << matJogo[i][j];
                    }
                }
                cout << "\n";
            }
            cout << "\n";

            if (carta == 2){

                if (c1 != c2){
                    cout << "ERROU!" << endl;
                    cout << "\n";
                    matJogo[coordLinC1][coordColC1] = 0;
                    matJogo[coordLinC2][coordColC2] = 0;
                    getchar();
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("clear");
                }

                if (c1 == c2){
                    cout << "ACERTOU!" << endl;
                    cout << "\n";
                    matJogo[coordLinC1][coordColC1] = c1;
                    matJogo[coordLinC2][coordColC2] = c2;
                    contPares++;
                    getchar();
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("clear");
                }
            }
        }
    }


    system("clear");
    cout << "Você perdeu!" << endl;

return 0;
}




