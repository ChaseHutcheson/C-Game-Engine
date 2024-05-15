#include <core/logger.h>
#include <core/asserts.h>

int main(void)
{

    KFATAL("A Test Message: %f", 3.14f);
    KERROR("A Test Message: %f", 3.14f);
    KWARN("A Test Message: %f", 3.14f);
    KINFO("A Test Message: %f", 3.14f);
    KDEBUG("A Test Message: %f", 3.14f);
    KTRACE("A Test Message: %f", 3.14f);

    KASSERT_MSG(1 == 1, "1 is not equal to 1");

    return 0;
}