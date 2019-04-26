#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{
    int nx, ny, nz;
    float r, g, b, a;
    voxel*** v;

    //dimensoes
    cin>>nx>>ny>>nz;

    //criando um objeto cubo da classe Sculptor
    sculptor cubo(nx, ny, nz);

    //cores
//    cin>>r>>g>>b>>a;

    //atribuindo valores de cores e transparência para o cubo através do método setColor
//    cubo.setColor(r, g, b, a);

    return 0;

}
