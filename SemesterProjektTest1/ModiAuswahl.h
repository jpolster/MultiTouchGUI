#pragma once


// ModiAuswahl-Dialogfeld
#include "SecureOverlay.h"
#include <sstream> 

class ModiAuswahl : public CDialog 
{
	DECLARE_DYNAMIC(ModiAuswahl)

public:
	int rbModusV;
	ModiAuswahl(CWnd* pParent = NULL);   // Standardkonstruktor
	virtual ~ModiAuswahl();

	BOOL OnInitDialog();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbuok();
};
