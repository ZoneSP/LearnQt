#include <QCoreApplication>
#include<QDebug>

void Display_QByteArray(QByteArray Array1, int Array_length);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*How to init QByteArray*/

    /*Method 1*/
    QByteArray ba("Hello");
    //需要注意，QByteArray会自动在字节数组对象结尾添加一个'\0'，所以这个数组实际角标为5，如：
    if('\0' == ba[5])
    {
        printf("角标5存在\n");
    }
    /*Method 1*/


    /*Method 2 使用resize()设置数组大小，并初始化每个数组元素*/
    QByteArray dc;
    dc.resize(6);
    dc[0] = 0x3c;
    dc[1] = 0x10;
    dc[2] = 0x10;
    dc[3] = 0x10;
    dc[4] = 0x10;
    dc[5] = 0x10;

    //使用fill为声明的数组声明默认值
    QByteArray dc1;
    dc1.resize(6);
    dc1.fill('D');

    /*Method 2 使用resize()设置数组大小，并初始化每个数组元素*/

    /*How to init QByteArray*/


    /*--------------------访问某个元素--------------------*/
    //四种方法[]，at()，data[]，constData[]
    //[]和data[]可以读写，at()和constData[]，只读
    //在只需读取的场合，推荐使用只读，因为不用深层复制，速度更快
    qDebug()<<"[]"<<dc1[2];
    qDebug()<<"at()"<<dc1.at(2);
    qDebug()<<"data[]"<<dc1.data()[2];
    qDebug()<<"constData[]"<<dc1.constData()[2];
    /*--------------------访问某个元素--------------------*/


    /*--------------------切片数组--------------------*/
    Display_QByteArray(ba,6);
    QByteArray testArray = ba.left(2);
    Display_QByteArray(testArray,3);
    testArray = ba.right(2);
    Display_QByteArray(testArray,3);
    testArray = ba.mid(1,3);
    Display_QByteArray(testArray,4);
    /*--------------------切片数组--------------------*/


    /*---------------------获取字节数组的大小--------------------*/
    //int size()     int length()     int count()
    //这三个函数，除了名字不同，其余全部相同

    int ba_length = ba.size();
    printf("ba的长度是：%d\n",ba_length);
    //size()不会记录\0，所以字符串中有\0，size()不会记录\0后的数据

    int ba_length_2 = ba.length();
    printf("ba的长度是：%d\n",ba_length_2);

    int ba_length_3 = ba.count();
    printf("ba的长度是：%d\n",ba_length_3);
    /*---------------------获取字节数组的大小--------------------*/
    return a.exec();
}



void Display_QByteArray(QByteArray Array1, int Array_length)
{
    int Loop = 0;
    for(Loop=0;Loop<Array_length;Loop++)
    {
        qDebug()<<Array1[Loop];
    }
}
