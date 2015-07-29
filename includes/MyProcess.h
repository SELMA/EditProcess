/* 
 * File:   MyProcess.h
 * Author: Sheol
 *
 * Created on 14 décembre 2014, 04:08
 */

#include <fstream>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include "Tools.h"

#ifndef MYPROCESS_H
#define	MYPROCESS_H

#define SIZE    1024

class MyProcess {
public:
    MyProcess();
    MyProcess(const MyProcess& orig);
    virtual ~MyProcess();
    
private:
    HANDLE                          _process;
    DWORD                           _processId;
    PROCESS_MEMORY_COUNTERS         _memory;
    LPVOID                          _address;
    char                            _addressValue[256];
    LPVOID                          _lastAddress;
    DWORD                           _aProcesses[SIZE];
    DWORD                           _cbNeeded;
    DWORD                           _cProcesses;
    Tools                           *_tools = new Tools();
    
public:
    DWORD                           getProcessId();
    HANDLE                          getProcess();
    LPVOID                          getAddress();
    std::string                     getAddressValue();
    LPVOID                          getLastAddress();
    int                             getNbOfProcess(); // todo
    DWORD                           getProcessIdByName(); // todo
    void                            setProcessId();
    void                            setProcess();
    void                            setMemory();
    void                            setLastAddress();
    bool                            readWhileProcessMemory();
    bool                            readLastProcessMemory();
    bool                            readProcessMemory(LPVOID);
    bool                            writeProcessMemory(int);
    void                            cleanAddressValue();
    /* test !!! */
    void                            test();
};

#endif	/* MYPROCESS_H */

