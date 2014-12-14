/* 
 * File:   Tools.h
 * Author: Sheol
 *
 * Created on 14 décembre 2014, 03:37
 */

#include <string>
#include <windows.h>

#ifndef TOOLS_H
#define	TOOLS_H

class Tools {
public:
    Tools();
    Tools(const Tools& orig);
    virtual ~Tools();
private:
    std::string         _windowTitle;
public:
    HWND                checkProcess();
    void                myError(std::string);
    std::string         getWindowTitle();
};

#endif	/* TOOLS_H */

