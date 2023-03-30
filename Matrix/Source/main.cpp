#include "../Header/matrix.h"
#include "../Header/rotmat.h"
int main()
{
    RotMat2D r1;
    RotMat2D r2(3.14);
    r1.print();
    std::cout << std::endl;
    r2.print();
    return 0;
}