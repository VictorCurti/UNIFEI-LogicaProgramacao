#include <iostream>
using namespace std;

/*Adiciona notas ao caixa eletronico*/
void Carrega_Caixa(int N[7]){
    int NOTAS[7] = {100,50,20,10,5,2,1};
    int aux;
    cout << "Rotina de carregamento de notas iniciado..." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Digite o numeor de notas de " << NOTAS[i] << " inseridas: ";
        cin >> aux;
        N[i] += aux;
    }
} 

/* Calcula o numero minimo de notas para um determinado valor N = [100,50,20,10,5,2,1]*/
void Calcula_Nota(int N[7],int valor){
    for (int i = 0; i < 7; i++)
        N[i] = 0;
    
    int NOTAS[7] = {100,50,20,10,5,2,1};
    for (int i = 0; i < 7,valor>0; i++)
        while (valor-NOTAS[i] >= 0)
        {
            valor -= NOTAS[i];
            N[i]++;
        }
}

/*Funcao que realiza o saque de um determinado valor*/
void F_Saque(int Disp[7]){
    int saque;
    int Notas_Saque[7];
    cout << "Digite a volor a sacar: ";
    cin >> saque;
    Calcula_Nota(Notas_Saque,saque);

    /*Valida Saque*/
    bool Saque_Valido = true;
    for (int i = 0; i < 7; i++)
        if (Disp[i] - Notas_Saque[i] < 0)   //Numero de notas no Maior que do a ser sacado
            Saque_Valido = false;
    
    if(Saque_Valido)
    {
        cout << "Saque Liberado: " << endl;
        cout << "100:\t" << Notas_Saque[0] << endl;
        cout << "50:\t"  << Notas_Saque[1] << endl;
        cout << "20:\t"  << Notas_Saque[2] << endl;
        cout << "10:\t"  << Notas_Saque[3] << endl;
        cout << "5:\t"   << Notas_Saque[4] << endl;
        cout << "2:\t"   << Notas_Saque[5] << endl;
        cout << "1:\t"   << Notas_Saque[6] << endl;
        for (int i = 0; i < 7; i++)
            Disp[i] -= Notas_Saque[i];
    }else cout << "Saque indisponivel, favor solicitar carga de notas!" << endl;
}

int main(){
    //Inicializa o caixa vazio
    int Notas_Dentro[7] = {0,0,0,0,0,0,0};  
    //Inicializa varial de opicoes com uma inesistente
    char Op = 'a';
    
    //Solicita carremento de notas
    Carrega_Caixa(Notas_Dentro);
    
    while (Op != '0')
    {
        cout << "[1] Carregar Notas." << endl;
        cout << "[2] Saque." << endl ;
        cout << "[3] Ver quantidade de notas no interior do caixa." << endl ;
        cout << "[0] Sair."  << endl ;
        cout << "Opicao: ";

        cin >> Op;
        switch (Op)
        {
        case '1':
            Carrega_Caixa(Notas_Dentro);
            break;
        case '2':
            F_Saque(Notas_Dentro);
            break;
        case '3':
            cout << "Notas no interior: " << endl;
            cout << "100:\t" << Notas_Dentro[0] << endl;
            cout << "50:\t"  << Notas_Dentro[1] << endl;
            cout << "20:\t"  << Notas_Dentro[2] << endl;
            cout << "10:\t"  << Notas_Dentro[3] << endl;
            cout << "5:\t"   << Notas_Dentro[4] << endl;
            cout << "2:\t"   << Notas_Dentro[5] << endl;
            cout << "1:\t"   << Notas_Dentro[6] << endl;
            break;
        case '0':
            return 0;
        default:
            cout << "Opicao selecionada invalida tente novamente\n";
            break;
        }
    }

    return 0;
}