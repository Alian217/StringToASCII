// StringToASCIIDlg.h : ͷ�ļ�
//

#define LIMITNULL 1
#define LIMITOVER 2
#define LIMITOK   3

#define LIMIT_INIT_SUM   30

#pragma once


// CStringToASCIIDlg �Ի���
class CStringToASCIIDlg : public CDialog
{
// ����
public:
	CStringToASCIIDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STRINGTOASCII_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
