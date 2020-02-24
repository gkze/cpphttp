#include <iostream>
#include <map>
#include <string>

#include "dotenv.h"
#include "fmt/format.h"
#include "httplib.h"
#include "json.hpp"
#include "spdlog/spdlog.h"

using namespace dotenv;
using namespace httplib;
using namespace nlohmann;
using namespace std;

namespace log = spdlog;

const int DEFAULT_PORT = 8000;
const string DEFAULT_HOST = "localhost";
const string HEALTH_STATUS_KEY = "health";
const string SERVER_NAME = "cppws";

namespace svrcfg {
enum CfgOpt { Host = 1, Port };

const map<CfgOpt, string> config_env_vars = {
    {CfgOpt::Host, "CPPHTTP_HOST"},
    {CfgOpt::Port, "CPPHTTP_PORT"},
};

struct Config {
  string host;
  int port;

  Config() {
    const auto &env_vars = env;

    host = get_host(env_vars);
    port = get_port(env_vars);
  }

private:
  string get_host(const class dotenv &env) {
    string val = env[config_env_vars.at(CfgOpt::Host)];
    if (val.empty()) {
      return DEFAULT_HOST;
    }

    return val;
  }

  int get_port(const class dotenv &env) {
    string val = env[config_env_vars.at(CfgOpt::Port)];
    if (val.empty()) {
      return DEFAULT_PORT;
    }

    return stoi(val);
  }
};
} // end namespace svrcfg

namespace svrhealth {
enum Status { Healthy = 1, Unhealthy };

struct health {
  Status status;
};

void to_json(json &j, const health &sh) {
  j = json{HEALTH_STATUS_KEY, sh.status};
}

void from_json(const json &j, health &sh) {
  j.at(HEALTH_STATUS_KEY).get_to(sh.status);
}
} // end namespace svrhealth

int main() {
  using namespace svrcfg;
  using namespace svrhealth;

  Config cfg;
  Server svr;

  svr.Get("/health", [](const Request &req, Response &res) {
    log::info("Received health check request");

    res.set_header("Server", SERVER_NAME);
    res.set_content(json{health{Status::Healthy}}.dump(), "application/json");
  });

  svr.Get(R"(/hello/([A-Za-z0-9-_]+))", [&](const Request &req, Response &res) {
    log::info("Received greeting request");

    auto name = req.matches[1];

    res.set_header("Server", SERVER_NAME);
    res.set_content(json{{"hello", name}}.dump(), "application/json");
  });

  log::info(fmt::format("Server listening on {}:{}", cfg.host, cfg.port));
  svr.listen(cfg.host.c_str(), cfg.port);
}
