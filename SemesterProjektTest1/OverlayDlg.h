#pragma once
#include "afxwin.h"


// OverlayDlg-Dialogfeld

class OverlayDlg : public CDialog
{
	DECLARE_DYNAMIC(OverlayDlg)

public:
	OverlayDlg(CWnd* pParent = NULL);   // Standardkonstruktor
	virtual ~OverlayDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = OverlayID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	BOOL OnInitDialog();

	void OnPaint();

	DECLARE_MESSAGE_MAP()
public:
	CBitmap bmp;

};
