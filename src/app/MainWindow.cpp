/*
* Author: Dawson Dauphinais
* ddauphin@nmu.edu
*
* Northern Michigan University
* Date Last Modified: 12/06/2021
*
* This file contains the implementations of the functions defined in MainWindow.h
*/
#include "app/MainWindow.h"

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(MENU_Save, MainWindow::OnSaveFile)
EVT_CHOICE(ID_FOUNDACCOUNTCHOICES, MainWindow::OnAccountSelected)
EVT_MENU(MENU_Quit, MainWindow::OnQuit)
EVT_BUTTON(wxID_CLOSE, MainWindow::ExitButtonClick)
EVT_BUTTON(ID_ENTERBUTTON, MainWindow::EnterButtonClick)
EVT_BUTTON(ID_LOADSAVEBTN, MainWindow::UseExistingAcctClick)
EVT_BUTTON(ID_CREATESAVEBTN, MainWindow::CreateNewSaveDataClick)
EVT_BUTTON(BTN_SUBMITACCINFO, MainWindow::OnAccInfoSubmit)
EVT_BUTTON(BTN_VIEWACCBTN, MainWindow::OnViewAccountClick)
EVT_BUTTON(BTN_GOACCHOME, MainWindow::OnGoToAccHome)
EVT_BUTTON(BTN_UPDATEACCBTN, MainWindow::OnUpdateAccClick)
EVT_BUTTON(BTN_UPDATENAME, MainWindow::OnUpdateName)
EVT_BUTTON(BTN_UPDATEBALANCE, MainWindow::OnUpdateBalance)
EVT_BUTTON(BTN_UPDATETRANS, MainWindow::OnUpdateTransactions)
EVT_BUTTON(BTN_HOMEFROMVIEW, MainWindow::OnHomeFromViewPanel)
EVT_BUTTON(BTN_CREATENEWACCBTN, MainWindow::OnCreateNewAccount)
EVT_BUTTON(BTN_SWITCHACCBTN, MainWindow::OnSwitchAccount)
EVT_BUTTON(BTN_TOOLSBTN, MainWindow::OnToolsBtnClick)
EVT_BUTTON(BTN_LOANCALCULATOR, MainWindow::OnLoanCalculatorClick)
EVT_BUTTON(BTN_CREDITCARDBTN, MainWindow::OnCreditCardClick)
EVT_BUTTON(BTN_DOUBLEINVESTMENTBTN, MainWindow::OnDoubleInvestmentClick)
EVT_BUTTON(BTN_LEVERAGERATIOBTN, MainWindow::OnLeverageRatioClick)
EVT_BUTTON(BTN_AVGGROWTHRATE, MainWindow::OnAverageGrowthClick)
EVT_BUTTON(BTN_NOWORLATER, MainWindow::OnNowOrLater)
EVT_BUTTON(BTN_VIEWCASHFLOW, MainWindow::OnViewCashFlow)
EVT_BUTTON(BTN_ADDINCOME, MainWindow::OnAddIncome)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                       long style, const wxString &name) : wxFrame(parent, id, title, pos, size, style, name)
{

    CreateGUIControls();
    MainMenu = new wxMenuBar();
    //    wxPanel *panel = new wxPanel(this, -1);

    auto *FileMenu = new wxMenu();

    // FileMenu->Append(MENU_New,
    //                  wxT("&New"), wxT("Create a new file"));
    // FileMenu->Append(MENU_Open,
    //                  wxT("&Open"), wxT("Open an existing file"));
    FileMenu->Append(MENU_Save,
                     wxT("&Save"), wxT("Save the current document"));
    // FileMenu->Append(MENU_SaveAs,
    //                  wxT("Save &As"), wxT("Save the current document under a new file name"));
    FileMenu->AppendSeparator();
    FileMenu->Append(MENU_Quit,
                     wxT("&Quit"), wxT("Quit the program"));

    MainMenu->Append(FileMenu,
                     wxT("File"));
    SetMenuBar(MainMenu);
}

