/*
* Author: Dawson Dauphinais
* ddauphin@nmu.edu
*
* Northern Michigan Univeristy
*
* Date Last Modified: 11/30/2021
*
* This file contains the defintions for the main functionality of the application.
*
* -------------------------------------------------------------------------------------
* This application contains software from:
* 
* Title: "JSON for Modern  C++"
* Author: Lohmann, Niels
*           -orchid: https://orcid.org/0000-0001-9037-795X
*           -email: mail@nlohmann.me
*            -website: https://nlohmann.me
*
* Version: 3.10.4
* License: MIT
* Repository-Code: "https://github.com/nlohmann"
* URL: https://json.nlohmann.me
**/

#ifndef PERSONALFINANCE_MAINWINDOW_H
#define PERSONALFINANCE_MAINWINDOW_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include "../include/Account.h"
#include "../include/formulas.h"
#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/wfstream.h>
#include <wx/filedlg.h>
#include <wx/filepicker.h>
#include <nlohmann/json.hpp>

#undef TestFrm_STYLE
#define TestFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX

/// The GUI class.
///
/// This class contains all of the functions that all for the application to run with a GUI.
/// \author Dawson Dauphinais.
class MainWindow : public wxFrame
{

private:
    DECLARE_EVENT_TABLE();

public:
    MainWindow();

    /// Constructor inherited from wxWindow.
    ///
    /// Creates the MainWindow which is inherited from the wxFrame class.
    /// \author Dawson Dauphinais
    MainWindow(wxWindow *parent,
               wxWindowID id,
               const wxString &title,
               const wxPoint &pos = wxDefaultPosition,
               const wxSize &size = wxDefaultSize,
               long style = wxDEFAULT_FRAME_STYLE,
               const wxString &name = wxFrameNameStr);

    /// Sets the name of the path defined by the user's input.
    ///
    /// \param path The path.
    /// \author Dawson Dauphinais
    void setPathName(wxString path);

    /// Returns the name of the path.
    ///
    /// \author Dawson Dauphinais
    wxString getPathName();

    /// On the View Account Button Click.
    ///
    /// \param event The click event.
    /// \author Dawson Dauphinais
    void OnViewAccountClick(wxCommandEvent &event);

    /// On the Account Selected Event.
    ///
    /// \param event The event.
    /// \author Dawson Dauphinais
    void OnAccountSelected(wxCommandEvent &event);

    /// Quits the application.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnQuit(wxCommandEvent &event);

    /// Opens a file.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnNewFile(wxCommandEvent &event);

    /// Opening a file.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnOpenFile(wxCommandEvent &event);

    /// Save file.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnSaveFile(wxCommandEvent &event);

    /// Save file as.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnSaveFileAs(wxCommandEvent &event);

    /// Event when the Exit Button is pressed.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void ExitButtonClick(wxCommandEvent &event);

    /// Event when the Enter Button is clicked.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void EnterButtonClick(wxCommandEvent &event);

    /// Event when the Existing Account Button is pressed.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void UseExistingAcctClick(wxCommandEvent &event);

    /// Event when the Create New Save Data button is clicked.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void CreateNewSaveDataClick(wxCommandEvent &event);

    /// Event when the Submit button is pressed.
    ///
    /// Submits the account information when the user clicks Submit.
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnAccInfoSubmit(wxCommandEvent &event);

    /// Set current panel to the Account Home Panel.
    ///
    /// \author Dawson Dauphinais
    /// \param event the event.
    void OnGoToAccHome(wxCommandEvent &event);

    /// Allows the user to update the current account.
    ///
    /// \param event When the Update Account Button is clicked.
    /// \author Dawson Dauphinais
    /// \see Account::getNameOfAccount() Account::setName() saveData() Account::setBalance() Account::getBalance() Account::addTransaction(Expense e)
    void OnUpdateAccClick(wxCommandEvent &event);

