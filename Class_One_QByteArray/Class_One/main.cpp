#include <QCoreApplication>
#include <QDebug>
#include <QtGlobal>
#include <iostream>
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

    qDebug()<<msg_4[0];
    qDebug()<<msg_4.data()[1];
    qDebug()<<msg_4.at(2);
    qDebug()<<msg_4.constData()[3];
    qDebug()<<msg_4.constData()[4];
    qDebug()<<msg_4.constData()[5];

    //5. 截取字符串
    //left()   right()    mid()
    //left(int len)：从索引0开始，截取长度len的片段。len超过数组长度，则返回字符数组
    //right(int len)：从索引尾部开始，截取长度len的片段。len超过数组长度，则返回字符数组
    //mid(int pos, int len = -1)：如果len = -1，或者pos+len大于数组长度，则返回整个字符数组，否则从pos开始，截取len长度的字符数组
    QByteArray msg_5 = "ABCDEFG";
    QByteArray msg_5_left = msg_5.left(3);
    qDebug()<<msg_5_left;
    QByteArray msg_5_right = msg_5.right(3);
    qDebug()<<msg_5_right;
    QByteArray msg_5_mid = msg_5.mid(1,4);
    qDebug()<<msg_5_mid;
    qDebug()<<" ";

    //6. 获取字节数组的大小
    //int size()
    //int length()
    //int count()
    //三个函数等价，遇到\0会被截断，停止统计，但是通过resize()函数开辟的内存，再手动填充的\0不会截断统计
    QByteArray msg_6 = "Hello";
    int msg_6_length = msg_6.size();
    qDebug()<<msg_6_length;
    QByteArray msg_6_resize;
    msg_6_resize.resize(6);
    msg_6_resize[0] = 'A';
    msg_6_resize[1] = '\0';
    msg_6_resize[2] = 'B';
    msg_6_resize[3] = 'C';
    msg_6_resize[4] = 'D';
    msg_6_resize[5] = 'E';
    int msg_6_count = msg_6_resize.count();
    qDebug()<<msg_6_count;
    qDebug()<<" ";

    //7. Hex转换
    //fromHex()：将数字字符串变化为16进制数，然后将16进制数转10进制数，然后转ASCII码得到字符
    //toHex()：将16进制数变成字符串输出
    QByteArray text = QByteArray::fromHex("517420697320677265617421");
    qDebug()<<text.data();
    qDebug()<<" ";
    QByteArray msg_7;
    msg_7.resize(3);
    msg_7[0] = 0x11;
    msg_7[1] = 0x12;
    msg_7[2] = 0x36;
    qDebug()<<msg_7.toHex();
    qDebug()<<" ";

    //8. 数值转换与输出
    //公有静态函数::number(int n, int base = 10)  公有函数：setNum<需要对象来调用>
    int n = 63;
    qDebug()<<QByteArray::number(n);
    qDebug()<<QByteArray::number(n, 16);
    qDebug()<<QByteArray::number(n, 16).toUpper();
    qDebug()<<QByteArray::number(n, 2);
    qDebug()<<QByteArray::number(n, 8);
    printf("setNum: \n");
    QByteArray msg_8;
    qDebug()<<msg_8.setNum(n,10);
    qDebug()<<msg_8.setNum(n,16);
    printf("\n");
    //9. 字母大小写的转换
    //.toUpper()  全部转化为大写     .toLower()  全部转化为小写

    //10. 判断是大写还是小写的函数
    //.isUpper()   .isLower()    ->如果字符数组里有小写的或者大写的，则返回true

    //11. 字符串数值转化为各类数值
    //toInt(&bool check, 进制)   toFloat()   toDouble()   toFloat和toDouble均只包含两位小数
    //小数用toInt()全部按0处理
    QByteArray strInt("1234");
    bool check;
    qDebug()<<strInt.toInt(&check, 16);
    if(check == true)
    {
        printf("check is true\n");
    }
    else
    {
        printf("check is False\n");
    }
    qDebug()<<strInt.toInt();
    printf("以下是小数区域：\n");
    QByteArray strFloat("1234.5678");
    qDebug()<<strFloat.toFloat();
    qDebug()<<strFloat.toDouble();
    printf("\n");

    //12. QByteArray和char*互转
    QByteArray msg_9("Hello world");
    char *data = msg_9.data();  //返回一个指向msg_9的指针,指向第一个字符

    //13. 与字符串QString互转
    //QString只存储可显示的字符，具体可查阅ASCII码表
    QString str = QString("hello world");
    QByteArray arr = str.toLatin1();
    qDebug()<<arr;
    QByteArray arr2("HELLOWORLD");
    QString str2 = arr;

    //14.
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~QByteArray学习区域~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    return a.exec();
}
