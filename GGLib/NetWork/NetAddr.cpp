
#include <ws2tcpip.h>
#include "NetAddr.h"

#pragma comment (lib,"ws2_32.lib")

GGNetAddr::GGNetAddr()
{
	_InitAddr();
}

GGNetAddr::GGNetAddr(const string& rsIP, const string& rsPort)
{
	_InitAddr();
	_AssignAddr(rsIP,rsPort);
}

GGNetAddr::~GGNetAddr()
{
	
}

void GGNetAddr::SetAddr(const string& rsIP, const string& rsPort)
{
	_InitAddr();
	_AssignAddr(rsIP,rsPort);
	return;
}

//void GGNetAddr::_SetAddress(string sIP)
//{
//		
//
//}
//void GGNetAddr::_SetPort(ggPort usPort)
//{
//	m_sockaddr.sin_port = htons(usPort);
//}

void GGNetAddr::_AssignAddr(const string& rsIP, const string& rsPort)
{
	addrinfo *pResult,*pCurrent;

	int iRet = getaddrinfo(rsIP.c_str(), rsPort.c_str(), NULL, &pResult);
	if (iRet != 0)
	{
		//GGTO: add fail process here
	}

	pCurrent = pResult;
	memcpy(&m_sockaddr, pCurrent->ai_addr, pCurrent->ai_addrlen);

	/*for (pCurrent = pResult; pCurrent != NULL; pCurrent = pCurrent->ai_next)
	{
		memcpy(&m_sockaddr, pCurrent->ai_addr, pCurrent->ai_addrlen);
	}*/

	freeaddrinfo(pResult);
}