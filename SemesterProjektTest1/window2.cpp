// window2.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "window2.h"
#include "afxdialogex.h"
#include "atlwin.h"
#include "Windows.h"


// window2-Dialogfeld

CStatic * bitMap;


IMPLEMENT_DYNAMIC(window2, CDialogEx)

window2::window2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINDOW2, pParent)
{
	this->SetBackgroundColor(50, 1);
}

window2::~window2()
{
}

void window2::DoDataExchange(CDataExchange* pDX)
{
	
}

BOOL window2::OnInitDialog() {
	
	/*HBITMAP hImage = (HBITMAP)LoadImage(NULL, L"bitmap1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HWND hImageView = CreateWindowEx(NULL, L"STATIC", NULL, SS_BITMAP | WS_VISIBLE | WS_CHILD, 0, 00, 500, 600, hWnd, (HMENU)IMAGE_VIEW, GetModuleHandle(NULL), NULL);
	SendMessage(hImageView, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hImage);*/
	//C:\Users\Jessi\Source\Repos\MultiTouch_Reich\SemesterProjektTest1\res\bitmap1.bmp
	//this->SetBackgroundImage(hImage, BACKGR_TOPLEFT, true);
	//bitMap = (CStatic *)GetDlgItem(IDC_BackBit);
	
	ShowWindow(SW_MAXIMIZE);
	OnSize(SW_MAXIMIZE, 10, 10);
	//CBitmap bmp;
	//bmp.LoadBitmap(BackgroundPicID);
	//this->SetBackgroundImage(BackgroundPicID, BACKGR_TOPLEFT, true);
	
	return true;
}

void window2::OnPaint()
{
	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // device context for painting
	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	//	// Center icon in client rectangle
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;
	//	// Draw the icon
	//	//dc.DrawIcon(x, y, m_hIcon);
	//}
	//else
	//{
	//	//Sample 01: Required Declarations
	//	CDC MemDC;
	//	CBitmap bmp;
	//	CPaintDC dc(this);

	//	//Sample 02: Get the Client co-ordinates
	//	CRect rct;
	//	this->GetClientRect(&rct);
	//	//Sample 03: Create the Dialog Compatible DC in the memory,
	//	//                                                                                                      Then load the bitmap to the memory.
	//	MemDC.CreateCompatibleDC(&dc);
	//	bmp.LoadBitmap(BackgroundPicID);
	//	MemDC.SelectObject(&bmp);
	//	//Sample 04: Finally perform Bit Block Transfer (Blt) from memory dc to
	//	//                                                                                                     dialog surface.
	//	dc.BitBlt(0, 0, rct.Width(), rct.Height(), &MemDC, 0, 0, SRCCOPY);
	//	CDialog::OnPaint();
	//}

	//CPaintDC dc(this);

	//CBitmap bitmap;
	//bitmap.LoadBitmap(BackgroundPicID);//Bitmap wird im res Ordner 
	//								//gespeichert 
	//BITMAP bm;
	//bitmap.GetObject(sizeof(bm), &bm);
	//CDC speicherDC;
	//speicherDC.CreateCompatibleDC(&dc);
	//speicherDC.SelectObject(&bitmap);
	//dc.BitBlt(
	//	0, 0, bm.bmWidth, bm.bmHeight, &speicherDC, 0, 0, SRCCOPY);

	CBitmap bitmap;
	bitmap.LoadBitmap(BackgroundPicID);

	BITMAP bm;
	bitmap.GetObject(sizeof(bm), &bm);

	CClientDC dc(this);

	CDC speicherDC;
	speicherDC.CreateCompatibleDC(&dc);

	CBitmap *pOldBitmap = speicherDC.SelectObject(&bitmap);
	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &speicherDC, 0, 0, SRCCOPY);

	speicherDC.SelectObject(pOldBitmap);

}

BEGIN_MESSAGE_MAP(window2, CDialog)
	ON_BN_CLICKED(IDOK, &OnBnClickedOk)
	ON_STN_CLICKED(IDC_BackBit, &window2::OnStnClickedBackbit)
	ON_BN_CLICKED(IDC_BUTTON1, &window2::OnBnClickedButton1)
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


void window2::OnBnClickedButton1()
{	
	char * buffer = NULL;
	//open the clipboard
	CString fromClipboard(L"EMPTY");
	if (OpenClipboard())
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		char * buffer = (char*)GlobalLock(hData);
		fromClipboard = buffer;
		GlobalUnlock(hData);
		CloseClipboard();
	}
	CWnd* button1 = GetDlgItem(IDC_BUTTON1);
	button1->SetWindowTextW(fromClipboard);
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}


void window2::OnStnClickedBackbit()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
}
