
// SemesterProjektTest1Dlg.h: Headerdatei
//

#pragma once


// CSemesterProjektTest1Dlg-Dialogfeld
class CSemesterProjektTest1Dlg : public CDialogEx
{
// Konstruktion
public:
	CSemesterProjektTest1Dlg(CWnd* pParent = NULL);	// Standardkonstruktor
	HMODULE hInstance;

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEMESTERPROJEKTTEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterst�tzung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen f�r die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
