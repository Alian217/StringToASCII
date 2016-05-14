// StringToASCIIDlg.h : 头文件
//

#define LIMITNULL 1
#define LIMITOVER 2
#define LIMITOK   3

#define LIMIT_INIT_SUM   30

#pragma once


// CStringToASCIIDlg 对话框
class CStringToASCIIDlg : public CDialog
{
// 构造
public:
	CStringToASCIIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_STRINGTOASCII_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nSumLimit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
