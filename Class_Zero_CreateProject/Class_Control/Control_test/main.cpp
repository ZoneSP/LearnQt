#include <QCoreApplication>
#include <QtGlobal>
int main(int argc, char *argv[])
{
    qint8 m;
    QCoreApplication a(argc, argv);

    printf("sizeof(uchar)=%d B\n",sizeof(uchar));
    printf("sizeof(uchar)=%d B\n",sizeof(m));
    printf("sizeof(uchar)=%d B\n",sizeof(qint8));
    printf("sizeof(uchar)=%d B\n",sizeof(qint16));
    printf("sizeof(uchar)=%d B\n",sizeof(qint32));
    printf("sizeof(uchar)=%d B\n",sizeof(qint64));
    printf("sizeof(uchar)=%d B\n",sizeof(quint32));
    printf("sizeof(uchar)=%d B\n",sizeof(qulonglong));

    return a.exec();
}
