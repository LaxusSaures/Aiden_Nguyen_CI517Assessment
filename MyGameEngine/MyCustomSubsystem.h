#include <stdio.h>


class MyCustomSubsystem
{
    friend class XCube2Engine; //make sure
private:
    MyCustomSubsystem();
public:
    ~MyCustomSubsystem();
    void otherfunction();
};


