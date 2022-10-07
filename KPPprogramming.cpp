// NAMA		: MOCHAMMAD ZHARIF ASYAM MARZUQI
// NRP		: 5025221163
// Jurusan	: TEKNIK INFORMATIKA

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

float speed_dgn_loss(float v0)
{
	if(1<=v0&&v0<=10) return 1.0;
    else if(v0<=20) return 3.0;
    else return 5.0;
}

void mencari_v0(float *v0,int *jarak){
    //mencari nilai loss
    int loss = speed_dgn_loss(*v0);
    //memproses v0 dikurangi loss speed
    *v0 = *v0 - loss;
    // kalkulasi jarak
    *jarak = *v0 * *v0 / GRAVITASI;
    //kalkulasi v0 sesuai jarak yang difloor
    *v0 = sqrt(*jarak * GRAVITASI);
    *v0 += loss;
}

int main() {
    int jarak; 
    float v0;
    std::cin >> v0;
    
  	mencari_v0(&v0,&jarak);
  
  	std::cout << jarak << " " << v0 << '\n' << std::endl;
    return 0;
}