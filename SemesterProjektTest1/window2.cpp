// window2.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "window2.h"
#include "afxdialogex.h"
#include "atlwin.h"


// window2-Dialogfeld

IMPLEMENT_DYNAMIC(window2, CDialogEx)

window2::window2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINDOW2, pParent)
{
}

window2::~window2()
{
}

void window2::DoDataExchange(CDataExchange* pDX)
{
}

BOOL window2::OnInitDialog() {
	ShowWindow(SW_MAXIMIZE);
	OnSize(SW_MAXIMIZE, 10, 10);
	return true;
}


BEGIN_MESSAGE_MAP(window2, CDialog)
	ON_BN_CLICKED(IDOK, &OnBnClickedOk)
END_MESSAGE_MAP()


// window2-Meldungshandler


void window2::OnBnClickedOk()
{
	EndDialog(IDOK);
}

void window2::OnSize(UINT nType, int cx, int cy)
{

	switch (nType)
	{
	case SIZE_MAXIMIZED:
		// window was maximized
		break;

	case SIZE_MINIMIZED:
		// window was minimized
		break;

	case SIZE_RESTORED:
		// misleading - this occurs when restored from minimized/maximized AND
		// for normal size operations when already restored
		break;

	default:
		// you could also deal with SIZE_MAXHIDE and SIZE_MAXSHOW
		// but rarely need to
		break;
	}
// Hiiiiiiiiiiiiiiier
	//GetDlgItem(IDC_STATIC)->SetWindowText("Anderer Text");
	GetDlgItem(IDOK)->MoveWindow(700, 350, 50, 50);
}
