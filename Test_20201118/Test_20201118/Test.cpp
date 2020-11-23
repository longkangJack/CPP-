//#include<iostream>
//#include<sstream>
//#include<string>
//using namespace std;
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//void Test1()
//{
//	const char* p1 = "hello";
//	const char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//
//}
////ģ����ػ�
//
//bool IsEqual1(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
////��ģ����ػ�
////ȫ�ػ�
//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<int,char>" << endl;
//	}
//private:
//	int  _d1;
//	char _d2;
//};
//void Test2()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//	Data<char, char> d3;
//}
////ƫ�ػ�:
////�κ����ģ�������һ����������������Ƶ��ػ��汾
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,int>" << endl;
//	}
//private:
//	T1 _d1;
//	int _d2;
//};
//void Test3()
//{
//	Data<char, int> d4;
//	Data<int, int> d5;
//	//���ȵ���ȫ�ػ���Ȼ����ƫ�ػ�
//}
//
//
////void Test4()
////{
////	int n = 123456789;
////	char s1[32];
////	_itoa(n, s1, 10);
////	char s2[32];
////	sprintf(s2, "%d", n);
////	char s3[32];
////	sprintf(s3, "%f", n);
////}
//void Test5()
//{
//	int a = 123456789;
//	string sa;
//	stringstream s;
//	s << a;
//	s >> sa;
//	s.clear();
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string svalue;
//	svalue = s.str();
//	cout << svalue << endl;
//	cout << sa.length()<< endl;	
//}
//
//int main()
//{
//	//Test1();
//	//Test2();
//	//Test3();
//	//Test4();
//	//Test5();
//	return 0;
//}
#include<iostream>                                                                                                     
#include<fstream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


struct ServerInfo
{
      char _ip[32];
       int _port;
 };
struct ConfigManager
{
 public:
         ConfigManager(const char* configfile = "bitserver.config")
         : _configfile(configfile)
               {}
         void WriteBin(const ServerInfo & info)
             {
              ofstream ofs(_configfile, ifstream::in | ifstream::binary);
              ofs.write((const char*)&info, sizeof(ServerInfo));
               ofs.close();
             }
         void ReadBin(ServerInfo & info)
             {
               ifstream ifs(_configfile, ifstream::out | ifstream::binary);
               ifs.read((char*)&info, sizeof(ServerInfo));
               ifs.close();
           }
         void WriteText(const ServerInfo& info)
         {
             // ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
             // C ���Ե��Ȱ�����itoa��д
             ofstream ofs(_configfile);
             ofs << info._ip << endl;
             ofs << info._port << endl;
             ofs.close();
         }
         void ReadText(ServerInfo& info)
         {
             // ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
             // C ���Ե��ȶ��ַ�������atoi
             ifstream ifs(_configfile);
             ifs >> info._ip;
             ifs >> info._port;
             ifs.close();
         }
private:
    string _configfile; // �����ļ�
 };
int main()
{
    ConfigManager cfgMgr;
    ServerInfo wtinfo;
    ServerInfo rdinfo;
    strcpy_s(wtinfo._ip, 32,"127.0.0.1");
    wtinfo._port = 80;
    // �����ƶ�д
    cfgMgr.WriteBin(wtinfo);
    cfgMgr.ReadBin(rdinfo);
    cout << rdinfo._ip << endl;
    cout << rdinfo._port << endl;
    // �ı���д
    cfgMgr.WriteText(wtinfo);
    cfgMgr.ReadText(rdinfo);
    cout << rdinfo._ip << endl;
    cout << rdinfo._port << endl;
    return 0;
}

