#ifndef SERVER_DATA_HPP
#define SERVER_DATA_HPP

#include "websrv.h"

class ServerData
{
private:
	int _port;
	std::string _host;
	std::string _name;
	int _client_body_size;
	// error_pages<error code, path of html error page>
	std::map<int, std::string> _error_pages;
	std::string _root_dir;
	std::vector<Location> _locations;

public:
	ServerData();
	~ServerData();

	void setPort(int const &);
	int const & getPort() const;

	void setHost(std::string const &);
	std::string const &getHost() const;

	void setName(std::string const &);
	std::string const & getName() const;
	
	void setClientBodySize(int const &);
	int const &getClientBodySize() const;
	
	void addErrorPage(int const &, std::string const &);
	std::map<int, std::string> const &getErrorPageMap() const;
	
	void setRootDir(std::string const &);
	std::string const &getRootDir() const;
	
	void addLocation(Location const &);
	std::vector<Location> const &getLocations() const;

};

std::ostream &operator<<(std::ostream &, const ServerData &);

#endif // !SERVER_DATA_HPP