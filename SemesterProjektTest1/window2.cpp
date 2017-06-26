// window2.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "window2.h"
#include "afxdialogex.h"
#include "atlwin.h"
#include "Windows.h"
#include <iostream>


// window2-Dialogfeld


IMPLEMENT_DYNAMIC(window2, CDialogEx)

window2::window2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINDOW2, pParent)
{
	//this->SetBackgroundColor(50, 1);
}

window2::~window2()
{
}

void window2::DoDataExchange(CDataExchange* pDX)
{
}

BOOL window2::OnInitDialog() {
	objSecureOverlay.SubclassWindow(m_hWnd);
	objSecureOverlay.m_nMessageHandler = CSecureOverlay::BackGroundPaint;
	objSecureOverlay.Load((LPCTSTR) "res\\bmp01.bmp");
	
	ShowWindow(SW_MAXIMIZE);
	OnSize(SW_MAXIMIZE, 10, 10);
	return true;
}

void window2::OnPaint()
{
}

BEGIN_MESSAGE_MAP(window2, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDBACK, &OnBnClickedBack)
	ON_BN_CLICKED(IDOK, &OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &window2::OnBnClickedOk)
END_MESSAGE_MAP()


// window2-Meldungshandler


void window2::OnBnClickedBack()
{	
	EndDialog(IDBACK);
}


void window2::OnSize(UINT nType, int cx, int cy)
{	
	GetDlgItem(IDC_STATIC)->MoveWindow(350, 850, 1000, 120);
	GetDlgItem(IDBACK)->MoveWindow(1500, 875,100, 50);
	GetDlgItem(IDC_BUTTON1)->MoveWindow(1400, 875, 50, 50);
}

void window2::OnBnClickedOk()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	CSemesterProjektTest1App::gesicherBerechtigt++;
	EndDialog(IDC_BUTTON1);
}

HBRUSH window2::OnCtlColor(CDC* pDC, CWnd* pWnd,UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	CBrush m_brush = m_brush.CreateStockObject(HOLLOW_BRUSH);
	pDC->SetTextColor(RGB(255,0,0));

	return hbr;
}