    /// Creates a text dialog that allows the user to set the name of the current account.
    ///
    /// \param event The text dialog event.
    /// \author Dawson Dauphinais
    void OnUpdateName(wxCommandEvent &event);

    /// Creates a text dialog that allows the user to update the account balance.
    ///
    /// \param event The text dialog event.
    /// \author Dawson Dauphinais
    void OnUpdateBalance(wxCommandEvent &event);

    /// Creates a text dialog that allows the user to enter a new transaction.
    ///
    /// \param event The text dialog event(s);
    /// \author Dawson Dauphinais
    void OnUpdateTransactions(wxCommandEvent &event);

    /// Creates a new account.
    ///
    /// \param event When The Create Account click occurs.
    /// \author Dawson Dauphinais
    /// \see Account::setValues(string, Money, map<string, string>)
    void OnCreateNewAccount(wxCommandEvent &event);

    /// Allows the user to switch the account currently being used.
    ///
    /// \param event When the Switch Account Button is clicked.
    /// \author Dawson Dauphinais
    /// \see fromJSON(nlohmann::json, Account, string)
    void OnSwitchAccount(wxCommandEvent &event);

    void OnToolsBtnClick(wxCommandEvent &event);

    void OnLoanCalculatorClick(wxCommandEvent &event);

    void OnCreditCardClick(wxCommandEvent &event);

    void OnDoubleInvestmentClick(wxCommandEvent &event);

    void OnLeverageRatioClick(wxCommandEvent &event);

    void OnAverageGrowthClick(wxCommandEvent &event);

    void OnNowOrLater(wxCommandEvent &event);

    void OnViewCashFlow(wxCommandEvent &event);

    void OnAddIncome(wxCommandEvent &event);

    void OnHomeFromViewPanel(wxCommandEvent &event);

    virtual ~MainWindow();

private:
    std::map<string, Account> accountMap;
    wxString pathName;

    wxPanel *LoadOptionsPanel;
    wxButton *ExitButton;
    wxButton *EnterButton;
    wxStaticText *TitleText2;

    wxButton *NextPageButtonExistingAcc;

    wxStaticText *TitleText;
    wxPanel *TitlePanel;
    wxTextCtrl *MainEditBox;
    wxButton *CreateNewAccountBtn;
    wxButton *LoadSaveDataBtn;
    wxMenuBar *MainMenu;
    wxFileDialog *ChooseFileDialog;
    wxPanel *ExistingAccountsPanel;
    wxSingleChoiceDialog *ChooseAccount;
    wxArrayString arrOfAccs;

    wxButton *SubmitAccountInfo;

    wxPanel *CreateAccountPanel;

    wxTextCtrl *EnterFileNameTextCtrl;
    wxTextCtrl *EnterNameAcctTextCtrl;
    wxTextCtrl *EnterBalanceTextCtrl;

    wxDirPickerCtrl *InitialFileSaveDir;

    wxString SAVE_DIR;

    // Main Options Panel Components
    wxPanel *MainOptionsPanel;
    wxButton *ToolsBtn;
    wxButton *ExitBtnMainPanel;
    wxButton *SwitchAccountsBtn;
    wxButton *CreateNewAccBtn;
    wxButton *UpdateAccountBtn;
    wxButton *ViewAccountBtn;
    wxStaticText *AccountHomeTitle;
    wxStaticText *AccountNameHomeTitle;

    // View Account Panel Components
    bool canUpdateGrid = true;
    wxPanel *ViewAccountPanel;
    wxGrid *TransactionsGrid;
    wxGrid *IncomeGrid;
    wxStaticBox *IncomeHistoryBox;
    wxStaticBox *TransactionsBox;
    wxStaticText *AccName;    // these two variables can probably be reused
    wxStaticText *AccBalance; //
    string *transName;
    string *transPrice;
    string *transRecurring;
    string *transDate;
    string *incomeVals;
    string *incomeDates;
    wxButton *GoBackViewBtn;

