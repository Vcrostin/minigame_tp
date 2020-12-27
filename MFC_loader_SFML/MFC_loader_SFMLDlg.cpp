
// MFC_loader_SFMLDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_loader_SFML.h"
#include "MFC_loader_SFMLDlg.h"
#include "afxdialogex.h"
#include "Dialog_Shop.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCloaderSFMLDlg



CMFCloaderSFMLDlg::CMFCloaderSFMLDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LOADER_SFML_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	VERIFY(m_bmpBack.LoadBitmap(IDB_BITMAP1));

	VERIFY(m_brushBack.CreatePatternBrush(&m_bmpBack));
}

void CMFCloaderSFMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCloaderSFMLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCloaderSFMLDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCloaderSFMLDlg

BOOL CMFCloaderSFMLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCloaderSFMLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCloaderSFMLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap* pOldBitmap = (CBitmap*)dcMem.SelectObject(&m_bmpEarth);
		BITMAP bmp = { 0 };
		m_bmpEarth.GetBitmap(&bmp);

		dc.TransparentBlt(
			10, 10, bmp.bmWidth, bmp.bmHeight, // destination coordinates and sizes
			&dcMem,                            // source DC
			0, 0, bmp.bmWidth, bmp.bmHeight,   // source coordinates and sizes
			RGB(255, 0, 0));                   // transparent color
		 // restore DC / free GDI objects 
		dcMem.SelectObject(pOldBitmap);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

BOOL CMFCloaderSFMLDlg::OnEraseBkgnd(CDC* pDC)
{
	// get clipping rectangle
	CRect rcClip;
	pDC->GetClipBox(rcClip);
	// fill rectangle using a given brush
	pDC->FillRect(rcClip, &m_brushBack);
	return TRUE; // returns non-zero to prevent further erasing
}

HBRUSH CMFCloaderSFMLDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hBrush = NULL;
	switch (nCtlColor)
	{
	case CTLCOLOR_DLG:
		// just return a not NULL brush handle
		hBrush = (HBRUSH)m_brushBack;
		break;
	case CTLCOLOR_STATIC:
	{
		// set text color, transparent back node then 
		pDC->SetTextColor(m_crStaticText);
		pDC->SetBkMode(TRANSPARENT);
		// return a not NULL brush handle
		hBrush = (HBRUSH)m_brushBack;
	}
	break;
	default:
		// do the default processing
		hBrush = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		break;
	}
	return hBrush;
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCloaderSFMLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCloaderSFMLDlg::OnBnClickedButton1()
{
	this->ShowWindow(SW_HIDE);
	Dialog_Shop dlg;
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}
