// SemesterProjektTest1Dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "SemesterProjektTest1.h"
#include "SemesterProjektTest1Dlg.h"
#include "afxdialogex.h"
#include "Windows.h"
#include "window2.h"
#include "ModiAuswahl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSemesterProjektTest1Dlg-Dialogfeld



CSemesterProjektTest1Dlg::CSemesterProjektTest1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SEMESTERPROJEKTTEST1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSemesterProjektTest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	int i = 0;
	while (i < 10) {
		i++;
		Sleep(1000);
	}
	window2 w;
	w.DoModal();

}

BEGIN_MESSAGE_MAP(CSemesterProjektTest1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSemesterProjektTest1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSemesterProjektTest1Dlg-Meldungshandler

BOOL CSemesterProjektTest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CSemesterProjektTest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CSemesterProjektTest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSemesterProjektTest1Dlg::OnBnClickedButton1()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	/*HWND window = NULL;
		window = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_WINDOW2), NULL, NULL);
		if (window != NULL)
			::ShowWindow(window, 3);
		else
			MessageBox("ACHTUNG", "CreateDialog returned NULL", true);*/
	window2 w;
	w.DoModal();
}

//Teeest-Kommentar von Jessi

//Test-Kommentar2 von Jessi