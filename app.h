#pragma once
#include <wx/wx.h>

class myApp : public wxApp
{
public:
    virtual bool OnInit();
};

class myTextCtrl : public wxTextCtrl
{
public:
	myTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value,
		const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
		long style = 0)
		: wxTextCtrl(parent, id, value, pos, size, style)
	{
		SetBackgroundColour(*wxWHITE);
		SetForegroundColour(*wxBLACK);
	}
private:
	wxTextCtrl* textCntrl;	
};