void MainWindow::CreateGUIControls()
{

    //************************
    //TitlePanel Components
    TitlePanel = new wxPanel(this, ID_TITLEPANEL, wxPoint(0, 0), wxSize(638, 615));
    TitleText = new wxStaticText(TitlePanel, ID_TITLETEXT, _("Personal Finance System"), wxPoint(165, 155), wxDefaultSize, wxALIGN_CENTRE, _("TitleText"));
    TitleText->SetFont(wxFont(18, wxSWISS, wxITALIC, wxBOLD, false, _("Palatino Linotype")));
    EnterButton = new wxButton(TitlePanel, ID_ENTERBUTTON, _("Enter"), wxPoint(245, 273), wxSize(88, 35), 0, wxDefaultValidator, _("EnterButton"));
    ExitButton = new wxButton(TitlePanel, wxID_CLOSE, _("Exit"), wxPoint(245, 333), wxSize(88, 35), 0, wxDefaultValidator, _("ExitButton"));

    //******************************
    //LoadOptionsPanel Components
    LoadOptionsPanel = new wxPanel(this, ID_ACCOUNTSPANEL, wxPoint(0, 0), wxSize(638, 615));
    LoadSaveDataBtn = new wxButton(LoadOptionsPanel, ID_LOADSAVEBTN, _("Load Save Data"), wxPoint(245, 250), wxSize(125, 50), 0, wxDefaultValidator, _("UseExistingAcctBtn"));
    CreateNewAccountBtn = new wxButton(LoadOptionsPanel, ID_CREATESAVEBTN, _("Create New Save"), wxPoint(245, 310), wxSize(125, 50), 0, wxDefaultValidator, _("CreateNewAccountBtn"));
    TitleText2 = new wxStaticText(LoadOptionsPanel, ID_TITLETEXT, _("Personal Finance System"), wxPoint(165, 155), wxDefaultSize, wxALIGN_CENTRE, _("TitleText2"));
    TitleText2->SetFont(wxFont(18, wxSWISS, wxITALIC, wxBOLD, false, _("Palatino Linotype")));
    LoadOptionsPanel->Show(false);

    //****************
    //ExistingAccountsPanel
    // ExistingAccountsPanel = new wxPanel(this, ID_EXISTINGACCOUNTSPANEL, wxPoint(0, 0), wxSize(638, 615));
    // ExistingAccountsPanel->Show(false);

    // NextPageButtonExistingAcc = new wxButton(ExistingAccountsPanel, ID_NEXTPAGECHOOSEACCBTN, _("Next"), wxPoint(364, 325), wxSize(75, 25), 0, wxDefaultValidator, _("NextPageButton"));
    // NextPageButtonExistingAcc->Show(false);

    //CreateAccountPanel Components
    CreateAccountPanel = new wxPanel(this, ID_CREATEACCTPANEL, wxPoint(0, 0), wxSize(638, 615));
    CreateAccountPanel->Show(false);

    EnterNameAcctTextCtrl = new wxTextCtrl(CreateAccountPanel, TEXT_NAMEACCT, "Name of Account", wxPoint(450, 150), wxDefaultSize, wxTE_LEFT | wxTE_RICH2, wxDefaultValidator, wxTextCtrlNameStr);
    EnterBalanceTextCtrl = new wxTextCtrl(CreateAccountPanel, TEXT_ACCTBALANCE, "Balance", wxPoint(450, 200), wxDefaultSize, wxTE_LEFT | wxTE_RICH2, wxDefaultValidator, wxTextCtrlNameStr);
    EnterFileNameTextCtrl = new wxTextCtrl(CreateAccountPanel, TEXT_FILENAME, "File Name", wxPoint(450, 250), wxDefaultSize, wxTE_LEFT | wxTE_RICH2, wxDefaultValidator, wxTextCtrlNameStr);
    SubmitAccountInfo = new wxButton(CreateAccountPanel, BTN_SUBMITACCINFO, _("Submit"), wxPoint(425, 400), wxSize(72, 25), 0, wxDefaultValidator, _("SubmitAccountInfo"));
    InitialFileSaveDir = new wxDirPickerCtrl(CreateAccountPanel, DIRP_SAVELOC, _(""), _("Select a folder"), wxPoint(450, 350), wxSize(185, 25), wxDIRP_DEFAULT_STYLE, wxDefaultValidator, _("InitialFileSaveDir"));

    // **********************
    // MainOptionsPanel Components
    MainOptionsPanel = new wxPanel(this, ID_MAINOPTIONSPANEL, wxPoint(0, 0), wxSize(638, 615));

    AccountHomeTitle = new wxStaticText(MainOptionsPanel, TEXT_ACCOUNTHOMETITLE, _("Account Home"), wxPoint(225, 40), wxDefaultSize, wxALIGN_CENTRE, _("AccountHomeTitle"));
    AccountHomeTitle->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxBOLD, false, _("Palatino Linotype")));

    AccountNameHomeTitle = new wxStaticText(MainOptionsPanel, TEXT_ACCOUNTNAMEHOMETITLE, wxEmptyString, wxPoint(225, 100), wxDefaultSize, wxALIGN_CENTER, _("AccountNameHomeTitle"));
    AccountNameHomeTitle->SetFont(wxFont(16, wxSWISS, wxITALIC, wxBOLD, false, _("Palatino Linotype")));

    ViewAccountBtn = new wxButton(MainOptionsPanel, BTN_VIEWACCBTN, _("View Account"), wxPoint(155, 165), wxSize(120, 55), 0, wxDefaultValidator, _("ViewAccountBtn"));
    UpdateAccountBtn = new wxButton(MainOptionsPanel, BTN_UPDATEACCBTN, _("Update Account"), wxPoint(347, 165), wxSize(120, 55), 0, wxDefaultValidator, _("UpdateAccountBtn"));
    CreateNewAccBtn = new wxButton(MainOptionsPanel, BTN_CREATENEWACCBTN, _("Create Account"), wxPoint(155, 250), wxSize(120, 55), 0, wxDefaultValidator, _("CreateNewAccBtn"));
    SwitchAccountsBtn = new wxButton(MainOptionsPanel, BTN_SWITCHACCBTN, _("Switch Accounts"), wxPoint(347, 250), wxSize(120, 55), 0, wxDefaultValidator, _("SwitchAccountsBtn"));
    ExitBtnMainPanel = new wxButton(MainOptionsPanel, wxID_CLOSE, _("Exit"), wxPoint(155, 355), wxSize(120, 55), 0, wxDefaultValidator, _("ExitBtnMainPanel"));
    ToolsBtn = new wxButton(MainOptionsPanel, BTN_TOOLSBTN, _("Tools"), wxPoint(347, 355), wxSize(120, 55), 0, wxDefaultValidator, _("ToolsBtn"));

    MainOptionsPanel->Show(false);

    //******************************
    // View Account Panel Components

    //************************************
    // Update Account Panel Components
    UpdateAccountPanel = new wxPanel(this, ID_UPDATEACCPANEL, wxPoint(0, 0), wxSize(638, 615));

    UpdateAccTitleText = new wxStaticText(UpdateAccountPanel, TEXT_UPDATETITLETXT, _("Update Account"), wxPoint(225, 40), wxDefaultSize, 0, _("UpdateAccTitleText"));
    UpdateAccTitleText->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false, _("Palatino Linotype")));

    ChangeAccNameBtn = new wxButton(UpdateAccountPanel, BTN_UPDATENAME, _("Change Account Name"), wxPoint(165, 190), wxSize(138, 155), 0, wxDefaultValidator, _("ChangeAccNameBtn"));
    UpdateBalanceBtn = new wxButton(UpdateAccountPanel, BTN_UPDATEBALANCE, _("Update Balance"), wxPoint(315, 190), wxSize(138, 155), 0, wxDefaultValidator, _("UpdateBalanceBtn"));
    UpdateTransactionsButton = new wxButton(UpdateAccountPanel, BTN_UPDATETRANS, _("Add Transaction(s)"), wxPoint(165, 360), wxSize(138, 155), 0, wxDefaultValidator, _("UpdateTransactionsButton"));
    ReturnToHomeBtn = new wxButton(UpdateAccountPanel, BTN_GOACCHOME, _("Return to Account Home"), wxPoint(315, 360), wxSize(138, 155), 0, wxDefaultValidator, _("ReturnToHomeBtn"));

    UpdateAccountPanel->Show(false);

    //*******************************************
    // Tools Panel
    ToolsPanel = new wxPanel(this, ID_UPDATEACCPANEL, wxPoint(0, 0), wxSize(638, 615));

    AccHomeFromToolsBtn = new wxButton(ToolsPanel, BTN_GOACCHOME, _("Account Home"), wxPoint(250, 506), wxSize(124, 66), 0, wxDefaultValidator, _("AccHomeFromToolsBtn"));
    AccHomeFromToolsBtn->SetToolTip(_("Return to the account home page."));

    LoanCalculatorBtn = new wxButton(ToolsPanel, BTN_LOANCALCULATOR, _("Loan Calculator"), wxPoint(347, 408), wxSize(124, 66), 0, wxDefaultValidator, _("LoanCalculatorBtn"));
    LoanCalculatorBtn->SetToolTip(_("Calculates the monthly payment given a loan amount."));

    CreditCardBtn = new wxButton(ToolsPanel, BTN_CREDITCARDBTN, _("Credit Card Calculator"), wxPoint(155, 408), wxSize(124, 66), 0, wxDefaultValidator, _("CreditCardBtn"));
    CreditCardBtn->SetToolTip(_("Calculates how long it will take to pay off a credit card (in months)."));

    DoubleInvestmentBtn = new wxButton(ToolsPanel, BTN_DOUBLEINVESTMENTBTN, _("Double an Investment"), wxPoint(347, 310), wxSize(124, 66), 0, wxDefaultValidator, _("DoubleInevstmentBtn"));
    DoubleInvestmentBtn->SetToolTip(_("Calculates how many years (roughly) it will take to double an investment."));

    LeverageRatioBtn = new wxButton(ToolsPanel, BTN_LEVERAGERATIOBTN, _("Leverage Ratio"), wxPoint(155, 310), wxSize(124, 66), 0, wxDefaultValidator, _("LeverageRatioBtn"));
    LeverageRatioBtn->SetToolTip(_("Determines the leverage ratio of the current account."));

    AvgGrowthRateBtn = new wxButton(ToolsPanel, BTN_AVGGROWTHRATE, _("Average Growth Rate"), wxPoint(347, 212), wxSize(124, 66), 0, wxDefaultValidator, _("AvgGrowthRateBtn"));
    AvgGrowthRateBtn->SetToolTip(_("Determines the compound annual growth rate of an investment."));

    NowOrLaterBtn = new wxButton(ToolsPanel, BTN_NOWORLATER, _("Now Or Later?"), wxPoint(155, 212), wxSize(124, 66), 0, wxDefaultValidator, _("NowOrLaterBtn"));
    NowOrLaterBtn->SetToolTip(_(" Answers the question: \"should you take $x payments each year for y years, or a lump sum of $z in y years.\""));

    ViewCashFlowBtn = new wxButton(ToolsPanel, BTN_VIEWCASHFLOW, _("View Cash Flow"), wxPoint(347, 114), wxSize(124, 66), 0, wxDefaultValidator, _("ViewCashFlowBtn"));
    ViewCashFlowBtn->SetToolTip(_("View this account's cash flow."));

    AddIncomeBtn = new wxButton(ToolsPanel, BTN_ADDINCOME, _("Add Income"), wxPoint(155, 114), wxSize(124, 66), 0, wxDefaultValidator, _("AddIncomeBtn"));
    AddIncomeBtn->SetToolTip(_("Add income to the current account."));

    ToolsText = new wxStaticText(ToolsPanel, TEXT_TOOLSTEXT, _("Tools"), wxPoint(275, 33), wxDefaultSize, wxALIGN_CENTRE, _("ToolsText"));
    ToolsText->SetFont(wxFont(20, wxSWISS, wxNORMAL, wxBOLD, false, _("Palatino Linotype")));

    ToolsPanel->Show(false);
    SetTitle(_("Personal Finance System"));
    SetIcon(wxNullIcon);
    SetSize(234, 67, 650, 650);
    Center();
}

