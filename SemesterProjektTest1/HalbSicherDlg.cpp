// HalbSicherDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "HalbSicherDlg.h"
#include "afxdialogex.h"


// HalbSicherDlg-Dialogfeld

IMPLEMENT_DYNAMIC(HalbSicherDlg, CDialogEx)

HalbSicherDlg::HalbSicherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDModusHalbsicherDlg, pParent)
{

}

HalbSicherDlg::~HalbSicherDlg()
{
}

void HalbSicherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HalbSicherDlg, CDialogEx)
END_MESSAGE_MAP()


// HalbSicherDlg-Meldungshandler
