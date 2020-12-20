
// MFC_loader_SFML.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCloaderSFMLApp:
// Сведения о реализации этого класса: MFC_loader_SFML.cpp
//

class CMFCloaderSFMLApp : public CWinApp
{
public:
	CMFCloaderSFMLApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCloaderSFMLApp theApp;