void MainWindow::initializeAccountGrid()
{

    //******************************
    // ViewAccountPanel Components
    ViewAccountPanel = new wxPanel(this, ID_VIEWACCPANEL, wxPoint(0, 0), wxSize(638, 615));
    ViewAccountPanel->Show(false);

    AccName = new wxStaticText(ViewAccountPanel, ID_CURRACCNAME, wxEmptyString, wxPoint(24, 30), wxDefaultSize, 0, _("AccName"));
    AccName->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, _("Palatino Linotype")));

    AccBalance = new wxStaticText(ViewAccountPanel, ID_CURRBALANCE, wxEmptyString, wxPoint(24, 100), wxDefaultSize, 0, _("AccBalance"));
    AccBalance->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false, _("Palatino Linotype")));

    TransactionsBox = new wxStaticBox(ViewAccountPanel, ID_TRANSACTIONSBOX, _("Transactions"), wxPoint(22, 150), wxSize(270, 430));
    TransactionsGrid = new wxGrid(ViewAccountPanel, ID_TRANSACTIONSV, wxPoint(24, 175), wxSize(265, 400));
    TransactionsGrid->SetDefaultColSize(75);
    TransactionsGrid->SetDefaultRowSize(25);
    TransactionsGrid->SetRowLabelSize(70);
    TransactionsGrid->SetColLabelSize(25);

    IncomeHistoryBox = new wxStaticBox(ViewAccountPanel, ID_INCOMEHISTORYBOX, _("Income History"), wxPoint(320, 150), wxSize(270, 430));
    IncomeGrid = new wxGrid(ViewAccountPanel, ID_INCOMELISTV, wxPoint(322, 175), wxSize(265, 400));
    IncomeGrid->SetDefaultColSize(75);
    IncomeGrid->SetDefaultRowSize(25);
    IncomeGrid->SetRowLabelSize(75);
    IncomeGrid->SetColLabelSize(25);

    GoBackViewBtn = new wxButton(ViewAccountPanel, BTN_HOMEFROMVIEW, _("Home"), wxPoint(462, 36), wxSize(122, 104), 0, wxDefaultValidator, _("GoBackViewBtn"));

    std::map<string, string>::iterator it;

    std::map<string, string> iList = MAIN_ACCOUNT.getIncomeList();
    auto numIncomes = 0;

    std::map<string, string> tList = MAIN_ACCOUNT.getTransactions();
    auto numTransactions = 0;

    int ct = 0;
    for (it = iList.begin(); it != iList.end(); ++it)
    {
        numIncomes++;
    }
    for (it = tList.begin(); it != tList.end(); ++it)
    {
        numTransactions++;
    }

    transName = new string[numTransactions];
    transPrice = new string[numTransactions];
    transRecurring = new string[numTransactions];
    transDate = new string[numTransactions];
    std::map<string, string> reccurring = MAIN_ACCOUNT.getRecurringList();
    for (it = tList.begin(); it != tList.end(); ++it)
    {
        std::map<string, string>::iterator recIt;
        string nm, prc, rec, dt;
        nm = it->first.substr(0, it->first.find('/'));
        dt = it->first.substr(it->first.find('/') + 1, it->first.length() - 1);
        recIt = reccurring.find(it->first);
        if (recIt != reccurring.end())
        {
            rec = "TRUE";
        }
        else
        {
            rec = "FALSE";
        }
        prc = Money::toString(Money(it->second));
        string mo = dt.substr(0, 2);
        string day = dt.substr(2, 2);
        string yr = dt.substr(4, 4);
        transName[ct] = nm;
        transPrice[ct] = prc;
        transRecurring[ct] = rec;
        transDate[ct] = mo + "-" + day + "-" + yr;
        ct++;
    }
    ct = 0;

    incomeVals = new string[numIncomes];
    incomeDates = new string[numIncomes];
    for (it = iList.begin(); it != iList.end(); ++it)
    {
        if (it->first == "Initial")
        {
            incomeDates[ct] = it->first;
        }
        else
        {
            string mo = it->first.substr(0, 2);
            string day = it->first.substr(2, 2);
            string yr = it->first.substr(4, 4);
            incomeDates[ct] = mo + "-" + day + "-" + yr;
        }
        incomeVals[ct] = it->second;
        ct++;
    }

    IncomeGrid->CreateGrid(numIncomes, 2, wxGrid::wxGridSelectNone);
    IncomeGrid->SetColLabelValue(0, _("Amount"));
    IncomeGrid->SetColLabelValue(1, _("Date Received"));
    IncomeGrid->SetColSize(1, 122);

    // populate the grids

    for (auto i = 0; i < numIncomes; i++)
    {
        for (auto j = 0; j < 2; j++)
        {
            IncomeGrid->SetCellValue(i, 0, wxString(incomeVals[i]));
            IncomeGrid->SetCellValue(i, 1, wxString(incomeDates[i]));
        }
    }

    TransactionsGrid->CreateGrid(numTransactions, 4, wxGrid::wxGridSelectNone);
    TransactionsGrid->SetColLabelValue(0, _("Name"));
    TransactionsGrid->SetColLabelValue(1, _("Price"));
    TransactionsGrid->SetColLabelValue(2, _("Recurring"));
    TransactionsGrid->SetColLabelValue(3, _("Date of Purchase"));
    TransactionsGrid->SetColSize(0, 100);
    TransactionsGrid->SetColSize(1, 75);
    TransactionsGrid->SetColSize(2, 75);
    TransactionsGrid->SetColSize(3, 100);

    for (auto i = 0; i < numTransactions; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            TransactionsGrid->SetCellValue(i, 0, wxString(transName[i]));
            TransactionsGrid->SetCellValue(i, 1, wxString(transPrice[i]));
            TransactionsGrid->SetCellValue(i, 2, wxString(transRecurring[i]));
            TransactionsGrid->SetCellValue(i, 3, wxString(transDate[i]));
        }
    }
}

