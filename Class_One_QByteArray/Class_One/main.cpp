#include <QCoreApplication>
#include <QDebug>
#include <QtGlobal>
int main(int argc, char *argv[])
{
    int Loop = 0;

    QCoreApplication a(argc, argv);

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~QByteArray学习区域~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    //1. 系统会自动在字节数组对象后加\0，所以实际数组长度 = 申请的数组长度+1
    QByteArray msg("Hello");
    qDebug()<<msg[0];
    qDebug()<<msg[1];
    qDebug()<<msg[2];
    qDebug()<<msg[3];
    qDebug()<<msg[4];
    qDebug()<<msg[5];

    //2. 使用resize()设置数组大小，并且初始化
    QByteArray msg_2;
    msg_2.resize(5);
    msg_2[0] = 0x3C;
    msg_2[1] = 0x02;
    msg_2[2] = 0x64;
    msg_2[3] = 0x3C;
    msg_2[4] = 0x01;

    //3. 使用fill()初始化数组，将元素初始化为特定值
    //fill(x,y)     ：x->要初始化的字符，y->如果不为-1，则重新开辟y个字节的内存
    QByteArray msg_3;
    msg_3.resize(5);
    msg_3.fill('A');
    for (Loop=0;Loop<6;Loop++)
    {
        qDebug()<<msg_3[Loop];
    }
    msg_3.fill('B', 3);
    for (Loop=0;Loop<6;Loop++)
    {
        qDebug()<<msg_3[Loop];
    }

    //4. 访问QByteArray中的元素
    //[], at(), data[], constData[]
    //[]和data[]可读可写，at()和constData[]只读，只读的速度最快，因为避免了复制
    QByteArray msg_4;
    msg_4.resize(5);
    msg_4[0] = 'A';
    msg_4[1] = 'B';
    msg_4.data()[2] = 'C';
    msg_4.data()[3] = 'D';
    msg_4.data()[4] = 'E';


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~QByteArray学习区域~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    return a.exec();
}
