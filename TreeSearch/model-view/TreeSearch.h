/************************************************************************
���������ࣨQTreeView + QStandardItemModel�棩
ʹ�÷�����
���ú���TreeSearch::SearchItem(para1, para2, para3);
��һ��������Ҫ��������QTreeView����������
�ڶ�����������������ģ��QStandardItemModel����������
��������������������Ĺؼ���
************************************************************************/

#ifndef TREESEARCH_H
#define TREESEARCH_H

#include <QTreeView>
#include <QStandardItemModel>
#include <Windows.h>

#define ITEM_SHOWN (Qt::UserRole + 17)

class TreeSearch
{
public:
	TreeSearch();
	~TreeSearch();
	static void SearchItem(QTreeView *, QStandardItemModel *, const QString &);//��������

private:
	static void FuzzySearch(QString &);								//ģ������
	static void FuzzySearchChildren(QStandardItem *, QString &);	//ģ�������ӽڵ㣨�ݹ飩
	static void PreciseSearch(const QString &);						//��ȷ����
	static void PreciseSearchChildren(QStandardItem *, const QString &);//��ȷ�����ӽڵ㣨�ݹ飩
	static void ShowTotalItem();									//��ʾ���нڵ�
	static void ShowTotalChildrenItem(QStandardItem *);				//��ʾ�����ӽڵ㣨�ݹ飩
	static void ShowTotalParentItem(QStandardItem *);				//�������и��ڵ����ʾ���ݹ飩
	static void GetPinYin(const QString &, QString &strInitial, QString &strQuanPin);	//������תΪƴ��������ĸ�Լ�ȫƴ��
	static void GetWString(const std::string &, std::wstring &wStrOut);//��stringתΪwstring

private:
	static QTreeView *m_pCurTreeView;			//��ǰ����
	static QStandardItemModel *m_pCurModel;		//��ǰ��������ģ��
};

#endif // TREESEARCH_H
