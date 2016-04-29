#ifndef GG_NET_ADDR
#define _GG_NET_ADDR

#include "NetDefine.h"
#include <string>

#ifdef _WIN32
//#include <WinSock2.h>
#else
#include <netdb.h>
#endif

using namespace std;

class GGNetAddr
{
	public:

		GGNetAddr();
		GGNetAddr(const string& rsIP,const string& rsPort);
		~GGNetAddr();

		void SetAddr(const string& rsIP, const string& rsPort);

	protected:

		void _InitAddr(){ memset(&m_sockaddr, 0, sizeof(m_sockaddr));}
		/*void _SetAddress(string sIP);
		void _SetPort(ggPort usPort);*/
		void _AssignAddr(const string& rsIP, const string& rsPort);

		//GGTO: add socket address

		sockaddr_in m_sockaddr;
};


#endif