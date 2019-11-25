#include <iostream>
#include <cstdlib>
#include <tchar.h.>

using namespace std;

/* Tamanha do vetor */
#define TAM 5

/* Estrutu de um produto: Codigo/Descricao/Categoria */
struct produto
{
    int codigoProduto = 0;
    string descricao;
    char categoria;
};
/* Estrutu do Estoque: Codigo/Quantidade */
struct estoque
{
    int codigoProduto;
    int quantidade = 0;
};

int menu();
void cadastrarProdutos(produto p[TAM], estoque c[TAM]);         //1
bool pesquisarProduto(produto p[TAM], int codigo, int &indice); //
void entradaEstoque(produto p[TAM], estoque c[TAM]);            //2
void saidaEstoque(produto p[TAM], estoque c[TAM]);              //3
void relatorioGeral(produto p[TAM], estoque c[TAM]);            //5
void relatorioProduto(produto p[TAM], estoque c[TAM]);          //4

int main()
{
    _tsetlocale(LC_ALL, _T("portuguese")); //Configura texto para portugues
    int Opcao = 0;
    produto p[TAM];
    estoque c[TAM];

    while (Opcao != 6)
    {
        Opcao = menu();

        switch (Opcao)
        {
        case 1:
            cadastrarProdutos(p, c);
            break;
        case 2:
            entradaEstoque(p, c);
            break;
        case 3:
            saidaEstoque(p, c);
            break;
        case 4:
            relatorioProduto(p, c);
            break;
        case 5:
            relatorioGeral(p, c);
            break;
        }
    }
    cout << "O PROGRAMA ESTÁ SENDO FINALIZADO ...";
    return 0;
}

int menu()
{
    int Opcao;
    do
    {
        cout << "MENU DE OPÇÕES: " << endl
             << endl
             << "1 - Cadastrar produtos." << endl
             << "2 - Entrada de estoque." << endl
             << "3 - Saída de estoque." << endl
             << "4 - Exibir relatório por produto." << endl
             << "5 - Exibir relatorio geral." << endl
             << "6 - Finalizar programa." << endl
             << endl
             << "Digite o número correspondedente a sua opção: ";
        cin >> Opcao;
        if (Opcao < 1 || Opcao > 6)
        {
            cout << "OPÇÃO INVÁLIDA !" << endl;
            system("CLS");
        }
    } while (Opcao < 1 || Opcao > 6);
    system("CLS");
    return Opcao;
}

void cadastrarProdutos(produto p[TAM], estoque c[TAM]) //1
{
    int indice = 0, codigo;
    if (p[0].codigoProduto == 0)
        for (int i = 0; i < TAM; i++)
        {
            bool AUX = false;
            do
            {
                cout << "Digite o codigo do produto a ser cadastrado: ";
                cin >> codigo;
                if (!pesquisarProduto(p, codigo, indice))
                    AUX = true;
                else
                    cout << "ESTE PRODUTO JÁ ESTÁ CADASTRADO!" << endl;
                system("CLS");
            } while (!AUX);

            p[i].codigoProduto = codigo;
            cout << "Digite a categoria do produto [a-z ou 1-9]: ";
            cin >> ws >> p[i].categoria;
            cout << "Digite a descrição do produto: ";
            cin >> ws;
            getline(cin, p[i].descricao);
            c[i].codigoProduto = codigo;
            c[i].quantidade = 0;
        }
    else
    {
        cout << "O LIMITE DE PRODUTOS CADASTRADOS FOI ATINGIDO !";
        system("CLS");
    }
}

bool pesquisarProduto(produto p[TAM], int codigo, int &indice)
{
    indice = -1; //Codigo de produto invalido
    for (int i = 0; i < TAM; i++)
        if (p[i].codigoProduto == codigo)
        {
            indice = i;
            break; //Para pesquisa ao encontrar o produto
        }
    if (indice != -1)
        return true;
    else
        return false;
}

void entradaEstoque(produto p[TAM], estoque c[TAM]) //2
{
    
    if (p[0].codigoProduto == 0)
    {
        cout << "Não há produtos cadastrados!" << endl;
        
    }
    else
    {
        int codigo, indice, temp;
        cout << "Digite o codigo do produto a ser cadastrado: ";
        cin >> codigo;
        if (pesquisarProduto(p, codigo, indice))
        {
            cout << "Digite a quantidade de produtos: ";
            cin >> temp;
            c[indice].quantidade += temp;
        }
        else
            cout
                << "Produto não encontrado!" << endl;
    }
}
void saidaEstoque(produto p[TAM], estoque c[TAM]) //3
{
    if (p[0].codigoProduto == 0)
    {
        cout << "Não há produtos cadastrados!" << endl;
        
    }
    else
    {
        int codigo, indice, temp;
        cout << "Digite o codigo do produto a ser cadastrado: ";
        cin >> codigo;
        if (pesquisarProduto(p, codigo, indice))
        {
            cout << "Digite a quantidade de saida do produto: ";
            cin >> temp;
            if(temp <= c[indice].quantidade)
                c[indice].quantidade -= temp;
            else
                cout << "NÃO É POSSÍVEL FAZER ESTA RETIRADA !A QUANTIDADE DISPONÍVEL É DE : " << 
                c[indice].quantidade << ". REAVALIE A RETIRADA E REPITA A OPERAÇÃO " << endl;
        }
        else
            cout
                << "Produto não encontrado!" << endl;
    }
}
void relatorioGeral(produto p[TAM], estoque c[TAM]) //5
{
    if (p[0].codigoProduto == 0)
    {
        cout << "Não há produtos cadastrados!" << endl;
        
    }
    else
    {
        cout << "**** RELATÓRIO GERAL ****" << endl;
        for (int i = 0; i < TAM; i++)
            cout << "PRODUTO: " << p[i].codigoProduto << endl
                 << "Descrição: " << p[i].descricao << endl
                 << "Categoria: " << p[i].categoria << endl
                 << "Quantidade disponivel em estoque: " << c[i].quantidade << endl
                 << endl
                 << endl;

        
    }
}
void relatorioProduto(produto p[TAM], estoque c[TAM]) //4
{
    if (p[0].codigoProduto == 0)
    {
        cout << "Não há produtos cadastrados!" << endl;
        
    }
    else
    {
        int codigo, indice;
        cout << "Digite o codigo do produto a ser cadastrado: ";
        cin >> codigo;
        if (pesquisarProduto(p, codigo, indice))
            cout << "PRODUTO: " << codigo << endl
                 << "Descrição: " << p[indice].descricao << endl
                 << "Categoria: " << p[indice].categoria << endl
                 << "Quantidade disponivel em estoque: " << c[indice].quantidade << endl
                 << endl
                 << endl;

        else
            cout
                << "Produto não encontrado!" << endl;
        
    }
}