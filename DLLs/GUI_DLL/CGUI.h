#pragma once
//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose: container-class for GUI elements
//
//******************************************************************************

#include <afxwin.h>
#include "LibDef.h"
#include "formula_editor\CFormulaEditor.h"
#include "dialog_scraper_output\DialogScraperOutput.h"
#include "Toolbar\CFlagsToolbar.h"
#include "MainFrame\MainFrm.h"
#include "statusbar\COpenHoldemStatusbar.h"
#include "OpenHoldem_title\COpenHoldemTitle.h"
#include "white_info_box\CWhiteInfoBox.h"

class CSingleDocTemplate;

class GUI_DLL_API CGUI: public CWnd {
public:
  CGUI();
  ~CGUI();
public:
  void CreateDialogScraperOutput(CFrameWnd *parent_window);
  void CreateFlagsToolbar(CFrameWnd *parent_window);
  void CreateStatusbar(CFrameWnd *parent_window);
public:
  void Update();
public:
  CSingleDocTemplate* CreateCSingleDocTemplate();
public:
  CFlagsToolbar *FlagsToolbar() {
    return _p_flags_toolbar;
  }
  CFormulaEditor *FormulaEditor() {
    return &_formula_editor;
  }
  CMainFrame *MainFrame() {
    // No explicit variable for this value
    // as the MainFrame gets initialized via MFC-magic
    return (CMainFrame*)AfxGetApp()->m_pMainWnd;
  }
  COpenHoldemStatusbar* OpenHoldemStatusbar() {
    return _p_openholdem_statusbar;
  }
  COpenHoldemTitle* OpenHoldemTitle() {
    return _p_openholdem_title;
  }
  CDlgScraperOutput *DlgScraperOutput() {
    return _p_dialog_scraper_output;
  }
  CWhiteInfoBox* WhiteInfoBox() { 
    return _p_white_infobox;
  }
public:
  afx_msg void OnAbout();
protected:
  DECLARE_MESSAGE_MAP()
private:
  void UpdateOnConnection();
  void UpdateOnDisconnection();
private:
  CFlagsToolbar* _p_flags_toolbar;
  CMainFrame* _p_main_frame;
  COpenHoldemStatusbar* _p_openholdem_statusbar; 
  COpenHoldemTitle* _p_openholdem_title;
  ///!init
  CDlgScraperOutput* _p_dialog_scraper_output;
  CWhiteInfoBox* _p_white_infobox;
private:
  CFormulaEditor _formula_editor;
};

GUI_DLL_API CGUI* GUI();