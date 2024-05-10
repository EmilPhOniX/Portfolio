#include "Console.h"

std::string PixelToStr(int pixel, pal palette) {
    int step = 256 / palette.size();
    for (int i = 0; i < palette.size(); i++) {
        if (pixel < 0) {
            pixel = pixel + 128;
        }
        if (pixel >= i * step && pixel < (i + 1) * step) {
            return palette[i];
        }
    }
}