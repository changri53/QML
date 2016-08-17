#ifndef CPOSITIONER_HPP
#define CPOSITIONER_HPP

#include <QWidget>

//class QBoxLayout;
class QComboBox;
class QSpinBox;

class CPositioner : public QWidget
{
   Q_OBJECT

   QList<QObject*> ml_rootObjects;
   QComboBox *m_objectsList;
   QSpinBox *m_xSpinBox;
   QSpinBox *m_ySpinBox;
   QSpinBox *m_widthSpinBox;
   QSpinBox *m_heightSpinBox;

   QObject *m_currentSelectedObject;

   void fillComboBox(QList<QObject*> objectsList);
   void fillSpinBoxes(QList<QObject*> objectsList);

signals:
   void mySignal(int);
public:
   explicit CPositioner(QWidget *parent = 0);
   void setRootObjects(QList<QObject*> rootObjects);

public slots:
   void selectedItemChanged(const QString &selectedObjectName);
   void valueXChanged(int value);
   void valueYChanged(int value);
   void valueWidthChanged(int value);
   void valueHeightChanged(int value);
};

#endif // CPOSITIONER_HPP
