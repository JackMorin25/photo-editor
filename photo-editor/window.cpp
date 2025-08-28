#include "window.h"
#include <wx/wx.h>
#include <wx/anybutton.h>

class App : public wxApp {
public:
    bool OnInit() {
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(900, 600));
        wxBoxSizer* sizerMain = new wxBoxSizer(wxHORIZONTAL);

        // Panels for left, center, right
        wxPanel* panelLeft = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
        wxPanel* panelCenter = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
        wxPanel* panelRight = new wxPanel(window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);

        // Give them background colors (so you can see the sections)
        panelLeft->SetBackgroundColour(*wxRED);
        panelCenter->SetBackgroundColour(*wxGREEN);
        panelRight->SetBackgroundColour(*wxBLUE);

        // Add panels to main sizer with borders
        sizerMain->Add(panelLeft, 2, wxEXPAND | wxALL, 2);
        sizerMain->Add(panelCenter, 2, wxEXPAND | wxALL, 2);
        sizerMain->Add(panelRight, 2, wxEXPAND | wxALL, 2);

      
        window->SetSizer(sizerMain);
        
        wxBoxSizer* sizerLeft = new wxBoxSizer(wxVERTICAL);
        wxButton* btnLeft = new wxButton(panelLeft, wxID_ANY, "Left Button");
        sizerLeft->Add(btnLeft, 0, wxALL, 10);
        panelLeft->SetSizer(sizerLeft);

        wxBoxSizer* sizerCenter = new wxBoxSizer(wxVERTICAL);
        wxButton* btnCenter = new wxButton(panelCenter, wxID_ANY, "Center Button");
        sizerCenter->Add(btnCenter, 0, wxALL, 10);
        panelCenter->SetSizer(sizerCenter);

        wxBoxSizer* sizerRight = new wxBoxSizer(wxVERTICAL);
        wxButton* btnRight = new wxButton(panelRight, wxID_ANY, "Right Button");
        sizerRight->Add(btnRight, 0, wxALL, 10);
        panelRight->SetSizer(sizerRight);


        window->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);
