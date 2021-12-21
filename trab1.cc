#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
typedef int *image;

void negativo(int *inicio, int *fim, int nl, int nc, int mn, int *aux);
void invertervertical(int *inicio, int *fim, int nl, int nc, int mn, int *aux);
void inverterhorizontal(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1);
void rotacaodireita(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1);
void escurecer(int *inicio, int *fim, int nl, int nc, int mn, int *aux);
void clarear(int *inicio, int *fim, int nl, int nc, int mn, int *aux);
void rotacaoesquerda(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1);
void vinheta(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1);

int *inicio, *fim, *aux, *aux1, *aux2;

int main(int argc, char **argv)
{

    int nl, nc, mn, op, temp, i;

    string line;
    ifstream myfile("stanford.pgm");
    if (myfile.is_open())
    {
        myfile >> line;
        // cout << "primeira linha: " << line << endl;
        myfile >> line;
        // cout << "segunda linha: " << line << endl;
        myfile >> nc;
        // cout << "nc : " << nc << endl;
        myfile >> nl;
        // cout << "nl : " << nl << endl;
        myfile >> mn;
        // cout << "mn : " <<mn << endl;
        // in =(int *) malloc(nl * nc * sizeof(int));
        int vetor[nc * nl];
        inicio = &vetor[0];
        fim = &vetor[nc * nl];
        i = 0;
        while (!myfile.eof())
        {
            myfile >> temp;
            vetor[i] = temp;
            // cout << vetor[i] << endl;
            i++;
        }
        myfile.close();
    }
    else
        cout << "Erro ao abrir o arquivo";

    do
    {
        cout << endl;
        cout << "0.Sair do programa." << endl;
        cout << "1.Negativo da imagem." << endl;
        cout << "2.Inversao vertical." << endl;
        cout << "3.Inversao horizontal." << endl;
        cout << "4.Rotação a direita." << endl;
        cout << "5.Escurecer borda." << endl;
        cout << "6.Escurecer Imagem." << endl;
        cout << "7.Clarear Imagem." << endl;
        cout << "8.Rotação a esquerda." << endl;

        cout << endl
             << "Digite uma opcao: ";
        cin >> op;
        switch (op)
        {
        case 0:
            cout << "Voce escolheu a opcao de encerrar o programa!";
            exit(100);
        case 1:
            negativo(inicio, fim, nl, nc, mn, aux);
            cout << "Imagem negativa" << endl;
            break;
        case 2:
            invertervertical(inicio, fim, nl, nc, mn, aux);
            cout << "2.Inversao vertical." << endl;
            break;
        case 3:
            inverterhorizontal(inicio, fim, nl, nc, mn, aux, aux1);
            cout << "3.Inversao horizontal." << endl;
            break;
        case 4:
            rotacaodireita(inicio, fim, nl, nc, mn, aux, aux1);
            cout << "4.Rotação a direita." << endl;
            break;
        case 5:
            vinheta(inicio,fim,nl,nc,mn,aux,aux1);
            cout << "5.Escurecer borda." << endl;
            break;
        case 6:
            escurecer(inicio, fim, nl, nc, mn, aux);
            cout << "6.Escurecer Imagem." << endl;
            break;
        case 7:
            clarear(inicio, fim, nl, nc, mn, aux);
            cout << "7.Clarear Imagem." << endl;
            break;
        case 8:
            rotacaoesquerda(inicio, fim, nl, nc, mn, aux, aux1);
            cout << "8.Rotação a esquerda." << endl;
            break;
        }
    } while (op != 0);
}

