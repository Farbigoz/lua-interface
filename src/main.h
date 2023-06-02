#ifndef __STATE_TREE_H__
#define __STATE_TREE_H__


#include <QMap>
#include <QString>
#include <QSpinBox>
#include <QLineEdit>
#include <QTreeWidgetItem>


typedef struct __StateTreeNode {
	QString						name;
	void 						*value;

	bool						isSignedNum;
	bool						isUnsignedNum;
	uint8_t						numSize;

	QTreeWidgetItem				*treeItem;

	QList<__StateTreeNode*>		children;
} StateTreeNode;


extern QList<StateTreeNode*>	STATE_TREE_DATA;



typedef struct __InputNode {
	QString					name;
	void 					*value;

	bool					isSignedNum;
	bool					isUnsignedNum;
	uint8_t					numSize;

	QSpinBox				*field;
} InputNode;




typedef struct __InputCommentNode {
	QLineEdit			*field;
	QString				comment;
} InputCommentNode;

typedef QMap<QString, InputCommentNode>	InputComments;
//typedef std::map<QString, InputCommentNode>	InputComments




#endif /* __STATE_TREE_H__ */