    //Update Account Panel Components
    wxPanel *UpdateAccountPanel;
    wxStaticText *UpdateAccTitleText;
    wxButton *ChangeAccNameBtn;
    wxButton *UpdateBalanceBtn;
    wxButton *UpdateTransactionsButton;
    wxButton *ReturnToHomeBtn;
    wxStaticText *Title_UpdateAcc;
    wxTextEntryDialog *EnterNewNameDialog;
    wxTextEntryDialog *EnterNewBalanceDialog;
    wxTextEntryDialog *EnterExpenseName;
    wxTextEntryDialog *EnterExpensePrice;
    wxTextEntryDialog *EnterExpenseDate;
    wxTextEntryDialog *EnterExpenseRecurring;
    wxTextEntryDialog *CreateAcc_NAME;
    wxTextEntryDialog *CreateAcc_BAL;

    //Tools Panel Components;
    wxPanel *ToolsPanel;
    wxButton *AccHomeFromToolsBtn;

    wxButton *LoanCalculatorBtn;
    wxTextEntryDialog *LoanCalculatorAmt;
    wxTextEntryDialog *LoanCalculatorInterest;
    wxTextEntryDialog *LoanCalculatorTerm;
    wxMessageDialog *LoanCalculatorAns;

    wxButton *CreditCardBtn;
    wxTextEntryDialog *CreditCardBalance;
    wxTextEntryDialog *CreditCardPayment;
    wxTextEntryDialog *CreditCardInterest;
    wxMessageDialog *CreditCardAns;

    wxButton *DoubleInvestmentBtn;
    wxTextEntryDialog *DoubleInvestmentRate;
    wxMessageDialog *DoubleInvestmentAns;

    wxButton *LeverageRatioBtn;
    wxTextEntryDialog *LeverageRatioDebts;
    wxMessageDialog *LeverageRatioAns;

    wxButton *AvgGrowthRateBtn;
    wxTextEntryDialog *AvgGrowthInitVal;
    wxTextEntryDialog *AvgGrowthFinalVal;
    wxTextEntryDialog *AvgGrowthYears;
    wxMessageDialog *AvgGrowthAns;

    wxButton *NowOrLaterBtn;
    wxTextEntryDialog *NowOrLaterPrice;
    wxTextEntryDialog *NowOrLaterInterest;
    wxTextEntryDialog *NowOrLaterPayments;
    wxMessageDialog *NowOrLaterAns;

    wxButton *ViewCashFlowBtn;
    wxMessageDialog *CashFlowDialog;

    wxButton *AddIncomeBtn;
    wxTextEntryDialog *AddIncomeIncome;
    wxTextEntryDialog *AddIncomeDate;
    wxMessageDialog *AddIncomeAns;

    wxStaticText *ToolsText;

    Account MAIN_ACCOUNT;
    nlohmann::json data;

    /// Loads the Account data from the specified JSON file.
    ///
    /// \param j The JSON object to store the data in.
    /// \param fileFound is set to true if the specified file is found.
    /// \author Dawson Dauphinais
    void loadAccountData(nlohmann::json &j, bool &fileFound);

    void loadAccountData(nlohmann::json &j);

    /// Generates a list of currently available accounts to choose from.
    ///
    /// Parses the JSON data for names of accounts and then returns them.
    /// \param data The JSON object containing the account data.
    /// \author Dawson Dauphinais
    wxArrayString generateCurrentAccountsList(nlohmann::json &data);

    /// Fills the map of account objects with accounts that are generated from the JSON file.
    ///
    /// \param accMap the map of the accounts.
    /// \param data the data to parse for account information.
    /// \author Dawson Dauphinais
    /// \see fromJSON(nlohmann::json, string)
    void generateAccountMapFromJSON(std::map<string, Account> &accMap, nlohmann::json data);

    Account fromJSON(nlohmann::json &j, const std::string &nameOf);


