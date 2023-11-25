#include "Log.h"

bool Log::contains(float playerPosition) {
    if ((center - size / 2) <= playerPosition && playerPosition >= (center + size /2)) {
        return true;
    }
    return false;
}

void Log::moveRight() {
    if (center >= 100) {
        center = 0 - size;
    } else {
        center = center + 0.2f;
    }
}

void Log::moveLeft() {
    if (center <= 0 - size) {
        center = 100;
    } else {
        center = center - 0.2f;
    }
}
