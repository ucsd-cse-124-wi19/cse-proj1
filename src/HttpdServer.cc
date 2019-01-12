#include <sysexits.h>

#include "logger.hpp"
#include "HttpdServer.hpp"

HttpdServer::HttpdServer(INIReader& t_config)
	: config(t_config)
{
	auto log = logger();

	long lport = config.GetInteger("httpd", "port", -1);
	if (lport < 0 || lport > 65535) {
		log->error("Port {} is outside the valid range", lport);
		exit(EX_CONFIG);
	}
	port = static_cast<uint16_t>(lport);

	string dr = config.Get("httpd", "doc_root", "");
	if (dr == "") {
		log->error("doc_root was not in the config file");
		exit(EX_CONFIG);
	}
	doc_root = dr;
}

void HttpdServer::launch()
{
	auto log = logger();

	log->info("Launching web server");
	log->info("Port: {}", port);
	log->info("doc_root: {}", doc_root);

	// Put code here that actually launches your webserver...
}
