/************************************************************************
���������ࣨQTreeWidget�棩
ʹ�÷�����
���ú���TreeSearch::SearchItem(para1, para2);
��һ��������Ҫ��������QTreeWidget����������
�ڶ�����������������Ĺؼ���
************************************************************************/

#ifndef TREESEARCH_H
#define TREESEARCH_H

#include <QTreeWidget>
#include <Windows.h>

#define ITEM_SHOWN (Qt::UserRole + 17)

class TreeSearch
{
public:
	TreeSearch();
	~TreeSearch();
	static void SearchItem(QTreeWidget *, const QString &);//��������

private:
	static void FuzzySearch(QString &);								//ģ������
	static void FuzzySearchChildren(QTreeWidgetItem *, QString &);	//ģ�������ӽڵ㣨�ݹ飩
	static void PreciseSearch(const QString &);						//��ȷ����
	static void PreciseSearchChildren(QTreeWidgetItem *, const QString &);//��ȷ�����ӽڵ㣨�ݹ飩
	static void ShowTotalItem();									//��ʾ���нڵ�
	static void ShowTotalChildrenItem(QTreeWidgetItem *);				//��ʾ�����ӽڵ㣨�ݹ飩
	static void ShowTotalParentItem(QTreeWidgetItem *);				//�������и��ڵ����ʾ���ݹ飩
	static void GetPinYin(const QString &, QString &strInitial, QString &strQuanPin);	//������תΪƴ��������ĸ�Լ�ȫƴ��
	static void GetWString(const std::string &, std::wstring &wStrOut);//��stringתΪwstring

private:
	static QTreeWidget *m_pCurTreeWidget;			//��ǰ����
};

#endif // TREESEARCH_H
