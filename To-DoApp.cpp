// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "app.h"
#include "mainFrame.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class myFrame : public wxFrame
{
public:
    myFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

enum
{
    ID_Hello = 3
};

wxIMPLEMENT_APP(myApp);

bool myApp::OnInit()
{
    myFrame* frame = new myFrame();
	frame->SetClientSize(800, 700); // Set the size of the window (width, height)
    frame->Show(true);
    return true;
}

myFrame::myFrame()
    : wxFrame(NULL, wxID_ANY, "To-Do")
{
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

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Running on wxWidgets 3.2.7");

    Bind(wxEVT_MENU, &myFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &myFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &myFrame::OnExit, this, wxID_EXIT);
}

void myFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void myFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void myFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello, To-Do List App made by Russell.");
}