// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// malagisView.h : CmalagisView 类的接口
//

#pragma once

//自定义头文件
#include "_malaBase.h"

class CmalagisView : public CView
{
protected: // 仅从序列化创建
	CmalagisView();
	DECLARE_DYNCREATE(CmalagisView)

// 特性
public:
	CmalagisDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmalagisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonPointsInput();

//自定义变量
private:
	CmalaMouseAction *mBaseOper;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	malaScreen mScreen;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // malagisView.cpp 中的调试版本
inline CmalagisDoc* CmalagisView::GetDocument() const
   { return reinterpret_cast<CmalagisDoc*>(m_pDocument); }
#endif

