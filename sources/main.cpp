#include "Tools.h"
#include "MyProcess.h"

int                     main()
{
    MyProcess           *process = new MyProcess();
    int                 test = 42;
    
    std::cout << test << std::endl;
    process->test();
    std::cout << test << std::endl;
    system("pause");
	
    return (false);
}