void MainWindow::setPathName(wxString path)
{
    pathName = path;
}

wxString MainWindow::getPathName()
{
    return pathName;
}

void MainWindow::loadAccountData(nlohmann::json &j)
{
    std::ifstream in(MainWindow::getPathName());
    if (!in.fail())
    {
        in >> j;
    }
}

void MainWindow::loadAccountData(nlohmann::json &j, bool &fileFound)
{
    std::ifstream in(pathName.ToStdString());
    if (!in.fail())
    {
        fileFound = true;
        in >> j;
    }
}

wxArrayString MainWindow::generateCurrentAccountsList(nlohmann::json &data)
{
    wxArrayString arr;
    std::map<string, Account> mp;
    MainWindow::generateAccountMapFromJSON(mp, data);
    std::map<string, Account>::iterator it;
    for (it = mp.begin(); it != mp.end(); ++it)
    {
        arr.Add(_(it->first));
    }
    return arr;
}

void MainWindow::generateAccountMapFromJSON(std::map<string, Account> &accMap, nlohmann::json data)
{
    for (nlohmann::json::iterator it = data["accounts"].begin(); it != data["accounts"].end(); ++it)
    {
        nlohmann::json j = it.value();
        const string &s = it.key();
        accMap[s] = MainWindow::fromJSON(j, s);
    }
}

Account MainWindow::fromJSON(nlohmann::json &j, const std::string &nameOf)
{
    Account acc;
    acc.setName(j["name"]);
    std::string bTmp = j["balance"];
    acc.setBalance(Money(bTmp));
    acc.setTransactions(j["transactions"]);
    acc.setRecurringList(j["recurring_transactions"]);
    acc.setIncomeList(j["income"]);
    return acc;
}

