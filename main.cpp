//  ________________________________
// |      AUTORES DO PROJETO:       |
// |--------------------------------|
// | MARCO VINICIUS DA COSTA BUSATO |
// | LAURA FERRARI HECKMANN         |
// |________________________________|

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
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
    system("CLS");

    // MATRIZ INICIAL JÁ POSSUI VALORES PRÉ DEFINIDOS
    int matInicial[4][4] = {1, 7, 2, 6, 4, 5, 3, 5, 8, 3, 1, 7, 2, 8, 6, 4};
    // MATRIZ GABARITO SERÁ GERADA PELO ALGORITMO DENTRE 4 OPÇÕES ABAIXO
    int matGabarito[4][4];
    // MATRIZ JOGO INICIA ZERADA E É PREENCHIDA AOS POUCOS PELO USUÁRIO
    int matJogo[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // ALGORITMO PARA GERAR UM NÚMERO INTEIRO ALEATÓRIO ENTRE 1 E 4
    srand(time(NULL));
    int random = 1 + rand() % 4;

    // MATRIZ GABARITO = MATRIZ INICIAL
    if (random == 1){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matGabarito[i][j] = matInicial[i][j];
            }
        }
    }

    // MATRIZ GABARITO = MATRIZ TRANSPOSTA
    if (random == 2){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                matGabarito[i][j] = matInicial[j][i];
            }
        }
    }

    // MATRIZ GABARITO = MATRIZ INVERTIDA POR LINHA
    if (random == 3){
    int k = -1;

        for (int i = 3; i >= 0; i--){
            k++;
            for (int j = 0; j < 4; j++){
                matGabarito[k][j] = matInicial[i][j];
            }
        }
    }

    // MATRIZ GABARITO = MATRIZ INVERTIDA POR COLUNA
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

    // VARIÁVEL CONTADORA QUE ARMAZENA QUANTOS PARES DE CARTAS FORAM DESCOBERTOS
    int contPares = 0;

    // FOR LOOP DE 24 REPETIÇÕES QUE CONTROLA O JOGO INTEIRO (24 JOGADAS NO MÁXIMO)
    for (int r = 1; r <= 24; r++){

        // VARIÁVEIS QUE RECEBEM OS VALORES DE LINHA E COLUNA. (C1 = CARTA 1 e C2 = CARTA 2)
        int coordLin, coordCol, coordLinC1, coordColC1, c1, coordLinC2, coordColC2, c2;

        // VERIFICAÇÃO --> CASO HAJA 8 PARES DESCOBERTOS, O JOGO FINALIZA COM A MENSAGEM DE VITÓRIA
        if (contPares == 8){
            system("CLS");
            cout <<
            "   _____                      _                         _ \n"
            "  | ___ \\                    | |                       | |\n"
            "  | |_/ /  __ _  _ __   __ _ | |__    ___  _ __   ___  | |\n"
            "  |  __/  / _` || '__| / _` || '_ \\  / _ \\| '_ \\ / __| | |\n"
            "  | |    | (_| || |   | (_| || |_) ||  __/| | | |\\__ \\ |_|\n"
            "  \\_|     \\__,_||_|    \\__,_||_.__/  \\___||_| |_||___/ (_)\n"
            << endl;
            cout << "\n";
            cout << "               ______________________________  " << endl;
            cout << "                                                          " << endl;
            cout << "                 Você ganhou em " << r-1 << " jogadas!    " << endl;
            cout << "               ______________________________  " << endl;
            return 0;
        }

        // IMPRESSÃO DA JOGADA EM QUE O USUÁRIO SE ENCONTRA
        cout << "Jogada " << r << " de 24" << endl;
        cout << "\n";

        // ESTÉTICA DE DIVISÃO DAS CARTAS NA IMPRESSÃO ("| |")
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

        // FOR LOOP QUE CONTROLA QUAL CARTA O USUÁRIO ESTÁ TENTANDO DESCOBRIR (PRIMEIRA OU SEGUNDA)
        for (int carta = 1; carta <= 2; carta++){

            // DO...WHILE PARA EXECUTAR AO MENOS UMA VEZ, ENQUANTO SUPRIR A EXIGÊNCIA (NÚMERO INTEIRO ENTRE 0 E 3)
            do {
                cout << "Insira o valor da linha da carta " << carta << ": ";
                cin >> coordLin;

                // CONTROLE CASO O USUÁRIO INSIRA UM VALOR MENOR QUE 0 OU MAIOR QUE 3
                if (coordLin < 0 || coordLin > 3){
                    cout << "ERRO: Coordenada inexistente!" << endl;
                    cout << "\n";
                    coordLin = -1;
                }

                // CONTROLE CASO ESTEJA NA CARTA 1 E SEJA INSERIDA UMA COORDENADA VÁLIDA
                if (carta == 1 && coordLin != -1){

                    // CONTROLE PARA VERIFICAR SE A LINHA ESCOLHIDA PELO USUÁRIO JÁ ESTÁ PREENCHIDA POR COMPLETO
                    if (matJogo[coordLin][0] != 0 && matJogo[coordLin][1] != 0 && matJogo[coordLin][2] != 0 && matJogo[coordLin][3] != 0){
                        cout << "ERRO: A linha já foi preenchida!" << endl;
                        cout << "\n";
                        coordLin = -1;
                    }

                    // CONTROLE CASO A COORDENADA ATENDA A TODOS OS REQUISITOS, TORNANDO-SE A COORDENADA DA LINHA DA CARTA 1
                    else{
                        coordLinC1 = coordLin;
                    }
                }

                if (carta == 2 && coordLin != -1){

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
                    coordCol = -1;
                }

                if (matJogo[coordLin][coordCol] != 0 && coordCol != -1) {
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

            // CASO ESTEJA NA CARTA 1, C1 RECEBE O VALOR CORRESPONDENTE AO DO ELEMENTO DA MATRIZ GABARITO NAS COORDENADAS INSERIDAS
            // PELO USUÁRIO E A MATRIZ JOGO DEIXA DE SER 0 E PASSA A SER O VALOR DE C1 NAQUELA POSIÇÃO.
            if (carta == 1) {
                c1 = matGabarito[coordLinC1][coordColC1];
                matJogo[coordLinC1][coordColC1] = c1;
            }

            if (carta == 2) {
                c2 = matGabarito[coordLinC2][coordColC2];
                matJogo[coordLinC2][coordColC2] = c2;
            }

            // IMPRESSÃO DA MATRIZ JOGO COM OS VALORES ATUALIZADOS NAS CARTAS DESCOBERTAS
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

            // VALIDAÇÃO DE ERRO OU ACERTO
            if (carta == 2){

                // SE A CARTA 1 FOR DIFERENTE DA CARTA 2, ERROU!
                if (c1 != c2){
                    cout << " ________"  << endl;
                    cout << "|        |" << endl;
                    cout << "| ERROU! |" << endl;
                    cout << "|________|" << endl;
                    cout << "\n";
                    // A MATRIZ JOGO VOLTA A VALER 0 NAS POSIÇÕES ESCOLHIDAS, POIS O USUÁRIO ERROU A JOGADA
                    matJogo[coordLinC1][coordColC1] = 0;
                    matJogo[coordLinC2][coordColC2] = 0;
                    getchar();
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("CLS");
                }

                // SE A CARTA 1 FOR IGUAL À CARTA 2, ACERTOU!
                if (c1 == c2){
                    cout << " __________"  << endl;
                    cout << "|          |" << endl;
                    cout << "| ACERTOU! |" << endl;
                    cout << "|__________|" << endl;
                    cout << "\n";
                    // A MATRIZ JOGO PERMANECE COM OS VALORES DE C1 E C2 NAS POSIÇÕES ESCOLHIDAS, POIS O USUÁRIO ACERTOU A JOGADA
                    matJogo[coordLinC1][coordColC1] = c1;
                    matJogo[coordLinC2][coordColC2] = c2;
                    contPares++;
                    getchar();
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("CLS");
                }
            }
        }
    }


    system("CLS");

    // CASO EXCEDA 24 JOGADAS, O JOGO ACABA COM A MENSAGEM DE DERROTA
    cout <<
   "  _   _                       ______                  _                _ \n"
   " | | | |                      | ___ \\                | |              | |\n"
   " | | | |  ___    ___   ___    | |_/ /  ___  _ __   __| |  ___  _   _  | |\n"
   " | | | | / _ \\  / __| / _ \\   |  __/  / _ \\| '__| / _` | / _ \\| | | | | |\n"
   " \\ \\_/ /| (_) || (__ |  __/   | |    |  __/| |   | (_| ||  __/| |_| | |_|\n"
   "  \\___/  \\___/  \\___| \\___|   \\_|     \\___||_|    \\__,_| \\___| \\__,_| (_) \n"
    << endl;

return 0;
}
