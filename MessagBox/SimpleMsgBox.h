#ifndef SIMPLEMSGBOX_H
#define SIMPLEMSGBOX_H

#include <QWidget>
#include <QEventLoop>
#include "ui_SimpleMsgBox.h"
#pragma execution_character_set("utf-8")

class SimpleMsgBox : public QWidget
{
	Q_OBJECT

public:
	enum ButtonRole{Yes, No};
	~SimpleMsgBox();
	static ButtonRole warning(QWidget *parent, const QString &title, const QString &text);


protected:
	void mousePressEvent(QMouseEvent *);	//��갴��	
	void mouseMoveEvent(QMouseEvent *);		//����ƶ�
	void mouseReleaseEvent(QMouseEvent *);	//����ɿ�

private:
	SimpleMsgBox(QWidget *parent = 0);
	void setTitle(const QString &);			//���ñ���
	void setText(const QString &);			//������������
	void setWarning(const QString &title, const QString &text);
	void initSignalAndSlotConnn();			//��ʼ���źŲ�����

private Q_SLOTS:
	void onOkBtnClickedSlot();		//ȷ����ť����
	void onCancelBtnClickedSlot();	//ȡ����ť����
	void onCloseBtnClockedSlot();	//�رհ�ť����

private:
	Ui::SimpleMsgBox ui;
	QEventLoop *m_pEvtLoop;
	static ButtonRole m_Role;	//��������ֵ
	bool m_bPressed;			//�������Ƿ���
	QPoint m_ptPress;			//��갴�µ������
};

#endif // SIMPLEMSGBOX_H