void MainWindow::fromJSON(const nlohmann::json &j, Account &acc, const std::string &nameOf)
{
    nlohmann::json accInfo = j["accounts"][nameOf];
    acc.setName(accInfo.at("name"));
    std::string bTmp = accInfo.at("balance");
    acc.setBalance(Money(bTmp));
    acc.setTransactions(accInfo.at("transactions"));
    acc.setRecurringList(accInfo.at("recurring_transactions"));
    acc.setIncomeList(accInfo.at("income"));
}

void MainWindow::toJSON(nlohmann::json &j, std::map<string, Account> accs)
{
    std::map<string, Account>::iterator it;
    for (it = accs.begin(); it != accs.end(); ++it)
    {
        nlohmann::json tmp = it->second.toJSON();
        j["accounts"][it->second.getNameOfAccount()] = tmp;
    }
}

void MainWindow::saveInit(nlohmann::json &j)
{
    wxString path = InitialFileSaveDir->GetPath() + R"(\)" + EnterFileNameTextCtrl->GetLineText(0) + ".json";
    MainWindow::setPathName(path);
    // wxMessageBox("path = " + path);
    std::ofstream os(path.ToStdString());
    if (os.is_open())
    {
        os << std::setw(4) << j << std::endl;
        os.flush();
        os.close();
    }
    else
    {
        cerr << "Failed to open file: " << errno << endl;
        exit(-1); // probably should change this so that the program doesn't exit if it can't save the file
    }
}

void MainWindow::saveData(std::map<string, Account> accounts)
{
    nlohmann::json j;
    MainWindow::toJSON(j, std::move(accounts));
    std::ofstream ofs(MainWindow::getPathName());
    if (ofs.is_open())
    {
        ofs << std::setw(4) << j << std::endl;
        ofs.flush();
        ofs.close();
    }
    else
    {
        wxMessageBox("failed to open file for saving.");
        // cerr << "Failed to open file: " << errno << endl;
        exit(-1); // again, probably shouldn't hard exit if the save file doesn't exist.
    }
}

void MainWindow::OnQuit(wxCommandEvent &event)
{
    // wxMessageBox("Goodbye!");
    Close(TRUE);
}

void MainWindow::OnSaveFile(wxCommandEvent &event)
{
    MainWindow::saveData(accountMap);
}

void MainWindow::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void MainWindow::ExitButtonClick(wxCommandEvent &event)
{
    //wxMessageBox("Goodbye!");
    Close(TRUE);
}

void MainWindow::EnterButtonClick(wxCommandEvent &event)
{
    TitlePanel->Show(false);
    LoadOptionsPanel->Show(true);
}

//TODO: Implement Logic to only show this button when no accounts.json file is found
void MainWindow::CreateNewSaveDataClick(wxCommandEvent &event)
{
    LoadOptionsPanel->Show(false);
    MainOptionsPanel->Show(false);
    CreateAccountPanel->Show(true);
    Connect(BTN_SUBMITACCINFO, wxEVT_TEXT, wxCommandEventHandler(MainWindow::OnAccInfoSubmit));
}

void MainWindow::OnUpdateAccClick(wxCommandEvent &event)
{
    MainOptionsPanel->Show(false);
    UpdateAccountPanel->Show(true);
}

void MainWindow::OnAccInfoSubmit(wxCommandEvent &event)
{
    if (!EnterNameAcctTextCtrl->IsModified() || !EnterBalanceTextCtrl->IsModified() || !EnterFileNameTextCtrl->IsModified())
    {
        wxMessageBox("Please fill all fields before submitting.");
    }
    else if (InitialFileSaveDir->GetPath() == "")
    {
        wxMessageBox("Please choose a save directory before continuing.");
    }
    else
    {
        // std::map<string, Account> accMap;
        nlohmann::json j;
        j["accounts"] = nullptr;
        MainWindow::saveInit(j);
        // wxMessageBox("Made it here");
        std::map<string, string> tr;
        std::map<string, string> v;
        wxString name = EnterNameAcctTextCtrl->GetLineText(0);
        wxString balance = EnterBalanceTextCtrl->GetLineText(0);
        // wxMessageBox("Name = " + name + ", Balance = " + balance);
        MAIN_ACCOUNT.setValues(name.ToStdString(), Money(balance.ToStdString()), tr, v);
        Income initial("Initial", Money(balance.ToStdString()));
        MAIN_ACCOUNT.addToIncomeList(initial);
        accountMap[name.ToStdString()] = MAIN_ACCOUNT;
        MainWindow::saveData(accountMap);
        CreateAccountPanel->Show(false);
        // show the main options panel
        AccountNameHomeTitle->SetLabel(MAIN_ACCOUNT.getNameOfAccount());
        MainOptionsPanel->Show(true);
    }
}

