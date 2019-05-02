#ifndef SCULPTOR_H
#define SCULPTOR_H

using namespace std;
/**
 * @brief Estrutura do voxel.
 */
//estrutura voxel
struct voxel {
    //cores
    float r,g,b;
    //transparência
    float a;
    //incluído ou não
    bool isOn;
};

/**
 * @brief Classe sculptor.
 */
class sculptor {

protected:
    //matriz 3D
    voxel ***v;
    //Dimensões
    int nx, ny, nz;
    //Cores
    float r, g, b, a;

public:

    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();
    void setColor(float vermelho, float verde, float azul, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    //void writeOFF(string filename);
    //void writeVECT(string filename);

};

#endif // SCULPTOR_H
