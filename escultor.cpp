#include "escultor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel **[nx];

    for(int x = 0; x < nx; x++){
        v[x] = new Voxel * [ny];
        for(int y = 0; y < ny; y++){
            v[x][y] = new Voxel[nz];
        }
    }

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                v[x][y][z].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            delete[] v[x][y];
        }
    }
    for(int x=0; x<nx; x++){
        delete[] v[x];
    }

    delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int z = z0; z <= z1; z++){
        for(int y = y0; y <= y1; y++){
            for(int x = x0; x <= x1; x++){
                putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int z = z0; z <= z1; z++){
        for(int y = y0; y <= y1; y++){
            for(int x = x0; x <= x1; x++){
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                int r = radius*radius;
                float xi = (x-xcenter)*(x-xcenter);
                float yi = (y-ycenter)*(y-ycenter);
                float zi = (z-zcenter)*(z-zcenter);
                if(xi+yi+zi<r){
                    putVoxel(x,y,z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                int r = radius*radius;
                int xi = (x-xcenter)*(x-xcenter);
                int yi = (y-ycenter)*(y-ycenter);
                int zi = (z-zcenter)*(z-zcenter);
                if(xi+yi+zi<=r){
                    cutVoxel(x,y,z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry,int rz){
    for(int x = xcenter - rx; x < xcenter + rx; x++){
        for(int y = ycenter - ry; y < ycenter + ry; y++){
            for(int z = zcenter - rz; z < zcenter + rz; z++){
                if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - ycenter, 2)/pow(ry, 2) + pow(x - xcenter, 2)/pow(rx, 2) < 1){
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry,int rz){
    for(int x = xcenter - rx; x < xcenter + rx; x++){
        for(int y = ycenter - ry; y < ycenter + ry; y++){
            for(int z = zcenter - rz; z < zcenter + rz; z++){
                if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - ycenter, 2)/pow(ry, 2) + pow(x - xcenter, 2)/pow(rx, 2) < 1){
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    ofstream fout;

    fixed(fout);

    int aux = 0, cont=0;
    int i, j, k;

    fout.open(filename);

    if(fout.is_open()){
        cout << "salvando aquivo OFF.\n";
    }
    else{
        cout << "arquivo OFF não encontrado\n";
        exit(1);
    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    cont++;
                }
            }
        }
    }

    fout << "OFF" << endl;
    fout << cont*8<< " " << cont*6 << " 0" << endl;

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                }
            }
        }
    }

    for(i=0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout << "4 " << aux << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << "4 " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " "
                        << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    aux+=8;
                }
            }
        }
    }

    if(fout.is_open()){
        cout << "Arquivo.OFF salvo com sucesso!"<<endl;
    }
}