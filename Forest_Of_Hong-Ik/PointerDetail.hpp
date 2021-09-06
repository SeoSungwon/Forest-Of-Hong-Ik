
#pragma

#include "Pointer.hpp"

#include <string>

class PointerDetail : public Pointer {
private:
    std::string pointerName;

public:
    PointerDetail(const int x, const int y, const std::string name) : Pointer(x, y), pointerName(name) {}
    std::string getPointerName() { return pointerName; }
};