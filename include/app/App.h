/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the definitions of the functions belonging to the myApp class.
 * These functions will be used to construct a GUI for the main application.
 * */

#ifndef PERSONALFINANCE_APP_H
#define PERSONALFINANCE_APP_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif


using namespace std;

class App : public wxApp
{
private:
    wxString pathName;

public:
    void setPathName(wxString path);
    virtual bool OnInit();
    int onExit();
};

#endif //PERSONALFINANCE_APP_H
