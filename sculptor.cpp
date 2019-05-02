#include "sculptor.h"
#include <iostream>
#include <cstdlib>

sculptor::sculptor(int _nx, int _ny, int _nz)
{
    //atribui valores aos argumentos
    nx = _nx; ny = _ny; nz = _nz;

    //aloca x, ponteiro para ponteiro
    v = new voxel**[nx];

    //verifica se foi alocado
    if(v == nullptr)
    {
        exit(0);
    }

    //aloca as colunas
    v[0] = new voxel*[nx*ny];

    //verifica se foi alocado
    if(v[0] == nullptr)
    {
        exit(0);
    }

    //aloca os planos
    v[0][0] = new voxel[nx*ny*nz];

    //verifica se foi alocado
    if(v[0][0] == nullptr)
    {
        exit(0);
    }

    //ajusta os endereços das linhas da matriz
    for(int i = 1; i<nx; i++){
        v[i] = v[i-1] + ny;
    }

    //ajusta os endereços dos planos da matriz
    for(int i = 1; i<ny*nz; i++){
        v[0][i] = v[0][i-1] + nz;
    }
}

sculptor::~sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void sculptor::setColor(float vermelho, float verde, float azul, float alpha)
{
    r = vermelho; g = verde; b = azul; a = alpha;
}

void sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    //faz o voxel aparecer
    v[x][y][z].isOn = true;

}

void sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;

}

void sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if((i>=x0 && i<=x1)&&(j>=y0 && j<=y1)&&(k>=z0 && k<=z1)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if((i>=x0 && i<=x1)&&(j>=y0 && j<=y1)&&(k>=z0 && k<=z1)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(((pow((i - xcenter),2)/(float)pow(rx,2) + (pow((j - ycenter),2))/(float)pow(ry,2) + (pow((k - zcenter),2))/(float)pow(rz,2)) <= 1)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}
