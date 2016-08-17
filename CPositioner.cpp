#include "CPositioner.hpp"
#include <QBoxLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QDebug>

CPositioner::CPositioner(QWidget *parent)
: QWidget(parent)
, m_currentSelectedObject(nullptr)
, m_objectsList(new QComboBox)
, m_xSpinBox(new QSpinBox)
, m_ySpinBox(new QSpinBox)
, m_widthSpinBox(new QSpinBox)
, m_heightSpinBox(new QSpinBox)
{
   m_xSpinBox->setRange(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
   m_ySpinBox->setRange(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
   m_widthSpinBox->setRange(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
   m_heightSpinBox->setRange(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
//   QSpinBox::editor()->setAlignment();
   QBoxLayout *boxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
   boxLayout->addWidget(m_objectsList);

   QBoxLayout *rowLayout1 = new QBoxLayout(QBoxLayout::LeftToRight);

   QLabel *textX = new QLabel;
   textX->setText("X:");
   rowLayout1->addWidget(textX);
   rowLayout1->addWidget(m_xSpinBox);

   rowLayout1->addSpacing(20);

   QLabel *textY = new QLabel;
   textY->setText("Y:");
   rowLayout1->addWidget(textY);
   rowLayout1->addWidget(m_ySpinBox);

   QBoxLayout *rowLayout2 = new QBoxLayout(QBoxLayout::LeftToRight);

   QLabel *textWidth = new QLabel;
   textWidth->setText("Width:");
   rowLayout2->addWidget(textWidth);
   rowLayout2->addWidget(m_widthSpinBox);

   rowLayout2->addSpacing(20);

   QLabel *textHeight = new QLabel;
   textHeight->setText("Height:");
   rowLayout2->addWidget(textHeight);
   rowLayout2->addWidget(m_heightSpinBox);

   boxLayout->addLayout(rowLayout1);
   boxLayout->addLayout(rowLayout2);
   this->setLayout(boxLayout);
//   QComboBox box;
   m_objectsList->setCurrentIndex(0);
   connect(m_objectsList, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectedItemChanged(QString)));
   connect(m_xSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueXChanged(int)));
   connect(m_ySpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueYChanged(int)));
   connect(m_widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueWidthChanged(int)));
   connect(m_heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueHeightChanged(int)));
}

void CPositioner::setRootObjects(QList<QObject *> rootObjects)
{
   ml_rootObjects = rootObjects;
   fillComboBox(rootObjects);
   fillSpinBoxes(rootObjects);
}

void CPositioner::selectedItemChanged(const QString &selectedObjectName)
{
   qDebug() << "set";
   for(QObject* obj: ml_rootObjects)
   {
      QObject* child = obj->findChild<QObject*>(selectedObjectName);
      if(child != nullptr)
      {
         m_currentSelectedObject = child;

         m_xSpinBox->setValue(child->property("x").toInt());
         m_ySpinBox->setValue(child->property("y").toInt());
         m_widthSpinBox->setValue(child->property("width").toInt());
         m_heightSpinBox->setValue(child->property("height").toInt());
         break;
      }
   }
}

void CPositioner::valueXChanged(int value)
{
   if(m_currentSelectedObject != nullptr)
   {
      m_currentSelectedObject->setProperty("x", QVariant(value));
   }
}

void CPositioner::valueYChanged(int value)
{
   if(m_currentSelectedObject != nullptr)
   {
      m_currentSelectedObject->setProperty("y", QVariant(value));
   }
}

void CPositioner::valueWidthChanged(int value)
{
   if(m_currentSelectedObject != nullptr)
   {
      m_currentSelectedObject->setProperty("width", QVariant(value));
   }
}

void CPositioner::valueHeightChanged(int value)
{
   if(m_currentSelectedObject != nullptr)
   {
      m_currentSelectedObject->setProperty("height", QVariant(value));
   }
}

void CPositioner::fillComboBox(QList<QObject *> objectsList)
{
   for(QObject* obj: objectsList)
   {
      m_objectsList->addItem(obj->objectName());

      qDebug() << obj->objectName();
//      m_xSpinBox->setValue(obj->property("x").toInt());
//      m_ySpinBox->setValue(obj->property("y").toInt());
//      m_widthSpinBox->setValue(200);
      QList<QObject *> childList = obj->children();
      if(!childList.isEmpty())
      {
         fillComboBox(childList);
      }
   }
}

void CPositioner::fillSpinBoxes(QList<QObject *> objectsList)
{

}
