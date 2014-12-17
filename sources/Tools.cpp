/* 
 * File:   Tools.cpp
 * Author: Sheol
 * 
 * Created on 14 décembre 2014, 03:37
 */

#include "Tools.h"
#include <iostream>

Tools::Tools() {
}

Tools::~Tools() {
}

HWND            Tools::checkProcess() {
    HWND        ret;
    
    std::cout << "Enter process name : ";
    std::cin >> this->_windowTitle;
    ret = FindWindow(NULL, this->_windowTitle.c_str());
    if (ret != NULL) {
        return (ret);
    }
    this->myError("checkProcess()");
    this->checkProcess();
    return (NULL);
}

void            Tools::myError(std::string function) {
    std::cerr << ">> Error on : " << function << " - Code : " << GetLastError() << std::endl;
}

std::string     Tools::getWindowTitle() {
    return (this->_windowTitle);
}