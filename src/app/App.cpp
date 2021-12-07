/*
 * Author: Dawson Dauphinais
 * ddauphin@nmu.edu
 *
 * Date Last Modified: 11/23/2021
 *
 * This file contains the code for the GUI for the main application.
 * */

#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/app/App.h"
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/app/id.h"
#include "C:/Users/dawso/Documents/source/CS480/PersonalFinance_GUI/include/app/MainWindow.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto *MainWin = new MainWindow(nullptr, window::id::MAINWINDOW, wxT("Personal Finance"));
    SetTopWindow(MainWin);
    MainWin->Show(MainWin);
    return true;
}


