#include "cpp/vectors/vector3d.h"
#include <iostream>

int main() {
        Vector3D v1(1, 3, 5);
        Vector3D v2(4, 12, 20);

        std::cout << v1.collinearity(v2) << std::endl;

        return 0;
}