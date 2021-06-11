#pragma once

#include "websrv.h"

class Connection;

class Request
{
public:
	struct Argument
	{
		std::string disp;
		std::string ctype;
		std::string data;
	};

	struct Header
	{
		std::string name;
		std::string value;
	};

private:
	std::string _data;
	std::string _method;
	std::string _uri;
	std::string _host;
	std::string _protocol;
	unsigned int _clen;
	std::string _ctype;
	std::string _body;
	std::string _boundary;
	std::string _disp;
	std::string _contype;
	std::vector<Header> _headers;
	std::vector<Argument> _args;
	Connection *_connection;
	bool _isArg;

	void appendToBody(std::string );
	int getSpaceIndex(const std::string &, int);
	Argument parseArgument(const std::string &);

public:
	bool isDone;

	Request();
	Request(Connection *);
	~Request();

	void parseRequest();
	void clear();
	void printRequest();
	void parseHeaders();

	const std::string &getMethod() const;
	const std::string &getUri() const;
	unsigned int getContentLen() const;
	const std::string &getContentType() const;
	const std::string &getBody() const;
	const std::string &getBoundary() const;
	const std::string &getDisposition() const;
	const std::string &getData() const;
	const std::string &getConnectionType() const;
	Connection *getConnection();
	// Data *getServerData();

	void	appendToData(std::string);

	size_t getLenArguments();
	Argument getArgument(int i);
	std::vector<Argument> getArguments();
	std::vector<Header> getHeaders();
};
