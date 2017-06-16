#pragma once


// HalbSicherDlg-Dialogfeld

class HalbSicherDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HalbSicherDlg)

public:
	HalbSicherDlg(CWnd* pParent = NULL);   // Standardkonstruktor
	virtual ~HalbSicherDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDModusHalbsicherDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
};
