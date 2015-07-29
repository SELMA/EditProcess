/* 
 * File:   MyProcess.cpp
 * Author: Sheol
 * 
 * Created on 14 décembre 2014, 04:08
 */

#include "MyProcess.h"
#include "Tools.h"

MyProcess::MyProcess() : _process(0), _processId(0), _address(0), _lastAddress(0) {
}

MyProcess::~MyProcess() {
    CloseHandle(this->_process);
}

LPVOID              MyProcess::getAddress() {
    return (this->_address);
}

std::string         MyProcess::getAddressValue() {
    return (std::string(this->_addressValue));
}

HANDLE              MyProcess::getProcess() {
    return (this->_process);
}

DWORD               MyProcess::getProcessId() {
    return (this->_processId);
}

LPVOID              MyProcess::getLastAddress() {
    return (this->_lastAddress);
}

int                 MyProcess::getNbOfProcess() {
    if (!EnumProcesses(this->_aProcesses, sizeof(this->_aProcesses), &this->_cbNeeded)) {
        return (true);
    }
    return (this->_cProcesses = this->_cbNeeded / sizeof(DWORD));
}

DWORD               MyProcess::getProcessIdByName() {
    return (false);
}

void                MyProcess::setProcessId() {
    GetWindowThreadProcessId(this->_tools->checkProcess(), &this->_processId);
}

void                MyProcess::setProcess() {
    if ((this->_process = OpenProcess(PROCESS_ALL_ACCESS, false, this->_processId)) == NULL) {
        this->_tools->myError("setProcess()");
    }
}

void                MyProcess::setMemory() {
    if (GetProcessMemoryInfo(this->_process, &this->_memory, sizeof(this->_memory)) > 0)
        this->_tools->myError("setMemory()");
}

void                MyProcess::setLastAddress() {
    this->_lastAddress = this->_address;
}

bool                MyProcess::readWhileProcessMemory() {
    this->_address = (BYTE*)this->_address + 1;
    if (this->readProcessMemory(this->_address))
        return (true);
    else
        return (false);
}

bool                MyProcess::readLastProcessMemory() {
    if (this->readProcessMemory(this->_lastAddress))
        return (true);
    else
        return (false);
}

bool                MyProcess::readProcessMemory(LPVOID address) {
    if (ReadProcessMemory(this->_process, address, &this->_addressValue, sizeof(this->_addressValue), NULL) != 0)
        return (true);
    else
        return (false);
}

bool                MyProcess::writeProcessMemory(int writed) {
    if (WriteProcessMemory(this->_process, this->_address, &writed, sizeof(writed), NULL) != 0)
        return (true);
    else
        return (false);
}

void                MyProcess::cleanAddressValue() {
    int             i;
    
    i = -1;
    while (++i != 256) {
        this->_addressValue[i] = '\0';
    }
}

void                MyProcess::test() {
    std::cout << this->getNbOfProcess() << std::endl;
    this->setProcessId();
    this->setProcess();
    this->setMemory();
    
    std::cout << this->getNbOfProcess() << std::endl;
    while ((unsigned long long)this->getLastAddress() != 11) {
        this->readWhileProcessMemory();
        //if (this->getAddressValue() == "4200") {
            std::cout << "Address : " << this->getAddress() << " value : " << this->getAddressValue() << std::endl;
            this->writeProcessMemory(11);
            this->setLastAddress();
            this->readLastProcessMemory();
        //}
        this->cleanAddressValue();
    }
}