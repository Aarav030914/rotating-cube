#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unistd.h>
using namespace std;
int main(){
    int const screen_height = 22;
    int const screen_width = 60;
    int x = screen_width/2+10;
    int y = screen_height/2;
    float theta = 0.4;
    float cosT = cos(theta);
    float sinT = sin(theta);
    float phi = 0;
    while(1){
        printf("\x1B[2J");
        printf("\x1B[H");        
        float cosP = cos(phi);
        float sinP = sin(phi);
        char output[screen_height][screen_width];
        char* begin = &output[0][0];
        fill(begin, begin + sizeof(output)/sizeof(output[0][0]), ' ');
        for(int k=-7;k<7;k++){
            for(int j=-6;j<6;j++){
                for(int i=-7;i<7;i++){
                    int x1 = x + cosP*i + sinP*j;
                    int y1 = y - cosT*sinP*i + cosP*cosT*j + sinT*k;
                    int z1 = sinT*sinP*i - j*cosP*sinT + cosT*k;
                    if(output[y1][x1] == ' '){
                        if(k == -7 or k == -6){
                            output[y1][x1] = '!';
                        }
                        else if(j == 6 or j == -6){
                            output[y1][x1] = '#';
                        }
                        else if((i) == 6){
                            output[y1][x1] = 'o';
                        }
                        else{
                            output[y1][x1] = '.';
                        }
                    }
                }
            }
        }
        for(int j=0;j<screen_height;j++){
            for(int i=0;i<screen_width;i++){
                putchar(output[j][i]);
            }
            putchar('\n');
        }
        phi+=0.02;
        usleep(30000);
    }
}