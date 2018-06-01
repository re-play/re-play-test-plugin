#ifndef TEST_H
#define TEST_H

#include <QQuickItem>

class Test : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Test)

public:
    Test(QQuickItem *parent = nullptr);
    ~Test();
};

#endif // TEST_H