    /// Converts JSON into an Account object.
    ///
    /// \param j The JSON object containing the Account information.
    /// \param acc The Account object to store the data in.
    /// \param nameOf The name of the Account.
    /// \author Dawson Dauphinais
    void fromJSON(const nlohmann::json &j, Account &acc, const string &nameOf);

    /// Converts Account object(s) into JSON object(s).
    ///
    /// \param j The JSON object.
    /// \param accs The map of Account objects.
    /// \author Dawson Dauphinais
    void toJSON(nlohmann::json &j, std::map<string, Account> accs);

    /// Creates an initial save for the account.
    ///
    /// \note This is different than saveData(std::map<string, Account>), as it only creates an initial save.
    /// \param j The JSON object containing the account information to be saved.
    /// \author Dawson Dauphinais
    void saveInit(nlohmann::json &j);

    /// Saves the current account information.
    ///
    /// \note This is different than saveInit(nlohmann::json). While it does perform similar operations, this one is for any account.
    /// \param accounts The map containing the accounts.
    /// \author Dawson Dauphinais
    void saveData(std::map<string, Account> accounts);

    /// Close the application.
    ///
    /// \param event The event that the close button is clicked.
    void OnClose(wxCloseEvent &event);

    /// Creates the different elements of the GUI.
    ///
    /// \author Dawson Dauphinais
    void CreateGUIControls();

    /// Initializes the Grids for Viewing Account Info.
    ///
    /// \author Dawson Dauphinais
    void initializeAccountGrid();
};

enum
{
    TEXT_Main = wxID_HIGHEST + 1,
    MENU_New,
    MENU_Open,
    MENU_Save,
    MENU_SaveAs,
    MENU_Quit,
    ID_ACCOUNTSPANEL,
    ID_ENTERBUTTON,
    ID_TITLETEXT,
    ID_TITLEPANEL,
    ID_CREATESAVEBTN,
    ID_LOADSAVEBTN,
    ID_EXISTINGACCOUNTSPANEL,
    ID_FOUNDACCOUNTCHOICES,
    ID_NEXTPAGECHOOSEACCBTN,
    ID_CREATEACCTPANEL,
    TEXT_NAMEACCT,
    TEXT_ACCTBALANCE,
    TEXT_FILENAME,
    BTN_SUBMITACCINFO,
    DIRP_SAVELOC,
    ID_MAINOPTIONSPANEL,

    //Main Options Panel ENUMS
    BTN_TOOLSBTN,
    BTN_EXITMAINPANEL,
    BTN_SWITCHACCBTN,
    BTN_CREATENEWACCBTN,
    BTN_UPDATEACCBTN,
    BTN_VIEWACCBTN,
    TEXT_ACCOUNTHOMETITLE,
    TEXT_ACCOUNTNAMEHOMETITLE,

    //View Account Panel
    ID_VIEWACCPANEL,
    ID_INCOMELISTV,
    ID_TRANSACTIONSV,
    ID_INCOMEHISTORYBOX,
    ID_TRANSACTIONSBOX,
    ID_CURRACCNAME,
    ID_CURRBALANCE,
    BTN_HOMEFROMVIEW,
    BTN_GOACCHOME,

    //update account panel
    ID_UPDATEACCPANEL,
    TEXT_UPDATETITLETXT,
    BTN_UPDATENAME,
    BTN_UPDATEBALANCE,
    BTN_UPDATETRANS,
    BTN_CREATENEWACC,
    BTN_RETURNHOMEFROMUPDATEACC,

    //Tools Panel
    BTN_LOANCALCULATOR,
    BTN_CREDITCARDBTN,
    BTN_DOUBLEINVESTMENTBTN,
    BTN_LEVERAGERATIOBTN,
    BTN_AVGGROWTHRATE,
    BTN_NOWORLATER,
    BTN_VIEWCASHFLOW,
    BTN_ADDINCOME,
    TEXT_TOOLSTEXT
};

#endif //PERSONALFINANCE_MAINWINDOW_H
