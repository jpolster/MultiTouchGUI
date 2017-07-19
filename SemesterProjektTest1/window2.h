#pragma once


// window2-Dialogfeld


class window2 : public CDialogEx
{
	DECLARE_DYNAMIC(window2)

public:

	window2(CWnd* pParent = NULL);   // Standardkonstruktor
	virtual ~window2();

	// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINDOW2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
public:
	void OnBnClickedBack();
	void OnSize(UINT nType, int cx, int cy);
	BOOL OnInitDialog();
	void OnPaint();
	afx_msg void OnBnClickedOk();
	HBRUSH OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor);
	//HBRUSH CtlColor(CDC * pDC, UINT nCtlColor);
private:
	CBitmap myBitMap;	
};
