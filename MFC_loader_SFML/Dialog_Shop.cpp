// Dialog_Shop.cpp: файл реализации
//

#include "pch.h"
#include "MFC_loader_SFML.h"
#include "Dialog_Shop.h"
#include "afxdialogex.h"


// Диалоговое окно Dialog_Shop

IMPLEMENT_DYNAMIC(Dialog_Shop, CDialog)

Dialog_Shop::Dialog_Shop(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SHOP, pParent)
{

}

Dialog_Shop::~Dialog_Shop()
{
}

void Dialog_Shop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog_Shop, CDialog)
	ON_BN_CLICKED(IDC_IsKnife, &Dialog_Shop::OnBnClickedIsknife)
	ON_BN_CLICKED(IDC_IsSword, &Dialog_Shop::OnBnClickedIssword)
	ON_BN_CLICKED(IDC_ARMOR, &Dialog_Shop::OnBnClickedArmor)
	ON_BN_CLICKED(IDC_HELMET, &Dialog_Shop::OnBnClickedHelmet)
	ON_BN_CLICKED(IDC_SHIELD, &Dialog_Shop::OnBnClickedShield)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog_Shop::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений Dialog_Shop


void Dialog_Shop::OnBnClickedIsknife()
{
	this->KCH = KnifeCH::Knife;
}


void Dialog_Shop::OnBnClickedIssword()
{
	this->KCH = KnifeCH::Sword;
}


void Dialog_Shop::OnBnClickedArmor()
{
	IsArmor = !IsArmor;
}


void Dialog_Shop::OnBnClickedHelmet()
{
	IsHelmet = !IsHelmet;
}


void Dialog_Shop::OnBnClickedShield()
{
	IsShield = !IsShield;
}


void Dialog_Shop::OnBnClickedButton1()
{
	if (KCH != KnifeCH::Default) {
		int counter = 0;
		if (IsHelmet)
			counter++;
		if (IsArmor)
			counter++;
		if (IsShield)
			counter++;
		this->ShowWindow(SW_HIDE);

		this->ShowWindow(SW_SHOW);
		this->OnOK();
	}
	else {
		CString sc ("Выберите меч");
		AfxMessageBox(sc, MB_OK, MB_ICONINFORMATION);
	}
}
