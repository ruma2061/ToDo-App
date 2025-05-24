// wxWidgets "Hello World" Program
#include <wx/wxprec.h>
#include "app.h"
#include "mainFrame.h"
#include "wx/splitter.h"
#include "wx/colordlg.h"
#include "wx/fontdlg.h"
#include "wx/numdlg.h"
#include "wx/tokenzr.h"

#include"wx/TextCtrl.h"

#include "wx/tooltip.h"

// For compilers that support precompilation, includes "wx/wx.h".
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class myFrame : public wxFrame
{
public:
    myFrame(const wxString &title, const wxPoint &pos,const wxSize &size);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void CreateControls();

    wxFont mainFont;
	wxTextCtrl* inputField;
    wxButton* addButton;
    wxCheckListBox* checkList;
    wxButton* clearButton;

    
};


//----------------------------------------------------------------------
// main()
//----------------------------------------------------------------------

wxIMPLEMENT_APP(myApp); // implements app after this

//----------------------------------------------------------------------
// MyApp
//----------------------------------------------------------------------

enum
{
    ID_Hello = 3

};

bool myApp::OnInit()
{
    myFrame* frame = new myFrame("To-DoApp", wxDefaultPosition, wxDefaultSize);

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append(wxID_UNDO);
    menuEdit->Append(wxID_REDO);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_CUT);
    menuEdit->Append(wxID_COPY);
    menuEdit->Append(wxID_PASTE);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_SELECTALL);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    //Add items to the menu taskbar
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    menuBar->Append(menuHelp, "&Help");

    frame->SetMenuBar(menuBar);

    //Show window frame
    frame->Show(true);

    // Report Success
    return true;
}
// Contructor of the mainFrame class
myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    CreateStatusBar();
    SetStatusText("Running on wxWidgets 3.2.7");

    Bind(wxEVT_MENU, &myFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &myFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &myFrame::OnExit, this, wxID_EXIT);

    CreateControls();


}

void myFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

// void OnAbout is called when user clicks on the "About" Menu taskbar item
void myFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void myFrame::CreateControls()
{
    wxSplitterWindow* splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);

    //Panels in window that appears
    wxPanel* left = new wxPanel(splitter);
    left->SetBackgroundColour(wxColor(200, 100, 100));

    wxPanel* right = new wxPanel(splitter);
    right->SetBackgroundColour(wxColor(100, 200, 100));

    splitter->SplitVertically(left, right);
    splitter->SetMinimumPaneSize(80);
    left->SetMinSize(wxSize(80, 0));
    splitter->SetSashGravity(0);
    splitter->SetSashPosition(20);
	inputField = new wxTextCtrl(right, wxID_ANY, " ", wxPoint(100, 80), wxSize(495, 35));
	inputField->SetBackgroundColour(wxColor(255, 255, 255));
	inputField->SetForegroundColour(wxColor(0, 0, 0));
	inputField->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	inputField->SetToolTip("Enter your task here");
	addButton = new wxButton(right, wxID_ANY, "Add Task", wxPoint(600,80), wxSize(100,35));
	checkList = new wxCheckListBox(right, wxID_ANY, wxPoint(100,120), wxSize(600,400));
	clearButton = new wxButton(right, wxID_ANY, "Clear", wxPoint(100,525),wxSize(100,35));
}

// void OnHello is called when user clicks on the "Hello" Menu taskbar item... under file
void myFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello, To-Do List App made by Russell.");
}