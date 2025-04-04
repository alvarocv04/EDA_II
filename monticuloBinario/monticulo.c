#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "monticulo.h"

/*
void heapsort(Monticulo *m){
    tipoElemento mini;
    int i=1;
    int n=m->tamanno;
    crearMonticulo2(m);
    printf("\nEn heapsort monticullo construido: %d\n", esMonticulo(*m));
    for(i=1;i<=n;i++){
        printf("%d ",m->elemento[i].clave);
    }
    for(i=1;i<=n;i++){
        eliminarMinimo(&mini);
        m->elemento[n-i+1]=mini;
    }
}
*/

void iniciaMonticulo(Monticulo *m)
{
    m->tamanno = 0;
}
int vacioMonticulo(Monticulo m)
{
    if (m.tamanno == 0)
    {
        return 1;
    }
    return 0;
}

int insertar(tipoElemento x, Monticulo *m)
{
    if (m->tamanno >= MAXIMO)
        return -1;

    m->tamanno++;
    m->elemento[m->tamanno] = x;
    filtradoAscendente(m, m->tamanno);
    return 0;
}

int eliminarMinimo(Monticulo *m, tipoElemento *minimo)
{
    if (m->tamanno <= 0)
        return -1;

    *minimo = m->elemento[1];
    m->elemento[1] = m->elemento[m->tamanno];
    m->tamanno--;

    filtradoDescendente(m, 1);
    return 0;
}

void decrementarClave(int pos, tipoClave cantidad, Monticulo *m)
{
    if (pos <= 0 || pos > m->tamanno)
        return;
    tipoElemento aDecrementar = m->elemento[pos];
    aDecrementar.clave -= cantidad;
    filtradoAscendente(m, pos);
}

void incrementar(int pos, tipoClave cantidad, Monticulo *m)
{
    if (pos <= 0 || pos > m->tamanno)
        return;
    tipoElemento aIncrementar = m->elemento[pos];
    aIncrementar.clave += cantidad;
    filtradoDescendente(m, pos);
}

int esMonticulo(Monticulo m)
{
    for (int i = m.tamanno; i > 1; i--)
    {
        if (m.elemento[i].clave < m.elemento[i / 2].clave)
        {
            return 0;
        }
    }
    return 1;
}

void filtradoAscendente(Monticulo *m, int i)
{
    tipoElemento aOrdenar = m->elemento[i];
    while (aOrdenar.clave < m->elemento[i / 2].clave && i > 1)
    {
        m->elemento[i] = m->elemento[i / 2];
        i = i / 2;
    }
    m->elemento[i] = aOrdenar;
}

void filtradoDescendente(Monticulo *m, int i)
{
    tipoElemento aOrdenar = m->elemento[i];
    int hijoMenor, finFiltrado = 0;
    while (2 * i <= m->tamanno && !finFiltrado)
    {
        hijoMenor = 2 * i;
        if (hijoMenor + 1 <= m->tamanno && m->elemento[hijoMenor + 1].clave < m->elemento[hijoMenor].clave)
        {
            hijoMenor = hijoMenor + 1;
        }
        if (m->elemento[hijoMenor].clave < aOrdenar.clave)
        {
            m->elemento[i] = m->elemento[hijoMenor];
            i = hijoMenor;
        }
        else
        {
            finFiltrado = 1;
        }
    }
    m->elemento[i] = aOrdenar;
}