void negativo(int *inicio, int *fim, int nl, int nc, int mn, int *aux) // ok
{

    int count = 0;

    ofstream myfile1;
    myfile1.open("negativo.pgm", ios::out);
    if (myfile1.is_open())
    {
        myfile1 << "P2\n";
        myfile1 << "#Create By Eduardo Sapio\n";
        myfile1 << nc << " " << nl << endl;
        myfile1 << mn << endl;
        for (aux = inicio; aux < fim; aux++)
        {
            if (count == 15)
            {
                myfile1 << endl;
                count = 0;
            }
            myfile1 << mn - *aux << " ";
            count++;
        }
        myfile1.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void invertervertical(int *inicio, int *fim, int nl, int nc, int mn, int *aux) // ook
{

    int count = 0;
    ofstream myfile2;
    myfile2.open("invertevertical.pgm", ios::out);
    if (myfile2.is_open())
    {
        myfile2 << "P2\n";
        myfile2 << "#Create By Eduardo Sapio\n";
        myfile2 << nc << " " << nl << endl;
        myfile2 << mn << endl;
        for (aux = fim - 1; aux > inicio; aux--)
        {
            if (count == 15)
            {
                myfile2 << endl;
                count = 0;
            }
            if (*aux < 0)
                myfile2 << 0 << " ";
            else if (*aux > 255)
                myfile2 << 255 << " ";
            else
                myfile2 << *aux << " ";
            count++;
        }
        myfile2.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void inverterhorizontal(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1) // ok
{

    int count = 0;
    ofstream myfile3;
    myfile3.open("inverterhorizontal.pgm", ios::out);
    if (myfile3.is_open())
    {
        myfile3 << "P2\n";
        myfile3 << "#Create By Eduardo Sapio\n";
        myfile3 << nc << " " << nl << endl;
        myfile3 << mn << endl;
        for (aux = inicio + nc; aux <= fim; aux += nc)
        {
            for (aux1 = aux; aux1 > aux - nc; aux1--)
            {
                if (count == 15)
                {
                    myfile3 << endl;
                    count = 0;
                }
                if (*aux1 < 0)
                    myfile3 << 0 << " ";
                else if (*aux1 > 255)
                    myfile3 << 255 << " ";
                else
                    myfile3 << *aux1 << " ";
                count++;
            }
        }
        myfile3.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void rotacaodireita(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1) // ok
{
    int count = 0;
    ofstream myfile4;
    myfile4.open("rotacaodireita.pgm", ios::out);
    if (myfile4.is_open())
    {
        aux2 = inicio;
        myfile4 << "P2\n";
        myfile4 << "#Create By Eduardo Sapio\n";
        myfile4 << nl << " " << nc << endl;
        myfile4 << mn << endl;
        for (aux1 = fim - nc; aux1 < fim; aux1++, aux2++)
        {
            for (aux = aux1; aux >= aux2; aux -= nc)
            {
                if (count == 15)
                {
                    myfile4 << endl;
                    count = 0;
                }
                myfile4 << *aux << " ";
                count++;
            }
        }
        myfile4.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void vinheta(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1)
{
    int count = 0,fator,x=0,k=0,y=1,p=0;
    ofstream myfile5;
    myfile5.open("vinheta.pgm", ios::out);
    if (myfile5.is_open())
    {
        
        myfile5 << "P2\n";
        myfile5 << "#Create By Eduardo Sapio\n";
        myfile5 << nc << " " << nl << endl;
        myfile5 << mn << endl;

        // for(aux = inicio; aux < fim;aux++){
        //     myfile5 << *aux << " ";
        // }

        for (fator = 100; fator >= 0; fator -= 10)
        {
            for (aux = inicio + x*nc + k, aux1 = inicio + y*nc - p; aux < aux1; aux++) // -------- de cima
                myfile5 << *aux - fator << " ";

            for (aux = inicio + y*nc - p, aux1 = fim - x*nc - k; aux < aux1; aux++) // | lado direito
                myfile5 << *aux - fator << " ";

            for (aux = fim - y*nc + p, aux1 = fim - x*nc - k; aux < aux1; aux++) // ------- de baixo
                myfile5 << *aux - fator << " ";

            for (aux = inicio + x*nc + k, aux1 = fim - y*nc + p; aux < aux1; aux++) // | lado esquerdo
                myfile5 << *aux - fator << " ";
            count++;
            if(count == 2)
                k = k + 2;
            else
                k = k + 1;
            x++;
            y++;
            p++;
        }
        myfile5.close();
    }
    else 
        cout << "Erro ao abrir o arquivo";
}

void escurecer(int *inicio, int *fim, int nl, int nc, int mn, int *aux) // escurecemos em um fator de 80 - ok
{

    int count = 0, fator = 80;

    ofstream myfile6;
    myfile6.open("escurecida.pgm", ios::out);
    if (myfile6.is_open())
    {
        myfile6 << "P2\n";
        myfile6 << "#Create By Eduardo Sapio\n";
        myfile6 << nc << " " << nl << endl;
        myfile6 << mn << endl;
        for (aux = inicio; aux < fim; aux++)
        {
            if (count == 15)
            {
                myfile6 << endl;
                count = 0;
            }
            if (*aux - fator < 0)
                myfile6 << 0 << " ";
            else
                myfile6 << *aux - fator << " ";
            count++;
        }
        myfile6.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void clarear(int *inicio, int *fim, int nl, int nc, int mn, int *aux) // clareamos em um fator de 80 - ok
{

    int count = 0, fator = 80;

    ofstream myfile7;
    myfile7.open("clareada.pgm", ios::out);
    if (myfile7.is_open())
    {
        myfile7 << "P2\n";
        myfile7 << "#Create By Eduardo Sapio\n";
        myfile7 << nc << " " << nl << endl;
        myfile7 << mn << endl;
        for (aux = inicio; aux < fim; aux++)
        {
            if (count == 15)
            {
                myfile7 << endl;
                count = 0;
            }
            if (*aux + fator > 255)
                myfile7 << 255 << " ";
            else
                myfile7 << *aux + fator << " ";
            count++;
        }
        myfile7.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

void rotacaoesquerda(int *inicio, int *fim, int nl, int nc, int mn, int *aux, int *aux1)
{
    int count = 0;
    ofstream myfile8;
    myfile8.open("rotacaoesquerda.pgm", ios::out);
    if (myfile8.is_open())
    {
        aux2 = fim;
        myfile8 << "P2\n";
        myfile8 << "#Create By Eduardo Sapio\n";
        myfile8 << nl << " " << nc << endl;
        myfile8 << mn << endl;
        for (aux1 = inicio + nc; aux1 > inicio; aux1--, aux2--)
        {
            for (aux = aux1; aux <= aux2; aux += nc)
            {
                if (count == 15)
                {
                    myfile8 << endl;
                    count = 0;
                }
                myfile8 << *aux << " ";
                count++;
            }
        }
        myfile8.close();
    }
    else
        cout << "Erro ao abrir o arquivo";
}

