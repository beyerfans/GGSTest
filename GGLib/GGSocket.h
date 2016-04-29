#ifndef _GG_SOCKET_H
#define _GG_SOCKET_H

class GGSocket
{
	public:

		GGSocket();
		~GGSocket();

		virtual bool Initialize()=0;
		virtual bool Create()=0;
		virtual bool Bind() = 0;
		virtual bool Listen() = 0;
		virtual bool Connect() = 0;

	protected:

};


#endif