
// SemesterProjektTest1.h: Hauptheaderdatei f�r die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"		// Hauptsymbole
#include "ModiAuswahl.h"


// CSemesterProjektTest1App:
// Siehe SemesterProjektTest1.cpp f�r die Implementierung dieser Klasse
//

class CSemesterProjektTest1App : public CWinApp
{
public:
	CSemesterProjektTest1App();
	static int gesicherBerechtigt;
	static CFont font;
	static ModiAuswahl dlg;

// �berschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CSemesterProjektTest1App theApp;
