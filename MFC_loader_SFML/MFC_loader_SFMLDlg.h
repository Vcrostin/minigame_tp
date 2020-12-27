
// MFC_loader_SFMLDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCloaderSFMLDlg
class CMFCloaderSFMLDlg : public CDialogEx
{
// Создание
public:
	CMFCloaderSFMLDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LOADER_SFML_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
private:
	HICON m_hIcon;
	CBitmap m_bmpBack;
	CBrush m_brushBack;
	CBitmap m_bmpEarth;
	COLORREF m_crStaticText;

protected:
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	BOOL OnEraseBkgnd(CDC* pDC);
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