//TODO: Implement Logic to only display this button if an accounts.json file is found
void MainWindow::UseExistingAcctClick(wxCommandEvent &event)
{
    LoadOptionsPanel->Show(false);
    bool fileFound;
    ChooseFileDialog = new wxFileDialog(LoadOptionsPanel, _("Choose a file"), _(""), _(""), _("*.json"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (ChooseFileDialog->ShowModal() == wxID_CANCEL)
    {
        return;
    }
    wxString path = ChooseFileDialog->GetPath();
    //  wxMessageBox(pathName); debug -- print path name
    wxFileInputStream ins(path);
    if (!ins.IsOk())
    {
        wxLogError("Cannot open file %s.", path);
    }
    setPathName(path);
    loadAccountData(data, fileFound);
    // ExistingAccountsPanel->Show(true);
    arrOfAccs = MainWindow::generateCurrentAccountsList(data);
    ChooseAccount = new wxSingleChoiceDialog(LoadOptionsPanel, _("Select an account."), _("Single Choice List"), arrOfAccs, NULL, wxOK | wxCENTER);
    auto selection = ChooseAccount->ShowModal();
    if (selection == wxID_OK)
    {
        wxString accName = ChooseAccount->GetStringSelection();
        // wxMessageBox("chose account: " + accName); // debug info to show which account was selected by the user
        // NextPageButtonExistingAcc->Show(true);
        MainWindow::fromJSON(data, MAIN_ACCOUNT, accName.ToStdString());
        MainWindow::generateAccountMapFromJSON(accountMap, data);
        //wxMessageBox("Account Name = " + MAIN_ACCOUNT.getNameOfAccount() + ", Balance = $" + Money::toString(MAIN_ACCOUNT.getBalance()));
        //ExistingAccountsPanel->Show(false);
        // show the main options panel
        AccountNameHomeTitle->SetLabel(MAIN_ACCOUNT.getNameOfAccount());
    }
    MainOptionsPanel->Show(true);

    // Connect(ID_FOUNDACCOUNTCHOICES, wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainWindow::OnAccountSelected));
}

void MainWindow::OnAccountSelected(wxCommandEvent &event)
{
    auto selection = ChooseAccount->ShowModal();
    if (selection != wxID_OK)
    {
        wxMessageBox("Please Select a Valid Choice");
    }
    else
    {
        wxString accName = ChooseAccount->GetStringSelection();
        // wxMessageBox("chose account: " + accName); // debug info to show which account was selected by the user
        NextPageButtonExistingAcc->Show(true);
        MainWindow::fromJSON(data, MAIN_ACCOUNT, accName.ToStdString());
        MainWindow::generateAccountMapFromJSON(accountMap, data);
        //wxMessageBox("Account Name = " + MAIN_ACCOUNT.getNameOfAccount() + ", Balance = $" + Money::toString(MAIN_ACCOUNT.getBalance()));
        //ExistingAccountsPanel->Show(false);
        // show the main options panel
        AccountNameHomeTitle->SetLabel(MAIN_ACCOUNT.getNameOfAccount());
        MainOptionsPanel->Show(true);
    }
}

void MainWindow::OnViewAccountClick(wxCommandEvent &event)
{
    MainOptionsPanel->Show(false);
    // this is probably a short term solution.. will need to figure out a way to detect if the grid should be updated or not.
    // for example, the user might view their account, then update their account, and then view their account again.
    if (canUpdateGrid == true)
    {
        canUpdateGrid = false;
        MainWindow::initializeAccountGrid();
    }

    AccName->SetLabel(MAIN_ACCOUNT.getNameOfAccount());
    AccBalance->SetLabel("Balance: $" + Money::toString(MAIN_ACCOUNT.getBalance()));

    ViewAccountPanel->Show(true);

    //DONT FORGET TO CLEAR UP MEMORY LEAKS
}

void MainWindow::OnSwitchAccount(wxCommandEvent &event)
{
    // TransactionsBox->Destroy();
    // IncomeHistoryBox->Destroy();
    MainOptionsPanel->Show(false);
    saveData(accountMap);
    canUpdateGrid = true;
    loadAccountData(data);
    arrOfAccs = MainWindow::generateCurrentAccountsList(data);
    ChooseAccount = new wxSingleChoiceDialog(LoadOptionsPanel, _("Select an account."), _("Single Choice List"), arrOfAccs, NULL, wxOK | wxCENTER);
    auto selection = ChooseAccount->ShowModal();
    if (selection == wxID_OK)
    {
        wxString accName = ChooseAccount->GetStringSelection();
        // wxMessageBox("chose account: " + accName); // debug info to show which account was selected by the user
        // NextPageButtonExistingAcc->Show(true);
        Account acc = accountMap.at(accName.ToStdString());
        // wxMessageBox("Acc Name" + acc.getNameOfAccount() + ", balance: " + Money::toString(acc.getBalance()));
        // MainWindow::fromJSON(data, MAIN_ACCOUNT, accName.ToStdString());
        //MainWindow::generateAccountMapFromJSON(accountMap, data);
        //wxMessageBox("Account Name = " + MAIN_ACCOUNT.getNameOfAccount() + ", Balance = $" + Money::toString(MAIN_ACCOUNT.getBalance()));
        //ExistingAccountsPanel->Show(false);
        // show the main options panel
        MAIN_ACCOUNT = acc;
        AccountNameHomeTitle->SetLabel(MAIN_ACCOUNT.getNameOfAccount());
    }

    MainOptionsPanel->Show(true);
}

void MainWindow::OnToolsBtnClick(wxCommandEvent &event)
{
    MainOptionsPanel->Show(false);
    ToolsPanel->Show(true);
}

void MainWindow::OnLoanCalculatorClick(wxCommandEvent &event)
{
    Money ans;

    LoanCalculatorAmt = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the loan amount."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    LoanCalculatorInterest = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the interest rate on the loan (i.e 4.56)."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    LoanCalculatorTerm = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the loan term in years."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    wxString p, interestRate, term;

    auto cP = LoanCalculatorAmt->ShowModal();
    if (cP == wxID_OK)
    {
        p = LoanCalculatorAmt->GetValue();
    }

    auto cI = LoanCalculatorInterest->ShowModal();
    if (cI == wxID_OK)
    {
        interestRate = LoanCalculatorInterest->GetValue();
    }

    auto cT = LoanCalculatorTerm->ShowModal();
    if (cT == wxID_OK)
    {
        term = LoanCalculatorTerm->GetValue();
    }

    ans = Formulas::amortization(Money(p.ToStdString()), stod(interestRate.ToStdString()), stoi(term.ToStdString()), 12);

    LoanCalculatorAns = new wxMessageDialog(ToolsPanel, _("Monthly Payment: $" + Money::toString(ans)), _("Result"), wxOK);
    LoanCalculatorAns->ShowModal();
}

void MainWindow::OnDoubleInvestmentClick(wxCommandEvent &event)
{
    string interestRate;
    DoubleInvestmentRate = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the interest rate on the investment (i.e. 4.56)"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto iR = DoubleInvestmentRate->ShowModal();
    if (iR == wxID_OK)
    {
        interestRate = DoubleInvestmentRate->GetValue();
    }
    double ans = Formulas::ruleOfSeventyTwo(stod(interestRate));
    DoubleInvestmentAns = new wxMessageDialog(ToolsPanel, _("It will take roughly " + to_string(ans) + " years for this investment to double in value."), _("Result"), wxOK);
    DoubleInvestmentAns->ShowModal();
}

void MainWindow::OnViewCashFlow(wxCommandEvent &event)
{
    Money income = MAIN_ACCOUNT.getGrossIncome();
    Money expenses = MAIN_ACCOUNT.getTotalFromTransactions();
    Money cashflow = Formulas::cashFlow(income, expenses);
    CashFlowDialog = new wxMessageDialog(ToolsPanel, _("Total Cashflow on account: \"" + MAIN_ACCOUNT.getNameOfAccount() + "\" = $" + Money::toString(cashflow)), _("Result"), wxOK);
    CashFlowDialog->ShowModal();
}

void MainWindow::OnNowOrLater(wxCommandEvent &event)
{
    wxString d, numPayments;
    double interestRate;

    NowOrLaterPrice = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the price of the payment."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto nP = NowOrLaterPrice->ShowModal();
    if (nP == wxID_OK)
    {
        d = NowOrLaterPrice->GetValue();
    }

    NowOrLaterInterest = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the interest rate (i.e. 4.56)"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto nI = NowOrLaterInterest->ShowModal();
    if (nI == wxID_OK)
    {
        wxString s = NowOrLaterInterest->GetValue();
        interestRate = stod(s.ToStdString());
        interestRate /= 100;
    }

    NowOrLaterPayments = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the number of payments to be made."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto nPy = NowOrLaterPayments->ShowModal();
    if (nPy == wxID_OK)
    {
        numPayments = NowOrLaterPayments->GetValue();
    }

    Money payment(d.ToStdString());
    Money ans = Formulas::futureValueOrdinaryAnnuity(payment, interestRate, stoi(numPayments.ToStdString()));

    NowOrLaterAns = new wxMessageDialog(ToolsPanel, _("Based on your input, the future value is: $" + Money::toString(ans)), _("Result"), wxOK);
    NowOrLaterAns->ShowModal();
}

void MainWindow::OnAddIncome(wxCommandEvent &event)
{
    wxString income, date;

    AddIncomeIncome = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the income amount."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto aI = AddIncomeIncome->ShowModal();
    if (aI == wxID_OK)
    {
        income = AddIncomeIncome->GetValue();
    }

    AddIncomeDate = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the date received."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto aD = AddIncomeDate->ShowModal();
    if (aD == wxID_OK)
    {
        date = AddIncomeDate->GetValue();
    }

    Money m(income.ToStdString());
    Income in(date.ToStdString(), m);
    MAIN_ACCOUNT.addIncome(in);
    accountMap[MAIN_ACCOUNT.getNameOfAccount()] = MAIN_ACCOUNT;
    AddIncomeAns = new wxMessageDialog(ToolsPanel, _("Balance Updated! Current balance = $" + Money::toString(MAIN_ACCOUNT.getBalance())), _("Result"), wxOK);
    AddIncomeAns->ShowModal();
    canUpdateGrid = true;
    saveData(accountMap);
}

void MainWindow::OnAverageGrowthClick(wxCommandEvent &event)
{
    wxString init, end, numPeriods;
    AvgGrowthInitVal = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the initial value of the investment."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    auto gI = AvgGrowthInitVal->ShowModal();
    if (gI == wxID_OK)
    {
        init = AvgGrowthInitVal->GetValue();
    }

    AvgGrowthFinalVal = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the final value of the investment."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto gF = AvgGrowthFinalVal->ShowModal();
    if (gF == wxID_OK)
    {
        end = AvgGrowthFinalVal->GetValue();
    }

    AvgGrowthYears = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the number of years on the investment as a whole number."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto gY = AvgGrowthYears->ShowModal();
    if (gY == wxID_OK)
    {
        numPeriods = AvgGrowthYears->GetValue();
    }

    Money i(init.ToStdString());
    Money e(end.ToStdString());
    double ans = Formulas::compoundAnnualGrowthRate(i, e, stoi(numPeriods.ToStdString()));
    AvgGrowthAns = new wxMessageDialog(ToolsPanel, _("Average Growth Rate = " + to_string(ans)), _("Result"), wxOK);
    AvgGrowthAns->ShowModal();
}

void MainWindow::OnLeverageRatioClick(wxCommandEvent &event)
{
    wxString debts;
    Money totalIncome = MAIN_ACCOUNT.getGrossIncome();
    Money liabilities = MAIN_ACCOUNT.getTotalFromTransactions();
    LeverageRatioDebts = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter your total debts tied to this account."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto rD = LeverageRatioDebts->ShowModal();
    if (rD == wxID_OK)
    {
        debts = LeverageRatioDebts->GetValue();
    }

    Money d(debts.ToStdString());

    double ratio = Formulas::leverageRatio(liabilities, d, totalIncome);

    LeverageRatioAns = new wxMessageDialog(ToolsPanel, _("Leverage Ratio = " + to_string(ratio)), _("Result"), wxOK);
    LeverageRatioAns->ShowModal();
    wxMessageBox("REMINDER: THE lower, the better! Anything less than 1.0 is excellent. (This would indicate that you could pay off every debt within your income period!");
}

void MainWindow::OnCreditCardClick(wxCommandEvent &event)
{
    CreditCardBalance = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the current balance on the credit card."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    CreditCardPayment = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the monthly payment being made."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    CreditCardInterest = new wxTextEntryDialog(ToolsPanel, wxEmptyString, _("Enter the interest rate on the credit card (i.e. 4.56)."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);

    wxString balance, monthlyPayment, interestRate;

    auto cB = CreditCardBalance->ShowModal();
    if (cB == wxID_OK)
    {
        balance = CreditCardBalance->GetValue();
    }

    auto cP = CreditCardPayment->ShowModal();
    if (cP == wxID_OK)
    {
        monthlyPayment = CreditCardPayment->GetValue();
    }

    auto cI = CreditCardInterest->ShowModal();
    if (cI == wxID_OK)
    {
        interestRate = CreditCardInterest->GetValue();
    }

    double ans = Formulas::creditCardEquation(Money(balance.ToStdString()), Money(monthlyPayment.ToStdString()), stod(interestRate.ToStdString()));
    if (ans <= 12.0)
    {
        CreditCardAns = new wxMessageDialog(ToolsPanel, _("It will take " + to_string(ans) + " months to pay off this credit card."), _("Result"), wxOK);
        // cout << "It will take " << ans << " months to pay off this credit card." << endl;
    }
    else
    {
        ans /= 12.0;
        CreditCardAns = new wxMessageDialog(ToolsPanel, _("It will take " + to_string(ans) + " years to pay off this credit card."), _("Result"), wxOK);
    }
    CreditCardAns->ShowModal();
}

void MainWindow::OnCreateNewAccount(wxCommandEvent &event)
{
    Account tmpAcc;
    wxString name, balance;
    map<string, string> tran, v;

    CreateAcc_NAME = new wxTextEntryDialog(UpdateAccountPanel, wxEmptyString, _("Enter the name of the new account."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto cName = CreateAcc_NAME->ShowModal();
    if (cName == wxID_OK)
    {
        name = CreateAcc_NAME->GetValue();
    }

    CreateAcc_BAL = new wxTextEntryDialog(UpdateAccountPanel, wxEmptyString, _("Enter the new account's inital balance"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto cBal = CreateAcc_BAL->ShowModal();
    if (cBal == wxID_OK)
    {
        balance = CreateAcc_BAL->GetValue();
    }
    tmpAcc.setValues(name.ToStdString(), Money(balance.ToStdString()), tran, v);
    Income initial("Initial", Money(balance.ToStdString()));
    tmpAcc.addToIncomeList(initial);
    accountMap[name.ToStdString()] = tmpAcc;
    saveData(accountMap);
}

void MainWindow::OnGoToAccHome(wxCommandEvent &event)
{
    // ExistingAccountsPanel->Show(false);
    CreateAccountPanel->Show(false);
    TitlePanel->Show(false);
    LoadOptionsPanel->Show(false);
    UpdateAccountPanel->Show(false);
    ToolsPanel->Show(false);
    MainOptionsPanel->Show(true);
}

void MainWindow::OnHomeFromViewPanel(wxCommandEvent &event){
    ViewAccountPanel->Show(false);
    MainOptionsPanel->Show(true);
}

void MainWindow::OnUpdateName(wxCommandEvent &event)
{
    EnterNewNameDialog = new wxTextEntryDialog(UpdateAccountPanel, _(""), _("Enter the new name of the account."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    string oldName = MAIN_ACCOUNT.getNameOfAccount();
    auto resp = EnterNewNameDialog->ShowModal();
    if (resp == wxID_OK)
    {
        auto newName = EnterNewNameDialog->GetValue();
        MAIN_ACCOUNT.setName(newName.ToStdString());
        wxMessageBox("New Account Name: " + MAIN_ACCOUNT.getNameOfAccount());
        accountMap[oldName] = MAIN_ACCOUNT;
        saveData(accountMap);
        AccountNameHomeTitle->SetLabelText(MAIN_ACCOUNT.getNameOfAccount());
    }
}

void MainWindow::OnUpdateBalance(wxCommandEvent &event)
{
    EnterNewBalanceDialog = new wxTextEntryDialog(UpdateAccountPanel, _(""), _("Enter the new name of the account."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto resp = EnterNewBalanceDialog->ShowModal();
    if (resp == wxID_OK)
    {
        auto nBal = EnterNewBalanceDialog->GetValue();
        MAIN_ACCOUNT.setBalance(Money(nBal.ToStdString()));
        wxMessageBox("New Balance: $" + Money::toString(MAIN_ACCOUNT.getBalance()));
        accountMap[MAIN_ACCOUNT.getNameOfAccount()] = MAIN_ACCOUNT;
        saveData(accountMap);
    }
}

void MainWindow::OnUpdateTransactions(wxCommandEvent &event)
{
    canUpdateGrid = true;
    Expense e;
    EnterExpenseName = new wxTextEntryDialog(UpdateAccountPanel, _(""), _("Enter the name of the expense."), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto nRes = EnterExpenseName->ShowModal();
    if (nRes == wxID_OK)
    {
        auto nm = EnterExpenseName->GetValue();
        e.setName(nm.ToStdString());
    }

    EnterExpensePrice = new wxTextEntryDialog(UpdateAccountPanel, wxEmptyString, _("Enter the price. (IGNORE $ SIGN)"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto prRes = EnterExpensePrice->ShowModal();
    if (prRes == wxID_OK)
    {
        auto pr = EnterExpensePrice->GetValue();
        e.setPrice(Money(pr.ToStdString()));
    }

    EnterExpenseDate = new wxTextEntryDialog(UpdateAccountPanel, wxEmptyString, _("Enter Date of Purchase (MMDDYYYY)"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto dtRes = EnterExpenseDate->ShowModal();
    if (dtRes == wxID_OK)
    {
        auto dt = EnterExpenseDate->GetValue();
        e.setDate(dt.ToStdString());
    }

    EnterExpenseRecurring = new wxTextEntryDialog(UpdateAccountPanel, wxEmptyString, _("Is this a recurring expense? (y/n)"), wxEmptyString, wxOK | wxCANCEL | wxCENTRE);
    auto recRes = EnterExpenseRecurring->ShowModal();
    if (recRes == wxID_OK)
    {
        auto rec = EnterExpenseRecurring->GetValue();
        if (rec.ToStdString() == "y")
        {
            e.setIsRecurring(true);
        }
        else
        {
            e.setIsRecurring(false);
        }
    }
    e.setType("");
    MAIN_ACCOUNT.addTransaction(e);
    accountMap[MAIN_ACCOUNT.getNameOfAccount()] = MAIN_ACCOUNT;
    saveData(accountMap);
}

MainWindow::~MainWindow()
{
    delete[] transName;
    delete[] transPrice;
    delete[] transRecurring;
    delete[] transDate;
    delete[] incomeVals;
    delete[] incomeDates;
}