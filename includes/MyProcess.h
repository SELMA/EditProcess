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
    int                             _addressValue;
    LPVOID                          _lastAddress;
    Tools                           *_tools = new Tools();
    
public:
    DWORD                           getProcessId();
    HANDLE                          getProcess();
    LPVOID                          getAddress();
    int                             getAddressValue();
    LPVOID                          getLastAddress();
    void                            setProcessId();
    void                            setProcess();
    void                            setMemory();
    void                            setLastAddress();
    bool                            readWhileProcessMemory();
    bool                            readLastProcessMemory();
    bool                            readProcessMemory(LPVOID);
    bool                            writeProcessMemory(int);
    /* test !!! */
    void                            test();
};

#endif	/* MYPROCESS_H */

