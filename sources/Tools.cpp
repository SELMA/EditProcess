/* 
 * File:   Tools.cpp
 * Author: Sheol
 * 
 * Created on 14 décembre 2014, 03:37
 */

#include "Tools.h"
#include <psapi.h>
#include <Oleacc.h>
#include <iostream>

Tools::Tools() : _windowTitle("") {
}

Tools::~Tools() {
}

HWND                Tools::checkProcess() {
    std::cout << "Enter process name : ";
    std::cin >> this->_windowTitle;
    if (EnumWindows((WNDENUMPROC)&this->enumProcess, 0)) {
        return (this->_hwnd);
    }
    this->myError("checkProcess()");
    this->checkProcess();
    return (NULL);
}

void                Tools::setHwnd(std::string title, HWND hwnd) {
    std::cout << title << " = " << this->_windowTitle << std::endl;
    if (title == this->_windowTitle)
        this->_hwnd = hwnd;
}

WINBOOL             Tools::enumProcess(HWND hwnd, LPARAM) {
    char            title[500];
    HANDLE          handle;
    DWORD           lpdwProcessId;
    Tools           *tools = new Tools();
    
    GetWindowThreadProcessId(hwnd, &lpdwProcessId);
    if ((handle = OpenProcess(PROCESS_ALL_ACCESS, false, lpdwProcessId)) != NULL) {
        if (GetModuleBaseName(handle, NULL, title, sizeof(title)) > 0) {
            tools->setHwnd(std::string(title), hwnd);
        }
        CloseHandle(handle);
    }
    return (false);
}

void                Tools::myError(std::string function) {
    std::cerr << ">> Error on : " << function << " - Code : " << GetLastError() << std::endl;
    this->_windowTitle = "";
}

std::string         Tools::getWindowTitle() {
    return (this->_windowTitle);
}