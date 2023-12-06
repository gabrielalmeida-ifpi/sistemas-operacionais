#include <iostream>
#include <climits>
using namespace std;

struct Processo {
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
    int n, i, j;

    // Entrada de dados
    cout << "Digite o numero de processos: ";
    cin >> n;
    Processo p[n];

    cout << "Digite o quantum: " << endl;
    cin >> quant;

    cout << "Digite os numeros dos processos: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].pos;

    cout << "Digite o tempo de chegada dos processos: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].AT;

    cout << "Digite o tempo de execucao dos processos: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].BT;

    // Declarando variáveis
    int c = n, s[n][20];
    float tempo = 0, mini = INT_MAX, b[n], a[n];

    // Inicializando arrays de tempo de execução e chegada
    int index = -1;
    for (i = 0; i < n; i++) {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++) {
            s[i][j] = -1;
        }
    }

    int total_tempo_espera, total_tempo_vida;
    total_tempo_espera = 0;
    total_tempo_vida = 0;
    bool flag = false;

    while (c != 0) {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++) {
            float p = tempo + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0) {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        // se at =1, então o loop termina, então define a flag como false
        if (!flag) {
            tempo++;
            continue;
        }

        // calculando o tempo de início
        j = 0;
        while (s[index][j] != -1) {
            j++;
        }

        if (s[index][j] == -1) {
            s[index][j] = tempo;
            p[index].ST[j] = tempo;
        }

        if (b[index] <= quant) {
            tempo += b[index];
            b[index] = 0;
        } else {
            tempo += quant;
            b[index] -= quant;
        }

        // Considerar a troca de contexto
        tempo += 4;

        if (b[index] > 0) {
            a[index] = tempo + 0.1;
        }

        // calculando tempo de chegada, execução e tempo final
        if (b[index] == 0) {
            c--;
            p[index].FT = tempo;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            total_tempo_espera += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            total_tempo_vida += p[index].TAT;
        }
    } // fim do loop while

    

    // Calculando tempo médio de espera e tempo de vida
    double media_tempo_espera, media_tempo_vida;
    media_tempo_espera = total_tempo_espera / static_cast<double>(n) - 4;
    media_tempo_vida = total_tempo_vida / static_cast<double>(n) - 4;

    // Exibindo tempo médio de espera e tempo de vida
    cout << "O tempo medio de espera eh: " << media_tempo_espera << endl;
    cout << "O tempo medio de vida eh: " << media_tempo_vida << endl;

    return 0;
}