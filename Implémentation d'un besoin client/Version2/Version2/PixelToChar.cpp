#include "PixelToChar.h"

char mapPixelToChar(int pixel) {
    //Dans le cas où des valeurs serai inférieur à 0 on les ramènes au positif, dans cette sitation le + 128 ne modifie pas la nuiance
    //On à 8 nuances toutes les 32 valeurs 
    if (pixel < 0) {
        pixel = pixel + 128;
    }
    if (pixel >= 0 && pixel < 32)
        return 'W';
    else if (pixel >= 32 && pixel < 64)
        return 'w';
    else if (pixel >= 64 && pixel < 96)
        return 'l';
    else if (pixel >= 96 && pixel < 128)
        return 'i';
    else if (pixel >= 128 && pixel < 160)
        return ';';
    else if (pixel >= 160 && pixel < 192)
        return ',';
    else if (pixel >= 192 && pixel < 224)
        return '.';
    else if (pixel >= 224 && pixel < 255)
        return ' ';
}