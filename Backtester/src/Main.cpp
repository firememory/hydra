#include <iostream>
#include "CedarHelper.h"
#include "CedarLogging.h"
#include "ProtoBufMsgHub.h"
#include "Backtester.h"

int main() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  CedarLogging::init("Backtester");
  CedarJsonConfig::getInstance().loadConfigFile("./config/Backtester.json");

  Backtester bt;

  LOG(INFO) << "CTPTrade service online!";
  CedarHelper::blockSignalAndSuspend();

  LOG(INFO) << "init quiting procedures now!";
  google::protobuf::ShutdownProtobufLibrary();
}
