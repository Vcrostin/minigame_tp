#pragma once


// Диалоговое окно Dialog_Shop
enum class KnifeCH {
	Default,
	Sword,
	Knife
};
class Dialog_Shop : public CDialog
{
	DECLARE_DYNAMIC(Dialog_Shop)

public:
	Dialog_Shop(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Dialog_Shop();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOP };
#endif

private:
	KnifeCH KCH = KnifeCH::Default;
	bool IsArmor = false;
	bool IsHelmet = false;
	bool IsShield = false;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedIsknife();
	afx_msg void OnBnClickedIssword();
	afx_msg void OnBnClickedArmor();
	afx_msg void OnBnClickedHelmet();
	afx_msg void OnBnClickedShield();
	afx_msg void OnBnClickedButton1();
};
