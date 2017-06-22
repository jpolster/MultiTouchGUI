// OverlayDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "OverlayDlg.h"
#include "afxdialogex.h"


// OverlayDlg-Dialogfeld

IMPLEMENT_DYNAMIC(OverlayDlg, CDialog)

OverlayDlg::OverlayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(OverlayID, pParent)
{
	
}

OverlayDlg::~OverlayDlg()
{
}

void OverlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(OverlayDlg, CDialog)
END_MESSAGE_MAP()
BOOL OverlayDlg::OnInitDialog()
{
	
		// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen

		bmp.LoadBitmap(IDB_bmp);

	return TRUE; // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten 
}

void OverlayDlg::OnPaint()
{
	CClientDC dc(this);
	BITMAP bm;
	bmp.GetObject(sizeof(bm), &bm);
	CDC SpeicherDC;
	SpeicherDC.CreateCompatibleDC(&dc);
	SpeicherDC.SelectObject(&bmp);
	CRect Rect;
	GetClientRect(&Rect);
	dc.SetStretchBltMode(HALFTONE);
	dc.StretchBlt(0, 0, Rect.right, Rect.bottom, &SpeicherDC,
		0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	CDialog::OnPaint();
}






// OverlayDlg-Meldungshandler
